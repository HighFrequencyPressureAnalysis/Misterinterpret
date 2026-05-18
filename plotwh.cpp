#include "plotwh.h"
#include"UnitChange.h"

PlotWh::PlotWh(QWidget *parent)
	: Plot(parent)
{
	UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
	QString pressureaxislabel = unitchange->getPlotAxisLabel(s_pressure);
	QString timeaxislabel = unitchange->getPlotAxisLabel(s_wht);
	plot->xAxis->setLabel(timeaxislabel);
	plot->yAxis->setLabel(pressureaxislabel);

}

PlotWh::~PlotWh()
{}

void PlotWh::drawPressGraph(const int freq,const DoubleVector&vp)
{
	Plot::createGraph(&graph, s_waterhammerpress, plot->yAxis, true, true, true);
	int count = vp.size();
	DoubleVector vt;
	for (int i = 0; i < count; i++) {
		vt.push_back((1.0 / double(freq)) * i);
	}
	Plot::drawGraph(vt, vp, &graph, true);
	initAxisValue();
}

void PlotWh::setGraphNull()
{
	graph = nullptr;
}