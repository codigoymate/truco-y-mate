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
	auto frame = std::make_shared<TCurses::Frame>(30, 4, 20, 15);
	frame->setBorder(std::make_shared<TCurses::LinedBorder>(1));
	frame->setLayout(TCurses::Component::LY_VERTICAL);

	auto label = std::make_shared<TCurses::Label>("Label 1");
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMaxH(1); //label->setMaxW(9);
	frame->addChild(label);
	label = std::make_shared<TCurses::Label>("Label 2");
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMaxH(1); //label->setMaxW(9);
	frame->addChild(label);
	label = std::make_shared<TCurses::Label>("Label 3");
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMaxH(1); //label->setMaxW(9);
	frame->addChild(label);
	label = std::make_shared<TCurses::Label>("Label 4");
	label->setTextAlign(TCurses::Component::HA_CENTER, TCurses::Component::VA_CENTER);
	label->setMaxH(1); //label->setMaxW(9);
	frame->addChild(label);

	screen->addChild(frame);

	frame->removeChild(label);
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
