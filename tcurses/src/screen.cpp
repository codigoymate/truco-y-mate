/**
 * @file screen.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de la clase Screen.
 * @date 2024-03-19
 * 
 * Contiene la implementación de las funciones miembro de la clase Screen.
 * La clase Screen representa la pantalla principal de la aplicación y se encarga de inicializar
 * el entorno ncurses y configurar las propiedades de la pantalla.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tcurses/screen.h>
#include <tcurses/application.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Constructor de la clase Screen.
 *        Inicializa el entorno ncurses y configura las propiedades de la pantalla.
 * @param Application* Referencia a Application.
 */
Screen::Screen(Application *application) : Component() {

	this->application = application;

	initscr();
    noecho();
    curs_set(0);
	nodelay(stdscr, TRUE);
    
    start_color();

    keypad(stdscr, TRUE);

    set_escdelay(0);

	// Propiedades de la pantalla
	this->setPos(0, 0);
	this->setSize(getmaxx(stdscr), getmaxy(stdscr));
}

/**
 * @brief Destructor de la clase Screen.
 *        Finaliza el entorno ncurses al destruir el objeto.
 */
Screen::~Screen() {
	endwin();
}

/**
 * @brief Actualiza todos los componentes de la pantalla.
 * 
 */
void Screen::updateAll() {
	internalUpdate();
}

/**
 * @brief Dibuja todos los componentes de la pantalla.
 * 
 */
void Screen::drawAll() {
	clear();
	internalDraw();
	refresh();
}

} // namespace TCurses
