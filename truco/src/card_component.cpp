/**
 * @file card_component.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de CardComponent
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <card_component.h>
#include <deck.h>
#include <truco_colors.h>

#include <tcurses/utilities.h>
#include <tcurses/border.h>
#include <ncurses.h>

namespace truco {

/**
 * @brief Constructor por defecto de CardComponent.
 * 
 */
CardComponent::CardComponent() : CardComponent(nullptr) {}

/**
 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
 * 
 * @param x Coordenada x del componente.
 * @param y Coordenada y del componente.
 */
CardComponent::CardComponent(const short x, const short y) : CardComponent(nullptr, x, y) {}

/**
 * @brief Constructor del componente CardComponent. Con el puntero a la carta a mostrar.
 * 
 * @param card Puntero a la carta.
 */
CardComponent::CardComponent(Card *card) : CardComponent(card, 0, 0) {}

/**
 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
 * Y el puntero a la carta a mostrar.
 * 
 * @param card Puntero a la carta.
 * @param x Coordenada x del componente.
 * @param y Coordenada y del componente.
 */
CardComponent::CardComponent(Card *card, const short x, const short y) :
					Component(x, y, 6, 4), card(card) {
	setMaxW(6); setMinW(6);
	setMaxH(4); setMinH(4);
	setBorder(std::make_shared<TCurses::LinedBorder>());
}

/**
 * @brief Establece la carta a mostrar.
 * 
 * @param card Puntero a la carta a mostrar.
 */
void CardComponent::setCard(Card *card) {
	this->card = card;
}

/**
 * @brief Inicializa el CardComponent.
 * 
 */
void CardComponent::init() {

}

/**
 * @brief Dibuja el CardComponent.
 * 
 */
void CardComponent::draw() {

	if (!card) return; // No dibuja la carta si es null.

	// Dibuja el lomo en el caso de se value == 0
	if (!card->getValue()) {
		attron(COLOR_PAIR(CARD_BACK_PAIR) | A_BOLD);
		for (unsigned j = 0; j < getH(); j ++) {
			for (unsigned i = 0; i < getW(); i ++) {
				mvaddch(j + getAbsY(), i + getAbsX(), 'X');
			}
		}
		attroff(COLOR_PAIR(CARD_BACK_PAIR) | A_BOLD);
		return;
	}

	attron(COLOR_PAIR(CARD_PAIR));
	TCurses::drawSolidRect(getAbsX(), getAbsY(), getW(), getH());
	getBorder()->draw();
	mvprintw(getAbsY() + 1, getAbsX() + 1, "%i", card->getValue());
	attroff(COLOR_PAIR(CARD_PAIR));

	switch (card->getType()) {
	case Card::ORO:
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'O' | COLOR_PAIR(CARD_ORO_PAIR));
		mvaddch(getAbsY() + 2, getAbsX() + 3, ACS_DIAMOND | COLOR_PAIR(CARD_ORO_PAIR) | A_ALTCHARSET);
		break;
	case Card::COPAS:
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'C' | COLOR_PAIR(CARD_COPAS_PAIR) | A_DIM);
		mvaddch(getAbsY() + 2, getAbsX() + 3, 'Y' | COLOR_PAIR(CARD_COPAS_PAIR) | A_DIM);
		break;
	case Card::ESPADAS:
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'E' | COLOR_PAIR(CARD_ESPADAS_PAIR));
		mvaddch(getAbsY() + 2, getAbsX() + 3, ACS_PLUS | COLOR_PAIR(CARD_ESPADAS_PAIR) | A_ALTCHARSET);
		break;
	case Card::BASTOS:
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'B' | COLOR_PAIR(CARD_BASTOS_PAIR));
		mvaddch(getAbsY() + 2, getAbsX() + 3, '/' | COLOR_PAIR(CARD_BASTOS_PAIR) | A_BOLD);
		break;
	}
}

} // namespace truco
