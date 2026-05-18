#pragma once
#include"ConstCharacter.h"
#include <QWidget>
#include "ui_widgetfracper.h"
#include<QClipBoard>
#include<QToolButton>

class WidgetFracPer : public QWidget
{
	Q_OBJECT

public:
	WidgetFracPer(QWidget *parent = nullptr);
	~WidgetFracPer();

	void setGroupVisible(bool);
	void setData(const double&, const DoubleVector&);
	void showData(const DoubleVector&);
	void setDefaultRowCount();
	void getData(DoubleVector&,double&);
	void clearTable();
private:
	Ui::WidgetFracPerClass ui;
private slots:
	void resetTableView();
	void loadClipData();
};

