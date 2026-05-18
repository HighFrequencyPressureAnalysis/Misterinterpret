#include "DialogWaitingReadData.h"
#include<QApplication>
#include<QDesktopWidget>
#include<QTime>
#include<QCoreApplication>

DialogWaitingReadData::DialogWaitingReadData(QWidget *parent)
	: DialogWaiting(parent)
{
	setTextInfor("读取历史数据");
	setShowProgressBar(true);
	connect(&thread, SIGNAL(sendMaxIter(int)), ui.progressBar, SLOT(setMaximum(int)));
	connect(&thread, SIGNAL(sendReadProgress(int)), ui.progressBar, SLOT(setValue(int)));
	connect(&thread, SIGNAL(finished()), this, SLOT(close()));
	thread.setMaxRowcount();
	thread.startRead();
	thread.start();
}

DialogWaitingReadData::~DialogWaitingReadData()
{
	thread.stopThread();
	if (!thread.isFinished()) {
		thread.wait();
	}else {
		thread.quit();
	}
}
