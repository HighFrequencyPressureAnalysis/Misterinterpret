#pragma once
#include"SingleTemplate.h"
#include<QDateTime>
#include"ConstDataType.h"

class HistoryDateModel
{
	DECLARE_SINGLEON(HistoryDateModel);
public:
	void clear();
	//设置是否显示日期时间
	void setShowDate(const bool);
	//获取是否显示日期时间
	bool getIsShowDate()const;
	//设置历史数据日期时间
	void setTestDateTimeString(const QString&);
	void setFracDateTimeString(const QString&);
	void checkChangeTestTime(DoubleVector&);
	QString getPlotDateString();

	//获取压力产量日期时间字符
	QString getFracDateTimeString(const double&);
	QString getTestDateTimeString(const double&);
private:
	HistoryDateModel();
	~HistoryDateModel();

	bool showdate = false;
	//压力产量日期时间
	QString fracdatetime;
	QString testdatetime;

	QString getDateTimeString(const double&, const QString&);
	
};

