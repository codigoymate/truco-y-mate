/**
 * @file player_frame.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de player_frame.h
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <components/player_frame.h>

#include <tcurses/label.h>
#include <components/card_component.h>

namespace truco {

/**
 * @brief Constructor de PlayerFrame.
 * 
 * @param playerName nombre del jugador.
 */
PlayerFrame::PlayerFrame(const std::string playerName) : Frame() {
	this->setLayout(TCurses::LY_VERTICAL);
	auto label = std::make_shared<TCurses::Label>(playerName);
	label->setMaxH(1);
	this->addChild(label);
	label->setHTextAlign(TCurses::HA_CENTER);

	auto frame = std::make_shared<Frame>();
	frame->setLayout(TCurses::LY_HORIZONTAL);
	this->addChild(frame);
	for (unsigned i = 0; i < 3; i ++) {
		cards[i] = std::make_shared<CardComponent>();
		frame->addChild(cards[i]);
	}

	setMaxW(18); setMinW(18);
	setMaxH(5); setMinH(5);
}

/**
 * @brief Establece la carta dado el índice.
 * 
 * @param i índice de la carta.
 * @param card puntero a la carta.
 */
void PlayerFrame::setCard(unsigned i, Card *card) {
	cards[i]->setCard(card);
}

};
