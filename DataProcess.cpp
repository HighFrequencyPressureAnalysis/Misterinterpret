#include "DataProcess.h"
#include"ConstUnit.h"



DataProcess::DataProcess()
{
}

DataProcess::~DataProcess()
{
}



int DataProcess::findClosestIndex(const QVector<double>& arr, double target)
{
	if (arr.isEmpty()) return -1;

	int closestIdx = 0;
	double minDiff = fabs(arr[0] - target);

	for (int i = 1; i < arr.size(); ++i)
	{
		double diff = fabs(arr[i] - target);
		if (diff < minDiff)
		{
			minDiff = diff;
			closestIdx = i;
		}
	}
	return closestIdx;
}

DoubleVector DataProcess::getNormalizationData(const DoubleVector&data)
{
	auto max = std::max_element(std::begin(data), std::end(data));
	//最小值表示：
	auto min = std::min_element(std::begin(data), std::end(data));
	//直接赋值表示
	double biggest = *max;
	double smallest = *min;
	double deltavalue = biggest - smallest;
	DoubleVector nordata;
	for (int i = 0; i < data.size(); i++) {
		nordata.push_back((data[i] - smallest) / deltavalue);
	}
	return nordata;
}

void DataProcess::changeToIntVector(DoubleVector&data)
{	
	double value = 0;
	int value1, value2;
	double delta1, delta2;
	for (int i = 0; i < data.size(); i++) {
		value = data[i];
		value1 = ceil(value);
		value2 = floor(value);
		delta1 = fabs(value - value1);
		delta2 = fabs(value - value2);
		if (delta1 <= delta2) {
			data[i] = value1;
		}
		else {
			data[i] = value2;
		}
	}
}

QVector<double> DataProcess::sliceByIndex(const QVector<double>& src, int startIdx, int endIdx)
{
	if (startIdx < 0) startIdx = 0;
	if (endIdx >= src.size()) endIdx = src.size() - 1;
	if (startIdx > endIdx) return {};

	return src.mid(startIdx, endIdx - startIdx + 1);
}

DoubleVector DataProcess::dataTypeChange(const FloatVector&floatVector)
{
	DoubleVector doubleVector;

	// 使用 std::transform 将 QVector<float> 中的元素转换为 double 并添加到 QVector<double> 中
	std::transform(floatVector.begin(), floatVector.end(), std::back_inserter(doubleVector), [](float f) { return static_cast<double>(f); });

	return doubleVector;
}

void DataProcess::removeSameData(DoubleVector&data)
{
	DoubleVector tempdata;
	double currentdata;
	for (int i = 0; i < data.size(); i++) {
		currentdata = data[i];
		if (!tempdata.contains(data[i])&&(!qIsNaN(currentdata))&&(currentdata!=0)) {
			tempdata.push_back(data[i]);
		}
	}
	data = tempdata;
}

void DataProcess::simplyData(DoubleVector&data,const int count)
{
	if (count < data.size()) {
		qSort(data.begin(), data.end());
		int intervalue = data.size() / count;
		int currentindex = 0;
		DoubleVector renewtempdata;
		while (currentindex < data.size()) {
			renewtempdata.push_back(data[currentindex]);
			currentindex += intervalue;
		}
		renewtempdata.push_back(data.last());
		data = renewtempdata;
	}
	
}

void DataProcess::changeElapsedTimeToDurationTime(DoubleVector&vt, DoubleVector&vq)
{
	const DoubleVector tempvt=vt;
	const DoubleVector tempvq=vq;
	changeToIntVector(vq);
	double currentq = vq.first();
	double t1 = vt.first();
	double t2;
	double sumq = 0;
	int sumcount = 0;
	DoubleVector durationt, durationq;
	int count = vq.size();
	for (int i = 0; i < count; i++) {
		if ((vq[i] == currentq)&&(i!=count-1)) {
			sumq += tempvq[i];
			sumcount++;
		}
		else if((vq[i]!=currentq)||(i==count-1&&vq[i]==currentq)) {
			
			t2 = vt[i];
			durationt.push_back(fabs(t2 - t1));
			if (currentq != 0) {
				if (sumcount) {
					durationq.push_back(sumq / double(sumcount));
				}
				else {
					durationq.push_back(tempvq[i]);
				}
				
				//durationq.push_back(currentq);
			}
			else {
				durationq.push_back(0);
			}
			sumq = 0;
			sumcount = 0;
			t1 = t2;
			currentq = vq[i];
		}
	}
	durationt.first() += tempvt.first();

	vt = durationt;
	vq = durationq;
}

