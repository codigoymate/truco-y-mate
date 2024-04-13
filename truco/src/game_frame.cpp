/**
 * @file gameframe.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de GameFrame.h
 * @date 2024-04-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <game_frame.h>
#include <start_frame.h>

#include <truco_colors.h>

#include <big_card_component.h>
#include <truco.h>
#include <player.h>

#include <ncurses.h>

namespace truco {

/**
 * @brief Constructor de GameFrame.
 * 
 * @param playerCount Cantidad de jugadores para configurar el partido.
 */
GameFrame::GameFrame(const unsigned playerCount) : TCurses::Frame() {
	turnManager = TurnManager(this);

	// Crea los jugadores
	for (unsigned i = 0; i < playerCount; i ++) players.push_back(std::make_shared<Player>());
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
	auto tableFrame = std::make_shared<TCurses::Frame>();
	mainFrame->addChild(tableFrame);

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
}

/**
 * @brief Al elegir salir en el menú.
 * 
 */
void GameFrame::quitItemAction() {
	application->getScreen()->removeChildren();
	application->getScreen()->addChild(std::make_shared<StartFrame>());
}

}
