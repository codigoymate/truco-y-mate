/**
 * @file card_component.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de BigCardComponent.
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <big_card_component.h>
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
BigCardComponent::BigCardComponent() : BigCardComponent(nullptr) {}

/**
 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
 * 
 * @param x Coordenada x del componente.
 * @param y Coordenada y del componente.
 */
BigCardComponent::BigCardComponent(const short x, const short y) : BigCardComponent(nullptr, x, y) {}

/**
 * @brief Constructor del componente CardComponent. Con el puntero a la carta a mostrar.
 * 
 * @param card Puntero a la carta.
 */
BigCardComponent::BigCardComponent(Card *card) : BigCardComponent(card, 0, 0) {}

/**
 * @brief Constructor del componente CardComponent. Con las coordenadas del componente.
 * Y el puntero a la carta a mostrar.
 * 
 * @param card Puntero a la carta.
 * @param x Coordenada x del componente.
 * @param y Coordenada y del componente.
 */
BigCardComponent::BigCardComponent(Card *card, const short x, const short y) :
					Component(x, y, 10, 6), card(card) {
	setMaxW(10); setMinW(10);
	setMaxH(6); setMinH(6);

	if (card->getValue()) {
		art = std::make_shared<TCurses::Art>();
		this->addChild(art);

		// Label valor
		value = std::make_shared<TCurses::Label>(std::to_string(card->getValue()), 1, 1, 2, 1);
		this->addChild(value);
		value->setBGTransparent(true);
		value->setTextPair(CARD_PAIR);

		// Label palo
		type = std::make_shared<TCurses::Label>(1, 2, 1, 1);
		this->addChild(type);
		type->setBGTransparent(true);

		switch (card->getType()) {
		case Card::ORO:
			art->setData({
0x50396C, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396B, 0x503978, 0x103920, 0x103920, 0x101920, 0x401A78, 0x401A78, 
0x101920, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 0x401A71, 0x1A20, 0x401A60, 0x401A60, 0x1A20, 0x401A71, 0x103920, 0x503978, 0x503978, 0x103920, 
0x401A71, 0x1A20, 0x401A60, 0x401A60, 0x1A20, 0x401A71, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x101920, 0x401A78, 0x401A78, 0x101920, 0x103920, 
0x103920, 0x503978, 0x50396D, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396A}, 10, 6);
			type->setTextPair(CARD_ORO_PAIR);
			type->setAttributes(A_ALTCHARSET);
			type->setText("`");
			break;

		case Card::COPAS:
			art->setData({
0x50396C, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396B, 0x503978, 0x103920, 0x20235C, 0x20236F, 0x20236F, 0x20236F, 
0x20236F, 0x20232F, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x20235C, 0x20236F, 0x20236F, 0x20232F, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 
0x103920, 0x103920, 0x602678, 0x602678, 0x103920, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x602671, 0x602676, 0x602676, 0x602671, 0x103920, 
0x103920, 0x503978, 0x50396D, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396A}, 10, 6);
			type->setTextPair(CARD_COPAS_PAIR);
			type->setText("C");
			break;

		case Card::ESPADAS:
			art->setData({
0x50396C, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396B, 0x503978, 0x103920, 0x103920, 0x103920, 0x103920, 0x503B6D, 
0x102920, 0x503B6B, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x103920, 0x103920, 0x20372F, 0x20372F, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 
0x103920, 0x103920, 0x20372F, 0x20372F, 0x103920, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x20372F, 0x20372F, 0x103920, 0x103920, 0x103920, 
0x103920, 0x503978, 0x50396D, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396A}, 10, 6);
			type->setTextPair(CARD_ESPADAS_PAIR);
			type->setText("E");
			break;

		case Card::BASTOS:
			art->setData({
0x50396C, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396B, 0x503978, 0x103920, 0x103920, 0x103920, 0x103920, 0x1820, 
0x1820, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x503B6D, 0x1820, 0x101340, 0x103920, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 
0x103920, 0x103B20, 0x101120, 0x503B6B, 0x103920, 0x103920, 0x103920, 0x503978, 0x503978, 0x103920, 0x103920, 0x103920, 0x400361, 0x103920, 0x103920, 0x103920, 
0x103920, 0x503978, 0x50396D, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x503971, 0x50396A}, 10, 6);
			type->setTextPair(CARD_BASTOS_PAIR);
			type->setText("B");
			break;
		}
	}
}

/**
 * @brief Inicializa el CardComponent.
 * 
 */
void BigCardComponent::init() {
	
}

/**
 * @brief Dibuja el CardComponent.
 * 
 */
void BigCardComponent::draw() {

	if (!card) return; // No dibuja la carta

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

	switch (card->getType()) {
	case Card::ORO:
		attron(COLOR_PAIR(CARD_ORO_PAIR) | A_ALTCHARSET);
		mvaddch(getAbsY() + 2, getAbsX() + 1, ACS_DIAMOND);
		attroff(COLOR_PAIR(CARD_ORO_PAIR) | A_ALTCHARSET);
		break;
	case Card::COPAS:
		attron(COLOR_PAIR(CARD_COPAS_PAIR));
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'C');
		attroff(COLOR_PAIR(CARD_COPAS_PAIR));
		break;
	case Card::ESPADAS:
		attron(COLOR_PAIR(CARD_ESPADAS_PAIR));
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'E');
		attroff(COLOR_PAIR(CARD_ESPADAS_PAIR));
		break;
	case Card::BASTOS:
		attron(COLOR_PAIR(CARD_BASTOS_PAIR));
		mvaddch(getAbsY() + 2, getAbsX() + 1, 'B');
		attroff(COLOR_PAIR(CARD_BASTOS_PAIR));
		break;
	}

	attron(COLOR_PAIR(CARD_PAIR));
	mvprintw(getAbsY() + 1, getAbsX() + 1, "%i", card->getValue());
	attroff(COLOR_PAIR(CARD_PAIR));
}

} // namespace truco
