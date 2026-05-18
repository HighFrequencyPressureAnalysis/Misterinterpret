#include "dialogfracbasic.h"
#include"WellDataControler.h"

DialogFracBasic::DialogFracBasic(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("Ñ¹ÁÑ»ù´¡ÐÅÏ¢");
	ui.widget->setCalDataVisible(false);
	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	DataMap datamap;
	StringMap stringmap;
	welldatamanager->getFracBasicData(datamap, stringmap);
	if (!datamap.isEmpty() && !stringmap.isEmpty()) {
		ui.widget->setData(datamap, stringmap);
	}

	connect(ui.pushButtonsure, &QPushButton::clicked, this, &DialogFracBasic::sureData);
	connect(ui.pushButtonclose, &QPushButton::clicked, this, &DialogFracBasic::close);
	
}

DialogFracBasic::~DialogFracBasic()
{}



void DialogFracBasic::sureData()
{
	DataMap datamap = ui.widget->getDataMap();
	StringMap stringmap = ui.widget->getStringMap();
	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	welldatamanager->setFracBasicData(datamap, stringmap);
	close();
}

