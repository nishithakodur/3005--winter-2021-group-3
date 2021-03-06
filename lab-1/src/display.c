/*
 * display.c
 *
 *  Created on: Feb. 15, 2021
 *      Author: nishitha
 */


#include <unistd.h>
#include <ncurses.h>
#include "../inc/display.h"
#include "../inc/gol_config.h"

/*
 * important variables, defined elsewhere
 */
extern cell_t env[config_NE][config_ME];
extern int STARTX;
extern int STARTY;
extern int ENDX;
extern int ENDY;
extern WINDOW *win;

/*
 * PRIVATE FUNCTIONS
 */
void create_newwin(int height, int width)
{
	win = newwin(height, width, STARTY, STARTX);
	box(win, 0, 0); /* Here 0,0 gives default characters
	 * for the vertical and horizontal lines */
	wrefresh(win); /* shows the box */

	return;
}

/*
 * PUBLIC FUNCTIONS
 */
void initDisplay(void)
{
	printf("\ninitializing display...\n");
	usleep(2 * config_TL);
	initscr();
	cbreak();
	timeout(TIME_OUT);
	keypad(stdscr, TRUE);
	create_newwin(config_NE, config_ME);
}

void updateDisplay(void)
{
//	ENDX = COLS - 1;
//	ENDY = LINES - 1;

	int i, j;
	wclear(win);
	for (i = STARTX; i != config_ME; ++i)
		for (j = STARTY; j != config_NE; ++j)
			if (env[j][i] == live)
				mvwaddch(win, j, i, CELL_CHAR);
	wrefresh(win);
}

/*
 ******************************************************************************************** reference
 */
