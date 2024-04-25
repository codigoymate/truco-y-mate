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
#include <entities/player.h>
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

	gameFrame->getApplication()->getScreen()->drawAll();
	
	this->currentPlayer()->play();
}

/**
 * @brief Inicia la siguiente ronda.
 * 
 */
void StepManager::nextRound() {
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
		currentPlayerIndex ++;
		if (currentPlayerIndex >= gameFrame->getPlayers().size()) currentPlayerIndex = 0;
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
	if (winner == -1) {
		// Parda, continua el siguiente jugador.
		currentPlayerIndex ++;
		if (currentPlayerIndex >= gameFrame->getPlayers().size()) currentPlayerIndex = 0;
	} else {
		// Continua el ganador
		currentPlayerIndex = winner;
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

}
