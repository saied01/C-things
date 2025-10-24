#include "input.h"

void handle_input(WINDOW *win, Snake *snake)
{
  int ch = wgetch(win);
  switch (ch)
  {
  case KEY_UP:
    if (snake->dy != 1)
    {
      snake->dx = 0;
      snake->dy = -1;
    }
    break;
  case KEY_DOWN:
    if (snake->dy != -1)
    {
      snake->dx = 0;
      snake->dy = 1;
    }
    break;
  case KEY_LEFT:
    if (snake->dx != -1)
    {
      snake->dy = 0;
      snake->dx = -1;
    }
    break;
  case KEY_RIGHT:
    if (snake->dx != 1)
    {
      snake->dy = 0;
      snake->dx = 1;
    }
    break;

  case 'q':
    printf("\033[?1003l\n");
    endwin();
    exit(0);
  }
}
