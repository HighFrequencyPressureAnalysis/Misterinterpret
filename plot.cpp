#include "plot.h"
#include"ExportPlotDataModel.h"
#include"dialogexportplotdata.h"

Plot::Plot(QWidget *parent)
	: QWidget(parent)
{
	qRegisterMetaType<QCPRange>("QCPRange");
	toolbar = new PlotToolBar(this);
	plot = new QCustomPlot(this);
	//plot->setInteraction(QCP::iSelectLegend, true);
	QVBoxLayout* v_layout = new QVBoxLayout;
	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(plot);
	layout->addWidget(toolbar);

	layout->setStretchFactor(plot, 15);
	layout->setStretchFactor(toolbar, 1);

	v_layout->addLayout(layout, 15);

	setLayout(v_layout);

	
	plot->setNoAntialiasingOnDrag(true);

	//plot->xAxis2->setTicks(false);
	//plot->yAxis2->setTicks(false);
	plot->yAxis2->setVisible(false);



	connect(toolbar->getAction(s_zoomin), SIGNAL(toggled(bool)), this, SLOT(zoomInPlot(bool)));
	connect(toolbar->getAction(s_zoomout), &QAction::triggered, this, &Plot::zoomOutPlot);
	connect(toolbar->getAction(s_init), &QAction::triggered, this, &Plot::initAxisValue);
	connect(toolbar->getAction(s_legend), SIGNAL(toggled(bool)), this, SLOT(setLegendVisible(bool)));
	connect(toolbar->getAction(s_zoom), SIGNAL(toggled(bool)), this, SLOT(setZoomModel(bool)));
	connect(toolbar->getAction(s_drag), SIGNAL(toggled(bool)), this, SLOT(setDragModel(bool)));
	connect(toolbar->getAction(s_showdata), SIGNAL(toggled(bool)), this, SLOT(setShowData(bool)));
	connect(toolbar->getAction(s_showdatetime), SIGNAL(toggled(bool)), this, SLOT(setDataTimeAxisVisible(bool)));

	connect(plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(showMenu(QMouseEvent*)));

	toolbar->setDataTimeVisible(false);
}

Plot::~Plot()
{}



void Plot::clearPlot()
{
	plot->clearGraphs();
	plot->replot();
}

void Plot::replot()
{
	plot->replot();
}

void Plot::removePlotItems()
{
	plot->clearItems();
}

void Plot::setToolbarUnenble()
{
	toolbar->setEnabled(false);
}

void Plot::setBackGroudColor(const QString& backcolor, bool gradient, const QString& gradientcolor)
{
	QLinearGradient plotGradient;
	QColor color1(backcolor);
	plotGradient.setColorAt(0, color1);
	if (gradient) {
		plotGradient.setColorAt(1, QColor(gradientcolor));
	}
	else {
		plotGradient.setColorAt(1, QColor(backcolor));
	}
	plot->setBackground(plotGradient);
	plot->replot();
}

void Plot::setPlotFont(const QString& fonttype, const QString& color)
{
	QFont font;
	font.setFamily(fonttype);
	QList<QCPAxis*>axis = getChooseAxis();
	QColor labelcolor(color);
	for (int i = 0; i < axis.size(); i++) {
		axis[i]->setLabelFont(font);
		axis[i]->setLabelColor(labelcolor);
	}
	plot->replot();
}



void Plot::removeGraph(Graph**graph)
{
	if ((*graph)) {
		plot->removeGraph(*graph);
		(*graph) = NULL;
	}
}

void Plot::showSelectData(const IntVector&index, Graph*graph)
{
	if (graph) {
		QCPDataSelection selection;
		QCPDataRange range(index.first(), index.last() + 1);
		selection.addDataRange(range);
		if (index.last() == index.first()) {
			graph->setSelectable(QCP::stSingleData);
		}
		else {
			graph->setSelectable(QCP::stDataRange);
		}
		graph->setSelection(selection);
		plot->replot(QCustomPlot::rpQueuedReplot);
	}
}

