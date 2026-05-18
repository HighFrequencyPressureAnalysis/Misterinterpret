#include "tablewidgetexportdata.h"
#include<QComboBox>
#include<QCheckBox>
#include"ConstCharacter.h"
#include"UnitChange.h"
#include"ConstBasic.h"

TableWidgetExportData::TableWidgetExportData(QWidget *parent)
	: QTableWidget(parent)
{
	QStringList headers;
	headers << "类型" << "是否导出" << "单位";

	int columncount = headers.size();
	setColumnCount(columncount);
	horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	//horizontalHeader()->setSectionResizeMode(columncount - 1, QHeaderView::Stretch);
	setHorizontalHeaderLabels(headers);
}

TableWidgetExportData::~TableWidgetExportData()
{}

void TableWidgetExportData::setTable(const QStringList&types)
{
	setColumnCount(3);
	setRowCount(types.size());
	QString type;
	QString inittype;
	QStringList unittypes;
	QString standardunit;
	UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
	for (int i = 0; i < types.size(); i++) {
		type = types[i];
		QTableWidgetItem* itemtype = new QTableWidgetItem(type);
		setItem(i,column_type, itemtype);
		QCheckBox* checkbox = new QCheckBox();
		checkbox->setChecked(true);
		if (type.contains(s_t)) {
			checkbox->setEnabled(false);
		}
		if (type.contains(s_interval)) {
			inittype = type.split(s_interval).first();
		}
		else {
			inittype = type;
		}
		unittypes = unitchange->getUnits(inittype);
		setCellWidget(i, column_export, checkbox);
		if (!unittypes.isEmpty()) {
			QComboBox* combobox = new QComboBox();
			combobox->addItems(unittypes);
			standardunit = unitchange->getStandardUnit(inittype);
			combobox->setCurrentText(standardunit);
			setCellWidget(i,column_unit, combobox);
		}
		else {
			QTableWidgetItem* unititem = new QTableWidgetItem();
			unititem->setFlags(Qt::ItemIsEditable);
			setItem(i, column_unit, unititem);
		}
		
	}
}

void TableWidgetExportData::setExportDataVector() 
{	
	ExportPlotDataModel* exportplotdatamodel = SingleTemplate<ExportPlotDataModel>::getInstance();
	GraphExportDataVector datavector;
	QString type;
	QString unit;
	for (int i = 0; i < rowCount(); i++) {
		type = item(i, column_type)->text();
		QCheckBox* checkbox = qobject_cast<QCheckBox*>(cellWidget(i, column_export));
		if (checkbox->isChecked()) {
			exportplotdatamodel->addGraphData(type);
			GraphExportData exportdata;
			QComboBox* combobox = qobject_cast<QComboBox*>(cellWidget(i, column_unit));
			if (combobox) {
				unit = combobox->currentText();
			}
			else {
				unit.clear();
			}
			if (!type.contains(s_t)) {
				exportdata.type = type;
				exportdata.unit = unit;
				exportplotdatamodel->setGraphUnit(type, unit);
			}
			else {
				exportplotdatamodel->setTimeUnit(unit);
			}
		}
		
	}
	
}
