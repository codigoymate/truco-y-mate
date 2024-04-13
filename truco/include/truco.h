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

#include <vector>

#include <tcurses/tcurses.h>

#include <deck.h>

namespace truco {

/**
 * @brief La clase Truco representa la aplicación del juego Truco.
 *        Hereda de la clase Application de la biblioteca TCurses.
 */
class Truco: public TCurses::Application {
public:
	/**
	 * @brief Inicializa la aplicación Truco.
	 *	Carga los elementos del juego.
	 */
	void init() override;

	/**
	 * @brief Devuelve la referencia al mazo.
	 */
	Deck &getDeck() { return deck; }

private:
	Deck deck; /**< El mazo de cartas del juego.*/

};

} // namespace Truco
