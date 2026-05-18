#pragma once
#include<QButtonGroup>
#include <QDialog>
#include "ui_dialogloaddata.h"
#include<qaxobject.h>

class DialogLoadData : public QDialog
{
	Q_OBJECT

public:
	DialogLoadData(const QString&,QWidget *parent = nullptr);
	~DialogLoadData();

private:
	Ui::DialogLoadDataClass ui;
	QButtonGroup* buttongrouploadtype;
	QButtonGroup* buttongroupchoosetype;
	
	QString type;
	QButtonGroup* buttongroup;
	QAxObject* excel = nullptr;
	QAxObject* workbook = nullptr;

	//设置表格是否可以编辑//
	void setTableEditable(bool);
	//发送TXT数据//
	void sendTxtData();
	//发送EXCEL数据//
	void sendExcelData();
	//发送剪切板数据
	void sendClipboardData();
	//加载历史数据//
	void loadData();
	//读取EXCEL数据//
	void readExcelData();
	//显示通过表格设置数据
	void showTableLoad();
	
	//是否安装excel读取软件
	bool isExcelInstalled();
	bool isWpsInstalled();
private slots:
	//设置初始导入方式
	
	//设置数据导入类型//
	void setLoadType();
	//读取EXCEL数据//
	void readExcelSheet(int);
	
	

	
};
