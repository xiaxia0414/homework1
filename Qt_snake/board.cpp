#include "board.h"
#include "iostream"
#include "time.h"
#include "stdlib.h"
#include "fstream"
#include "cstring"
#include "QDebug"
Board::Board(int len)
{
    length=len;
    srand((unsigned)time(NULL));

    atime=200;
    score = 0;
    memset(map,0,sizeof(map));

    for(int i=0;i<=length+1;i++)
    {
        map[i][0]=map[i][length+1]=map[0][i]=map[length+1][i]=1;
    }
    snake = new Snake(this);

    food_x=food_y=0;
    while(map[food_x][food_y]!=0)
    {
        food_x=rand()%length+1;
        food_y=rand()%length+1;
    }
    map[food_x][food_y]=2;
}

void Board::makeFood()
{
    food_x=food_y=0;
    while(map[food_x][food_y]!=0)
    {
        food_x=rand()%length+1;
        food_y=rand()%length+1;
    }
    map[food_x][food_y]=2;
}

bool Board::isEnd()
{
    int type=snake->detect();
    qDebug()<<'a'<<type<<' ';
    if(type==1)snake->toNext();
    else if(type==2)
    {
        snake->eat();
        makeFood();
        score+=1;
        atime-=5;
    }
    else if(type==0)
    {
        return true;
    }
    return false;
}

