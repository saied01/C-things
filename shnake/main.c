#include "board.h"
#include "entities.h"
#include "input.h"
#include "utils.h"
#include <ncurses.h>

WINDOW *win;
int xmax;
int ymax;
int xcenter;
int ycenter;
int win_h, win_w;
int score;

void game_over()
{
  nodelay(win, FALSE);
  int mid_y = win_h / 2;
  int mid_x = win_w / 2 - 7; // centrado aprox.

  mvwprintw(win, mid_y - 2, mid_x - 2, "Final score: %d", score);
  mvwaddstr(win, mid_y - 3, mid_x - 3, "=== Game Over ===");
  mvwaddstr(win, mid_y - 1, mid_x - 10, "Press 'q' to quit or 'r' to retry");
  wrefresh(win);
  while (1)
  {
    int ch = wgetch(win);
    if (ch == 'q')
    {
      endwin();
      exit(0);
    }
    else
    {
      nodelay(win, TRUE);
      break;
    }
  }
}

int main(int argc, char **argv)
{
  // initialize ncurses
  initscr();
  noecho();
  curs_set(0);
  cbreak();

  // draw board on middle of window
  getmaxyx(stdscr, ymax, xmax);

  win = newwin(ymax / 2, xmax / 2, ymax / 4, xmax / 4);

  // no delay for user input and keypad for reading user input
  nodelay(win, TRUE);
  keypad(win, TRUE);

  score = 0;
  box(win, 0, 0);

  // shnake
  mvwprintw(win, 0, 2, "shnake");

  // initialize food
  Food food;
  food.x = rand() % (xmax / 2 - 2) + 1; // dentro del board
  food.y = rand() % (ymax / 2 - 2) + 1;

  // initialize shnake
  Snake snake;
  snake.length = 2;
  xcenter = (xmax / 2) / 2;
  ycenter = (ymax / 2) / 2;

  snake.dx = 1;
  snake.dy = 0;
  for (int i = 0; i < snake.length; i++)
  {
    snake.body[i].x = xcenter - i;
    snake.body[i].y = ycenter;
  }
  getmaxyx(win, win_h, win_w);
  // game loop
  while (1)
  {

    if (snake.body[0].x <= 0 || snake.body[0].x >= win_w - 1 ||
        snake.body[0].y <= 0 || snake.body[0].y >= win_h - 1)
    {
      game_over();
      snake.length = 2;
      snake.dx = 1;
      snake.dy = 0;
      snake.body[0].x = win_w / 2;
      snake.body[0].y = win_h / 2;
      snake.body[1].x = win_w / 2 - 1;
      snake.body[1].y = win_h / 2;

      food.x = rand() % (win_w - 2) + 1;
      food.y = rand() % (win_h - 2) + 1;
    }
    handle_input(win, &snake);
    update_snake(&snake, xmax, ymax);

    werase(win);

    draw_board(win);
    draw_snake(win, &snake);
    draw_food(win, &food);
    int new_score = update_food(&food, &snake, xmax, ymax, score);
    score = new_score;
    update_score(win, score);

    wrefresh(win);
    usleep(100000);
  }

  endwin();
  return 0;
}
