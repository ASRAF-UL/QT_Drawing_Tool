#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

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
#include "clickable_label.h"
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QNetworkRequest>
#include <QVideoProbe>
static MainWindow * staticObj;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    staticObj = this;
    ui->setupUi(this);
    clickl = new Clickable_Label();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Draw Reactangle
void MainWindow::on_pushButton_clicked()
{
    setWindowTitle("Drawing Tool");
    QVideoWidget *_vw1 = new QVideoWidget;
    QMediaPlayer *_player1 = new QMediaPlayer;
    _player1->setVideoOutput(_vw1);
    const QUrl url1 = QUrl("rtsp://admin:admin123@192.168.0.109:554");
    const QNetworkRequest requestRtsp1(url1);
    _player1->setMedia(requestRtsp1);
    _vw1->setGeometry(100,100,300,400);
    _player1->play();

    QVideoProbe* videoProbe = new QVideoProbe(this);
    QImage img;

    if(!test_image.data)
    {
        qDebug()<<"test image invalid";
        QMessageBox msg;
        msg.setText("Could not load Image");
        msg.exec();
    }

    img= QImage((uchar*) test_image.data, test_image.cols, test_image.rows, static_cast<int>(test_image.step),QImage::Format_RGB888);
    pixel = QPixmap::fromImage(img.rgbSwapped());
    ui->horizontalLayout->addWidget(clickl);
    ui->horizontalLayout->addWidget(_vw1);

    clickl->setPixmap(pixel);
    clickl->setFixedHeight(pixel.height());
    clickl->setFixedWidth(pixel.width());

}


void MainWindow::on_pushButton_3_clicked()
{
    clickl->flags.end_position_flag=0;
    clickl->flags.initial_position_flag=0;
    clickl->flags.nearest_point = 0;
    clickl->flags.resize = 0;
    update();
}

void MainWindow::on_pushButton_2_clicked()
{
    QRect rect(clickl->point.init_p,clickl->point.end_p);
    QPixmap cropped = pixel.copy(rect);
    cropped.save("/home/asraful-sigmind/human/cropped_image.jpg");
}

