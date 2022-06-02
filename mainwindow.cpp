#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "C://Users/abram/point.h" //Так как я слегка напортачил с путем файла, то надо вручную указать место заголовочного файла у вас
#include <QMouseEvent>             // у вас на компьюетере
int i=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (int i =0;i<mas.size();++i)
    {
        mas[i].draw(&painter);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
   Point point(event->x(),event->y(),3);
   mas.push_back(point);
   if((i++)==2)
       valid = false;
   else
       valid = true;
   if(valid)
   {
       repaint();
   }
}


