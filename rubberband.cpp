#include "rubberband.h"

RubberBand::RubberBand(QCustomPlot *p_plot,QRubberBand::Shape type)
	: QRubberBand(type,p_plot)
{
	plot = p_plot;
	connect(plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(createRubber(QMouseEvent*)));
	connect(plot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(moveRubber(QMouseEvent*)));
	connect(plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(releaseRubber(QMouseEvent*)));
}

RubberBand::~RubberBand()
{
}

void RubberBand::createRubber(QMouseEvent*event)
{
	if (event->button() == Qt::LeftButton)
	{
		initpos = event->pos();
		setGeometry(QRect(initpos, QSize()));
		show();
	}
}