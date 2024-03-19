#pragma once

#include <memory>

namespace TCurses {

class Screen;

class Application {
public:
	Application();
	virtual ~Application() = default;

	void run();

private:

	std::shared_ptr<Screen> screen;

	void initColors();
};

}
