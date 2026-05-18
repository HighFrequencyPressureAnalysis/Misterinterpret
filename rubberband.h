#pragma once
#include"qcustomplot.h"
#include <QRubberBand>


//数据选择框

class RubberBand : public QRubberBand
{
	Q_OBJECT
signals:
	//删除
	void removeRubber();
public:
	RubberBand(QCustomPlot *plot,QRubberBand::Shape type = Rectangle);
	~RubberBand();
protected:
	QCustomPlot* plot;
	QPoint initpos;
private slots:
	//创建选择框
	virtual void createRubber(QMouseEvent*);
	//移动选择框
	virtual void moveRubber(QMouseEvent*) = 0;
	//释放选择框
	virtual void releaseRubber(QMouseEvent*) = 0;
};
