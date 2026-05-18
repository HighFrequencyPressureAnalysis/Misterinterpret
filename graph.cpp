#include "graph.h"


Graph::Graph(QCPAxis*keyaxis,QCPAxis* valueaxis)
	: QCPGraph(keyaxis,valueaxis)
{
}

Graph::~Graph()
{
}


void Graph::getRangeData(const double lower, const double upper, QVector<double>&x, QVector<double>&y)
{
	
	for (int i = 0; i < dataCount(); i++) {
		if (dataMainKey(i) >= lower && dataMainKey(i) <= upper) {
			x.push_back(dataMainKey(i));
			y.push_back(dataMainValue(i));
		}
		if (dataMainKey(i) > upper){
			break;
		}
	}
}

double Graph::getValue(const double key)
{	
	int datacount = dataCount();
	double minkey = dataMainKey(0);
	double maxkey = dataMainValue(datacount - 1);
	double value = 0;
	if (key < minkey) {
		value = dataMainValue(0);
	}else if (key > maxkey) {
		value = dataMainValue(datacount-1);
	}else {
		for (int i = 0; i < dataCount(); i++) {
			if (dataMainKey(i) > key) {
				value = dataMainValue(i);
				break;
			}
		}
	}
	return value;
}

double Graph::getLeftValue()
{	
	double value = -1;
	double nvalue = 0;
	int index = 0;
	for (int i = 1; i < dataCount(); i++) {
		nvalue = dataMainValue(i);
		if (value>=nvalue){
			index = i - 1;
			break;
		}
		value = nvalue;
	}
	return dataMainKey(index);
}

double Graph::getRigetValue()
{
	double value = -1;
	double nvalue = 0;
	int index = 0;
	for (int i = dataCount()-1; i >0; i--) {
		nvalue = dataMainValue(i);
		if (value >= nvalue) {
			index = i + 1;
			break;
		}
		value = nvalue;
	}
	return dataMainKey(index);
}

int Graph::getPos(const double value)const
{	
	int pos=dataCount()-1;
	for (int i = 0; i < dataCount(); i++) {
		if(value<=dataMainKey(i)){	
			pos = i;
			break;
		}
	}
	return pos;
}





double Graph::getKeyLower()const
{	
	bool foundrange = true;
	return getKeyRange(foundrange).lower;
}

double Graph::getKeyUpper()const
{
	bool foundrange = true;
	return getKeyRange(foundrange).upper;
}

double Graph::getValueLower()const
{
	bool foundrange = true;
	return getValueRange(foundrange).lower;
}

double Graph::getValueUpper()const
{
	bool foundrange = true;
	return getValueRange(foundrange).upper;
}

QVector<int> Graph::getChooseKeyData(const QCPRange&range)const
{
	QVector<int>rows(2);
	int count = 0;
	for (int i = 0; i < dataCount(); i++) {
		if (dataMainKey(i) >= range.lower&&dataMainKey(i) <= range.upper) {
			if (count == 0) {
				rows.first() = i;
			}
			count++;
		}
		if (dataMainKey(i) > range.upper) {
			break;
		}
	}
	rows.last() = rows.first() + count - 1;
	return rows;
}

QVector<int> Graph::getChooseValueData(const QCPRange&range)const
{
	QVector<int>rows(2);
	int count = 0;
	for (int i = 0; i < dataCount(); i++) {
		if (dataMainValue(i) >= range.lower&&dataMainValue(i) <= range.upper) {
			if (count == 0) {
				rows.first() = i;
			}
			if (dataMainValue(i) > range.upper) {
				break;
			}
			count++;
		}
	}
	rows.last() = rows.first() + count - 1;
	return rows;
}

QVector<double> Graph::getChooseTime(double pos)
{
	QVector<double>time(2);
	for (int i = 1; i < dataCount(); i++) {
		if (pos <= dataMainKey(i)) {
			time.first() = dataMainKey(i - 1);
			time.last() = dataMainKey(i);
			break;
		}
	}
	return time;
}

QVector<double> Graph::getValueData(const QVector<double>&range)const
{
	QVector<double>data;
	for (int i = 0; i < dataCount(); i++) {
		if (range.isEmpty()) {
			data.push_back(dataMainValue(i));
		}else {
			if (dataMainKey(i) >= range.first() && dataMainKey(i) <= range.last()) {
				data.push_back(dataMainValue(i));
			}
		}
	}
	return data;
}

QVector<double> Graph::getTimeData(const QVector<double>&range)const
{
	QVector<double>data;
	for (int i = 0; i < dataCount(); i++) {
		if (range.isEmpty()) {
			data.push_back(dataMainKey(i));
		}
		else {
			if (dataMainKey(i) >= range.first() && dataMainKey(i) <= range.last()) {
				data.push_back(dataMainKey(i));
			}
		}
	}
	return data;
}

QVector<int> Graph::getTimeIndex(const QVector<double>&time)const
{	
	QVector<int>timeindex;
	bool init = true;
	for (int i = 0; i < dataCount(); i++) {
		if (dataMainKey(i) >= time.first()&&init) {
			timeindex.push_back(i);
			init = false;
		}
		if (dataMainKey(i) >= time.last()) {
			timeindex.push_back(i);
			break;
		}
	}
	return timeindex;
}