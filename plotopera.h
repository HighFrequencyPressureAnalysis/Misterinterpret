#pragma once

#include "plot.h"

class PlotOpera  : public Plot
{
	Q_OBJECT

public:
	PlotOpera(QWidget *parent);
	~PlotOpera();

	void setDateTime(const QString&);
	void drawOperaGraph(const DoubleVectorMap&);
	void drawTestGraph(const DoubleVectorMap&);
	void drawMergeGraph(const DoubleVector&, const DoubleVector&);
	void setGraphNull();
private :
	QCPAxis* axissand = nullptr;
	Graph* graphpressure = nullptr;
	Graph* graphqpump = nullptr;
	Graph* graphsandcon = nullptr;
	Graph* graphtest = nullptr;
	Graph* graphmerge = nullptr;
private slots:
	void initAxisValue();
};

