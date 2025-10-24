#ifndef UTILS_H
#define UTILS_H

#define SNAKE_MAX_LENGTH 100

typedef struct
{
  int x;
  int y;
} Point;

typedef struct
{
  Point body[SNAKE_MAX_LENGTH];
  int length;
  int dx;
  int dy;
} Snake;

typedef struct
{
  int x;
  int y;
} Food;

#endif
