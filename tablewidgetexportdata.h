#pragma once
#include<QheaderView>
#include <QTableWidget>
#pragma execution_character_set("utf-8")
#include"ExportPlotDataModel.h"

const int column_type = 0;
const int column_value = 1;
const int column_match = 1;
const int column_export = 1;
const int column_unit = 2;
const int column_initvalue = 3;
const int column_min = 4;
const int column_max = 5;
const int column_precision = 6;
const int column_unitrange = 3;

class TableWidgetExportData  : public QTableWidget
{
	Q_OBJECT

public:
	TableWidgetExportData(QWidget *parent);
	~TableWidgetExportData();

	void setTable(const QStringList&);
	void setExportDataVector();
};
