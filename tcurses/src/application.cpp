/**
 * @file application.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de la clase Application.
 * @date 2024-03-19
 * 
 * Contiene la implementación de las funciones miembro de la clase Application.
 * La clase Application representa la aplicación principal y se encarga de inicializar el entorno ncurses,
 * crear la pantalla principal y ejecutar el bucle principal de la aplicación.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tcurses/application.h>

#include <clocale>
#include <ncurses.h>

#include <tcurses/screen.h>
#include <tcurses/colors.h>

namespace TCurses {

/**
 * @brief Constructor de la clase Application.
 *        Inicializa el entorno de ncurses y crea la pantalla principal.
 */
Application::Application() {
	setlocale(LC_ALL, "");

	screen = std::make_shared<Screen>();

	initColors();
}

/**
 * @brief Ejecuta la aplicación.
 *        Esta función inicializa la aplicación y entra en el bucle principal.
 */
void Application::run() {
	init();

	int ch = 0;
	while (ch != 27) { // Salir del bucle al presionar la tecla ESC (código ASCII 27)

		screen->drawAll(); // Dibuja la pantalla
		ch = getch();
	}
}

/**
 * @brief Inicializa los colores utilizados por la aplicación.
 *        Esta función configura la paleta de colores para la interfaz de la aplicación.
 */
void Application::initColors() {
	int bg, fg, p = 1;

	/* Inicializar pares de colores */
	for (bg = 0; bg < 8; bg ++) {
		for (fg = 0; fg < 8; fg ++) {
			init_pair(p, fg, bg); p ++;
		}
	}

	init_pair(LABEL_TEXT_PAIR, COLOR_WHITE, COLOR_GREEN);
	init_pair(LABEL_BG_PAIR, COLOR_BLACK, COLOR_GREEN);
}

} // namespace TCurses
