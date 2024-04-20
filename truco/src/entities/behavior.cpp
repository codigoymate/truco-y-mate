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

} // namespace truco
