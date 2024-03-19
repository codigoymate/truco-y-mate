#pragma once

#include <tcurses/tcurses.h>

namespace Truco {

class TrucoApp: public TCurses::Application {
public:
	void init() override;
};

}
