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
#include <ncurses.h>

namespace Truco {

/**
 * @brief Inicializa la aplicación Truco.
 *        Esta función se encarga de inicializar los componentes necesarios para ejecutar el juego.
 */
void TrucoApp::init() {
	menu = std::make_shared<TCurses::Menu>(10, 5, 10, 5);
	menu->setBorder(std::make_shared<TCurses::LinedBorder>(1));
	menu->addChild(std::make_shared<TCurses::MenuItem>("Rojo", std::bind(&TrucoApp::redAction, this)));
	menu->addChild(std::make_shared<TCurses::MenuItem>("Verde", std::bind(&TrucoApp::greenAction, this)));
	menu->addChild(std::make_shared<TCurses::MenuItem>("Azul", std::bind(&TrucoApp::blueAction, this)));

	screen->addChild(menu);
}

void TrucoApp::redAction() {
	init_pair(TCurses::MENU_BORDER_PAIR, COLOR_RED, COLOR_RED);
}

void TrucoApp::greenAction() {
	init_pair(TCurses::MENU_BORDER_PAIR, COLOR_GREEN, COLOR_GREEN);
}

void TrucoApp::blueAction() {
	init_pair(TCurses::MENU_BORDER_PAIR, COLOR_BLUE, COLOR_BLUE);
}

}

/**
 * @brief Función principal de la aplicación.
 * @param argc El número de argumentos de la línea de comandos.
 * @param argv Un arreglo de punteros a caracteres que representan los argumentos de la línea de comandos.
 * @return Devuelve 0 si la aplicación se ejecutó correctamente.
 */
int main(int argc, char *argv[]) {
	auto app = Truco::TrucoApp();
	app.run();

	return 0;
}
