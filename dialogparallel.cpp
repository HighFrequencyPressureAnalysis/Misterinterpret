#include "dialogparallel.h"
#include<QScreen>
#include<QMovie>

DialogParallel::DialogParallel(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);//ÉèÖÃÎÞ´°¿Ú¿ò¼Ü±ß½ç
    setAttribute(Qt::WA_TranslucentBackground);//ÉèÖÃ±³¾°Í¸Ã÷
    int frmX = width();
    int frmY = height();
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    QSize screenSize = screenGeometry.size();
    int deskWidth = screenSize.width();
    int deskHeight = screenSize.height();
    QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
    move(movePoint);
    //¼ÓÔØgifÍ¼Æ¬
    QMovie* movie = new QMovie(":/HighFrequencyPressureAnalysis/res/Icon/waiting.gif");
    ui.labelmovie->setMovie(movie);
    movie->start();
}

DialogParallel::~DialogParallel()
{}

void DialogParallel::setType(const QString&type)
{
    ui.labeltext->setText(type);
}
