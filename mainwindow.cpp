#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QtMqtt/QMqttClient>

#include <QMainWindow>
#include <QVector>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video/tracking.hpp>
#include <QDebug>
#include <QList>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include "myvideoobject.h"
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QNetworkRequest>
#include <QVideoProbe>
#include <clickable_label.h>

#include <QGraphicsVideoItem>
static MainWindow * staticObj;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    staticObj = this;
    ui->setupUi(this);
    _vw1 = new MyVideoObject();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Draw Reactangle
void MainWindow::on_pushButton_clicked()
{
    QGraphicsVideoItem *item1 = new QGraphicsVideoItem;


    setWindowTitle("Drawing Tool");
    QMediaPlayer *_player1 = new QMediaPlayer;
    _player1->setVideoOutput(item1);
    const QUrl url1 = QUrl("rtsp://admin:admin123@192.168.0.109:554");
    const QNetworkRequest requestRtsp1(url1);
    _player1->setMedia(requestRtsp1);
    _vw1->setGeometry(100,100,100,100);
    _player1->play();

    ui->horizontalLayout->addWidget(_vw1);

}


void MainWindow::on_pushButton_3_clicked()
{
//    _vw1->flags.end_position_flag=0;
//    _vw1->flags.initial_position_flag=0;
//    _vw1->flags.nearest_point = 0;
//    _vw1->flags.resize = 0;
//    update();
}

void MainWindow::on_pushButton_2_clicked()
{
//    QRect rect(_vw1->point.init_p,_vw1->point.end_p);
//    QPixmap cropped = pixel.copy(rect);
//    cropped.save("/home/asraful-sigmind/human/cropped_image.jpg");
}

