/**
 * @file mainframe.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Frame del menú principal.
 * @date 2024-04-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tcurses/tcurses.h>

namespace truco {

/**
 * @brief Frame del menú principal.
 * 
 */
class MainFrame: public TCurses::Frame {
public:
	/**
	 * @brief Constructor de MainFrame.
	 * 
	 */
	MainFrame();

	/** Al inicializar el componente. */
	void init() override;

private:
	std::shared_ptr<TCurses::Menu> mainMenu; /**< Compunente menú principal.*/
	void quitAction(); /**< Método llamado por la opción "Salir". */
};

} // namespace truco
