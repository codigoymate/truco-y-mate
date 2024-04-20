/**
 * @file gameframe.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de GameFrame.h
 * @date 2024-04-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <components/game_frame.h>
#include <components/start_frame.h>

#include <truco_colors.h>

#include <components/big_card_component.h>
#include <truco.h>
#include <entities/player.h>
#include <entities/behavior.h>
#include <components/player_frame.h>
#include <utils/random.h>

#include <ncurses.h>

#include <cstdlib>

namespace truco {

/**
 * @brief Constructor de GameFrame.
 * 
 * @param playerCount Cantidad de jugadores para configurar el partido.
 */
GameFrame::GameFrame(const unsigned playerCount) : TCurses::Frame() {
	// Crea los jugadores
	for (unsigned i = 0; i < playerCount; i ++) {
		if (!i) {
			players.push_back(std::make_shared<Player>(std::make_shared<Human>(this), std::getenv("USER")));
		} else players.push_back(std::make_shared<Player>(std::make_shared<Human>(this)));
		
		playerFrames.push_back(std::make_shared<PlayerFrame>(players[i]->getName()));
	}

	// Elige el jugador mano
	startPlayer = Random::randInt(0, players.size() - 1);

}

/**
 * @brief Al inicia el Frame.
 * 
 */
void GameFrame::init() {
	this->setLayout(TCurses::Component::LY_VERTICAL);

	// Título
	auto title = std::make_shared<TCurses::Label>("Truco Argentino");
	title->setMaxH(1);
	title->setTextPair(TITLE_PAIR);
	title->setBGPair(TITLE_PAIR);
	title->setHTextAlign(TCurses::Component::HA_CENTER);
	title->setAttributes(A_BOLD);
	addChild(title);

	// Frame del centro ***************************
	mainFrame = std::make_shared<TCurses::Frame>();
	mainFrame->setLayout(TCurses::Component::LY_HORIZONTAL);
	addChild(mainFrame);

	// Frame de la mesa
	mainFrame->addChild(this->layoutTable());

	// Cartas de la mano del jugador 1
	for (unsigned i = 0; i < 3; i ++) {
		hand[i] = std::make_shared<BigCardComponent>();
		hand[i]->setVAlign(Component::VA_BOTTOM);
		mainFrame->addChild(hand[i]);
	}

	// Menu del juego
	menu = std::make_shared<TCurses::Menu>();
	menu->setMinH(1); menu->setMaxH(1);
	menu->setMinW(15); menu->setMaxW(15);
	menu->setVAlign(TCurses::Component::VA_BOTTOM);
	mainFrame->addChild(menu);

	menu->addChild(std::make_shared<TCurses::MenuItem>("Salir", std::bind(&GameFrame::quitItemAction, this)));

	// ********************************************

	// Status
	status = std::make_shared<TCurses::Label>();
	status->setMaxH(1);
	status->setTextPair(TITLE_PAIR);
	status->setBGPair(TITLE_PAIR);
	status->setAttributes(A_BOLD);
	addChild(status);

	// TODO: Provisorio: mezcla y reparte
	auto &deck = static_cast<Truco *>(application)->getDeck();

	deck.merge();
	deck.deliver(players);

	this->update();
}

/**
 * @brief Actualiza los componentes con la lógica de la partida.
 * 
 */
void GameFrame::update() {
	// Las cartas de la mano del jugador 1
	for (unsigned i = 0; i < 3; i ++) {
		hand[i]->setCard(players[0]->getHand(i));
	}

	// Las carta jugadas
	for (unsigned p = 0; p < players.size(); p ++) {
		for (unsigned c = 0; c < 3; c ++) {
			playerFrames[p]->setCard(c, players[p]->getPlayed(c));
		}
	}
}

/**
 * @brief Al elegir salir en el menú.
 * 
 */
void GameFrame::quitItemAction() {
	application->getScreen()->removeChildren();
	application->getScreen()->addChild(std::make_shared<StartFrame>());
}

/**
 * @brief Distribuye los jugadores en la mensa.
 * 
 * @return std::shared_ptr<Frame> Frame de la mesa con los jugadores distribuidos.
 */
std::shared_ptr<TCurses::Frame> GameFrame::layoutTable() {
	auto tableFrame = std::make_shared<TCurses::Frame>();
	tableFrame->setLayout(TCurses::Component::LY_VERTICAL);

	switch (players.size()) {
	case 2:
		playerFrames[1]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[1]);

		tableFrame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[0]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[0]);
		break;
	
	case 4: {
		playerFrames[2]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[2]);

		auto frame = std::make_shared<TCurses::Frame>();
		tableFrame->addChild(frame);
		frame->setLayout(TCurses::Component::LY_HORIZONTAL);

		playerFrames[1]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[1]);

		frame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[3]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[3]);

		playerFrames[0]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[0]);
		} break;

	case 6: {
		playerFrames[3]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[3]);

		auto frame = std::make_shared<TCurses::Frame>();
		tableFrame->addChild(frame);
		frame->setLayout(TCurses::Component::LY_HORIZONTAL);

		playerFrames[2]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[2]);

		frame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[4]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[4]);

		frame = std::make_shared<TCurses::Frame>();
		tableFrame->addChild(frame);
		frame->setLayout(TCurses::Component::LY_HORIZONTAL);

		playerFrames[1]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[1]);

		frame->addChild(std::make_shared<TCurses::Frame>());

		playerFrames[5]->setVAlign(TCurses::Component::VA_CENTER);
		frame->addChild(playerFrames[5]);

		playerFrames[0]->setHAlign(TCurses::Component::HA_CENTER);
		tableFrame->addChild(playerFrames[0]);
		} break;
	}

	return tableFrame;
}

/**
 * @brief Verifica si no se jugó una carta en la mano indicada.
 * 
 * @param n el número de mano.
 * @return true si no se jugó alguna carta.
 */
bool GameFrame::isHandClear(const unsigned n) {
	for (auto p : players) {
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
bool GameFrame::isHandFull(const unsigned n) {
	for (auto p : players) {
		if (!p->getPlayed(n)) return false;
	}

	return true;
}

/**
 * @brief Inicia la siguiente ronda.
 * 
 */
void GameFrame::nextRound() {
	round ++;
	handIndex = 0;

	// Incrementa el jugador mano
	this->startPlayer ++;
	if (this->startPlayer >= players.size()) this->startPlayer = 0;

	// Mezcla y reparte
	auto &deck = static_cast<Truco *>(application)->getDeck();
	deck.merge();
	deck.deliver(players);

}

/**
 * @brief Determina el próximo turno.
 * 
 */
void GameFrame::nextPlayer() {
	if (handIndex == 0 && this->isHandClear(0)) {
		currentPlayerIndex = startPlayer;
	}
}

}
