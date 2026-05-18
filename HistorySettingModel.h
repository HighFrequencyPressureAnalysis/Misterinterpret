#pragma once
#include"SingleTemplate.h"
#include<QString>

//导入压力数据编辑选择模型

class HistorySettingModel
{	
	DECLARE_SINGLEON(HistorySettingModel);
public:

	void setEditType(const QString&);
	//设置当前设置列
	void setColumn(const int);
	//设置当前数据类型
	void setType(const QString&);
	//设置单位
	void setUnit(const QString&);
	//获取当前列
	int getColumn()const;
	//获取数据类型
	QString getType()const;
	//获取单位
	QString getUnit()const;
	//获取编辑类型
	QString getEditType()const;
private:
	int column;
	QString type;
	QString unit;

	QString edittype;
	HistorySettingModel();
	virtual ~HistorySettingModel();
};

