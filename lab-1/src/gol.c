/*
 * gol.c
 *
 *  Created on: Feb. 15, 2021
 *      Author: nishitha
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <ncurses.h>
#include "../inc/gol_config.h"
#include "../inc/cells.h"
#include "../inc/display.h"

/*
 * global variables
 */
cell_t env[config_NE][config_ME];
cell_t update_env[config_NE][config_ME];
bool reproduction_flag = false;

int STARTX = 0;
int STARTY = 0;
int ENDX = config_ME;
int ENDY = config_NE;
WINDOW *win;
/*
 * main code
 */
int main(void)
{
	pthread_t threadptrs[config_K * config_L]; // thread handles
	threadID_t threadID[config_K * config_L]; 

	// initialize workspace
	initEnvironment();

	// create the threads
	printf("\ncreating threads...\n");
	size_t index;
	for (size_t i = 0; i != config_K; ++i)
	{
		for (size_t j = 0; j != config_L; ++j)
		{
			index = i * config_L + j; // mapping (i,j) to  index
			threadID[index].row = i;
			threadID[index].col = j;
			// On successful creation of thread the below if function returns 0
			if (pthread_create(&threadptrs[index], NULL, &updateCommFunc,
					&threadID[index]) != 0)
			{
				printf("failed to create the thread %d\n", (int) index);
				return 1;
			}
		}
	}

	// Initializing display
	initDisplay();

	unsigned short int ctr = 0;
	while (1)
	{
		reproduction_flag = true;
		usleep(config_TL / 2); 
		reproduction_flag = false;
		usleep(config_TL / 2);
		if (++ctr == config_TDISP)
		{
			ctr = 0;
			updateDisplay();
		}
		copyEnvironment(); // writes changes to the environment and env from update_env
	}


	return 1;
}
