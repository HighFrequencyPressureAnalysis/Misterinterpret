#pragma once
#pragma execution_character_set("utf-8")
#include"ConstBasic.h"
#include <QWidget>
#include "ui_widgetbasicfrac.h"
#include"ConstBasic.h"
#include"ConstDataType.h"

class WidgetBasicFrac : public QWidget
{
	Q_OBJECT

public:
	WidgetBasicFrac(QWidget *parent = nullptr);
	~WidgetBasicFrac();

	void setDefault();
	void setLocked(bool locked);
	QString getFracType()const;
	QString getFracAgent()const;
	DataMap getDataMap()const;
	StringMap getStringMap()const;
	void setCalDataVisible(bool);
	void setData(const DataMap&, const StringMap&);
private:
	Ui::WidgetBasicFracClass ui;

	bool m_locked = false;
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;
};