bool DataProcess::isDataVectorEqual(const DoubleVector&v1, const DoubleVector&v2)
{
	bool equal = true;
	if (v1.size() == v2.size()) {
		for (int i = 0; i < v1.size(); i++) {
			if (fabs(v1[i] - v2[i]) > 1e-3) {
				equal = false;
				break;
			}
		}
	}
	else {
		equal = false;
	}
	return equal;
}

bool DataProcess::isCompleteDataVectorEqual(const DoubleVector&v1, const DoubleVector&v2)
{
	bool equal = true;
	if (v1.size() == v2.size()) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i]) {
				equal = false;
				break;
			}
		}
	}
	else {
		equal = false;
	}
	return equal;
}

void DataProcess::checkIndex(const QStringList&indexes, QString&index)
{	
	while (indexes.contains(index)) {
		index += s_poundsign;
	}
}

void DataProcess::changeDurationToElapsedTime(DoubleVector&t)
{
	if (!t.isEmpty()) {
		t.push_front(0);
		int count = t.size();
		if (count > 1) {
			for (int i = 1; i < count; i++) {
				t[i] = t[i] + t[i - 1];
			}
		}
	}
}

void DataProcess::changeElapsedTimeToDuration(DoubleVector&t)
{
	QVector<double>tempt;
	tempt.push_back(t.first());
	for (int i = 1; i < t.size(); i++) {
		tempt.push_back(fabs(t[i] - t[i - 1]));
	}
	t = tempt;
}

void DataProcess::changeToPlotData(DoubleVector&t, DoubleVector&q)
{
	if (!t.isEmpty()) {
		t.push_front(0);
		int count = t.size();
		if (count > 1) {
			for (int i = 1; i < count; i++) {
				t[i] = t[i] + t[i - 1];
			}
		}
	}
	if (!q.isEmpty()) {
		q.push_front(q.first());
	}
	/*HistoryDateModel* datemodel = SingleTemplate<HistoryDateModel>::getInstance();
	datemodel->ChangeToPlotTime(t, s_rate);*/
}

StringVectorVector DataProcess::changeStringToStringVectorVector(const QString& sloadddata, int& columncount, int& rowocount, bool containscount)
{
	QStringList temploaddata = sloadddata.split(s_linefeed);
	temploaddata.removeAll(QString());
	QString tempstring;
	StringVector stringvector;

	int count = temploaddata.size();
	if (containscount) {
		count = 100;
		if (temploaddata.size() < count) {
			count = temploaddata.size();
		}
	}

	StringVectorVector loaddata;
	for (int i = 0; i < count; i++) {
		tempstring = temploaddata[i];
		stringvector = tempstring.split(QRegExp(s_blankstring)).toVector();
		if (stringvector.size() > columncount) {
			columncount = stringvector.size();
		}
		loaddata.push_back(stringvector);
	}
	return loaddata;
}

StringVectorVector DataProcess::changeQVariantListToStringVectorVector(const QVariantList& varlist, bool considercount)
{
	StringVectorVector doublestringvector;
	StringVector stringvector;
	int count = varlist.size();
	if (considercount) {
		count = 100;
		if (varlist.size() < count) {
			count = varlist.size();
		}
	}
	for (int i = 0; i < count; i++) {
		QVariantList tempvar = varlist[i].toList();
		if (isValidVariantList(tempvar)) {
			for (int j = 0; j < tempvar.size(); j++) {
				QDateTime datetime = tempvar[j].toDateTime();
				QTime time = tempvar[j].toTime();
				if (datetime.isValid()) {
					QString stringdate = datetime.toString(s_yyyyMMdd);
					stringvector.push_back(stringdate);
				}
				else {
					stringvector.push_back(tempvar[j].toString());
				}

			}
			doublestringvector.push_back(stringvector);
			stringvector.clear();
		}
	}
	return doublestringvector;
}

