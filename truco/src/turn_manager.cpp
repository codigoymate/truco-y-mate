/**
 * @file turn_manager.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementacion de truco.h
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <turn_manager.h>

#include <game_frame.h>

namespace truco {

/**
 * @brief Constructor de TurnManager.
 * 
 * @param truco Referencia a truco.
 */
TurnManager::TurnManager(GameFrame *gameFrame) : gameFrame{gameFrame} {
}

} // namespace truco
