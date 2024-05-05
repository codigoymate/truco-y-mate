/**
 * @file step_manager.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de step_manager.h
 * @version 0.1
 * @date 2024-04-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <entities/step_manager.h>

#include <utils/random.h>

#include <components/game_frame.h>
#include <components/score_frame.h>
#include <entities/player.h>

#include <dialogs/end_round_dialog.h>

#include <truco.h>

namespace truco {

/**
 * @brief Constructor de step manager.
 *  
 * @param gameFrame El frame de la partida actual.
 */
StepManager::StepManager(GameFrame *gameFrame) : gameFrame{gameFrame} {
	// Elige el jugador mano
	startPlayer = Random::randInt(0, gameFrame->getPlayers().size() - 1);
}

/**
 * @brief Devuelve el jugador actual.
 */
std::shared_ptr<Player> StepManager::currentPlayer() {
	return gameFrame->getPlayers()[currentPlayerIndex];
}

/**
 * @brief Verifica si no se jugó una carta en la mano indicada.
 * 
 * @param n el número de mano.
 * @return true si no se jugó alguna carta.
 */
bool StepManager::isHandClear(const unsigned n) {
	for (auto p : gameFrame->getPlayers()) {
		if (p->getPlayed(n)) return false;
	}

	return true;
}

/**
 * @brief Verifica si se jugaron todas las cartas en la mano indicada.
 * 
 * @param n el número de mano.
 * @return true si se jugaron todas las cartas
 */
bool StepManager::isHandFull(const unsigned n) {
	for (auto p : gameFrame->getPlayers()) {
		if (!p->getPlayed(n)) return false;
	}

	return true;
}

/**
 * @brief "Próximo paso": llama al siguente jugador para realizar la jugada.
 * 
 */
void StepManager::step() {
	this->nextPlayer();
}

/**
 * @brief Inicia la siguiente ronda.
 * 
 */
void StepManager::nextRound() {

	halt = false;

	round ++;
	handIndex = 0;

	// Incrementa el jugador mano
	this->startPlayer ++;
	if (this->startPlayer >= gameFrame->getPlayers().size()) this->startPlayer = 0;

	// Mezcla y reparte
	auto &deck = static_cast<Truco *>(gameFrame->getApplication())->getDeck();
	deck.merge();
	deck.deliver(gameFrame->getPlayers());

	this->step();

}

/**
 * @brief Determina el próximo turno.
 * 
 */
void StepManager::nextPlayer() {
	if (this->isHandClear(handIndex)) nextPlayerHandClear();
	else if (this->isHandFull(handIndex)) nextPlayerHandFull();
	else {
		// Se jugaron cartas, pero no completaron la mano ...
		incrementPlayerIndex();
	}

	gameFrame->getCurrentPlayerLabel()->setText(
		"Turno de " + currentPlayer()->getName()
	);
}

/**
 * @brief Próximo jugador cuando no hay cartas en la mano.
 * 
 */
void StepManager::nextPlayerHandClear() {
	// Si es la primera mano
	if (handIndex == 0) {
		// Turno del jugador mano
		currentPlayerIndex = startPlayer;
	}
}

/**
 * @brief Próximo jugador cuando todos jugaron una carta en la mano.
 * 
 */
void StepManager::nextPlayerHandFull() {
	// Busca el ganador de la mano
	auto winner = getHandWinner(handIndex);
	if (winner == -1) { // En el caso de que sea parda
		switch (handIndex) {
		case 0: // Primera mano
			incrementPlayerIndex();
			break;
		case 1: {// Segunda mano
			auto winner0 = getHandWinner(0);
			// Si se empardó la primera ...
			if (winner0 == -1) incrementPlayerIndex();
			else {
				// Gana el ganador de la segunda.
				endRound(winner); return;
			}
			}
			break;
		case 2: // Tercera mano
			// Se enpardó las tres manos ...
			// Gana el jugador mano.
			endRound(startPlayer); return;
			break;
		}
		
	} else {
		switch (handIndex) {
		case 0: // Primera mano
			// Continua el ganador
			currentPlayerIndex = winner;
			break;
		case 1: {// Segunda mano
			auto winner0 = getHandWinner(0);
			if (winner0 == -1) { // Si se empardó primera ...
				// Gana el ganador de la segunda.
				endRound(winner); return;
			} else {
				// Si alguien ganó primera ...
				// Si un solo equipo obtuvo primera y segunda ..
				if (winner % 2 == winner0 % 2) {
					// Gana el ganador de segunda y primera
					endRound(winner); return;
				} else {
					// Continua el ganador
					currentPlayerIndex = winner;
				}
			}
			} break;
		case 2: // Tercera mano
			endRound(winner); return;
		}

	}

	// Próxima mano
	handIndex ++;
}

/**
 * @brief Busca el ganador de la mano n.
 * Si se empata la mano (parda), devuelve -1.
 * 
 * @param n Número de mano.
 * @return const signed Índice del jugador ganador o -1 si hay empate.
 */
const signed StepManager::getHandWinner(const unsigned n) const {
	std::vector<std::shared_ptr<Player>> players;

	// Copia la lista de jugadores
	for (auto p : gameFrame->getPlayers()) {
		players.push_back(p);
	}

	// Ordena los jugadores según las cartas jugadas en la mano
	for (signed i = 0; i < players.size() - 1; i ++) {
		if (players[i]->getPlayed(n)->getWeight() < players[i + 1]->getPlayed(n)->getWeight()) {
			auto p = players[i];
			players[i] = players[i + 1];
			players[i + 1] = p; i = -1;
		}
	}

	// Si hay empate
	if (players[0]->getPlayed(n)->getWeight() == players[1]->getPlayed(n)->getWeight()) {
		return -1;
	}

	return players[0]->getID();
}

/**
 * @brief Incrementa el índice de jugador. Cuando se alcanza el máximo, 
 * arranca de 0.
 * 
 */
void StepManager::incrementPlayerIndex() {
	currentPlayerIndex ++;
	if (currentPlayerIndex >= gameFrame->getPlayers().size()) currentPlayerIndex = 0;
}

/**
 * @brief Finaliza una ronda indicando el ganador.
 * 
 * @param winnner El ganador de la ronda.
 */
void StepManager::endRound(unsigned winnner) {

	// Muestra mensaje de ganador
	std::string wins;
	if (gameFrame->getPlayers().size() == 2) wins = " gana ";
	else wins = (winnner % 2 ? " ganan " : " ganamos ");

	gameFrame->setInfoText(gameFrame->getTeamName(winnner % 2) +
	wins + "la ronda.");

	// Asigna los puntos
	gameFrame->getScoreFrame()->setScore(winnner % 2, 1);

	// Detiene el StepManager
	halt = true;

	// Muestra el diálogo de final de ronda.
	gameFrame->getApplication()->showEmergent(std::make_shared<EndRoundDialog>(gameFrame, winnner % 2));

}

}
