#ifndef CLICKABLE_LABEL_H
#define CLICKABLE_LABEL_H

#include <QWidget>
#include <QLabel>

class Clickable_Label : public QLabel
{
    Q_OBJECT
public:
    explicit Clickable_Label(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *event) override;
    void getNearestPoint(QPoint);

    struct controls {
      int initial_position_flag = 0;
      int end_position_flag = 0;
      int resize = 0;
      int nearest_point = 0;
    } flags;

    struct points {
      QPoint init_p;
      QPoint end_p;
      QPoint resize_p;
    } point;

signals:
    void clicked(QPoint);
    void released(QPoint);
    void moved(QPoint);

public slots:
};

#endif // CLICKABLE_LABEL_H
