#pragma once

#include "rubberband.h"

//缩放选择框

class RubberBandZoom : public RubberBand
{
	Q_OBJECT

public:
	RubberBandZoom(QCustomPlot *);
	~RubberBandZoom();
private slots:
	void moveRubber(QMouseEvent*);
	void releaseRubber(QMouseEvent*);
};
