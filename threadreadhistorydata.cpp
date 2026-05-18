#include"threadreadhistorydata.h"
#include"HistoryLoadDataModel.h"

ThreadReadHistoryData::ThreadReadHistoryData(QObject *parent)
	: QThread(parent)
{
	
}

ThreadReadHistoryData::~ThreadReadHistoryData()
{
}

void ThreadReadHistoryData::setMaxRowcount()
{
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	rowcount = historyloaddatamodel->getReadMaxRowCount();
	emit sendMaxIter(rowcount);
}

void ThreadReadHistoryData::startRead()
{
	stop = false;
}

void ThreadReadHistoryData::stopThread()
{
	stop = true;
	
}

void ThreadReadHistoryData::run()
{	
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	for (int i = 0; i < rowcount; i++) {
		historyloaddatamodel->readDataToVectorMap(i);
		if (stop) {
			historyloaddatamodel->clearVectormap();
			break;
		}else {
			emit sendReadProgress(i+1);
		}
	}
	msleep(1000);
}
