#ifndef ENTITIES_H
#define ENTITIES_H

#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils.h"
#include <stdint.h>

void draw_snake(WINDOW *, Snake *);
void update_snake(Snake *, int, int);
void draw_food(WINDOW *, Food *);
int update_food(Food *, Snake *, int, int, int);

#endif
