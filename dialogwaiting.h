#pragma once
#include <QDialog>
#include "ui_dialogwaiting.h"
#include<QMovie>

class DialogWaiting : public QDialog
{
	Q_OBJECT

public:
	DialogWaiting(QWidget *parent = nullptr);
	~DialogWaiting();
protected:
	//设置文本信息
	Ui::DialogWaitingClass ui;
	//设置显示文本
	void setTextInfor(const QString&);
	//设置显示时间
	void setShowTime(bool);
	//设置显示进度条
	void setShowProgressBar(bool);
protected slots:
	//设置显示时间
	void setTime(const double value);
private:
	QMovie* movie;
};