void Plot::showSelectData(const QCPRange&range, Graph*graph)
{
	if (graph) {
		QCPDataSelection selection;
		QCPDataRange datarange(range.lower, range.upper);
		selection.addDataRange(datarange);
		if (range.lower == range.upper) {
			graph->setSelectable(QCP::stSingleData);
		}
		else {
			graph->setSelectable(QCP::stDataRange);
		}
		graph->setSelection(selection);
		plot->replot(QCustomPlot::rpQueuedReplot);
	}
}

void Plot::getCurrentRange(DoubleVector&range)
{
	range.clear();
	range.push_back(plot->xAxis->range().lower);
	range.push_back(plot->xAxis->range().upper);
}

void Plot::getDataRange(DoubleVector&range)
{
	DoubleVector vmint,vmaxt;
	int datacount = 0;
	for (int i = 0; i < plot->graphCount(); i++) {
		if (plot->graph(i)->visible()) {
			datacount = plot->graph(i)->dataCount();
			vmint.push_back(plot->graph(i)->dataMainKey(0));
			vmaxt.push_back(plot->graph(i)->dataMainKey(datacount - 1));
		}
	}
	double mint = *std::min_element(std::begin(vmint), std::end(vmint));
	double maxt = *std::max_element(std::begin(vmaxt), std::end(vmaxt));
	range.clear();
	range.push_back(mint);
	range.push_back(maxt);
}

void Plot::setOpenGL()
{
	plot->setOpenGl(true);
}

void Plot::createDateTimeAxis(QCPAxisRect* rect,const int angel, const int tickcount)
{
	axisdatetime = rect->addAxis(QCPAxis::atBottom);
	axisdatetime->setLabel(s_datetime+s_interval+s_hhmmss);
	axisdatetime->setTickLabelRotation(angel);
	QSharedPointer<QCPAxisTickerDateTime>dateTimeTicker(new QCPAxisTickerDateTime);
	dateTimeTicker->setDateTimeFormat(s_hhmmss);
	axisdatetime->setTicker(dateTimeTicker);
	QDateTime datetime = QDateTime::currentDateTime();
	axisdatetime->setRange(QCPAxisTickerDateTime::dateTimeToKey(datetime), QCPAxisTickerDateTime::dateTimeToKey(datetime.addDays(10)));
	axisdatetime->ticker()->setTickCount(tickcount);
	connect(rect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(const QCPRange&)), this, SLOT(resetLocalDateTime(const QCPRange&)));
}

void Plot::initAxis(QCPAxis* axis,bool notcheckvisible,bool checkave)
{	
	if (axis->visible()||notcheckvisible) {
		QList<QCPGraph*>graphs = axis->graphs();
		double minvalue = FLT_MAX;
		double maxvalue = -FLT_MAX;
		for (int i = 0; i < graphs.size(); i++) {
			Graph* graph = qobject_cast<Graph*>(graphs[i]);
			if (axis->orientation()== Qt::Orientation::Vertical) {
				minvalue = std::min(graph->getValueLower(), minvalue);
				maxvalue = std::max(graph->getValueUpper(), maxvalue);
				
			}
			else {
				minvalue = std::min(graph->getKeyLower(), minvalue);
				maxvalue = std::max(graph->getKeyUpper(), maxvalue);
			}
		}
		if (minvalue != FLT_MAX && maxvalue != -FLT_MAX) {
			const int count = 100;
			double ave=0;
			if (axis->scaleType() == QCPAxis::stLogarithmic) {
				axis->setRange(pow(10, floor(log10f(minvalue))), pow(10, ceil(log10f(maxvalue))));
			}
			else {
				if (checkave) {
					ave = (maxvalue - minvalue) / count;
				}
				
				if (!ave) {
					ave = 1;
				}
				axis->setRange(minvalue - ave, maxvalue + ave);

			}
		}
	}
	
}

void Plot::setAxisColor(const QColor&color, QCPAxis*axis)
{
	QPen pen(color);
	axis->setBasePen(pen);
	axis->setLabelColor(color);
	axis->setSubTickPen(pen);
}

void Plot::outputPic()
{
	QPixmap pixmap = plot->toPixmap();
	QClipboard* clipborad = QApplication::clipboard();
	clipborad->setPixmap(pixmap);
}

