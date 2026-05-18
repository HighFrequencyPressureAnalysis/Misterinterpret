#pragma once
#include "qcustomplot.h"


class Graph : public QCPGraph
{
	Q_OBJECT

public:
	Graph(QCPAxis *keyaxis,QCPAxis* valueaxis);
	~Graph();
	

	
	void getRangeData(const double, const double, QVector<double>&, QVector<double>&);
	double getValue(const double t);
	double getLeftValue();
	double getRigetValue();
	double getKeyLower()const;
	double getKeyUpper()const;
	double getValueLower()const;
	double getValueUpper()const;
	int getPos(const double)const;
	
	QVector<int> getChooseKeyData(const QCPRange&)const;
	QVector<int> getChooseValueData(const QCPRange&)const;
	QVector<double> getValueData(const QVector<double>&timerange=QVector<double>())const;
	QVector<double> getTimeData(const QVector<double>&timerange=QVector<double>())const;
	QVector<double> getChooseTime(double pos);
	QVector<int> getTimeIndex(const QVector<double>&)const;
};

typedef QVector<Graph*>GraphVector;
