/**
 * @file border.cpp
 * @author Javier Candales (codigo.mate.9@gmail.com)
 * @brief 
 * @date 2024-03-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <tcurses/border.h>
#include <tcurses/component.h>

#include <ncurses.h>

namespace TCurses {

void LinedBorder::draw() const {
	short x1 = comp->getAbsX();
	short y1 = comp->getAbsY();
	short x2 = comp->getAbsX() + comp->getW() - 1;
	short y2 = comp->getAbsY() + comp->getH() - 1;

	mvhline(y1, x1, ACS_HLINE, comp->getW());
	mvhline(y2, x1, ACS_HLINE, comp->getW());
	mvvline(y1, x1, ACS_VLINE, comp->getH());
	mvvline(y1, x2, ACS_VLINE, comp->getH());

	mvaddch(y1, x1, ACS_ULCORNER);
	mvaddch(y2, x1, ACS_LLCORNER);
	mvaddch(y1, x2, ACS_URCORNER);
	mvaddch(y2, x2, ACS_LRCORNER);
}

} 
