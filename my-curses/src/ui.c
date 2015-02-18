/*
 * =====================================================================================
 *
 *       Filename:  ui.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/02/15 12:50:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#include "ui.h"

ui_t *create_ui() {
	ui_t *ui = malloc(sizeof(ui_t));
	
	initscr();
	if (has_colors() == FALSE) {
		endwin();
		printf("Your terminal does not support colours.\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	refresh();

	ui->screen = newwin(LINES - 6, COLS - 1, 1, 1);
	box(ui->screen, 0, 0);
	
	ui->prompt = newwin(4, COLS - 1, LINES - 5, 1);
	box(ui->prompt, 0, 0);
	mvwprintw(ui->prompt, 1, 1, "$> ");

	wrefresh(ui->screen);
	wrefresh(ui->prompt);

	return ui;
}

void destroy_ui(ui_t *ui) {
	delwin(ui->screen);
	delwin(ui->prompt);
	endwin();
	free(ui);
}
