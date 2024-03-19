#pragma once

namespace TCurses {

class Application {
public:
	Application();
	virtual ~Application();

	void run();

private:
	void initColors();
};

}
