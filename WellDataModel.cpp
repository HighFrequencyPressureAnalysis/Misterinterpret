#include "WellDataModel.h"

DataModelFracBasic::DataModelFracBasic()
{}

DataModelFracBasic::~DataModelFracBasic()
{}

void DataModelFracBasic::setData(const DataMap&d_datamap, const StringMap&s_stringmap)
{
	datamap = d_datamap;
	stringmap = s_stringmap;
}

void DataModelFracBasic::getData(DataMap&d_datamap, StringMap&s_stringmap)
{
	d_datamap = datamap;
	s_stringmap = stringmap;
}



QDataStream& operator<<(QDataStream&out, const DataModelFracBasic&model)
{	
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		out << model.datamap;
		out<< model.stringmap;
		return out;
	}
	else {
		return out;
	}
	
}

QDataStream& operator>>(QDataStream&in, DataModelFracBasic&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		return in >> model.datamap >> model.stringmap;
	}
	else {
		return in;
	}
	
}

QDataStream& operator<<(QDataStream&out, const DataModelFracPer&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		out << model.bgvalue;
		out << model.perdata;
		return out;
	}
	else {
		return out;
	}
}

QDataStream& operator>>(QDataStream&in, DataModelFracPer&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		return in >> model.bgvalue >> model.perdata;
	}
	else {
		return in;
	}
}



DataModelFracPer::DataModelFracPer()
{}

DataModelFracPer::~DataModelFracPer()
{}

void DataModelFracPer::setData(const double&d_bgvalue, const DoubleVector&v_perdata)
{
	bgvalue = d_bgvalue;
	perdata = v_perdata;
}

void DataModelFracPer::getData(double&d_bg, DoubleVector&v_perdata)
{
	d_bg = bgvalue;
	v_perdata = perdata;
}

DataModelFracOpera::DataModelFracOpera()
{}

DataModelFracOpera::~DataModelFracOpera()
{}

void DataModelFracOpera::setData(const QString&s_datatime, const DoubleVectorMap&v_vectormap)
{
	datetime=s_datatime;
	vectormap=v_vectormap;
}

void DataModelFracOpera::getData(QString&s_datetime, DoubleVectorMap&v_vectormap)
{
	v_vectormap=vectormap;
	s_datetime=datetime;
}

QDataStream& operator<<(QDataStream&out, const DataModelFracOpera&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		out << model.datetime;
		out << model.vectormap;
		return out;
	}
	else {
		return out;
	}
}

QDataStream& operator>>(QDataStream&in, DataModelFracOpera&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		return in >> model.datetime >> model.vectormap;
	}
	else {
		return in;
	}
}

DataModelFracTest::DataModelFracTest()
{}

DataModelFracTest::~DataModelFracTest()
{}

void DataModelFracTest::setData(const QString& s_datatime, const DoubleVectorMap& v_vectormap)
{
	datetime = s_datatime;
	vectormap = v_vectormap;
}

void DataModelFracTest::getData(QString& s_datetime, DoubleVectorMap& v_vectormap)
{
	v_vectormap = vectormap;
	s_datetime = datetime;
}

QDataStream& operator<<(QDataStream& out, const DataModelFracTest& model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		out << model.datetime;
		out << model.vectormap;
		return out;
	}
	else {
		return out;
	}
}

QDataStream& operator>>(QDataStream& in, DataModelFracTest& model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		return in >> model.datetime >> model.vectormap;
	}
	else {
		return in;
	}
}

QDataStream& operator<<(QDataStream&out, const DataModelFracWH&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		out << model.freq;
		out << model.whpress;
		return out;
	}
	else {
		return out;
	}
}

QDataStream& operator>>(QDataStream&in, DataModelFracWH&model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		return in >> model.freq >> model.whpress;
	}
	else {
		return in;
	}
}



DataModelFracWH::DataModelFracWH()
{}

DataModelFracWH::~DataModelFracWH()
{}

void DataModelFracWH::setData(const int&i_freq, const DoubleVector&vp)
{
	freq = i_freq;
	whpress = vp;
}

void DataModelFracWH::getData(int&i_freq, DoubleVector&vp)
{
	i_freq=freq;
	vp=whpress;
}

DataModelFracMerge::DataModelFracMerge()
{}

DataModelFracMerge::~DataModelFracMerge()
{}

void DataModelFracMerge::setData(const DoubleVector&vt, const DoubleVector&vp)
{
	t = vt;
	p = vp;
}

void DataModelFracMerge::getData(DoubleVector&vt, DoubleVector&vp)
{
	vt = t;
	vp = p;
}

QDataStream& operator<<(QDataStream& out, const DataModelFracMerge& model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		out << model.t;
		out << model.p;
		return out;
	}
	else {
		return out;
	}
}

QDataStream& operator>>(QDataStream& in, DataModelFracMerge& model)
{
	AppVersion* appversion = SingleTemplate<AppVersion>::getInstance();
	if (appversion->getAppVersion() == appversion->getVersion()) {
		return in >> model.t >> model.p;
	}
	else {
		return in;
	}
}
