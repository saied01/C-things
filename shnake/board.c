#include "board.h"

void draw_board(WINDOW *win)
{
  box(win, 0, 0);

  mvwprintw(win, 0, 2, "shnake");
}

void update_score(WINDOW *win, int score)
{
  mvwprintw(win, 0, 20, "Score: %d", score);
}
