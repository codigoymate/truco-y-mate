/**
 * @file end_round_dialog.h
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Diálogo emergente al termina la ronda.
 * @version 0.1
 * @date 2024-05-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <tcurses/emergent.h>

namespace truco {

class GameFrame;

/**
 * @brief Diálogo al finalizar la ronda. Muestra al equipo ganador y la tabla de puntos.
 * 
 */
class EndRoundDialog: public TCurses::Emergent {
public:
	/**
	 * @brief Constructor de EndRoundDialog.
	 * 
	 * @param gameFrame Referencia a GameFrame.
	 * @param winner El indice del equipo ganador de la ronda.
	 */
	EndRoundDialog(GameFrame *gameFrame, const unsigned winner);

	/**
	 * @brief Al iniciar el diálogo.
	 * 
	 */
	void init() override;

private:
	GameFrame *gameFrame; /**< Referencia a GameFrame.*/
	unsigned winner;

	/**
	 * @brief Al seleccionar la opción "Continuar".
	 * 
	 */
	void okItemAction();
};

};
