/**
 * @file gameframe.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Frame del juego. Contiene el título, la barra de estado
 * y el frame principal.
 * @date 2024-04-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/tcurses.h>
#include <array>

namespace truco {

class BigCardComponent;
class Player;
class PlayerFrame;
class StepManager;

/**
 * @brief Frame del juego. Una partida ya está iniciada con éste frame.
 * 
 */
class GameFrame: public TCurses::Frame {
public:
	/**
	 * @brief Constructor de GameFrame.
	 * 
	 * @param playerCount Cantidad de jugadores para configurar el partido.
	 */
	GameFrame(const unsigned playerCount);

	/**
	 * @brief Al iniciar el frame.
	 */
	void init() override;

	/**
	 * @brief Actualiza la lógica del GameFrame.
	 * 
	 */
	void update() override;

	/**
	 * @brief Devuelve una referencia a la lista de jugadores.
	 */
	std::vector<std::shared_ptr<Player>> &getPlayers() { return players; }

	/**
	 * @brief Actualiza los componentes con la lógica de la partida.
	 * 
	 */
	void updateComponents();

	/**
	 * @brief Devuelve el administrador de turnos.
	 */
	std::shared_ptr<StepManager> getStepManager() { return stepManager; }

	/**
	 * @brief Devuelve el label del próximo jugador ubicado en la barra de estado.
	 */
	std::shared_ptr<TCurses::Label> getCurrentPlayerLabel() const { return currentPlayerLabel; }

private:

	std::vector<std::shared_ptr<Player>> players; /**< La lista de jugadores.*/

	std::shared_ptr<StepManager> stepManager; /**< Administrador de turnos.*/

	std::shared_ptr<TCurses::Frame> mainFrame; /**< Frame principal (Contiene la mesa, las tres cartas y el menu)*/
	std::shared_ptr<TCurses::Menu> menu; /**< El menú de control del juego.*/
	std::shared_ptr<TCurses::MenuItem> trucoMenuItem; /**< Opción Truco.*/
	std::shared_ptr<TCurses::MenuItem> envidoMenuItem; /**< Opción Envido.*/
	std::shared_ptr<TCurses::MenuItem> quitMenuItem; /**< Opción Salir.*/

	// Barra de estado
	std::shared_ptr<TCurses::Label> currentPlayerLabel; /**< Label que indica el jugador actual.*/

	std::array<std::shared_ptr<BigCardComponent>, 3> hand; /**< Las tres cartas de la mano.*/
	std::vector<std::shared_ptr<PlayerFrame>> playerFrames; /**< Frame de los jugadores en la mesa.*/

	/**
	 * @brief Al elegir salir en el menú.
	 * 
	 */
	void quitItemAction();

	/**
	 * @brief Distribuye los jugadores en la mensa.
	 * 
	 * @return std::shared_ptr<Frame> Frame de la mesa con los jugadores distribuidos.
	 */
	std::shared_ptr<TCurses::Frame> layoutTable();

};

} // namespace truco
