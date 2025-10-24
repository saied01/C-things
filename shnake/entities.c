#include "entities.h"
#include "utils.h"
#include <ncurses.h>
#include <stdint.h>

void update_snake(Snake *snake, int xmax, int ymax)
{

  for (int i = snake->length - 1; i > 0; --i)
  {
    snake->body[i] = snake->body[i - 1];
  }

  snake->body[0].x += snake->dx;
  snake->body[0].y += snake->dy;
}

void draw_snake(WINDOW *win, Snake *snake)
{

  mvwaddstr(win, snake->body[0].y, snake->body[0].x, "O");

  for (int i = 1; i < snake->length; ++i)
  {
    mvwaddstr(win, snake->body[i].y, snake->body[i].x, "o");
  }
}

void draw_food(WINDOW *win, Food *food)
{
  mvwaddstr(win, food->y, food->x, "*");
}

int update_food(Food *food, Snake *snake, int xmax, int ymax, int score)
{
  if (snake->body[0].x == food->x && snake->body[0].y == food->y)
  {
    snake->length++;
    score += 10;
    food->x = rand() % (xmax / 2 - 2) + 1;
    food->y = rand() % (ymax / 2 - 2) + 1;
  }
  return score;
}
