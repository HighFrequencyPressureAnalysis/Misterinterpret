#pragma once

#include "plot.h"

class PlotWh  : public Plot
{
	Q_OBJECT

public:
	PlotWh(QWidget *parent);
	~PlotWh();

	void drawPressGraph(const int,const DoubleVector&);
	void setGraphNull();
private :
	Graph* graph = nullptr;
};

