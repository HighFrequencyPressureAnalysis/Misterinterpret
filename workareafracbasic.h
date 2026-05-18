#pragma once

#include <QWidget>
#include "ui_workareafracbasic.h"

class WorkAreaFracBasic : public QWidget
{
	Q_OBJECT

public:
	WorkAreaFracBasic(QWidget *parent = nullptr);
	~WorkAreaFracBasic();

	void renewFracBasicData(const DataMap&, const StringMap&);
	void renewFracPerData(const double&, const DoubleVector&);
	void renewFracOperaData(const QString&,const DoubleVectorMap&);
	void renewFracTestData(const QString&, const DoubleVectorMap&);
	void renewFracWHData(const int&, const DoubleVector&);
	void renewFracMergeData(const DoubleVector&, const DoubleVector&);
	void clear();
private:
	Ui::WorkAreaFracBasicClass ui;
};