void Plot::createGraph(Graph** graph, const QString& name, QCPAxis* yaxis, bool issample, bool lsline, bool ssdisc)
{
	if (!(*graph)) {
		*graph = new Graph(plot->xAxis, yaxis);
		if (lsline) {
			(*graph)->setLineStyle(QCPGraph::lsLine);
		}
		else {
			(*graph)->setLineStyle(QCPGraph::lsNone);
		}
		if (ssdisc) {
			(*graph)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
		}
		else {
			(*graph)->setScatterStyle(QCPScatterStyle::ssNone);
		}
		if (issample) {
			(*graph)->setAdaptiveSampling(true);
		}
		else {
			(*graph)->setAdaptiveSampling(false);
		}
		QPen pen;
		pen.setColor(Qt::green);
		 (*graph)->selectionDecorator()->setPen(pen);
		GraphPlotSetting* graphplotsetting = SingleTemplate<GraphPlotSetting>::getInstance();
		pen.setColor(graphplotsetting->getColor(name));
		(*graph)->setName(name);
		(*graph)->setPen(pen);
	}
}

void Plot::createGraph(Graph** graph, const QString& name,QCPAxis*xaxis,QCPAxis* yaxis, bool issample, bool lsline, bool ssdisc)
{
	if (!(*graph)) {
		*graph = new Graph(xaxis, yaxis);
		if (lsline) {
			(*graph)->setLineStyle(QCPGraph::lsLine);
		}
		else {
			(*graph)->setLineStyle(QCPGraph::lsNone);
		}
		if (ssdisc) {
			(*graph)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
		}
		else {
			(*graph)->setScatterStyle(QCPScatterStyle::ssNone);
		}
		if (issample) {
			(*graph)->setAdaptiveSampling(true);
		}
		else {
			(*graph)->setAdaptiveSampling(false);
		}
		QPen pen;
		pen.setColor(Qt::green);
		(*graph)->selectionDecorator()->setPen(pen);
		GraphPlotSetting* graphplotsetting = SingleTemplate<GraphPlotSetting>::getInstance();
		pen.setColor(graphplotsetting->getColor(name));
		(*graph)->setName(name);
		(*graph)->setPen(pen);
	}
}

void Plot::drawGraph(const QVector<double>&x, const QVector<double>&y, Graph** graph,bool alreadysort)
{
	if ((*graph)) {
		(*graph)->setData(x, y, alreadysort);
	}
}

void Plot::zoomInPlot(bool checked)
{
	toolbar->getAction(s_zoom)->setChecked(false);
	toolbar->getAction(s_drag)->setChecked(false);
	toolbar->getAction(s_showdata)->setChecked(false);
	if (checked) {
		plot->setCursor(Qt::CrossCursor);
		plot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);
	}else {
		plot->setCursor(Qt::ArrowCursor);
		plot->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
	}
}

void Plot::setRragAndZoomUnable()
{
	toolbar->setDragAndZoomUnable();
	setZoomModel(false);
	setDragModel(false);
}

Axises Plot::getChooseAxis() const
{
	Axises axises;
	axises.push_back(plot->xAxis);
	axises.push_back(plot->yAxis);
	return axises;
}

QDateTime Plot::getDateTime() const
{
	return QDateTime::currentDateTime();
}


QString Plot::getAxisStringValue(QCPAxis*axis, const double pixelvalue)
{
	QString strvalue;
	QString label = axis->label();
	if (axis->label().contains(s_datetime)) {
		int a = 0;
		double time = plot->xAxis->pixelToCoord(pixelvalue);
		QDateTime startdatetime = getDateTime();
		QDateTime tempdatetime = startdatetime.addSecs(time * 3600);
		strvalue = tempdatetime.toString(s_datetimeformat);
	}else {
		double value = axis->pixelToCoord(pixelvalue);
		strvalue = QString::number(value);
	}
	return strvalue;
}

void Plot::zoomOutPlot()
{
	QRectF rect = plot->rect();
	QMarginsF margin(0, 0, 20, 20);
	rect += margin;
	plot->axisRect()->zoom(rect);
	plot->replot(QCustomPlot::rpQueuedReplot);
}

