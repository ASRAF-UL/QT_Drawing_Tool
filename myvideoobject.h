#ifndef MYVIDEOOBJECT_H
#define MYVIDEOOBJECT_H

#include <QVideoWidget>
#include <QGraphicsView>

class QRubberBand;

class MyVideoObject : public QGraphicsView
{
public:
    MyVideoObject(QWidget *parent = nullptr);
protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);
private:
    QRubberBand *rubberBand;
    QPoint origin;
    QRect rect;
};

#endif // MYVIDEOOBJECT_H
