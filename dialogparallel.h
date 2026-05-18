#pragma once
#include <QDialog>
#include "ui_dialogparallel.h"

class DialogParallel : public QDialog
{
	Q_OBJECT

public:
	DialogParallel(QWidget *parent = nullptr);
	~DialogParallel();
protected:
	void setType(const QString&);
private:
	Ui::DialogParallelClass ui;
};
