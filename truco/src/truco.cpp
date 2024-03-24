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

    auto label = std::make_shared<TCurses::Label>(text);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMinH(5);
	label->setMaxH(5);
	label->setVAlign(TCurses::Component::VA_BOTTOM);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMinH(5);
	label->setMaxH(5);
	label->setVAlign(TCurses::Component::VA_CENTER);
	label->setBGPair(40);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMinH(5);
	label->setMaxH(5);
	label->setVAlign(TCurses::Component::VA_TOP);
	screen->addChild(label);

	label = std::make_shared<TCurses::Label>(text);
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setBGPair(40);
	screen->addChild(label);

	screen->setLayout(TCurses::Component::LY_HORIZONTAL);

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
