/**
 * @file player.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de la clase Player definida en player.h.
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <player.h>

namespace truco {

/**
 * @brief Construye un nuevo objeto Player.
 */
Player::Player() : Player("") {}

/**
 * @brief Construye un nuevo objeto Player con el nombre dado.
 * 
 * @param name El nombre del jugador.
 */
Player::Player(const std::string name) : name{name} {
	for (unsigned i = 0; i < 3; i ++) {
		hand[i] = played[i] = nullptr;
	}
}

} // namespace truco
