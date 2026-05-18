#pragma once
#include "tablemodel.h"
#include"ConstDataType.h"
#include<QAxObject>

//导入数据表格模型

class LoadTableModel : public TableModel
{
	Q_OBJECT

public:
	LoadTableModel(QObject *parent=nullptr);
	~LoadTableModel();

	//停止读取
	void stopRead();
	//设置行数
	void setRowCount(const int);
	//设置列数
	void setColumnCount(const int);
	//设置行数和列数
	void setRowAndColumn(const int, const int);
	//设置加载数据
	void setLoadData(const QString&);
	//设置加载数据向量
	void setStringList(const StringVectorVector&);
	//更新模型
	void updateModel();
	//设置表头
	void setHeader(const int, const QString&);
	//清理指定表头
	void clearAppointHeader(const int);
	//获取当前数据类型
	QString getCurrentType(const int);
	//获取表格内容字符形式
	StringVectorVector getTableStringVectorVector()const;
	//获取数据类型
	QStringList getDataTypes()const;
	//获取表头所有数据类型
	QStringList getAllDataTypes()const;
protected:
	//设置数据
	bool setData(const QModelIndex& index, const QVariant& value, int role /* = Qt::EditRole */);
	//获取行数和列数
	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;
	//获取数据
	QVariant data(const QModelIndex& index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	Qt::ItemFlags flags(const QModelIndex& index)const;
private:
	bool editable = false;
	bool isread = true;
	int rowcount = 0;
	int columncount = 0;
	StringVectorVector loaddata;
	StringVector headertypes;
	
};
