/**
 * @file mainframe.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Frame dónde se aloja el título y el menú principal.
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <mainframe.h>

#include <deck.h>
#include <truco.h>

#include <big_card_component.h>

namespace truco {

MainFrame::MainFrame() : TCurses::Frame() {}

/**
 * @brief Al iniciar el frame.
 * 
 */
void MainFrame::init() {
	this->setLayout(TCurses::Component::LY_VERTICAL);

	// Título
	auto title = std::make_shared<TCurses::Art>(std::vector<unsigned int>({
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x501371, 0x501371, 0x501371, 0x501377, 0x501377, 
0x501371, 0x501371, 0x501371, 0x0000, 0x50136C, 0x501377, 0x501371, 0x501371, 0x501371, 0x501371, 0x50136B, 0x0000, 0x0000, 0x501378, 0x501378, 0x0000, 
0x0000, 0x0000, 0x0000, 0x501378, 0x501378, 0x0000, 0x0000, 0x50136C, 0x501371, 0x501371, 0x501371, 0x501371, 0x501371, 0x0000, 0x0000, 0x50136C, 
0x501371, 0x501371, 0x501371, 0x501371, 0x50136B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x501378, 0x501378, 0x0000, 0x0000, 0x0000, 
0x0000, 0x501378, 0x501378, 0x0000, 0x0000, 0x0000, 0x0000, 0x501378, 0x501378, 0x0000, 0x501378, 0x501378, 0x0000, 0x0000, 0x0000, 0x0000, 
0x501378, 0x501378, 0x0000, 0x50136C, 0x501375, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x50136C, 0x501375, 0x0000, 0x0000, 0x0000, 
0x0000, 0x501374, 0x50136B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C78, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C74, 
0x501C71, 0x501C71, 0x501C71, 0x501C77, 0x501C75, 0x0000, 0x0000, 0x501C78, 0x501C78, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C78, 0x0000, 
0x501C78, 0x501C78, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C78, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C78, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C78, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C78, 0x501C78, 0x0000, 0x0000, 0x0000, 
0x501C6D, 0x501C75, 0x0000, 0x0000, 0x501C6D, 0x501C75, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C74, 0x501C6A, 0x0000, 0x501C6D, 0x501C75, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C6D, 0x501C75, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C74, 0x501C6A, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x501C6D, 0x501C6A, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C6D, 0x501C6A, 0x0000, 0x0000, 0x0000, 0x0000, 0x501C6D, 0x501C71, 
0x0000, 0x0000, 0x501C6D, 0x501C71, 0x501C71, 0x501C71, 0x501C71, 0x501C6A, 0x0000, 0x0000, 0x0000, 0x501C6D, 0x501C71, 0x501C71, 0x501C71, 0x501C71, 
0x501C71, 0x0000, 0x0000, 0x501C6D, 0x501C71, 0x501C71, 0x501C71, 0x501C71, 0x501C6A, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x200741, 0x0000, 0x200752, 0x0000, 0x200747, 0x0000, 0x200745, 0x0000, 0x20074E, 0x0000, 
0x200754, 0x0000, 0x200749, 0x0000, 0x20074E, 0x0000, 0x20074F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000	}), 45, 11);
	title->setHAlign(TCurses::Component::HA_CENTER);
	this->addChild(title);

	mainMenu = std::make_shared<TCurses::Menu>();
	mainMenu->setMaxW(20); mainMenu->setMaxH(5);
	mainMenu->setBorder(std::make_shared<TCurses::LinedBorder>(1));
	mainMenu->setHAlign(TCurses::Component::HA_CENTER);
	this->addChild(mainMenu);

	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Uno contra uno"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Dos contra dos"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Tres contra tres"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Opciones"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Salir", std::bind(&MainFrame::quitAction, this)));

	auto &deck = static_cast<Truco *>(application)->getDeck();
	deck.merge();

	auto frame = std::make_shared<TCurses::Frame>();
	frame->setLayout(TCurses::Component::LY_HORIZONTAL);
	frame->addChild(std::make_shared<BigCardComponent>(&deck[40]));
	frame->addChild(std::make_shared<BigCardComponent>(&deck[39]));
	frame->addChild(std::make_shared<BigCardComponent>(&deck[38]));
	this->addChild(frame);
}

/**
 * @brief Al seleccionar "Salir" en el menú principal.
 * 
 */
void MainFrame::quitAction() {
	application->quit();
}

} // namespace truco
