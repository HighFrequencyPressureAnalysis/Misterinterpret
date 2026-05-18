#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include "ui_dialogfracbasic.h"

class DialogFracBasic : public QDialog
{
	Q_OBJECT

public:
	DialogFracBasic(QWidget *parent = nullptr);
	~DialogFracBasic();

private:
	Ui::DialogFracBasicClass ui;
	
private slots:
	void sureData();
};

