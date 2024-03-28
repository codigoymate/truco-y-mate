/**
 * @file label.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de label.h
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <tcurses/label.h>

#include <ncurses.h>

#include <tcurses/colors.h>
#include <tcurses/utilities.h>
#include <tcurses/border.h>

namespace TCurses {

/**
 * @brief Constructor predeterminado de Label::Label.
 * 
 */
Label::Label() : Label("") {}

/**
 * @brief Constructor de Label::Label que establece la posición inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
Label::Label(const short x, const short y) : Label("", x, y) {}

/**
 * @brief Constructor de Label::Label que establece la posición y el tamaño inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
Label::Label(const short x, const short y, const short w, const short h) :
			Label("", x, y, w, h) {}

/**
 * @brief Constructor de Label::Label que establece el texto inicial.
 * @param text El texto inicial del Label::Label.
 */
Label::Label(const std::string text) : Label(text, 0, 0) {}

/**
 * @brief Constructor de Label::Label que establece el texto inicial y la posición.
 * @param text El texto inicial del Label::Label.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
Label::Label(const std::string text, const short x, const short y)
		: Label(text, x, y, 20, 1) {}

/**
 * @brief Constructor de Label::Label que establece el texto inicial, la posición y el tamaño.
 * @param text El texto inicial del Label::Label.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
Label::Label(const std::string text, const short x, const short y,
	const short w, const short h) : Component(x, y, w, h), text(text) {
	setBGPair(LABEL_BG_PAIR);
	setBorderPair(LABEL_BORDER_PAIR);
	setTextPair(LABEL_TEXT_PAIR);
}

/**
 * @brief Dibuja el Label.
 * 
 */
void Label::draw() {

	// Dibuja el rectángulo de fondo
	attron(COLOR_PAIR(getBGPair()));
	drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
	attroff(COLOR_PAIR(getBGPair()));

	// Dibuja el borde
	attron(COLOR_PAIR(getBorderPair()));
	getBorder()->draw();
	attroff(COLOR_PAIR(getBorderPair()));

	// Dibuja el texto
	attron(COLOR_PAIR(textPair));
	drawTextArea(text, getAbsX(), getAbsY(), getAbsX() + getW(), getAbsY() + getH(),
		hTextAlign, vTextAlign);
	attroff(COLOR_PAIR(textPair));

}

}
