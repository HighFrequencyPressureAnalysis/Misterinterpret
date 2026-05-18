#include "GraphPlotSetting.h"
#include"ConstBasic.h"

GraphPlotSetting::GraphPlotSetting()
{
	
	colormap[s_pressure] = Qt::red;
	colormap[s_waterhammerpress] = Qt::red;
	colormap[s_qpump] = Qt::blue;
	colormap[s_sandCon] = Qt::gray;
	colormap[s_mergepressure] = Qt::magenta;
	
}

GraphPlotSetting::~GraphPlotSetting()
{
}

QString GraphPlotSetting::getDefaultColorString(const int inputindex)
{
	QVector<QColor>colorvector;
	colorvector.push_back(Qt::black);
	colorvector.push_back(Qt::red);
	colorvector.push_back(Qt::blue);
	colorvector.push_back(Qt::green);
	colorvector.push_back(Qt::cyan);
	colorvector.push_back(Qt::magenta);
	colorvector.push_back(Qt::yellow);
	colorvector.push_back(Qt::gray);
	colorvector.push_back(Qt::darkGray);
	colorvector.push_back(Qt::lightGray);
	if (inputindex > colorvector.size()) {
		index = 0;
	}
	QColor color = colorvector[index];
	index++;
	return color.name();
}

QColor GraphPlotSetting::getColor(const QString&type)
{
	return colormap[type];
}

QPen GraphPlotSetting::getDashPen() const
{
	QPen pen;
	pen.setColor(Qt::gray);
	QVector<qreal> dashes;
	qreal space = 4;
	dashes << 3 << space << 9 << space;
	pen.setDashPattern(dashes);
	return pen;
}

