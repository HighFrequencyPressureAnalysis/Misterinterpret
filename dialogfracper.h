#pragma once

#include <QDialog>
#include "ui_dialogfracper.h"

class DialogFracPer : public QDialog
{
	Q_OBJECT

public:
	DialogFracPer(QWidget *parent = nullptr);
	~DialogFracPer();

private:
	Ui::DialogFracPerClass ui;
private slots:
	void loadPerData();
};

