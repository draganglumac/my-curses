/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/02/15 12:41:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "ui.h"

int main(int argc, char **argv) {
	ui_t *ui = create_ui();
	while (TRUE) {	
		char *msg = get_message(ui);
		if (strcmp(msg, ":q") == 0) {
			break;
		}
		else if (strncmp(msg, "r/", 2) == 0) {
			display_remote_message(ui, msg);
		}
		else {
			display_local_message(ui, msg);
		}
	}
	destroy_ui(ui);
	return 0;
}
