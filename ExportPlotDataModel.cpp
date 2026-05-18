#include "ExportPlotDataModel.h"
#include"ConstBasic.h"
#include"ConstCharacter.h"
#include"ConstUnit.h"
#include"UnitChange.h"
#include"DataProcess.h"

ExportPlotDataModel::ExportPlotDataModel()
{
}

ExportPlotDataModel::~ExportPlotDataModel()
{
}

void ExportPlotDataModel::getRangeData(GraphExportData& exportdata)
{

	double min = exportdatainfor.range.first();
	double max = exportdatainfor.range.last();
	int count = exportdata.graph->dataCount();
	QSharedPointer<QCPGraphDataContainer> graphdata = exportdata.graph->data();
	DoubleVector x, y;
	QCPDataContainer<QCPGraphData>::const_iterator iter = graphdata.data()->at(0);//迭代器
	while (1) {
		if (iter->key >= min && iter->key <= max) {
			x.push_back(iter->key);
			y.push_back(iter->value);
		}

		if (iter->key > max|| iter == graphdata.data()->at(count-1)) {
			break;
		}
		iter++;
	}
	exportdata.x = x;
	exportdata.y = y;
	exportdata.datacount = x.count();
	

}

void ExportPlotDataModel::sortBySize()
{
	qSort(exportdatavector.begin(), exportdatavector.end(), [](const GraphExportData& a, const GraphExportData& b) {
		return a.datacount > b.datacount;
	});

}

void ExportPlotDataModel::clearExportGraphDataVector()
{
	for (int i = 0; i < exportdatavector.size(); i++) {
		exportdatavector[i].x.clear();
		exportdatavector[i].y.clear();
	}
	exportdatavector.clear();
}

void ExportPlotDataModel::clear()
{
	ExportDataInfor emptyexportdatainfor;
	exportdatainfor = emptyexportdatainfor;
	exporttype.clear();
	filepath.clear();
	tunit.clear();
	qdatatype.clear();
	content.clear();
	for (int i = 0; i < initexportdatavector.size(); i++) {
		initexportdatavector[i].x.clear();
		initexportdatavector[i].y.clear();
	}
	initexportdatavector.clear();
	clearExportGraphDataVector();
}

void ExportPlotDataModel::changeQData()
{
	DoubleVector t, q;
	int count = 0;
	double currentt = 0;
	for (int i = 0; i < exportdatavector.size(); i++) {
		if (exportdatavector[i].type.contains(s_qpump)) {
			t = exportdatavector[i].x;
			q = exportdatavector[i].y;
			DataProcess* dataprocess = SingleTemplate<DataProcess>::getInstance();
			dataprocess->changeElapsedTimeToDuration(t);
			t.removeFirst();
			q.removeFirst();
			exportdatavector[i].x = t;
			exportdatavector[i].y = q;
			exportdatavector[i].datacount = t.size();
			break;
		}
	}
}


int ExportPlotDataModel::getMaxRowCount()
{
	content.clear();
	for (int i = 0; i < exportdatavector.size(); i++) {
		getRangeData(exportdatavector[i]);
	}

	sortBySize();
	return exportdatavector.first().datacount;
}

int ExportPlotDataModel::getExportDataVectorCount() const
{
	return exportdatavector.size();
}

ExportDataInfor ExportPlotDataModel::getExportDataInfor() const
{
	return exportdatainfor;
}

void ExportPlotDataModel::setExportDataInfor(const ExportDataInfor&infor)
{
	exportdatainfor = infor;
}

void ExportPlotDataModel::setSaveFileInfor(const QString&s_type, const QString&s_filepath)
{
	exporttype = s_type;
	filepath = s_filepath;
}

void ExportPlotDataModel::setExportType(const QString&s_exporttype)
{
	exporttype = s_exporttype;
}

void ExportPlotDataModel::setGraphExportDataVector(const GraphExportDataVector&datavector)
{
	initexportdatavector = datavector;
}

void ExportPlotDataModel::setTimeUnit(const QString&timeunit)
{
	tunit = timeunit;
}

QString ExportPlotDataModel::getFilePath() const
{
	return filepath;
}

