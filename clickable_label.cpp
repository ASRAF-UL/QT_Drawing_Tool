#include "clickable_label.h"
#include<QLabel>
#include <qdebug.h>
#include <QMouseEvent>
#include <qpainter.h>
#include <cmath>

Clickable_Label::Clickable_Label(QWidget *parent) : QLabel(parent)
{

}

void Clickable_Label::mousePressEvent(QMouseEvent* event)
{
    if(!flags.resize)
    {
       QPoint init_p= event->pos();
       flags.initial_position_flag = 1;
       point.init_p = init_p;
       qDebug()<<"i"<<init_p;
    }

     if(flags.resize == 1)
     {
        QPoint resize_p = event->pos();

        getNearestPoint(resize_p);
        if(!flags.nearest_point)
        {
           point.init_p = resize_p;
        }

       else
        {
           point.end_p = resize_p;
        }
     }

}

void Clickable_Label::mouseMoveEvent(QMouseEvent* event)
{
    if(!flags.resize)
    {
       QPoint moved_p= event->pos();
       flags.end_position_flag = 1;
       point.end_p = moved_p;
    }

    if(flags.resize)
    {
       QPoint moved_p= event->pos();
       flags.end_position_flag = 1;

       if(!flags.nearest_point)
       {
          point.init_p = moved_p;
       }

      else
       {
          point.end_p = moved_p;
       }
    }
    update();

}

void Clickable_Label::mouseReleaseEvent(QMouseEvent* event)
{
    if(!flags.resize)
    {
       QPoint end_p= event->pos();
       point.end_p = end_p;
       flags.resize = 1;
    }
    else
    {
       QPoint resize_p= event->pos();
       if(!flags.nearest_point)
       {
          point.init_p = resize_p;
       }
      else
       {
          point.end_p = resize_p;
       }
    }

}

void Clickable_Label::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    if(flags.initial_position_flag && flags.end_position_flag)
    {
        QPainter painter(this);
        painter.setPen(Qt::green);
        QRect r1(point.init_p, point.end_p );
        painter.drawRect(r1);
    }
}

void Clickable_Label::getNearestPoint(QPoint p)
{
    int d0 = sqrt(pow(p.x() - point.init_p.x(), 2) + pow(p.y() - point.init_p.y(), 2));
    int d1 = sqrt(pow(p.x() - point.end_p.x(), 2) + pow(p.y() - point.end_p.y(), 2));
    if(d0<d1)
    {
        flags.nearest_point = 0;
    }
    else
    {
         flags.nearest_point = 1;
    }
}
