/**
 * @file end_round_dialog.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief Implementación de end_round_dialog.h
 * @version 0.1
 * @date 2024-05-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <dialogs/end_round_dialog.h>

#include <components/game_frame.h>
#include <components/score_frame.h>
#include <entities/step_manager.h>
#include <entities/player.h>
#include <tcurses/tcurses.h>

namespace truco {

/**
 * @brief Constructor de EndRoundDialog.
 * 
 * @param gameFrame Referencia a GameFrame.
 * @param winner El indice del equipo ganador de la ronda.
 */
EndRoundDialog::EndRoundDialog(GameFrame *gameFrame, const unsigned winner) : Emergent(40, 15),
			gameFrame{gameFrame}, winner{winner} {}

/**
 * @brief Al iniciar el diálogo.
 * 
 */
void EndRoundDialog::init() {
	this->setLayout(TCurses::Component::LY_VERTICAL);

	// Envia el menu abajo
	//this->addChild(std::make_shared<TCurses::Frame>());

	auto frame = std::make_shared<TCurses::Frame>();
	frame->setLayout(TCurses::Component::LY_HORIZONTAL);
	this->addChild(frame);

	
	// Agrega el label de información.
	std::string labelText = "";
	if (gameFrame->getPlayers().size() == 2) {
		labelText = gameFrame->getPlayers()[winner]->getName() + " gana ";
	} else {
		auto wins = (winner == 1 ? " ganan " : " ganamos ");
		labelText = gameFrame->getTeamName(winner) + wins;
	}

	labelText += "la ronda anotando X puntos.";

	auto label = std::make_shared<TCurses::Label>(labelText);
	label->setWrap(TCurses::Label::WRAP_WORD);
	frame->addChild(label);

	// Menu "Continuar"
	auto menu = std::make_shared<TCurses::Menu>();
	menu->setMaxW(11); menu->setMaxH(1);
	menu->setHAlign(TCurses::Component::HA_CENTER);
	this->addChild(menu);

	auto okItem = std::make_shared<TCurses::MenuItem>("Continuar",
			std::bind(&EndRoundDialog::okItemAction, this));
	menu->addChild(okItem);
}

/**
 * @brief Al seleccionar la opción "Continuar".
 * 
 */
void EndRoundDialog::okItemAction() {
	// Destruye el dialogo
	application->disposeEmergent();

	gameFrame->getStepManager()->nextRound();
}
	
} // namespace truco
