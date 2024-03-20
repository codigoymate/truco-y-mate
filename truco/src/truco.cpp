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

namespace Truco {

/**
 * @brief Inicializa la aplicación Truco.
 *        Esta función se encarga de inicializar los componentes necesarios para ejecutar el juego.
 */
void TrucoApp::init() {

	std::string text = "Rojo\nVerde\nAzul";
	//std::string text = "Rojo 1111111\nVerde 222222\nAzul 33333\nAmarillo 444444\nVioleta\nMarron\nEsmeralda\nCiano";

    auto label = std::make_shared<TCurses::Label>(text, 10, 2, 10, 6);
	label->setTextAlign(TCurses::Component::HA_LEFT, TCurses::Component::VA_TOP);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 30, 2, 10, 6);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_TOP);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 50, 2, 10, 6);
	label->setTextAlign(TCurses::Component::HA_RIGHT, TCurses::Component::VA_TOP);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 10, 10, 10, 6);
	label->setTextAlign(TCurses::Component::HA_LEFT, TCurses::Component::VA_CENTER);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 30, 10, 10, 6);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 50, 10, 10, 6);
	label->setTextAlign(TCurses::Component::HA_RIGHT, TCurses::Component::VA_CENTER);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 10, 18, 10, 6);
	label->setTextAlign(TCurses::Component::HA_LEFT, TCurses::Component::VA_BOTTOM);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 30, 18, 10, 6);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_BOTTOM);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text, 50, 18, 10, 6);
	label->setTextAlign(TCurses::Component::HA_RIGHT, TCurses::Component::VA_BOTTOM);
	screen->addChild(label);

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
