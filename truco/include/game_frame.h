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

namespace truco {

/**
 * @brief Frame del juego. Una partida ya está iniciada con éste frame.
 * 
 */
class GameFrame: public TCurses::Frame {
public:
	/**
	 * @brief Constructor de GameFrame.
	 */
	GameFrame();

	/**
	 * @brief Al iniciar el frame.
	 */
	void init() override;

private:
	std::shared_ptr<TCurses::Frame> mainFrame;
	std::shared_ptr<TCurses::Label> status;
};

} // namespace truco
