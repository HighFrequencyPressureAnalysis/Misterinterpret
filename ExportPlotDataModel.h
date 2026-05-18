#pragma once
#include"SingleTemplate.h"
#include"graph.h"
#include<QDateTime>
#include"ConstDataType.h"
#include<QString>

const double minpara = -100000000;
const double maxpara = 10000000;

struct ExportDataInfor{
	bool issametime;
	QDateTime datetime;
	QString timetype;
	QStringList types;
	DoubleVector range;
	DoubleVector currentrange;
	QCPAxis* xaxis;
	QCPAxis* yaxis;
};

struct GraphExportData {
	QCPGraph* graph;
	DoubleVector x;
	DoubleVector y;
	StringVector vdatetime;
	QString unit;
	QString type;
	int datacount;
	int posindex;
};

typedef QVector<GraphExportData>GraphExportDataVector;

class ExportPlotDataModel
{
	DECLARE_SINGLEON(ExportPlotDataModel);
public:
	void clearExportGraphDataVector();
	void clear();
	void changeQData();
	int getMaxRowCount();
	int getExportDataVectorCount()const;
	ExportDataInfor getExportDataInfor()const;
	void setExportDataInfor(const ExportDataInfor&);
	void setSaveFileInfor(const QString&, const QString&);
	void setExportType(const QString&);
	void setGraphExportDataVector(const GraphExportDataVector&);
	void setTimeUnit(const QString&);
	QString getFilePath()const;
	void exportData();
	void addGraphData(const QString&);
	void setGraphUnit(const QString&,const QString&);
	void setCurrentRange(const double, const double);
	void setRateDataType(const QString&);
	void setContainDateTime(const bool);
	void setDateTime(const QDateTime&);
	QString getStringContent()const;
private:
	ExportPlotDataModel();
	~ExportPlotDataModel();

	ExportDataInfor exportdatainfor;
	GraphExportDataVector initexportdatavector;
	GraphExportDataVector exportdatavector;
	QString exporttype;
	QString filepath;
	QString tunit;
	bool containdatetime;
	QString qdatatype;
	QDateTime datetime;
	void getRangeData(GraphExportData&);
	void sortBySize(); 
	QString content;
};

