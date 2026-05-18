#pragma once
#include"readonlydelegate.h"
#include"numberitemdelegate.h"
#include <QTableView>
#include<QStandardItemModel>
#include<QHeaderView>
#include"ConstDataType.h"
#pragma execution_character_set("utf-8")

class TableView  : public QTableView
{
	Q_OBJECT
signals:
	void sendSelectSignal(const IntVector&);
public:
	TableView(QWidget *parent=nullptr);
	~TableView();

	//基础设置
	void addSelectConnect();

	void initTable();
	void setHorizontalHeaderTypes(const QStringList&);
	void setVerticalHeaderTypes(const QStringList&);
	void setHorizontalHeaderVisible(bool visible);
	void setVerticalHeaderVisible(bool visible);
	void setRowAndColumnCount(const int, const int);
	//设置当前列不可以编辑
	void setTableEditUnable();
	void setColumnEditUnable(const int column);
	void setRowEditUnable(const int row);
	//设置当前列只能为数字
	void setNumberColumn(const int column);
	IntVector getSelectRows()const;
protected:
	QStandardItemModel* model=nullptr;
	//获取选择行
	
private slots:
	void sendSelectRange(const QItemSelection&, const QItemSelection&);
};
