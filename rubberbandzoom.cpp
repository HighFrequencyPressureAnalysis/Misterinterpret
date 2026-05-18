#include "rubberbandzoom.h"

RubberBandZoom::RubberBandZoom(QCustomPlot *plot)
	: RubberBand(plot)
{
}

RubberBandZoom::~RubberBandZoom()
{
}

void RubberBandZoom::moveRubber(QMouseEvent*event)
{
	if (isVisible()) {
		setGeometry(QRect(initpos, event->pos()).normalized());
	}
}

void RubberBandZoom::releaseRubber(QMouseEvent*event)
{
	QRectF zoomrect = geometry();
	plot->axisRect()->zoom(zoomrect);
	plot->replot();
	emit removeRubber();
}


