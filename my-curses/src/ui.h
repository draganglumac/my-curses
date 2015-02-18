/*
 * =====================================================================================
 *
 *       Filename:  ui.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/02/15 12:52:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __UI_H__
#define __UI_H__

#include <ncurses.h>

typedef struct {
	WINDOW *prompt;
	WINDOW *screen;	
} ui_t;

ui_t *create_ui();
void destroy_ui(ui_t *ui);

#endif // __UI_H__
