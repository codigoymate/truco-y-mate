/**
 * @file player.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de la clase Player definida en player.h.
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <entities/player.h>
#include <entities/behavior.h>
#include <utils/utils.h>
#include <utils/random.h>

namespace truco {

/**
 * @brief Contructor de Player.
 * 
 * @param behavior Comportamiento del jugador.
 */
Player::Player(std::shared_ptr<Behavior> behavior) : Player(behavior, "") {
	she = Random::randInt(0, 1);
	name = she ? randomizeFemaleName() :
			randomizeMaleName();
}

/**
 * @brief Construye un nuevo objeto Player con el nombre dado.
 * 
 * @param behavior Comportamiento del jugador.
 * @param name Nombre del jugador.
 */
Player::Player(std::shared_ptr<Behavior> behavior, const std::string name) :
			name{name}, behavior{behavior} {
	for (unsigned i = 0; i < 3; i ++) {
		hand[i] = played[i] = nullptr;
	}
}

} // namespace truco
