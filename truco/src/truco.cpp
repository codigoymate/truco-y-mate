/**
 * @file truco.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de la aplicación Truco.
 * @date 2024-03-19
 * 
 * Contiene la implementación de la función `init` de la clase TrucoApp,
 * que se encarga de inicializar la aplicación del juego Truco.
 * Contiene el bucle principal.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <truco.h>
#include <mainframe.h>
#include <truco_colors.h>

#include <ncurses.h>

namespace truco {

/**
 * @brief Inicializa la aplicación Truco.
 *	Carga los elementos del juego.
 */
void Truco::init() {

	// Colores
	init_pair(CARD_PAIR, COLOR_BLACK, COLOR_WHITE);
	init_pair(CARD_ORO_PAIR, COLOR_YELLOW, COLOR_WHITE);
    init_pair(CARD_COPAS_PAIR, COLOR_GREEN, COLOR_WHITE);
    init_pair(CARD_ESPADAS_PAIR, COLOR_CYAN, COLOR_WHITE);
    init_pair(CARD_BASTOS_PAIR, COLOR_GREEN, COLOR_WHITE);

	screen->setLayout(TCurses::Component::LY_VERTICAL);
	screen->addChild(std::make_shared<MainFrame>());
}

}

/**
 * @brief Función principal de la aplicación.
 */
int main(int argc, char *argv[]) {
	auto app = truco::Truco();
	app.run();

	return 0;
}
