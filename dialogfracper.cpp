#include "dialogfracper.h"
#include"WellDataControler.h"

DialogFracPer::DialogFracPer(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle("…‰ø◊Œª÷√…Ë÷√");
	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	double bgvalue;
	DoubleVector perdata;
	welldatamanager->getFracPerData(bgvalue, perdata);
	if (!perdata.isEmpty()) {
		ui.widget->setData(bgvalue, perdata);
	}
	setMinimumHeight(600);
	connect(ui.pushButtonsure, &QPushButton::clicked, this, &DialogFracPer::loadPerData);
	connect(ui.pushButtonclose, &QPushButton::clicked, this, &DialogFracPer::close);
}

DialogFracPer::~DialogFracPer()
{}


void DialogFracPer::loadPerData()
{
	double bgvalue;
	DoubleVector datavector;
	ui.widget->getData(datavector,bgvalue);
	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	welldatamanager->setPerData(bgvalue, datavector);
	close();
}
