#pragma once
#include"SingleTemplate.h"
#include<QStringList>
#include"ConstCharacter.h"
#include"ConstDataType.h"
#include<QDateTime>
#include"ConstDataType.h"
#include<QVariantList>
#include"ConstBasic.h"

class DataProcess
{
	DECLARE_SINGLEON(DataProcess);
public:
	DoubleVector dataTypeChange(const FloatVector&);
	void removeSameData(DoubleVector&);
	void simplyData(DoubleVector& ,const int);
	void changeElapsedTimeToDurationTime(DoubleVector&,DoubleVector&);
	//判断数据相等
	bool isDataVectorEqual(const DoubleVector&, const DoubleVector&);
	bool isCompleteDataVectorEqual(const QVector<double>&, const QVector<double>&);
	//检查索引
	void checkIndex(const QStringList&, QString&);
	//阶段时间与持续时间转换
	void changeDurationToElapsedTime(DoubleVector&);
	void changeElapsedTimeToDuration(DoubleVector&);
	//转换成画图时间
	void changeToPlotData(DoubleVector&, DoubleVector&);
	//转换为持续时间
	bool changeToElapsetime(const QDateTime& initdatetime, const QString&, const QString&, QString&, QString&, double&);
	bool changeToElapsetime(const QDateTime& initdatetime, const QString&, const QString&, double&);
	//判断链表是否有效
	bool isValidVariantList(const QVariantList&);
	//检查导入数据//
	void checkRateVectorMap(DoubleVectorMap&);
	//转换为字符数组
	StringVectorVector changeStringToStringVectorVector(const QString&, int&, int&, bool containscount = false);
	StringVectorVector changeQVariantListToStringVectorVector(const QVariantList&, bool considercount);
	void changeToDeltat(DoubleVector&t);
	
	DoubleVectorMap mergeData(const DoubleVectorMap&, const DoubleVectorMap&);
private:
	DataProcess();
	~DataProcess();

	int findClosestIndex(const QVector<double>& arr, double target);
	DoubleVector getNormalizationData(const DoubleVector&);
	void changeToIntVector(DoubleVector&);
	QVector<double> sliceByIndex(const QVector<double>& src, int startIdx, int endIdx);
};

