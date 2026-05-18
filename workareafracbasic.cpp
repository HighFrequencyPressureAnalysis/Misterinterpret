#include "workareafracbasic.h"
#include"WellDataControler.h"
#include"HistoryDateModel.h"

WorkAreaFracBasic::WorkAreaFracBasic(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	WellDataManager* welldatamanger = SingleTemplate<WellDataManager>::getInstance();
	welldatamanger->setWorkAreaBasic(this);
	
	ui.widgetper->setGroupVisible(false);
	ui.widgetfracbasic->setLocked(true);
	
}

WorkAreaFracBasic::~WorkAreaFracBasic()
{}

void WorkAreaFracBasic::renewFracBasicData(const DataMap&datamap, const StringMap&stringmap)
{
	ui.widgetfracbasic->setData(datamap, stringmap);
}

void WorkAreaFracBasic::renewFracPerData(const double&bgvalue, const DoubleVector&perdata)
{
	ui.widgetper->setData(bgvalue, perdata);
}

void WorkAreaFracBasic::renewFracOperaData(const QString&sdatetime,const DoubleVectorMap&data)
{
	HistoryDateModel* datemodel = SingleTemplate<HistoryDateModel>::getInstance();
	datemodel->setFracDateTimeString(sdatetime);
	ui.plotopera->setDateTime(sdatetime);
	ui.plotopera->drawOperaGraph(data);
}

void WorkAreaFracBasic::renewFracTestData(const QString&datetime, const DoubleVectorMap&data)
{
	HistoryDateModel* datemodel = SingleTemplate<HistoryDateModel>::getInstance();
	datemodel->setTestDateTimeString(datetime);
	DoubleVectorMap plotdata = data;
	datemodel->checkChangeTestTime(plotdata[s_t]);
	ui.plotopera->drawTestGraph(plotdata);
}

void WorkAreaFracBasic::renewFracWHData(const int&freq, const DoubleVector&vp)
{
	ui.plotwh->drawPressGraph(freq, vp);
}

void WorkAreaFracBasic::renewFracMergeData(const DoubleVector&t, const DoubleVector&p)
{
	ui.plotopera->drawMergeGraph(t, p);
}



void WorkAreaFracBasic::clear()
{
	ui.widgetfracbasic->setDefault();
	ui.widgetper->clearTable();
	ui.plotopera->clearPlot();
	ui.plotopera->setGraphNull();
	ui.plotwh->clearPlot();
	ui.plotwh->setGraphNull();
}


