#ifndef BOARD_H
#define BOARD_H

#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

void draw_board(WINDOW *);
void update_score(WINDOW *, int);

#endif
