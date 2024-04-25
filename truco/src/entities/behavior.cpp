/**
 * @file behavior.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de behavior.h
 * @date 2024-04-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <entities/behavior.h>

#include <components/game_frame.h>
#include <entities/player.h>
#include <entities/step_manager.h>

#include <thread>
#include <chrono>

namespace truco {

/**
 * @brief Constructor de Behavior.
 * 
 * @param gameFrame Frame principal.
 */
Behavior::Behavior(GameFrame *gameFrame) : gameFrame{gameFrame} {}

/**
 * @brief Constructor del comportamiento Human.
 * 
 * @param gameFrame Frame principal.
 */
Human::Human(GameFrame *gameFrame) : Behavior(gameFrame) {}

/**
 * @brief Realiza la acción de jugar.
 * 
 */
void Human::play() {

}

/**
 * @brief Constructor del comportamiento IA.
 * 
 * @param gameFrame Frame principal.
 */
IA::IA(GameFrame *gameFrame) : Behavior(gameFrame) {}

/**
 * @brief Realiza la acción de jugar.
 * 
 */
void IA::play() {

	std::this_thread::sleep_for(std::chrono::seconds(2));

	auto player = gameFrame->getStepManager()->currentPlayer();

	// Provisorio: juega una carta de izquierda a derecha.
	for (unsigned i = 0; i < 3; i ++) {
		if (!player->getHand(i)) continue;
		player->playCard(i);
		break;
	}

	// Componentes del GameFrame
	gameFrame->update();

	// Redibuja la pantalla
	//gameFrame->getApplication()->getScreen()->drawAll();

	gameFrame->getStepManager()->step();
}

} // namespace truco