void Plot::setLegendVisible(bool visible)
{
	
	if (plot->legend) {
		plot->legend->setVisible(visible);
		plot->replot(QCustomPlot::rpQueuedReplot);
	}

}

void Plot::removeRubber()
{
	plot->setCursor(Qt::ArrowCursor);
	delete rubberbandzoom;
	rubberbandzoom = nullptr;
	toolbar->getAction(s_zoomin)->setChecked(false);
}

void Plot::setDragModel(bool checked)
{
	if (checked) {
		plot->setCursor(Qt::OpenHandCursor);
		toolbar->getAction(s_zoomin)->setChecked(false);
		toolbar->getAction(s_showdata)->setChecked(false);
		QList<QCPAxis*>axis = getChooseAxis();
		plot->axisRect()->setRangeDragAxes(axis);
	}else {
		plot->setCursor(Qt::ArrowCursor);
	}

	plot->setInteraction(QCP::iRangeDrag, checked);
}

void Plot::setZoomModel(bool checked)
{
	if (checked) {
		QList<QCPAxis*>axis = getChooseAxis();
		plot->axisRect()->setRangeZoomAxes(axis);
	}
	plot->setInteraction(QCP::iRangeZoom, checked);
}

void Plot::setShowData(bool checked)
{
	if (checked) {
		toolbar->getAction(s_zoomin)->setChecked(false);
		toolbar->getAction(s_drag)->setChecked(false);
		plot->setCursor(Qt::CrossCursor);
		if (!itemdataline) {
			itemdataline = new QCPItemStraightLine(plot);
			itemdataline->setPen(QPen(Qt::gray, 1, Qt::DashLine));
			itemdataline->setClipToAxisRect(true);
			itemdataline->point1->setCoords(0, 0);
			itemdataline->point2->setCoords(0, 0);
		}
		connect(plot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(showChooseData(QMouseEvent*)));
	}else {
		plot->setCursor(Qt::ArrowCursor);
		if (itemdataline) {
			plot->removeItem(itemdataline);
			itemdataline = nullptr;
		}
		disconnect(plot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(showChooseData(QMouseEvent*)));
	}
}

void Plot::showMenu(QMouseEvent*event)
{
	if (event->buttons() == Qt::RightButton) {
		menu = new QMenu(this);
		menu->setAttribute(Qt::WA_DeleteOnClose);
		menu->addAction("输出图片", this, [this]() {this->outputPic(); });
		menu->addAction("输出数据", this, [this]() {this->showExportDataDialog(); });
		menu->popup(event->globalPos());
	}
}

void Plot::showExportDataDialog()
{
	
	int graphcount = plot->graphCount();
	//int a = plot->graph()->dataCount();
	if (graphcount) {
		GraphExportDataVector graphexportdatavector;
		ExportDataInfor exportdatainfor;
		QStringList types;
		for (int i = 0; i < graphcount; i++) {
			if (plot->graph(i)->visible()) {
				types.push_back(plot->graph(i)->name());
				GraphExportData graphexportdata;
				graphexportdata.graph = plot->graph(i);
				graphexportdata.type = plot->graph(i)->name();
				graphexportdatavector.push_back(graphexportdata);
			}
		
		}
		
		QString timetype = plot->xAxis->label();
		if (timetype.contains(s_interval)) {
			timetype = timetype.split(s_interval).first();
		}
		types.push_back(timetype);
		DoubleVector range, currentrange;
		getDataRange(range);
		getCurrentRange(currentrange);
		exportdatainfor.datetime = startdatetime;
		exportdatainfor.issametime = issametime;
		exportdatainfor.timetype = timetype;
		exportdatainfor.types = types;
		exportdatainfor.currentrange = currentrange;
		exportdatainfor.range = range;
		ExportPlotDataModel* exportplotdatamodel = SingleTemplate<ExportPlotDataModel>::getInstance();
		exportplotdatamodel->setExportDataInfor(exportdatainfor);
		exportplotdatamodel->setGraphExportDataVector(graphexportdatavector);
		DialogExportPlotData* dialog = new DialogExportPlotData();
		dialog->exec();
	}
	
}

