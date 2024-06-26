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
class ScoreFrame;

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
	 * @brief Devuelve el nombre del equipo dependiendo de la cantidad de jugadores
	 * y los géneros.
	 * 
	 * @param team Equipo objetivo.
	 * @return const std::string nombre del equipo.
	 */
	const std::string getTeamName(const unsigned team) const;

	/**
	 * @brief Actualiza los componentes.
	 * 
	 */
	void updateComponents();

	/**
	 * @brief Actualiza el menú.
	 * 
	 */
	void updateMenu();

	/**
	 * @brief Devuelve el administrador de turnos.
	 */
	std::shared_ptr<StepManager> getStepManager() { return stepManager; }

	/**
	 * @brief Devuelve el componente de puntuación
	 * 
	 * @return std::shared_ptr<ScoreFrame> componente de puntuación.
	 */
	std::shared_ptr<ScoreFrame> getScoreFrame() { return scoreFrame; }

	/**
	 * @brief Devuelve el label del próximo jugador ubicado en la barra de estado.
	 */
	std::shared_ptr<TCurses::Label> getCurrentPlayerLabel() const { return currentPlayerLabel; }

	/**
	 * @brief Establece el texto del label de información.
	 * 
	 * @param text Texto de información.
	 */
	void setInfoText(const std::string text);

private:

	std::vector<std::shared_ptr<Player>> players; /**< La lista de jugadores.*/

	std::shared_ptr<StepManager> stepManager; /**< Administrador de turnos.*/

	std::shared_ptr<TCurses::Frame> mainFrame; /**< Frame principal
					(Contiene la mesa, el cuadro de informacion, las tres cartas y el menu)*/
	std::shared_ptr<TCurses::Label> infoLabel; /**< Label de información.*/

	// Frame de puntos
	std::shared_ptr<ScoreFrame> scoreFrame; /**< Componente de puntos*/

	// Menú
	std::shared_ptr<TCurses::Menu> menu; /**< El menú de control del juego.*/
	std::shared_ptr<TCurses::MenuItem> playCardItem[3]; /**< Opciones jugar cartas.*/
	std::shared_ptr<TCurses::MenuItem> trucoMenuItem; /**< Opción Truco.*/
	std::shared_ptr<TCurses::MenuItem> envidoMenuItem; /**< Opción Envido.*/
	std::shared_ptr<TCurses::MenuItem> quitMenuItem; /**< Opción Salir.*/

	// Barra de estado
	std::shared_ptr<TCurses::Label> currentPlayerLabel; /**< Label que indica el jugador actual.*/

	std::array<std::shared_ptr<BigCardComponent>, 3> hand; /**< Las tres cartas de la mano.*/
	std::vector<std::shared_ptr<PlayerFrame>> playerFrames; /**< Frame de los jugadores en la mesa.*/

	/**
	 * @brief Al elegir Carta 1 en el menú.
	 * 
	 */
	void playCard1Action();

	/**
	 * @brief Al elegir Carta 2 en el menú.
	 * 
	 */
	void playCard2Action();

	/**
	 * @brief Al elegir Carta 3 en el menú.
	 * 
	 */
	void playCard3Action();

	/**
	 * @brief Llamado por el menú para jugar una carta.
	 * 
	 * @param c La carta a jugar.
	 */
	void humanPlayCard(const unsigned c);

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
