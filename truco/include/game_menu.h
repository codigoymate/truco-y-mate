/**
 * @file game_menu.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Menú del juego.
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/menu.h>

namespace truco {

/**
 * @brief Menú del juego. Suele tener los comando principales para jugar.
 * 
 */
class GameMenu: public TCurses::Menu {
public:
	/**
	 * @brief Constructor del menu.
	 * 
	 */
	GameMenu();

	/**
	 * @brief Al iniciar el menú.
	 * 
	 */
	void init() override;

private:
	/**
	 * @brief Evento al elegir el item "Salir"
	 * 
	 */
	void quitAction();
};

} // namespace truco
