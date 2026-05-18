#pragma once
#include"threadexportdata.h"
#include "dialogparallel.h"

class DialogParallelExport  : public DialogParallel
{
	Q_OBJECT

public:
	DialogParallelExport(QWidget *parent=nullptr);
	~DialogParallelExport();
private:
	ThreadExportData thread;
};
