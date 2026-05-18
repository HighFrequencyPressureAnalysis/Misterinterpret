#include "HistoryLoadDataModel.h"
#include"DataProcess.h"
#include"UnitChange.h"
#include"ConstCharacter.h"
#include"HistorySettingModel.h"
#include"ConstBasic.h"

HistoryLoadDataModel::HistoryLoadDataModel()
{

}

HistoryLoadDataModel::~HistoryLoadDataModel()
{

}




void HistoryLoadDataModel::setEditType(const QString&s_edittype)
{
	edittype = s_edittype;
}

void HistoryLoadDataModel::setRead(bool b_isread)
{
	isread = b_isread;
}

void HistoryLoadDataModel::setLoadHistoryDataType(LoadHistoryDataType type)
{
	historyloadtype = type;
}

void HistoryLoadDataModel::setText(const QString&s_text)
{
	text = s_text;
}

void HistoryLoadDataModel::setVariantList(const QVariantList&v_variantlist)
{
	varlist = v_variantlist;
}


void HistoryLoadDataModel::clear()
{
	text.clear();
	stringvectorvector.clear();
	varlist.clear();
	vectormap.clear();
	types.clear();
	intdatamap.clear();
	unitmap.clear();
	nontimetypes.clear();
	ratetimetype.clear();
}

void HistoryLoadDataModel::clearVectormap()
{
	vectormap.clear();
}

void HistoryLoadDataModel::setStringVectorVector(const StringVectorVector&s_stringvectorvector)
{
	stringvectorvector = s_stringvectorvector;
}

void HistoryLoadDataModel::setDateTime(const QDateTime&d_datetime)
{
	initdatetime = d_datetime;
}

void HistoryLoadDataModel::setHeaderDataTypes(const QStringList&types)
{
	headerdatatypes = types;
}

void HistoryLoadDataModel::readDataToVectorMap(const int i)
{	
	QString type, unit;
	double value = 0;
	bool timeok;
	bool valueok=true;
	int column;
	UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
	QStringList temptypes;
	double beforevalue=0;
	DataMap datamap;
	HistorySettingModel* settingmodel = SingleTemplate<HistorySettingModel>::getInstance();
	const QString edittype = settingmodel->getEditType();
	if (stringvectorvector[i].size() <= maxcolumncount) {
		return;
	}
	if (edittype != s_waterhammerpress) {
		if (types.contains(s_t)) {
			column = intdatamap.value(s_t);
			value = stringvectorvector[i][column].toDouble(&timeok);
			if (timeok) {
				type = s_t;
				if (timeok) {
					unit = unitmap.value(type);
					unitchange->checkStandardValue(s_t, unit, value);
					datamap[s_t] = value;
					valueok = true;
				}

			}

		}
		else {
			DataProcess* dataprocess = SingleTemplate<DataProcess>::getInstance();
			if (types.contains(s_datetime)) {
				QString datetimestring;
				QString datetimeformat;
				column = intdatamap.value(s_datetime);
				datetimestring = stringvectorvector[i][column];
				datetimeformat = unitmap.value(s_datetime);
				timeok = dataprocess->changeToElapsetime(initdatetime, datetimestring, datetimeformat, value);

			}
			else {
				int columndate = 0;
				int columntime = 0;
				QString datestring, timestring, dateformat, timeformat;
				if (types.contains(s_time) && types.contains(s_date)) {
					columndate = intdatamap.value(s_date);
					columntime = intdatamap.value(s_time);
					datestring = stringvectorvector[i][columndate];
					timestring = stringvectorvector[i][columntime];
					dateformat = unitmap.value(s_date);
					timeformat = unitmap.value(s_time);

				}
				else {
					UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
					dateformat = unitchange->getStandardUnit(s_date);
					columntime = intdatamap.value(s_time);
					datestring = initdatetime.date().toString(dateformat);
					timestring = stringvectorvector[i][columntime];
					timeformat = unitmap.value(s_time);
				}
				timeok = dataprocess->changeToElapsetime(initdatetime, datestring, dateformat, timestring, timeformat, value);
			}

			if (timeok) {
				datamap[s_t] = value;
			}
		}
	}
	else {
		timeok = true;
	}
	
	if (valueok) {
		for (int j = 0; j < nontimetypes.size(); j++) {
			type = nontimetypes[j];
			column = intdatamap[type];
			if (column < stringvectorvector[i].size()) {
				value = stringvectorvector[i][column].toDouble(&valueok);
				if (value<1&&valueok) {
					int a = 0;
				}
				if (valueok) {
					unit = unitmap.value(type);
					unitchange->checkStandardValue(type, unit, value);
					datamap[type] = value;
				}
			}

		}
	}
	
	if (timeok&&valueok) {
		temptypes = datamap.keys();
		for (int k = 0; k < temptypes.size(); k++) {
			type = temptypes[k];
			vectormap[type].push_back(datamap[type]);
		}
	}
}

bool HistoryLoadDataModel::isTableLoadData() const
{
	bool tableload = false;
	if (historyloadtype==LoadHistoryDataType::table) {
		tableload = true;
	}
	return tableload;
}

int HistoryLoadDataModel::getReadMaxRowCount() 
{
	vectormap.clear();
	int rowcount = 0;
	int columncount = 0;
	maxcolumncount = 0;
	DataProcess*dataprocess = SingleTemplate<DataProcess>::getInstance();
	switch (historyloadtype)
	{
	case excel:
		stringvectorvector = dataprocess->changeQVariantListToStringVectorVector(varlist, false);
		break;
	case txt:
		stringvectorvector = dataprocess->changeStringToStringVectorVector(text, columncount, rowcount, false);
		break;
	case clipboard:
		stringvectorvector = dataprocess->changeStringToStringVectorVector(text, columncount, rowcount, false);
		break;
	case table:
		break;
	default:
		break;
	}
	
	QString type;
	QString unit;
	
	for (int i = 0; i < headerdatatypes.size(); i++) {
		if (headerdatatypes[i] != s_empty) {
			type = headerdatatypes[i].split(s_interval).first();
			unit = headerdatatypes[i].split(s_interval).last();
			if (unit == "dd HH:mm:ss") {
				unit = s_datetimeformat2;
			}
			intdatamap[type] = i;
			if (maxcolumncount < i) {
				maxcolumncount = i;
			}
			unitmap[type] = unit;
			types.push_back(type);
			if (!type.contains(s_t)) {
				nontimetypes.push_back(type);
			}
		}
	}
	count = types.size();
	if (types.contains(s_time)) {
		count--;
	}

	rowcount = stringvectorvector.size();
	return rowcount;
}

DoubleVectorMap HistoryLoadDataModel::getVectorMap() const
{
	return vectormap;
}

void HistoryLoadDataModel::setRateTimeType(const QString&type)
{
	ratetimetype = type;
}

QString HistoryLoadDataModel::getRateTimeType() const
{
	return ratetimetype;
}

