/**
 * @file screen.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Archivo de cabecera para la clase Screen.
 * @date 2024-03-19
 * 
 * Contiene la definición de la clase Screen, que representa la pantalla principal de la aplicación.
 * La clase Screen hereda de la clase Component.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <tcurses/component.h>

namespace TCurses {

/**
 * @brief La clase Screen representa la pantalla principal de la aplicación.
 *        Hereda de la clase Component.
 */
class Screen : public Component {
public:
    /**
     * @brief Constructor por defecto de la clase Screen.
     */
	Screen();

    /**
     * @brief Destructor de la clase Screen.
     */
	virtual ~Screen();
};

} // namespace TCurses
