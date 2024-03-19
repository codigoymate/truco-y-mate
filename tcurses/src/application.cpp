#include <tcurses/application.h>

#include <clocale>
#include <ncurses.h>

namespace TCurses {

Application::Application() {
	setlocale(LC_ALL, "");

    initscr();
    noecho();
    curs_set(0);
    
    start_color();
    initColors();

    keypad(stdscr, TRUE);

    set_escdelay(0);
}

Application::~Application() {
	endwin();
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
