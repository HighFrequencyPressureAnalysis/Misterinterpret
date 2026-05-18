#pragma once
#include"SingleTemplate.h"
#include"ConstDataType.h"
#include<QDateTime>
#include"ConstDataType.h"
#include<QVariantList>

enum LoadHistoryDataType
{
	excel,
	txt,
	clipboard,
	table,
};

class HistoryLoadDataModel
{
	DECLARE_SINGLEON(HistoryLoadDataModel);
public:
	//设置编辑类型
	void setEditType(const QString&);
	//设置是否读取
	void setRead(bool);
	//设置导入历史数据的方式
	void setLoadHistoryDataType(LoadHistoryDataType);
	//设置输入文本数据
	void setText(const QString&);
	//设置EXCEL输入数据
	void setVariantList(const QVariantList&);
	//清理所有数据
	void clear();
	//清空读取向量
	void clearVectormap();
	//设置表格字符数据
	void setStringVectorVector(const StringVectorVector&);
	//设置日期时间
	void setDateTime(const QDateTime&);
	//获取表头所有数据类型
	void setHeaderDataTypes(const QStringList&types);
	//读取数据
	void readDataToVectorMap(const int);
	//判断是否通过表格导入数据
	bool isTableLoadData()const;
	int getReadMaxRowCount();
	//获取读取结果
	DoubleVectorMap getVectorMap()const;
	void setRateTimeType(const QString&);
	QString getRateTimeType()const;
private:
	
	HistoryLoadDataModel();
	~HistoryLoadDataModel();
	bool isread;
	LoadHistoryDataType historyloadtype;
	QString text;
	QVariantList varlist;
	StringVectorVector stringvectorvector;
	QDateTime initdatetime;
	QStringList headerdatatypes;
	DoubleVectorMap vectormap;
	QStringList types;
	IntDataMap intdatamap;
	StringMap unitmap;
	QStringList nontimetypes;
	QString edittype;
	QString ratetimetype;
	bool changeqt=false;
	int count;
	int maxcolumncount=0;
};

