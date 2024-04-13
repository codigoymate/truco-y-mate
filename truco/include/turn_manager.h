/**
 * @file turn_manager.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Declaracion de la clase TurnManager.
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

namespace truco {

class GameFrame;

/**
 * @brief Asigna el turno para cada ronda del partido.
 * 
 */
class TurnManager {
public:

	/**
	 * @brief Constructor de GameFrame por defecto.
	 * 
	 */
	TurnManager() = default;

	/**
	 * @brief Constructor de TurnManager.
	 * 
	 * @param truco Referencia a GameFrame.
	 */
	TurnManager(GameFrame *gameFrame);

private:
	GameFrame *gameFrame; /**< Referencia a GameFrame. */
};

} // namespace truco
