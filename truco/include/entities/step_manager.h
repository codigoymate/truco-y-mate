/**
 * @file step_manager.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Módulo encargado de administrar los turnos de los jugadores.
 * @version 0.1
 * @date 2024-04-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <memory>

namespace truco {

class GameFrame;
class Player;

/**
 * @brief Se encarga de administrar los turnos de los jugadores.
 * 
 */
class StepManager {
public:
	/**
	 * @brief Constructor de step manager.
	 *  
	 * @param gameFrame El frame de la partida actual.
	 */
	StepManager(GameFrame *gameFrame);

	/**
	 * @brief "Próximo paso": llama al siguente jugador para realizar la jugada.
	 * 
	 */
	void step();

	/**
	 * @brief Determina el próximo turno.
	 * 
	 */
	void nextPlayer();

	/**
	 * @brief Inicia la siguiente ronda.
	 * 
	 */
	void nextRound();

	/**
	 * @brief Finaliza una ronda indicando el ganador.
	 * 
	 * @param winnner El ganador de la ronda.
	 */
	void endRound(unsigned winnner);

	/**
	 * @brief Devuelve el jugador actual.
	 */
	std::shared_ptr<Player> currentPlayer();

private:
	GameFrame *gameFrame; /**< Referencia a GameFrame.*/

	signed currentPlayerIndex;	/**< Indice del turno actual. */
	signed startPlayer; /**< Indice del jugador mano. */
	unsigned round{}; /**< Conteo de rondas. */
	unsigned handIndex{}; /**< Mano actual. */

	/**
	 * @brief Verifica si no se jugó una carta en la mano indicada.
	 * 
	 * @param n el número de mano.
	 * @return true si no se jugó alguna carta.
	 */
	bool isHandClear(const unsigned n);

	/**
	 * @brief Verifica si se jugaron todas las cartas en la mano indicada.
	 * 
	 * @param n el número de mano.
	 * @return true si se jugaron todas las cartas
	 */
	bool isHandFull(const unsigned n);

	/**
	 * @brief Próximo jugador cuando no hay cartas en la mano.
	 * 
	 */
	void nextPlayerHandClear();

	/**
	 * @brief Próximo jugador cuando todos jugaron una carta en la mano.
	 * 
	 */
	void nextPlayerHandFull();

	/**
	 * @brief Busca el ganador de la mano n.
	 * Si se empata la mano (parda), devuelve -1.
	 * 
	 * @param n Número de mano.
	 * @return const signed Índice del jugador ganador o -1 si hay empate.
	 */
	const signed getHandWinner(const unsigned n) const;

	/**
	 * @brief Incrementa el índice de jugador. Cuando se alcanza el máximo, 
	 * arranca de 0.
	 * 
	 */
	void incrementPlayerIndex();
};

} // namespace truco
