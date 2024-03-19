#include <tcurses/screen.h>

#include <ncurses.h>

namespace TCurses {

Screen::Screen() : Component() {
	initscr();
    noecho();
    curs_set(0);
    
    start_color();

    keypad(stdscr, TRUE);

    set_escdelay(0);

	// Propiedades de la pantalla
	this->setPos(0, 0);
	this->setSize(getmaxx(stdscr), getmaxy(stdscr));
}

Screen::~Screen() {
	endwin();
}

}
