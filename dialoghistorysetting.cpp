#include "dialoghistorysetting.h"
#include"UnitChange.h"
#include"ConstBasic.h"
#include"HistorySettingModel.h"
#include"TableViewControler.h"

DialogHistorySetting::DialogHistorySetting(const QStringList&datatype,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle("设置数据类型");
	setAttribute(Qt::WA_DeleteOnClose);
	ui.comboBoxtype->addItems(datatype);
	ui.comboBoxtype->setCurrentIndex(-1);
	connect(ui.comboBoxtype, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(setUnitType(const QString&)));
	ui.comboBoxtype->setCurrentIndex(0);
	connect(ui.pushButtonsure, &QPushButton::clicked, this, &DialogHistorySetting::setDataType);
}

DialogHistorySetting::~DialogHistorySetting()
{
}

void DialogHistorySetting::setUnitType(const QString&type)
{
	ui.comboBoxunit->clear();
	QStringList units;
	QString unit;
	UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
	if (type != s_undefined) {
		units = unitchange->getUnits(type);
		unit = unitchange->getStandardUnit(type);
	}
	
	ui.comboBoxunit->addItems(units);
	ui.comboBoxunit->setCurrentText(unit);
}

void DialogHistorySetting::setDataType()
{
	HistorySettingModel* settingmodel = SingleTemplate<HistorySettingModel>::getInstance();
	settingmodel->setType(ui.comboBoxtype->currentText());
	settingmodel->setUnit(ui.comboBoxunit->currentText());
	TableViewControler* tableviewcontroler = SingleTemplate<TableViewControler>::getInstance();
	tableviewcontroler->setHeader();
	close();
}