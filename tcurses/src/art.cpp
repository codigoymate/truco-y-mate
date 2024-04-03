/**
 * @file art.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación del componente Art.
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <tcurses/art.h>
#include <tcurses/colors.h>
#include <tcurses/utilities.h>
#include <tcurses/border.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Constructor por defecto de Art.
 * 
 */
Art::Art() : Art({}, 1, 1) {}

/**
 * @brief Constructor de Art donde se indica el gráfico y el tramaño del mismo.
 * 
 * @param data Vector del gráfico curses art.
 * @param w Ancho del gráfico.
 * @param h Alto del gráfico.
 */
Art::Art(std::vector<unsigned int> data, const short w, const short h) :
		Art(data, 0, 0, w, h) {}

/**
 * @brief Constructor de Art donde se indica el gráfico y la transformación del dibujo.
 * 
 * @param data Vector del gráfico curses art.
 * @param x Posición X del componente.
 * @param y Posición Y del componente.
 * @param w Ancho del gráfico.
 * @param h Alto del gráfico.
 */
Art::Art(std::vector<unsigned int> data, const short x, const short y,
	const short w, const short h) : Component(x, y, w, h) {
	this->setData(data, w, h);
}

void Art::setData(std::vector<unsigned int> data, const short w, const short h) {
	this->data = data;
	setW(w); setH(h);
	setMinW(w); setMaxW(w); 
	setMinH(h); setMaxH(h);

	setBGPair(ART_BG_PAIR);
	setBorderPair(ART_BORDER_PAIR);
}

void Art::draw() {

	// Dibuja el rectángulo de fondo
	if (!isBGTransparent()) {
		attron(COLOR_PAIR(getBGPair()));
		drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
		attroff(COLOR_PAIR(getBGPair()));
	}

	// Dibuja el borde
	attron(COLOR_PAIR(getBorderPair()));
	getBorder()->draw();
	attroff(COLOR_PAIR(getBorderPair()));

	unsigned i = 0;
	for (short y = 0; y < getH(); y ++)
		for (short x = 0; x < getW(); x ++) {
				if (data[i]) mvaddch(y + getAbsY(), x + getAbsX(), data[i]);
				i ++;
		}

}

}
