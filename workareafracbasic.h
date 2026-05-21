#pragma once

#include <QWidget>
#include "ConstDataType.h"

class FracDockPage;

class WorkAreaFracBasic : public QWidget
{
	Q_OBJECT

public:
	explicit WorkAreaFracBasic(QWidget *parent = nullptr);
	~WorkAreaFracBasic();

	void renewFracBasicData(const DataMap&, const StringMap&);
	void renewFracPerData(const double&, const DoubleVector&);
	void renewFracOperaData(const QString&, const DoubleVectorMap&);
	void renewFracTestData(const QString&, const DoubleVectorMap&);
	void renewFracWHData(const int&, const DoubleVector&);
	void renewFracMergeData(const DoubleVector&, const DoubleVector&);
	void clear();

protected:
	void showEvent(QShowEvent *event) override;

private:
	FracDockPage *m_page = nullptr;
};

