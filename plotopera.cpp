#include "plotopera.h"
#include"UnitChange.h"

PlotOpera::PlotOpera(QWidget *parent)
	: Plot(parent)
{
	setOpenGL();
	plot->xAxis2->setTicks(false);
	plot->xAxis2->setVisible(true);

	plot->yAxis2->setVisible(true);
	plot->yAxis2->setTicks(true);

	axissand = plot->axisRect()->addAxis(QCPAxis::atRight);
	

	UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
	QString pressureaxislabel = unitchange->getPlotAxisLabel(s_pressure);
	QString timeaxislabel = unitchange->getPlotAxisLabel(s_elapsetime);
	QString qpumpaxislabel = unitchange->getPlotAxisLabel(s_qpump);
	QString sandconaxislabel = unitchange->getPlotAxisLabel(s_sandCon);
	plot->xAxis->setLabel(timeaxislabel);
	plot->yAxis->setLabel(pressureaxislabel);
	plot->yAxis2->setLabel(qpumpaxislabel);
	axissand->setLabel(sandconaxislabel);
	plot->replot(QCustomPlot::rpQueuedReplot);
	toolbar->setDataTimeVisible(true);
	createDateTimeAxis(plot->axisRect(), 0, 5);

	plot->legend->setVisible(true);
}

PlotOpera::~PlotOpera()
{}

void PlotOpera::setDateTime(const QString&datetimestring)
{
	startdatetime = QDateTime::fromString(datetimestring, s_datetimeformat);
}

void PlotOpera::drawOperaGraph(const DoubleVectorMap&vectormap)
{
	DoubleVector vt = vectormap[s_t];
	DoubleVector vp = vectormap[s_pressure];
	DoubleVector vq = vectormap[s_qpump];
	DoubleVector vs = vectormap[s_sandCon];
	Plot::createGraph(&graphpressure, s_pressure, plot->yAxis, true, true, true);
	Plot::drawGraph(vt, vp, &graphpressure, true);

	Plot::createGraph(&graphqpump, s_qpump, plot->yAxis2, true, true, true);
	Plot::drawGraph(vt, vq, &graphqpump, true);
	if (!vs.isEmpty()) {
		Plot::createGraph(&graphsandcon, s_sandCon, axissand, true, true, true);
		Plot::drawGraph(vt, vs, &graphsandcon, true);
	}
	
	initAxisValue();
}

void PlotOpera::drawTestGraph(const DoubleVectorMap&vectormap)
{
	DoubleVector vt = vectormap[s_t];
	DoubleVector vp = vectormap[s_pressure];
	Plot::createGraph(&graphtest, s_surfacepressure, plot->yAxis, true, true, true);
	Plot::drawGraph(vt, vp, &graphtest, true);
	initAxisValue();
}

void PlotOpera::drawMergeGraph(const DoubleVector&t, const DoubleVector&p)
{
	Plot::createGraph(&graphmerge, s_mergepressure, plot->yAxis, true, false, true);
	QPen pen = graphmerge->pen();
	pen.setStyle(Qt::DashLine);
	graphmerge->setPen(pen);
	Plot::drawGraph(t,p, &graphmerge, true);
	initAxisValue();
}

void PlotOpera::setGraphNull()
{
	graphpressure = nullptr;
	graphqpump = nullptr;
	graphsandcon = nullptr;
	graphtest = nullptr;
	graphmerge = nullptr;
}

void PlotOpera::initAxisValue()
{
	initAxis(plot->xAxis);
	initAxis(plot->yAxis);
	
	plot->yAxis2->setRange(-5,50);
	axissand->setRange(-5, 500);
	plot->replot(QCustomPlot::rpQueuedReplot);
}


