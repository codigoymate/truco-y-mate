#pragma once

#include <tcurses/tcurses.h>

class TestingApplication: public TCurses::Application {
public:
	TestingApplication() = default;

	void init() override;

private:

	std::shared_ptr<TCurses::Frame> testBench;

	unsigned emergentX{}, emergentY{};

	void itemTestTextAlign();
	void itemTestTextWrap();
	void itemTestEmergent();
	void itemQuit();

	void itemEmergentNew();
	void itemEmergentClose();

	void showNewEmergent();
};
