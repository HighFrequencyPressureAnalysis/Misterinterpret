#pragma once
#include"ConstDataType.h"
#include "tableview.h"
#include"loadtablemodel.h"
#include<QAxObject>
#include<QMenu>
#include"ConstBasic.h"

//读取历史数据表格

class TableViewLoadHistory : public TableView
{
	Q_OBJECT

public:
	TableViewLoadHistory(QWidget *parent);
	~TableViewLoadHistory();

	//停止读取
	void stopRead();
	//设置行和列
	void setRowAndColumn(const int, const int);
	//设置读取数据
	void setLoadData(const QString&);
	void setStringList(const StringVectorVector&);
	//检查表头
	void checkHeader(QStringList&,int column);
	//设置表头
	void setHeader(const QString&, const QString&, const int);
	//检查表格状态
	bool checkTableState(const QString&edittype);
	//获取表头所有数据类型
	QStringList getHeaderAllDataTypes()const;
	//获取字符形式的表格内容
	StringVectorVector getTableStringVectorVector()const;
	
public slots:
	//设置表格行数和列数
	void setTableRowCount(int);
	void setTableColumnCount(int);
private:
	QMenu *menucolumn;
	LoadTableModel* loaditemmodel;
private slots:
	//显示数据设置窗口
	void showDataSetting(int);
	//清空表头
	void clearHeader();	
	//显示设置窗口
	void columncustomContextMenuRequested(QPoint);
};
