/**
 * @file frame.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de frame.h
 * @date 2024-03-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tcurses/frame.h>
#include <tcurses/utilities.h>
#include <tcurses/border.h>
#include <tcurses/colors.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Constructor predeterminado de Frame.
 */
Frame::Frame() : Component(0, 0) {}

/**
 * @brief Constructor de Frame que establece la posición inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
Frame::Frame(const short x, const short y) : Frame(x, y, 15, 5) {}

/**
 * @brief Constructor de Frame que establece la posición y el tamaño inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del frame.
 * @param h La altura inicial del frame.
 */
Frame::Frame(const short x, const short y, const short w, const short h)
					 : Component(x, y, w, h) {
	setBGPair(FRAME_BG_PAIR);
	setBorderPair(FRAME_BORDER_PAIR);
}

/**
 * @brief Dibuja el frame.
 * 
 */
void Frame::draw() {
	// Dibuja el rectángulo de fondo
	attron(COLOR_PAIR(getBGPair()));
	drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
	attroff(COLOR_PAIR(getBGPair()));

	// Dibuja el borde
	attron(COLOR_PAIR(getBorderPair()));
	getBorder()->draw();
	attroff(COLOR_PAIR(getBorderPair()));
}

}
