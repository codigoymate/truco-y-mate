#include <tcurses/application.h>

#include <clocale>
#include <ncurses.h>

#include <tcurses/screen.h>

namespace TCurses {

Application::Application() {
	setlocale(LC_ALL, "");

	screen = std::make_shared<Screen>();

	initColors();

}

void Application::run() {
	int ch = 0;

	while (ch != 27) {
		ch = getch();
	}
}

void Application::initColors() {
	int bg, fg, p = 1;

    /* Init color pairs */
    for (bg = 0; bg < 8; bg ++) {
        for (fg = 0; fg < 8; fg ++) {
            init_pair(p, fg, bg); p ++;
        }
    }

}

}
