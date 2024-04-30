/**
 * @file score_frame.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Componente Score para mostrar el puntaje en el frame principal. 
 * @date 2024-04-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/frame.h>
#include <tcurses/label.h>

#include <array>

namespace truco {

class GameFrame;

/**
 * @brief Componente ScoreFrame. Muestra el puntaje de los equipos.
 * De 0 a 30 o de 0 a 15.
 * 
 */
class ScoreFrame : public TCurses::Frame {
public:
	/**
	 * @brief Constructor de ScoreFrame.
	 * 
	 * @param gameFrame referencia a GameFrame.
	 */
	ScoreFrame(GameFrame *gameFrame) : gameFrame{gameFrame} {}

	/**
	 * @brief Al iniciar el componente.
	 * 
	 */
	void init() override;

	/**
	 * @brief Agrega puntos a al total indicando el equipo.
	 * 
	 * @param team Equipo a agregar puntos.
	 * @param score Puntos a agregar.
	 */
	void setScore(const unsigned team, const unsigned score);

	/**
	 * @brief Devuelve el total de puntos de un equipo.
	 * 
	 * @param team Equipo objetivo.
	 * @return unsigned Total de puntos del equipo.
	 */
	unsigned getScore(const unsigned team) const;

private:
	GameFrame *gameFrame; /**< Referencia a GameFrame.*/
	std::array<unsigned, 2> score{}; /**<El puntaje de los equipos.*/
	std::array<std::shared_ptr<TCurses::Label>, 2> scoreLabel; /**< Los labels del puntaje*/
};

} // namespace truco