void DataProcess::changeToDeltat(DoubleVector& t)
{
	DoubleVector vdeltat;
	double initt = t.first();
	for (int i = 1; i < t.size(); i++) {
		vdeltat.push_back(t[i] - initt);
	}
	t=vdeltat;
}

DoubleVectorMap DataProcess::mergeData(const DoubleVectorMap&fracdatamap, const DoubleVectorMap&testdatamap)
{
	DoubleVector fract = fracdatamap[s_t];
	DoubleVector fracp = fracdatamap[s_pressure];
	DoubleVector testt = testdatamap[s_t];
	DoubleVector testp = testdatamap[s_pressure];
	int indexvector = findClosestIndex(fract, testt.first());
	DoubleVector tempt = sliceByIndex(fract, 0, indexvector);
	DoubleVector tempp = sliceByIndex(fracp, 0, indexvector);
	double deltap = tempp.last() - testp.first();
	for (int i = 0; i < testp.size(); i++) {
		testp[i] += deltap;
	}
	tempt += testt;
	tempp += testp;
	DoubleVectorMap datamap;
	datamap[s_t] = tempt;
	datamap[s_pressure] = tempp;
	return datamap;
}

bool DataProcess::changeToElapsetime(const QDateTime& initdatetime, const QString& date, const QString& dateformat, QString& time, QString& timeformat, double& value)
{
	QString format;
	format = dateformat;
	QString tempdatetime = date;
	tempdatetime.replace(s_interval, s_slash);
	QString a = initdatetime.toString(s_datetimeformat);
	if (!time.isEmpty()) {
		format += s_empty;
		format += timeformat;
		tempdatetime += s_empty;
		tempdatetime += time;
	}
	QDateTime enddatetime = QDateTime::fromString(tempdatetime, format);
	bool ok = true;
	if (enddatetime.isValid()) {
		double inittime = initdatetime.toTime_t();
		double endtime = enddatetime.toTime_t();
		value = endtime - inittime;
		value /= 3600.0;
		if (value < 0) {
			value += 24;
		}
	}
	else {
		ok = false;
	}
	return ok;
}

bool DataProcess::changeToElapsetime(const QDateTime& initdatetime, const QString&datetime, const QString&datetimeformat, double&value)
{
	bool ok = true;
	QDateTime enddatetime = QDateTime::fromString(datetime, datetimeformat);
	if (enddatetime.isValid()) {
		double inittime = initdatetime.toTime_t();
		double endtime = enddatetime.toTime_t();
		value = endtime - inittime;
		value /= 60 * 60;
		QString s_value = QString::number(value, 'g', value);
		value = s_value.toDouble();
	}
	else {
		ok = false;
	}
	return ok;
}

bool DataProcess::isValidVariantList(const QVariantList&tempvar)
{
	bool valid = false;
	for (int i = 0; i < tempvar.size(); i++) {
		if (tempvar[i].isValid()) {
			valid = true;
			break;
		}
	}
	return valid;
}

void DataProcess::checkRateVectorMap(DoubleVectorMap&vectormap)
{
	QString mainrate = s_qpump;
	QStringList types = vectormap.keys();
	QVector<double>mainq = vectormap[mainrate];
	int count = mainq.size();
	if (count != 1) {
		QVector<int>removerows;
		for (int i = count - 1; i > 0; i--) {
			if (fabs(mainq[i] - mainq[i - 1])<0.1) {
				vectormap[s_t][i - 1] += vectormap[s_t][i];
				removerows.push_back(i);
			}

		}
		if (!removerows.isEmpty()) {
			int removecount = removerows.size();
			for (int i = 0; i < removecount; i++) {
				for (int j = 0; j < types.size(); j++) {
					vectormap[types[j]].removeAt(removerows[i]);
				}
			}
		}
	}
	if (vectormap[s_qpump].first() == 0) {
		vectormap[s_qpump].first() = 1;
	}
}

