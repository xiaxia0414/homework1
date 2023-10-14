#ifndef BOARD_H
#define BOARD_H
#include "snake.h"
class Board
{
public:
    int score;
    int maxScore;
    int atime;
    int length;
    int food_x;
    int food_y;
    Snake *snake;
    int map[100][100];
public:
    Board(int len);
    void makeFood();
    bool isEnd();
};

#endif // BOARD_H
