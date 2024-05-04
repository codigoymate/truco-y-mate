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
#include <thread>
#include <chrono>

#include <ncurses.h>

#include <tcurses/screen.h>
#include <tcurses/colors.h>
#include <tcurses/input_event.h>
#include <tcurses/emergent.h>

namespace TCurses {

/**
 * @brief Constructor de la clase Application.
 *        Inicializa el entorno de ncurses y crea la pantalla principal.
 */
Application::Application() {
	setlocale(LC_ALL, "");

	screen = std::make_shared<Screen>(this);

	// Agrega el primer input listener
	inputListeners.push(std::list<std::shared_ptr<InputListener>>());

	initColors();
}

/**
 * @brief Ejecuta la aplicación.
 *        Esta función inicializa la aplicación y entra en el bucle principal.
 */
void Application::run() {
	init();

	int ch = 0;
	running = true;
	while (running) {

		screen->updateAll();
		for (auto &e : emergents) e->updateAll();
		
		clear();
		screen->drawAll(); // Dibuja la pantalla
		for (auto &e : emergents) e->drawAll();
		refresh();

		

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		ch = getch();

		if (ch != ERR) { // Se presionó una tecla

			if (ch == KEY_RESIZE) {
				screen->setSize(getmaxx(stdscr), getmaxy(stdscr));
				clear();
				screen->drawAll(); // Dibuja la pantalla
				for (auto &e : emergents) e->drawAll();
				refresh();
			} else {
				// Crea una copia de los input listeners para que no haya problemas con el foreach
				auto il = std::list<std::shared_ptr<InputListener>>(inputListeners.top());
				for (auto &i : il) {
					i->keyPressed(ch);
				}
			}
		}
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

	init_pair(FRAME_BG_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(FRAME_BORDER_PAIR, COLOR_WHITE, COLOR_BLACK);

	init_pair(LABEL_TEXT_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(LABEL_BG_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(LABEL_BORDER_PAIR, COLOR_WHITE, COLOR_BLACK);

	init_pair(MENU_BG_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(MENU_BORDER_PAIR, COLOR_WHITE, COLOR_BLACK);

	init_pair(MENUITEM_TEXT_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(MENUITEM_BG_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(MENUITEM_BORDER_PAIR, COLOR_WHITE, COLOR_BLACK);

	init_pair(MENUITEM_SEL_TEXT_PAIR, COLOR_BLACK, COLOR_GREEN);
	init_pair(MENUITEM_SEL_BG_PAIR, COLOR_BLACK, COLOR_GREEN);
	init_pair(MENUITEM_SEL_BORDER_PAIR, COLOR_WHITE, COLOR_GREEN);

	init_pair(ART_BG_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(ART_BORDER_PAIR, COLOR_WHITE, COLOR_WHITE);

	init_pair(EMERGENT_BG_PAIR, COLOR_BLACK, COLOR_BLUE);
	init_pair(EMERGENT_BORDER_PAIR, COLOR_WHITE, COLOR_BLUE);
}

/**
 * @brief Agrega un componente InputListener a los eventos de entrada.
 * 
 * @param listener Puntero compartido a componente InputListener.
 */
void Application::addInputListener(std::shared_ptr<InputListener> listener) {
	inputListeners.top().push_back(listener);
}

/**
 * @brief Quita un componente InputListener de los eventos de entrada.
 * 
 * @param listener Puntero compartido a componente InputListener.
 */
void Application::removeInputListener(std::shared_ptr<InputListener> listener) {
	inputListeners.top().remove(listener);
}

/**
 * @brief Registra y muestra un Emergent.
 * 
 * @param e Emergent a mostrar.
 */
void Application::showEmergent(std::shared_ptr<Emergent> e) {
	emergents.push_back(e);
	e->setApplication(this);

	// Agrega una lista de input listeners a la cola
	inputListeners.push(std::list<std::shared_ptr<InputListener>>());

	e->init();
}

/**
 * @brief Elimina el último Emergent de Application.
 * 
 */
void Application::disposeEmergent() {
	inputListeners.pop();
	emergents.pop_back();
}

} // namespace TCurses
