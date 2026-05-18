#pragma once
#include"ConstDataType.h"
#include<qdatastream.h>
#include"AppVersion.h"
#include<QFile>

class DataModelFracBasic
{
public:
	DataModelFracBasic();
	~DataModelFracBasic();

	void setData(const DataMap&, const StringMap&);
	void getData(DataMap&, StringMap&);
	friend QDataStream& operator<<(QDataStream&, const DataModelFracBasic&);
	friend QDataStream& operator>>(QDataStream&, DataModelFracBasic&);
private:
	DataMap datamap;
	StringMap stringmap;
	
};

class DataModelFracPer
{
public:
	DataModelFracPer();
	~DataModelFracPer();

	void setData(const double&, const DoubleVector&);
	void getData(double&, DoubleVector&);
	friend QDataStream& operator<<(QDataStream&, const DataModelFracPer&);
	friend QDataStream& operator>>(QDataStream&, DataModelFracPer&);
private:
	double bgvalue;
	DoubleVector perdata;

};

class DataModelFracOpera
{
public:
	DataModelFracOpera();
	~DataModelFracOpera();

	void setData(const QString&, const DoubleVectorMap&);
	void getData(QString&, DoubleVectorMap&);
	friend QDataStream& operator<<(QDataStream&, const DataModelFracOpera&);
	friend QDataStream& operator>>(QDataStream&, DataModelFracOpera&);
private:
	QString datetime;
	DoubleVectorMap vectormap;

};

class DataModelFracTest
{
public:
	DataModelFracTest();
	~DataModelFracTest();

	void setData(const QString&, const DoubleVectorMap&);
	void getData(QString&, DoubleVectorMap&);
	friend QDataStream& operator<<(QDataStream&, const DataModelFracTest&);
	friend QDataStream& operator>>(QDataStream&, DataModelFracTest&);
private:
	QString datetime;
	DoubleVectorMap vectormap;

};

class DataModelFracWH
{
public:
	DataModelFracWH();
	~DataModelFracWH();

	void setData(const int&, const DoubleVector&);
	void getData(int&, DoubleVector&);
	friend QDataStream& operator<<(QDataStream&, const DataModelFracWH&);
	friend QDataStream& operator>>(QDataStream&, DataModelFracWH&);
private:
	int freq;
	DoubleVector whpress;

};


class DataModelFracMerge
{
public:
	DataModelFracMerge();
	~DataModelFracMerge();

	void setData(const DoubleVector&, const DoubleVector&);
	void getData(DoubleVector&, DoubleVector&);
	friend QDataStream& operator<<(QDataStream&, const DataModelFracMerge&);
	friend QDataStream& operator>>(QDataStream&, DataModelFracMerge&);
private:
	DoubleVector t;
	DoubleVector p;

};

