#pragma once
#include "tableview.h"
#include<QStandardItemModel>
#include"ConstDataType.h"
#pragma execution_character_set("utf-8")


class TableViewPerpos  : public TableView
{
	Q_OBJECT

public:
	TableViewPerpos(QWidget *parent);
	~TableViewPerpos();

	int getCurrentCount()const;
	void setRowCount(const int);
	void setRowCount(const int, const int);
	void showPerData(const DoubleVector&);
	DoubleVector getPerData()const;
};
