/**
 * @file menu.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de menu.h
 * @date 2024-03-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <tcurses/menu.h>
#include <tcurses/colors.h>
#include <tcurses/utilities.h>
#include <tcurses/border.h>
#include <tcurses/menuitem.h>

#include <ncurses.h>

namespace TCurses {

/**
 * @brief Constructor predeterminado de Menu.
 */
Menu::Menu() : Menu(0, 0) {}

/**
 * @brief Constructor de Menu que establece la posición inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 */
Menu::Menu(const short x, const short y) :
				Menu(x, y, 25, 10) {}

/**
 * @brief Constructor de Menu que establece la posición y el tamaño inicial.
 * @param x La coordenada x de la posición inicial.
 * @param y La coordenada y de la posición inicial.
 * @param w El ancho inicial del menu.
 * @param h La altura inicial del menu.
 */
Menu::Menu(const short x, const short y, const short w, const short h) :
				Component(x, y, w, h) {
	setBGPair(MENU_BG_PAIR);
	setBorderPair(MENU_BORDER_PAIR);
	setLayout(Component::LY_VERTICAL);
}

/**
 * @brief Dibuja el menu.
 * 
 */
void Menu::draw() {
	// Dibuja el rectángulo de fondo
	attron(COLOR_PAIR(getBGPair()));
	drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
	attroff(COLOR_PAIR(getBGPair()));

	// Dibuja el borde
	attron(COLOR_PAIR(getBorderPair()));
	getBorder()->draw();
	attroff(COLOR_PAIR(getBorderPair()));
}

/**
 * @brief Escucha el teclado.
 * 
 * @param key tecla de entrada.
 */
void Menu::keyPressed(int key) {
	switch (key) {

	case KEY_UP:
		itemIndex --;
		if (itemIndex < 0) itemIndex = getChildren().size() - 1;
		updateItems();
		break;

	case KEY_DOWN:
		itemIndex ++;
		if (itemIndex >= getChildren().size()) itemIndex = 0;
		updateItems();
		break;
	
	// Acción del menú item
	case 10: {
			int i = 0;
			if (!getChildren().empty()) {
				for (auto &c : getChildren()) {
					if (i == itemIndex)
						if (std::dynamic_pointer_cast<MenuItem>(c)) {
							std::dynamic_pointer_cast<MenuItem>(c)->doAction();
						}
					i ++;
				}
			}
		} break;

	}
}

/**
 * @brief Actualiza el estado de los items;
 * 
 */
void Menu::updateItems() {
	unsigned i = 0;
	for (auto &c : getChildren()) {
		if (std::static_pointer_cast<MenuItem>(c)) {
			std::static_pointer_cast<MenuItem>(c)->setSelected(
				i == itemIndex
			);
		}
		i ++;
	}
}

}
