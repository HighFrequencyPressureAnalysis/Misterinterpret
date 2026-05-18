#pragma once

#include <QAbstractTableModel>

//数据表格基类

class TableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	TableModel(QObject *parent=nullptr);
	~TableModel();
	
	//设置表头
	void setHeaderTypes(const QStringList&);
	//更新表格
	void updateModel();
	//设置索引
	void setIndex(const QString&);
	//改变单位
	void changeUnit();
	//清理模型
	void clearModel();
	//获取行数和列数
	virtual int rowCount(const QModelIndex&parent = QModelIndex())const=0;
	virtual int columnCount(const QModelIndex&parent = QModelIndex())const=0;
	//获取数据
	virtual QVariant data(const QModelIndex& index, int role /* = Qt::DisplayRole */)const=0;
	//获取表头
	QVariant headerData(int section, Qt::Orientation orientation, int role /* = Qt::DisplayRole */)const;
protected:
	QString dataindex;
	QStringList headertypes;
};