void ExportPlotDataModel::exportData()
{	
	
	bool issametime = exportdatainfor.issametime;
	QString typecontent;
	//数据类型
	QString unitcontent;
	int typecount = exportdatavector.size();
	//写入表头
	for (int i = 0; i < typecount; i++) {
		if (!issametime) {
			typecontent.push_back(s_t);
			typecontent.push_back(s_blankstring);
			unitcontent.push_back(tunit);
			unitcontent.push_back(s_blankstring);
			if (containdatetime) {
				typecontent.push_back(s_datetime);
				typecontent.push_back(s_blankstring);
				unitcontent.push_back(s_datetimeformat);
				unitcontent.push_back(s_blankstring);
			}
		}
		else {
			if (i == 0) {
				typecontent.push_back(s_t);
				typecontent.push_back(s_blankstring);
				unitcontent.push_back(tunit);
				unitcontent.push_back(s_blankstring);
				if (containdatetime) {
					typecontent.push_back(s_datetime);
					typecontent.push_back(s_blankstring);
					unitcontent.push_back(s_datetimeformat);
					unitcontent.push_back(s_blankstring);
				}
			}
		}
		typecontent.push_back(exportdatavector[i].type);
		unitcontent.push_back(exportdatavector[i].unit);
		if (i == typecount - 1) {
			typecontent.push_back(s_linefeed);
			unitcontent.push_back(s_linefeed);
		}
		else {
			typecontent.push_back(s_blankstring);
			unitcontent.push_back(s_blankstring);
		}
		
	}
	content += typecontent;
	content += unitcontent;

	//写入数据
	int maxrow = exportdatavector.first().datacount;
	int datatypecount = exportdatavector.size();
	UnitChange* unitchange = SingleTemplate<UnitChange>::getInstance();
	QString unit,type;
	double key, value;
	int precision = 0;
	if (issametime) {
		for (int i = 0; i < maxrow; i++) {
			for (int j = 0; j < datatypecount; j++) {
				key = exportdatavector[j].x[i];
				value = exportdatavector[j].y[i];
				
				if (j == 0) {
					if (!tunit.isEmpty()) {
						unitchange->changeStandardunitToCurrentUnit(s_t, tunit, key);
					}
					precision = 12;
					content.push_back(QString::number(key, 'f', precision));
					content.push_back(s_blankstring);
					if (containdatetime) {
						unitchange->changeUnitValue(tunit, s_sec, s_t, key);
						content.push_back(datetime.addSecs(key).toString());
						content.push_back(s_blankstring);
					}
				}
				
				unit = exportdatavector[j].unit;
				type = exportdatavector[j].type;
				if (type.contains(s_interval)) {
					type.truncate(type.indexOf(s_interval));
				}
				if (!unit.isEmpty()) {
					unitchange->changeStandardunitToCurrentUnit(type, unit, value);
				}
				content.push_back(QString::number(value, 'f', precision));
				content.push_back(s_blankstring);
					
			}
			content.push_back(s_linefeed);
			
		}
	}
	else {
		precision = 4;
		int temprowcount = 0;
		for (int i = 0; i < maxrow; i++) {
			for (int j = 0; j < datatypecount; j++) {
				temprowcount = exportdatavector[j].datacount;
				if (i < temprowcount) {
					key = exportdatavector[j].x[i];
					value = exportdatavector[j].y[i];
					if (!tunit.isEmpty()) {
						unitchange->changeStandardunitToCurrentUnit(s_t, tunit, key);
					}
					content.push_back(QString::number(key, 'f', precision));
					content.push_back(s_blankstring);
					if (containdatetime) {
						unitchange->changeUnitValue(tunit, s_sec, s_t, key);
						content.push_back(datetime.addSecs(key).toString(s_datetimeformat));
						content.push_back(s_blankstring);
					}
					
					unit = exportdatavector[j].unit;
					type = exportdatavector[j].type;
					if (type.contains(s_interval)) {
						type.truncate(type.indexOf(s_interval));
					}
					if (!unit.isEmpty()) {
						unitchange->changeStandardunitToCurrentUnit(type, unit,value);
					}
					content.push_back(QString::number(value, 'f', precision));
					content.push_back(s_blankstring);
					
				}
				
			}
			content.push_back(s_linefeed);

		}
	}
	
}

void ExportPlotDataModel::addGraphData(const QString&type)
{
	for (int i = 0; i < initexportdatavector.size(); i++) {
		if (initexportdatavector[i].type == type) {
			exportdatavector.push_back(initexportdatavector[i]);
			break;
		}
	}
}

void ExportPlotDataModel::setGraphUnit(const QString&type,const QString&unit)
{
	for (int i = 0; i < exportdatavector.size(); i++) {
		if (exportdatavector[i].type == type) {
			exportdatavector[i].unit = unit;
			break;
		}
	}
}

void ExportPlotDataModel::setCurrentRange(const double min, const double max)
{
	DoubleVector range;
	range.push_back(min);
	range.push_back(max);
	exportdatainfor.range = range;
}

void ExportPlotDataModel::setRateDataType(const QString&s_ratetype)
{
	qdatatype = s_ratetype;
}

void ExportPlotDataModel::setContainDateTime(const bool b_containdatetime)
{
	containdatetime = b_containdatetime;
}

void ExportPlotDataModel::setDateTime(const QDateTime&d_datetime)
{
	datetime = d_datetime;
}

QString ExportPlotDataModel::getStringContent() const
{
	return content;
}


