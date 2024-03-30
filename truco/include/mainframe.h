#pragma once

#include <tcurses/tcurses.h>

namespace truco {

class MainFrame: public TCurses::Frame {
public:
	MainFrame();

	void init() override;

private:
	std::shared_ptr<TCurses::Menu> mainMenu;
	void quitAction();
};

}
