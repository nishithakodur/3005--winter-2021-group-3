/*
 * cells.h
 *
 *  Created on: Feb. 15, 2021
 *      Author: nishitha
 */

#ifndef CELLS_H_
#define CELLS_H_
#include "gol_config.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
 * functions
 */
void initEnvironment(void);

void copyEnvironment(void);

void* updateCommFunc(void*);


#endif /* CELLS_H_ */
