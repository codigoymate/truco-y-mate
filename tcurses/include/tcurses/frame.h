/**
 * @file frame.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente Frame que sirve como contenedor.
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/component.h>

namespace TCurses {

class Frame: public Component {
public:
    /**
	 * @brief Constructor predeterminado de Frame.
	 */
	Frame();

	/**
	 * @brief Constructor de Frame que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Frame(const short x, const short y);

	/**
	 * @brief Constructor de Frame que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del frame.
	 * @param h La altura inicial del frame.
	 */
	Frame(const short x, const short y, const short w, const short h);

	/**
	 * @brief Dibuja el frame.
	 * 
	 */
	void draw() override;
};

}
