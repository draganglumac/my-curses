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

void show_prompt(ui_t *ui) {
	wmove(ui->prompt, 1, 1);
	wclear(ui->prompt);
	mvwprintw(ui->prompt, 1, 1, "$> ");
	wrefresh(ui->prompt);
}
ui_t *create_ui() {
	ui_t *ui = malloc(sizeof(ui_t));
	
	initscr();
	if (has_colors() == FALSE) {
		endwin();
		printf("Your terminal does not support colours.\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	ui->screen = newwin(LINES - 6, COLS - 1, 1, 1);
	box(ui->screen, 0, 0);
	ui->next_line = 1;
	wrefresh(ui->screen);
	
	ui->prompt = newwin(4, COLS - 1, LINES - 5, 1);
	show_prompt(ui);

	return ui;
}
void destroy_ui(ui_t *ui) {
	delwin(ui->screen);
	delwin(ui->prompt);
	endwin();
	free(ui);
}
char *get_message(ui_t *ui) {
	char *msg = malloc(1024);
	wmove(ui->prompt, 1, 4);
	wgetstr(ui->prompt, msg);
	show_prompt(ui);
	return msg;
}
void update_next_line(ui_t *ui) {
	ui->next_line++;
}
void display_message(ui_t *ui, char *msg) {
	attron(COLOR_PAIR(1));
	mvwprintw(ui->screen, ui->next_line, 1, "%s\n", msg);
	update_next_line(ui);
	box(ui->screen, 0, 0);
	wrefresh(ui->screen);
	attroff(COLOR_PAIR(1));
	free(msg);
}
