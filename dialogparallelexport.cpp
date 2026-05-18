#include "dialogparallelexport.h"

DialogParallelExport::DialogParallelExport(QWidget *parent)
	: DialogParallel(parent)
{
	setType("导出数据");
	thread.start();
	connect(&thread, SIGNAL(finished()), this, SLOT(close()));
}

DialogParallelExport::~DialogParallelExport()
{
	thread.quit();
}
