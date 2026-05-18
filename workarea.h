#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include "ui_workarea.h"

class WorkArea : public QWidget
{
	Q_OBJECT
public:
	WorkArea(QWidget *parent = nullptr);
	~WorkArea();

private:
	Ui::WorkAreaClass ui;
private slots:
	void clearChoose();
};

