#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include "ui_dialogexportplotdata.h"
#include<QButtonGroup>

const QString s_filemanager = "文件管理";
const QString s_txt = "txt文件";
const QString s_excel = "excel文件";
const QString s_file = "文件";
const QString s_clipboard = "剪切板";

class DialogExportPlotData : public QDialog
{
	Q_OBJECT

public:
	DialogExportPlotData(QWidget *parent = nullptr);
	~DialogExportPlotData();

private:
	Ui::DialogExportPlotDataClass ui;
	QButtonGroup* buttongroupsavetype;
	QButtonGroup* buttongroupfiletype;

	QString getFileName(const QString&);
private slots:
	void setSaveType();
	void setSaveTxtPath();
	void setSaveExcelPath();
	void setSaveFileType();
	bool exportData();
};
