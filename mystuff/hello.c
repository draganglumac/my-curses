/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/02/15 13:45:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <ncurses.h>

void clear_line() {
	int x, y;
	getyx(stdscr, x, y);
	move(x, 0);
	clrtoeol();
}

int main() {
	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("Type any character to see it in bold\n");
	ch = getch();

	while (TRUE) {
		clear_line();
		if (ch == KEY_F(1)) {
			printw("F1 key pressed.");
			refresh();
			break;
		}
		else {
			printw("The pressed key is ");
			attron(A_BOLD);
			printw("%c", ch);
			attroff(A_BOLD);
		}
		refresh();
		ch = getch();
	}
	endwin();

	return 0;
}
