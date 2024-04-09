/**
 * @file game_menu.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación del menú del juego.
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <game_menu.h>

#include <tcurses/menuitem.h>
#include <tcurses/application.h>
#include <tcurses/screen.h>

#include <start_frame.h>

namespace truco {

/**
 * @brief Constructor del menu.
 * 
 */
GameMenu::GameMenu() : Menu() {
	setMaxW(15); setMinW(10);
	setMaxH(1); setMinH(1);
	setVAlign(TCurses::Component::VA_BOTTOM);
}


/**
 * @brief Al iniciar el menú.
 * 
 */
void GameMenu::init() {
	addChild(std::make_shared<TCurses::MenuItem>("Salir", std::bind(&GameMenu::quitAction, this)));
}

/**
 * @brief Evento al elegir el item "Salir".
 * Vuelve a la pantalla del título.
 * 
 */
void GameMenu::quitAction() {
	// Vuelve al menu de título
	application->getScreen()->removeChildren();
	application->getScreen()->addChild(std::make_shared<StartFrame>());
}

} // namespace truco
