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
	short x1 = comp->getAbsX() - pos;
	short y1 = comp->getAbsY() - pos;
	short x2 = comp->getAbsX() + comp->getW() - 1 + pos;
	short y2 = comp->getAbsY() + comp->getH() - 1 + pos;

	mvhline(y1, x1, ACS_HLINE, comp->getW() + pos);
	mvhline(y2, x1, ACS_HLINE, comp->getW() + pos);
	mvvline(y1, x1, ACS_VLINE, comp->getH() + pos);
	mvvline(y1, x2, ACS_VLINE, comp->getH() + pos);

	mvaddch(y1, x1, ACS_ULCORNER);
	mvaddch(y2, x1, ACS_LLCORNER);
	mvaddch(y1, x2, ACS_URCORNER);
	mvaddch(y2, x2, ACS_LRCORNER);
}

} 