void Plot::resetLocalDateTime(const QCPRange&range)
{
	QDateTime tempstartdatetime = startdatetime.addSecs(range.lower * 3600);
	QDateTime tempenddatetime = startdatetime.addSecs(range.upper * 3600);
	axisdatetime->setRange(QCPAxisTickerDateTime::dateTimeToKey(tempstartdatetime), QCPAxisTickerDateTime::dateTimeToKey(tempenddatetime));
}

void Plot::setDataTimeAxisVisible(bool visible)
{	
	if (axisdatetime) {
		axisdatetime->setVisible(visible);
	}
	plot->replot(QCustomPlot::rpQueuedReplot);
}

void Plot::showChooseData(QMouseEvent* event)
{
	if (plot->viewport().contains(event->pos()) && plot->graphCount() != 0) {
		int xpos = event->pos().x();
		int ypos = event->pos().y();

		QCPGraph* graph = nullptr;
		bool graphtyperate = true;
		int index = 0;
		double tvalue = 0;
		//判断是否存在产量轴
		for (int i = 0; i < plot->graphCount(); i++) {
			graph = plot->graph(i);
			if (graph->lineStyle() != QCPGraph::LineStyle::lsStepRight) {
				graphtyperate = false;
				break;
			}
		}
		double xval = plot->xAxis->pixelToCoord(xpos);
		double yval = plot->yAxis->pixelToCoord(ypos);
		double xmin = plot->xAxis->range().lower;
		double xmax = plot->xAxis->range().upper;

		//如果为产量轴
		if (graphtyperate) {
			tvalue = xval;
		}
		else {

			//itemdataline->point1->setCoords(xval, ymin);
			//itemdataline->point2->setCoords(xval, ymax);

			int count = graph->dataCount();
			if (xval <= xmin) {
				index = 0;
			}
			else if (xval >= xmax) {
				index = count - 1;
			}
			else {
				QSharedPointer<QCPGraphDataContainer> graphdata = graph->data();
				QCPDataContainer<QCPGraphData>::const_iterator iterstart = graphdata->findEnd(xval);//迭代器
				//tvalue = graph->dataMainKey(index);
				tvalue = iterstart->key;
			}
			
		}

		QCPAxis* axis = nullptr;
		QString content;
		QString tempcontent;
		QString strvalue;
		QString labeltype;
		labeltype = plot->xAxis->label();

		strvalue = QString::number(tvalue);
		tempcontent = labeltype + s_colon + strvalue;
		tempcontent += s_linefeed;
		content += tempcontent;
		if (axisdatetime && axisdatetime->visible()) {
			strvalue = startdatetime.addSecs(tvalue * 3600).toString(s_datetimeformat);
			tempcontent = s_datetime + s_colon + strvalue;
			tempcontent += s_linefeed;
			content += tempcontent;
		}



		int graphcount = plot->graphCount();
		
		for (int i = 0; i < graphcount; i++) {
			graph = plot->graph(i);

			labeltype = graph->name();
			if (graph->lineStyle() == QCPGraph::LineStyle::lsStepRight) {
				Graph* rategraph = qobject_cast<Graph*>(graph);
				int rateindex = rategraph->getPos(tvalue);
				strvalue = QString::number(graph->dataMainValue(rateindex));
			}
			else {
				QSharedPointer<QCPGraphDataContainer> graphdata = graph->data();
				QCPDataContainer<QCPGraphData>::const_iterator iterstart = graphdata->findEnd(xval);//迭代器
				strvalue = QString::number(iterstart->value);
			}

			tempcontent = labeltype + s_colon + strvalue;

			if (i != graphcount - 1) {
				tempcontent += s_linefeed;
			}
			content += tempcontent;
		}
		QToolTip::hideText();
		QToolTip::showText(event->globalPos(), content, this, rect());
		//plot->replot(QCustomPlot::rpQueuedReplot);

	}

}

void Plot::initAxisValue()
{
	/*Axises axises = getChooseAxis();
	for (int i = 0; i < axises.size(); i++) {
		initAxis(axises[i]);
	}*/
	initAxis(plot->xAxis);
	initAxis(plot->yAxis);
	if (plot->yAxis2->visible()) {
		initAxis(plot->yAxis2);
	}
	plot->replot(QCustomPlot::rpQueuedReplot);
	
}


