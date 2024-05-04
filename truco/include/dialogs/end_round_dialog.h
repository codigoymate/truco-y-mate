#pragma once

#include <tcurses/emergent.h>

namespace truco {

class GameFrame;

class EndRoundDialog: public TCurses::Emergent {
public:
	EndRoundDialog(GameFrame *gameFrame);

	void init() override;

private:
	GameFrame *gameFrame;

	void okItemAction();
};

};
