/**
 * @file art.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente que aloja un gráfico curses-art.
 * https://github.com/codigoymate/curses-art
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/component.h>

#include <vector>

namespace TCurses {

/**
 * @brief Componente TCurses que aloja un gráfico curses-art
 * 
 */
class Art: public TCurses::Component {
public:
	/**
	 * @brief Constructor por defecto de Art.
	 * 
	 */
	Art();

	/**
	 * @brief Constructor de Art donde se indica el gráfico y la transformación del dibujo.
	 * 
	 * @param data Vector del gráfico curses art.
	 * @param x Posición X del componente.
	 * @param y Posición Y del componente.
	 * @param w Ancho del gráfico.
	 * @param h Alto del gráfico.
	 */
	Art(std::vector<unsigned int> data, const short x, const short y, const short w, const short h);

	/**
	 * @brief Constructor de Art donde se indica el gráfico y el tramaño del mismo.
	 * 
	 * @param data Vector del gráfico curses art.
	 * @param w Ancho del gráfico.
	 * @param h Alto del gráfico.
	 */
	Art(std::vector<unsigned int> data, const short w, const short h);

	/**
	 * @brief Establece el gráfico curses-art.
	 * 
	 * @param data Vector del gráfico curses art.
	 * @param w Ancho del gráfico.
	 * @param h Alto del gráfico.
	 */
	void setData(std::vector<unsigned int> data, const short w, const short h);

	/**
	 * @brief Dibuja el componente.
	 * 
	 */
	void draw() override;

private:
	std::vector<unsigned int> data; /**< Gráfico curses-art representado en un vector de enteros.*/
};

} // namesplace TCurses
