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
#include <entities/deck.h>
#include <utils/utils.h>
#include <utils/random.h>
#include <components/game_frame.h>

namespace truco {

/**
 * @brief Contructor de Player.
 * 
 * @param behavior Comportamiento del jugador.
 */
Player::Player(const unsigned id, std::shared_ptr<Behavior> behavior) : Player(id, behavior, "") {
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
Player::Player(const unsigned id, std::shared_ptr<Behavior> behavior, const std::string name) :
			id{id}, name{name}, behavior{behavior} {
	for (unsigned i = 0; i < 3; i ++) {
		hand[i] = played[i] = nullptr;
	}
}

/**
 * @brief El jugador juega una carta.
 * 
 * @param n El número de carta que tiene en la mano.
 */
void Player::playCard(const unsigned n) {
	for (unsigned i = 0; i < 3; i ++) {
		if (played[i]) continue;
		played[i] = hand[n];
		hand[n] = nullptr;
		behavior->getGameFrame()->setInfoText(name + " juega " + played[i]->str());
		break;
	}
}

/**
 * @brief Realiza la jugada. Depende el comportamiento.
 * 
 */
void Player::play() {
	behavior->play();
}

} // namespace truco
