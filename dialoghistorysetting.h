#pragma once

#include <QDialog>
#include "ui_dialoghistorysetting.h"

//历史数据窗口设置//

class DialogHistorySetting : public QDialog
{
	Q_OBJECT

public:
	DialogHistorySetting(const QStringList&,QWidget *parent = Q_NULLPTR);
	~DialogHistorySetting();

private:
	Ui::DialogHistorySetting ui;
private slots:
	//设置单位类型
	void setUnitType(const QString&);	
	//设置数据类型
	void setDataType();								
};
