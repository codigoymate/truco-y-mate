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

#include <turn_manager.h>

namespace truco {

class BigCardComponent;
class Player;

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

private:

	std::vector<std::shared_ptr<Player>> players; /**< La lista de jugadores.*/
	TurnManager turnManager;

	std::shared_ptr<TCurses::Frame> mainFrame; /**< Frame principal (Contiene la mesa, las tres cartas y el menu)*/
	std::shared_ptr<TCurses::Menu> menu; /**< El menú de control del juego.*/
	std::shared_ptr<TCurses::Label> status; /**< La barra de estado.*/

	std::array<std::shared_ptr<BigCardComponent>, 3> hand; /**< Las tres cartas de la mano.*/

	/**
	 * @brief Actualiza los componentes con la lógica de la partida.
	 * 
	 */
	void update();

	/**
	 * @brief Al elegir salir en el menú.
	 * 
	 */
	void quitItemAction();
};

} // namespace truco
