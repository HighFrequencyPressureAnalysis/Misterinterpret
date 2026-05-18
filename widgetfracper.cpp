#include "widgetfracper.h"

WidgetFracPer::WidgetFracPer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	int a = 0;
	ui.doubleSpinBoxbg->setMaximum(10000.0);
	connect(ui.spinBox, SIGNAL(valueChanged(int)), this, SLOT(resetTableView()));
	QStringList charatypes;
	charatypes << s_interval << s_wave;
	ui.comboBoxsymbol->addItems(charatypes);
	connect(ui.toolButtonload, &QToolButton::clicked, this, &WidgetFracPer::loadClipData);

}

WidgetFracPer::~WidgetFracPer()
{}

void WidgetFracPer::setGroupVisible(bool visible)
{
	ui.groupBoxper->setVisible(visible);
}

void WidgetFracPer::setData(const double&bgvalue, const DoubleVector&perdata)
{
	ui.doubleSpinBoxbg->setValue(bgvalue);
	showData(perdata);
}

void WidgetFracPer::showData(const DoubleVector& perdatavector)
{
	ui.spinBox->setValue(0);
	ui.spinBox->setValue(perdatavector.size());
	ui.tableviewperpos->showPerData(perdatavector);
}

void WidgetFracPer::setDefaultRowCount()
{
	int count = ui.spinBox->value();
	ui.tableviewperpos->setRowCount(0, count);
}

void WidgetFracPer::getData(DoubleVector& perdatavector,double&bgvalue)
{
	perdatavector = ui.tableviewperpos->getPerData();
	bgvalue = ui.doubleSpinBoxbg->value();
}

void WidgetFracPer::clearTable()
{
	ui.tableviewperpos->setRowCount(0);
}

void WidgetFracPer::loadClipData()
{
	QClipboard* board = QApplication::clipboard();
	QString content = board->text();
	QStringList temploaddata = content.split(s_linefeed);
	temploaddata.removeAll("");
	QString chara = ui.comboBoxsymbol->currentText();
	DoubleVector datavector;
	for (int i = 0; i < temploaddata.size(); i++) {
		QStringList tempdata = temploaddata[i].split(chara);
		if (tempdata.size()) {
			datavector.push_back(tempdata.first().toDouble());
		}
	}
	int count = datavector.size();
	if (count) {
		ui.spinBox->setValue(count);
		ui.tableviewperpos->showPerData(datavector);
	}

}


void WidgetFracPer::resetTableView()
{
	int count = ui.spinBox->value();
	int currentcount = ui.tableviewperpos->getCurrentCount();
	if (currentcount > count) {
		ui.tableviewperpos->setRowCount(count);
	}
	else {
		ui.tableviewperpos->setRowCount(currentcount, count);
	}
}