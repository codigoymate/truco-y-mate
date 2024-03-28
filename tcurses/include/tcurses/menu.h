/**
 * @file menu.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente Menu de la interfaz de usiario. Contiene colección de items para
 * ser seleccionados.
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/component.h>

namespace TCurses {

class Menu: public Component {
public:
	/**
	 * @brief Constructor predeterminado de Menu.
	 */
	Menu();

	/**
	 * @brief Constructor de Menu que establece la posición inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 */
	Menu(const short x, const short y);

	/**
	 * @brief Constructor de Menu que establece la posición y el tamaño inicial.
	 * @param x La coordenada x de la posición inicial.
	 * @param y La coordenada y de la posición inicial.
	 * @param w El ancho inicial del menu.
	 * @param h La altura inicial del menu.
	 */
	Menu(const short x, const short y, const short w, const short h);

	/**
	 * @brief Dibuja el menu.
	 * 
	 */
	void draw() override;

};

}
