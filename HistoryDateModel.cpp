#include "HistoryDateModel.h"
#include"ConstUnit.h"

HistoryDateModel::HistoryDateModel()
{
}

HistoryDateModel::~HistoryDateModel()
{
}

QString HistoryDateModel::getDateTimeString(const double&t, const QString&s_datetime) 
{	
	QDateTime datetime = QDateTime::fromString(s_datetime, s_datetimeformat);
	return datetime.addSecs(t * 60 * 60).toString(s_datetimeformat);
}

void HistoryDateModel::clear()
{
	fracdatetime.clear();
	testdatetime.clear();
}

void HistoryDateModel::setShowDate(const bool b_showdate)
{
	showdate = b_showdate;
}

bool HistoryDateModel::getIsShowDate() const
{
	return showdate;
}

void HistoryDateModel::setTestDateTimeString(const QString&datetime)
{
	testdatetime = datetime;
}

void HistoryDateModel::setFracDateTimeString(const QString&datetime)
{
	fracdatetime = datetime;
}

void HistoryDateModel::checkChangeTestTime(DoubleVector&t)
{
	if (!fracdatetime.isEmpty()) {
		const double muti = 3600;
		if (fracdatetime != testdatetime) {
			QDateTime dfracdatetime=QDateTime::fromString(fracdatetime,s_datetimeformat);
			QDateTime dtestdatetime = QDateTime::fromString(testdatetime, s_datetimeformat);
			double value = dtestdatetime.secsTo(dfracdatetime) / muti;
			if (value) {
				for (int i = 0; i < t.size(); i++) {
					t[i] -= value;
				}
			}
		}
		
	}
}

QString HistoryDateModel::getPlotDateString()
{	
	if (!fracdatetime.isEmpty()) {
		return fracdatetime;
	}else {
		return testdatetime;
	}
}

QString HistoryDateModel::getFracDateTimeString(const double&t) 
{
	return getDateTimeString(t, fracdatetime);
}

QString HistoryDateModel::getTestDateTimeString(const double&t) 
{
	return getDateTimeString(t,testdatetime);
}

