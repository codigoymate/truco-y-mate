#include <tcurses/label.h>

#include <ncurses.h>

#include <tcurses/colors.h>

namespace TCurses {

/**
 * @brief Constructor predeterminado de Label::Label.
 * 
 */
Label::Label() : Component() {}

/**
 * @brief Constructor de Label::Label que establece la posición inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
Label::Label(const short x, const short y) : Component(x, y) {}

/**
 * @brief Constructor de Label::Label que establece la posición y el tamaño inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
Label::Label(const short x, const short y, const short w, const short h) : Component(x, y, w, h) {}

/**
 * @brief Constructor de Label::Label que establece el texto inicial.
 * @param text El texto inicial del Label::Label.
 */
Label::Label(const std::string text) : Component(), text(text) {}

/**
 * @brief Constructor de Label::Label que establece el texto inicial y la posición.
 * @param text El texto inicial del Label::Label.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
Label::Label(const std::string text, const short x, const short y)
		: Component(x, y), text(text) {}

/**
 * @brief Constructor de Label::Label que establece el texto inicial, la posición y el tamaño.
 * @param text El texto inicial del Label::Label.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
Label::Label(const std::string text, const short x, const short y,
	const short w, const short h) : Component(x, y, w, h), text(text) {}

/**
 * @brief Dibuja el Label.
 * 
 */
void Label::draw() const {
	// TODO: Mover funciones a otro módulo

	// Dibuja el rectángulo. TODO: mejorar
	attron(COLOR_PAIR(LABEL_BG_PAIR));
	for (short j = getAbsY(); j < (getAbsY() + getH()); j ++) {
		for (short i = getAbsX(); i < (getAbsX() + getW()); i ++) {
			mvaddch(j, i, ' ');
		}
	}
	attroff(COLOR_PAIR(LABEL_BG_PAIR));

	// Dibuja el texto (provisorio)
	attron(COLOR_PAIR(LABEL_TEXT_PAIR));
	for (int c = 0; c < text.length(); c ++) {
		if (c > getW()) break;
		mvaddch(getAbsY(), getAbsX() + c, text[c]);
	}
	attroff(COLOR_PAIR(LABEL_TEXT_PAIR));

}

}
