#pragma once
#pragma execution_character_set("utf-8")
#include<QString>
#include <QWidget>
#include"qcustomplot.h"
#include"plottoolbar.h"
#if __has_include(<GL/glut.h>)
#include <GL/glut.h>
#elif __has_include(<GLUT/glut.h>)
#include <GLUT/glut.h>
#endif
#include"graph.h"
#include<algorithm>
#include"ConstCharacter.h"
#include"ConstDataType.h"
#include"ConstBasic.h"
#include"GraphPlotSetting.h"
#include"rubberbandzoom.h"
#include"ConstUnit.h"


struct GraphData
{
	QString name;
	QVector<double>x;
	QVector<double>y;
};

using namespace std;

typedef QList<QCPAxis*>Axises;

class Plot  : public QWidget
{
	Q_OBJECT

public:
	Plot(QWidget *parent=nullptr);
	~Plot();

	void clearPlot();
	void replot();
	void removePlotItems();
	void setToolbarUnenble();
	void setBackGroudColor(const QString&, bool, const QString&);
	void setPlotFont(const QString&, const QString&);
public slots:
	virtual void initAxisValue();
protected:
	PlotToolBar* toolbar;
	QCustomPlot* plot;
	QMenu* menu;
	QCPAxis* axisdatetime=nullptr;
	void removeGraph(Graph**);
	void showSelectData(const IntVector&, Graph*);
	void showSelectData(const QCPRange&, Graph*);
	void getCurrentRange(DoubleVector&);
	void getDataRange(DoubleVector&);
	void setOpenGL();
	void createDateTimeAxis(QCPAxisRect* ,const int angel=15, const int tickcount =5);
	void initAxis(QCPAxis*,bool notcheckvisible =false,bool ave=true);
	void setAxisColor(const QColor&, QCPAxis*);
	void createGraph(Graph**, const QString&, QCPAxis*, bool issample = false, bool lsline = true, bool ssdisc = true);
	void createGraph(Graph**, const QString&, QCPAxis*,QCPAxis*,bool issample = false, bool lsline = true, bool ssdisc = true);
	void drawGraph(const QVector<double>&, const QVector<double>&, Graph** graph,bool alreadysort=true);

	//������ק������������
	void setRragAndZoomUnable();
	virtual Axises getChooseAxis()const;
	virtual QDateTime getDateTime()const;
	RubberBandZoom* rubberbandzoom = nullptr;
	QCPItemStraightLine* itemdataline = nullptr;
	QDateTime startdatetime;
	bool issametime = false;
	

private:
	QString getAxisStringValue(QCPAxis*,const double);
private slots:
	void outputPic();
	void zoomInPlot(bool checked);
	void zoomOutPlot();
	void setLegendVisible(bool);
	void removeRubber();
	void setDragModel(bool);
	void setZoomModel(bool);
	void setShowData(bool);
	void showMenu(QMouseEvent*);
	void showExportDataDialog();
	void resetLocalDateTime(const QCPRange&);
	void setDataTimeAxisVisible(bool);
	virtual void showChooseData(QMouseEvent*);

};
