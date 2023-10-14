 #include "mainwindow.h"
#include "QPainter"
#include "QDebug"
#include "QTimer"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Qt贪吃蛇");
    board = new Board(30);
    flag_stop=0;
    isPress=false;
    timer = new QTimer(this);
    timer->setInterval(board->atime);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(timerEvent()));
    resize(800,800);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::lightGray);

    painter.setBrush(Qt::black);
    for(int i=0;i<=board->length+1;i++)
    {
        painter.drawRect(0*20,i*20,20,20);
        painter.drawRect((board->length+1)*20,i*20,20,20);
        painter.drawRect(i*20,0*20,20,20);
        painter.drawRect(i*20,(board->length+1)*20,20,20);
    }
    painter.setPen(Qt::black);
    painter.setBrush(Qt::darkGreen);
    painter.drawRect(board->snake->s[board->snake->len][1]*20,
                     board->snake->s[board->snake->len][0]*20,20,20);
    for(int i=0;i<board->snake->len;i++)
    {
        painter.drawRect(board->snake->s[i][1]*20,board->snake->s[i][0]*20,20,20);
    }

    painter.setBrush(Qt::red);
    painter.drawRect(board->food_y*20,board->food_x*20,20,20);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Enter)
    {

    }


    if(event->key()==Qt::Key_Up)
    {
        if(!(board->snake->dx==1&&board->snake->dy==0))
        {
            board->snake->turnUp();
            isPress = true;
        }
    }
    else if(event->key()==Qt::Key_Down)
    {
        if(!(board->snake->dx==-1&&board->snake->dy==0))
        {
            board->snake->turnDown();
            isPress = true;
        }
    }
    else if(event->key()==Qt::Key_Left)
    {
        if(!(board->snake->dx==0&&board->snake->dy==1))
        {
            board->snake->turnLeft();
            isPress = true;
        }
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(!(board->snake->dx==0&&board->snake->dy==-1))
        {
            board->snake->turnRight();
            isPress = true;
        }
    }
}
void MainWindow::timerEvent()
{
    timer->setInterval(board->atime);
    if(board->isEnd())
    {
        timer->stop();
        QMessageBox::information(this,"提示","游戏结束");
    }
    this->update();
    isPress=false;
}

MainWindow::~MainWindow()
{

}


