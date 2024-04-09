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
#include <truco_colors.h>

#include <game_menu.h>

#include <ncurses.h>

namespace truco {

/**
 * @brief Constructor de GameFrame.
 */
GameFrame::GameFrame() : TCurses::Frame() {}

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

	// Menu del juego
	mainFrame->addChild(std::make_shared<GameMenu>());

	// ********************************************

	// Status
	status = std::make_shared<TCurses::Label>();
	status->setMaxH(1);
	status->setTextPair(TITLE_PAIR);
	status->setBGPair(TITLE_PAIR);
	status->setAttributes(A_BOLD);
	addChild(status);
}

}
