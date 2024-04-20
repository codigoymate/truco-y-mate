/**
 * @file player_frame.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente que representa a cada jugador puesto en ronda en la mesa.
 * @date 2024-04-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/frame.h>

#include <array>
#include <string>

namespace truco {

class CardComponent;
class Card;

/**
 * @brief Frame que representa uno de los jugadores y contiene las cartas jugadas junto
 * con el nombre y otros datos.
 * 
 */
class PlayerFrame: public TCurses::Frame {
public:

	/**
	 * @brief Constructor de PlayerFrame.
	 * 
	 * @param playerName nombre del jugador.
	 */
	PlayerFrame(const std::string playerName);

	/**
	 * @brief Establece la carta dado el índice.
	 * 
	 * @param i índice de la carta.
	 * @param card puntero a la carta.
	 */
	void setCard(unsigned i, Card *card);

private:
	std::array<std::shared_ptr<CardComponent>, 3> cards; /**< Las tres cartas del jugador.*/
};

} // namespace truco
