#include "TableViewControler.h"
#include"HistorySettingModel.h"

TableViewControler::TableViewControler()
{
}

TableViewControler::~TableViewControler()
{
}



void TableViewControler::setTableViewLoad(TableViewLoadHistory* p_tableview)
{
	tableviewloadhistory = p_tableview;
}



void TableViewControler::setHeader()
{
	if (tableviewloadhistory) {
		HistorySettingModel* settingmodel = SingleTemplate<HistorySettingModel>::getInstance();
		const QString type = settingmodel->getType();
		const QString unit = settingmodel->getUnit();
		const int column = settingmodel->getColumn();
		tableviewloadhistory->setHeader(type, unit, column);
	}
	
}

