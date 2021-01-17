#include "myvideoobject.h"

#include <QMouseEvent>
#include <QPainter>
#include <QRubberBand>
#include <QGraphicsView>

MyVideoObject::MyVideoObject(QWidget *parent):
    QGraphicsView(parent),
    rubberBand(nullptr){}

void MyVideoObject::mousePressEvent(QMouseEvent *ev)
{
    origin = ev->pos();
    if(!rubberBand)
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    rubberBand->setGeometry(QRect(origin,QSize()));
    rubberBand->show();
    QGraphicsView::mousePressEvent(ev);
}

void MyVideoObject::mouseMoveEvent(QMouseEvent *ev)
{
    rubberBand->setGeometry(QRect(origin,ev->pos()).normalized());
    QGraphicsView::mouseMoveEvent(ev);
}

void MyVideoObject::mouseReleaseEvent(QMouseEvent *ev)
{
    rect = rubberBand->geometry();
    update();
    QGraphicsView::mouseReleaseEvent(ev);
}

void MyVideoObject::paintEvent(QPaintEvent *ev)
{


    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(3);

    QGraphicsView::paintEvent(ev);
    QPainter painter(this->viewport());
    painter.save();
    painter.setPen(pen);
    if(!rect.isNull())
        painter.drawRect(rect);
    painter.restore();
}
