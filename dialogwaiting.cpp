#include "dialogwaiting.h"
#include<QApplication>
#include<QDesktopWidget>

DialogWaiting::DialogWaiting(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("¶ÁÈ¡Êý¾Ý");
	setAttribute(Qt::WA_DeleteOnClose);
	setFixedSize(400, 150);
	int frmX = width();
	int frmY = height();
	QRect rect = QApplication::desktop()->availableGeometry();
	int deskWidth = rect.width();
	int deskHeight = rect.height();
	QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
	move(movePoint);
	movie = new QMovie(":/HighFrequencyPressureAnalysis/res/Icon/waiting.gif");
	ui.labelpic->setMovie(movie);
	movie->start();
	setShowTime(false);
	setShowProgressBar(false);
	
}

DialogWaiting::~DialogWaiting()
{}

void DialogWaiting::setTextInfor(const QString&text)
{
	ui.labelinfor->setText(text);
	setWindowTitle(text);
}

void DialogWaiting::setShowTime(bool show)
{	
	ui.labeltime->setVisible(show);
	ui.labeltimevalue->setVisible(show);
}

void DialogWaiting::setShowProgressBar(bool visible)
{	
	ui.labelprogress->setVisible(visible);
	ui.progressBar->setVisible(visible);
}

void DialogWaiting::setTime(const double value)
{
	ui.labeltimevalue->setText(QString::number(value));
}
