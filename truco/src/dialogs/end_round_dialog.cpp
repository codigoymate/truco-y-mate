#include <dialogs/end_round_dialog.h>

#include <components/game_frame.h>
#include <entities/step_manager.h>
#include <tcurses/tcurses.h>

namespace truco {

EndRoundDialog::EndRoundDialog(GameFrame *gameFrame) : Emergent(40, 15),
			gameFrame{gameFrame} {}

void EndRoundDialog::init() {
	this->setLayout(TCurses::Component::LY_VERTICAL);

	// Envia el menu abajo
	this->addChild(std::make_shared<TCurses::Frame>());

	auto menu = std::make_shared<TCurses::Menu>();
	menu->setMaxW(10); menu->setMaxH(1);
	this->addChild(menu);

	auto okItem = std::make_shared<TCurses::MenuItem>("Continuar",
			std::bind(&EndRoundDialog::okItemAction, this));
	menu->addChild(okItem);
}

void EndRoundDialog::okItemAction() {
	// Destruye el dialogo
	application->disposeEmergent();

	gameFrame->getStepManager()->nextRound();
}
	
} // namespace truco
