#include <truco.h>

#include <ncurses.h>


int main(int argc, char *argv[]) {

	initscr();
	start_color();

	getch();

	endwin();

	return 0;
}
