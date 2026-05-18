#pragma once
#include"SingleTemplate.h"
#include<QColor>
#include<QPen>
#include"ConstDataType.h"


class GraphPlotSetting
{
	DECLARE_SINGLEON(GraphPlotSetting);
public:
	QColor getColor(const QString&type);
	QPen getDashPen()const;
	QString getDefaultColorString(const int);
	

private:
	GraphPlotSetting();
	~GraphPlotSetting();

	int index=0;
	ColorMap colormap;
	
};

