/**
 * @file menuitem.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief  Implementación de MenuItem.
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <tcurses/menuitem.h>
#include <tcurses/colors.h>
#include <tcurses/utilities.h>
#include <tcurses/border.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Constructor predeterminado de MenuItem.
 * 
 */
MenuItem::MenuItem() : MenuItem("") {}

/**
 * @brief Constructor de MenuItem que establece la posición inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
MenuItem::MenuItem(const short x, const short y) : MenuItem("", x, y) {}

/**
 * @brief Constructor de MenuItem que establece la posición y el tamaño inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
MenuItem::MenuItem(const short x, const short y, const short w, const short h) :
			MenuItem("", x, y, w, h) {}

/**
 * @brief Constructor de MenuItem que establece el texto inicial.
 * @param text El texto inicial del MenuItem::MenuItem.
 */
MenuItem::MenuItem(const std::string text) : MenuItem(text, 0, 0) {}

/**
 * @brief Constructor de MenuItem que establece el texto inicial y la posición.
 * @param text El texto inicial del MenuItem.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
MenuItem::MenuItem(const std::string text, const short x, const short y)
		: MenuItem(text, x, y, 20, 1) {}

/**
 * @brief Constructor de MenuItem que establece el texto inicial, la posición y el tamaño.
 * @param text El texto inicial del MenuItem.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del componente.
 * @param h La altura inicial del componente.
 */
MenuItem::MenuItem(const std::string text, const short x, const short y,
	const short w, const short h) : Label(text, x, y, w, h) {
	setBGPair(MENUITEM_BG_PAIR);
	setBorderPair(MENUITEM_BORDER_PAIR);
	setTextPair(MENUITEM_TEXT_PAIR);
	setSelBGPair(MENUITEM_SEL_BG_PAIR);
	setSelBorderPair(MENUITEM_SEL_BORDER_PAIR);
	setSelTextPair(MENUITEM_SEL_TEXT_PAIR);

	// Configura el estilo del MenuItem.
	setTextAlign(Component::HA_CENTER, Component::VA_CENTER);
	setHAlign(Component::HA_CENTER);
	setMaxH(1);
}

/**
 * @brief Dibuja el MenuItem.
 * 
 */
void MenuItem::draw() {
	// Dibuja el rectángulo de fondo
	attron(COLOR_PAIR(selected ? getSelBGPair() : getBGPair()));
	drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
	attroff(COLOR_PAIR(selected ? getSelBGPair() : getBGPair()));

	// Dibuja el borde
	attron(COLOR_PAIR(selected ? getSelBorderPair() : getBorderPair()));
	getBorder()->draw();
	attroff(COLOR_PAIR(selected ? getSelBorderPair() : getBorderPair()));

	// Dibuja el texto
	attron(COLOR_PAIR(selected ? getSelTextPair() : getTextPair()));
	drawTextArea(text, getAbsX(), getAbsY(), getAbsX() + getW(), getAbsY() + getH(),
		hTextAlign, vTextAlign);
	attroff(COLOR_PAIR(selected ? getSelTextPair() : getTextPair()));
}

}
