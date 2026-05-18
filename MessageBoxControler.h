#pragma once
#include"SingleTemplate.h"
#include<QString>
#include<QMessageBox>
#include<qpushbutton.h>
#include<QVBoxLayout>
#include<qlineedit.h>
#pragma execution_character_set("utf-8")

class MessageBoxControler
{
	DECLARE_SINGLEON(MessageBoxControler);
public:
	void showInformationMessageBox(const QString&);
	void showWarningMessageBox(const QString&);
	void showCriticalMessageBox(const QString&);
	bool showQuestionMessageBox(const QString&);
	QString showInputMessageBox(const QString&,const QString&);
private:
	MessageBoxControler();
	~MessageBoxControler();
};

