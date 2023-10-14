#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QKeyEvent"
#include "board.h"
#include "QTimer"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool flag_stop;
    bool isPress;
    QTimer *timer;
    Board *board;


    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();
public slots:
    void timerEvent();
};
#endif // MAINWINDOW_H
