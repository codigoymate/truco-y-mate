/**
 * @file border.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de las funciones miembro de las clases relacionadas con los bordes en la biblioteca TCurses.
 * @date 2024-03-24
 * 
 * Este archivo contiene la implementación de las funciones miembro de la clase LinedBorder para dibujar un borde formado por líneas alrededor de un componente en la biblioteca TCurses.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tcurses/border.h>
#include <tcurses/component.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Dibuja un borde formado por líneas alrededor del componente asociado.
 * 
 * Calcula las coordenadas de las líneas y esquinas del borde utilizando la posición del borde y el tamaño del componente.
 * Luego, utiliza las funciones de ncurses para dibujar las líneas y esquinas del borde en la pantalla.
 * 
 * @note Esta función es una implementación de la función virtual pura definida en la clase Border.
 */
void LinedBorder::draw() const {
	// Calcular las coordenadas del borde
	short x1 = comp->getAbsX() - pos;
	short y1 = comp->getAbsY() - pos;
	short x2 = comp->getAbsX() + comp->getW() - 1 + pos;
	short y2 = comp->getAbsY() + comp->getH() - 1 + pos;

	// Dibujar las líneas horizontales
	mvhline(y1, x1, ACS_HLINE, comp->getW() + pos);
	mvhline(y2, x1, ACS_HLINE, comp->getW() + pos);

	// Dibujar las líneas verticales
	mvvline(y1, x1, ACS_VLINE, comp->getH() + pos);
	mvvline(y1, x2, ACS_VLINE, comp->getH() + pos);

	// Dibujar las esquinas del borde
	mvaddch(y1, x1, ACS_ULCORNER); // Esquina superior izquierda
	mvaddch(y2, x1, ACS_LLCORNER); // Esquina inferior izquierda
	mvaddch(y1, x2, ACS_URCORNER); // Esquina superior derecha
	mvaddch(y2, x2, ACS_LRCORNER); // Esquina inferior derecha
}

} // namespace TCurses
