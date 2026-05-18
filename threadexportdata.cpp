#include "threadexportdata.h"
#include"ExportPlotDataModel.h"

ThreadExportData::ThreadExportData(QObject *parent)
	: QThread(parent)
{}

ThreadExportData::~ThreadExportData()
{}

void ThreadExportData::run()
{
	ExportPlotDataModel* exportplotdatamodel = SingleTemplate<ExportPlotDataModel>::getInstance();
	exportplotdatamodel->exportData();
	msleep(1000);
	quit();
}