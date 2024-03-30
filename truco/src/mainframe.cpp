#include <mainframe.h>

namespace truco {

MainFrame::MainFrame() : TCurses::Frame() {}

void MainFrame::init() {
	this->setLayout(TCurses::Component::LY_VERTICAL);

	mainMenu = std::make_shared<TCurses::Menu>();
	this->addChild(mainMenu);

	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Un Jugador"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Dos Jugadores"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Tres Jugadores"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Opciones"));
	mainMenu->addChild(std::make_shared<TCurses::MenuItem>("Salir", std::bind(&MainFrame::quitAction, this)));
}

void MainFrame::quitAction() {
	application->quit();
}

}
