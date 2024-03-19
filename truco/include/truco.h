/**
 * @file truco.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Archivo de cabecera para la aplicación Truco.
 * @date 2024-03-19
 * 
 * Contiene la declaración de la clase TrucoApp, que representa la aplicación del juego Truco.
 * La clase TrucoApp hereda de la clase Application de la biblioteca TCurses.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <tcurses/tcurses.h>

namespace Truco {

/**
 * @brief La clase TrucoApp representa la aplicación del juego Truco.
 *        Hereda de la clase Application de la biblioteca TCurses.
 */
class TrucoApp: public TCurses::Application {
public:
	/**
	 * @brief Inicializa la aplicación Truco.
	 *        Esta función se encarga de inicializar los componentes necesarios para ejecutar el juego.
	 */
	void init() override;
};

} // namespace Truco
