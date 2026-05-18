#pragma once
#include"SingleTemplate.h"
#include"ConstDataType.h"
#include"ConstCharacter.h"
#include"ConstUnit.h"

class UnitChange
{
	DECLARE_SINGLEON(UnitChange);
public:
	//单个参数单位换算
	void changeUnitValue(const QString&, const QString&, const QString&, double&);
	//数组值单位换算
	void changeUnitVector(const QString&, const QString&, const QString&, QVector<double>&);
	//检查单位是否为标准单位
	void checkStandardVector(const QString&, const QString&, QVector<double>&);
	void checkStandardValue(const QString& type, const QString& unit, double& value);
	//转换为表格单位数据
	void checkTableVector(const QString&, const QString&, QVector<double>&);
	void checkTableValue(const QString& type, const QString& unit, double& value);
	//获取单位换算系数
	double getChangeFactor(const QString&, const QString&, const QString&);
	double getChangeFactor(const QString& type, const QString& unit);
	//获取标准单位
	QString getStandardUnit(const QString&);
	//获取单位类型
	QStringList getUnits(const QString&);
	QStringList getUnitParaTypes()const;
	StringDataMap getUnitChangeMap()const;
	QString getPlotAxisLabel(const QString&);
	//根据当前值进行单位换算
	void changeStandardunitToCurrentUnit(const QString&, const QString&, double&);
private:
	UnitChange();
	~UnitChange();
	StringMap standardunitmap;
	StringDataMap unitchangemap;

	//转换温度单位
	void changeTempratureUnit(const QString&, const QString&, double&);
};

