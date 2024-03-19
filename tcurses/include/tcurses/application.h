#pragma once

#include <memory>

namespace TCurses {

class Screen;

class Application {
public:
	Application();
	virtual ~Application() = default;

	virtual void init() = 0;

	void run();

private:

	std::shared_ptr<Screen> screen;

	void initColors();
};

}
