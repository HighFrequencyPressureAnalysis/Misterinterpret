#include "widgetbasicfrac.h"
#include"ConstUnit.h"

WidgetBasicFrac::WidgetBasicFrac(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.dateTimeEdittime->setDateTime(QDateTime::currentDateTime());


	QStringList fractypes;
	fractypes << s_sandfrac;
	ui.comboBoxfraopera->addItems(fractypes);
	
	QStringList agenttypes;
	agenttypes << s_emulsion << s_powder << s_emupow;
	ui.comboBoxpstype->addItems(agenttypes);

	this->installEventFilter(this);
}

WidgetBasicFrac::~WidgetBasicFrac()
{}

bool WidgetBasicFrac::eventFilter(QObject* watched, QEvent* event)
{
	if (!m_locked) {
		return QWidget::eventFilter(watched, event);
	}

	// 拦截所有用户操作事件
	switch (event->type())
	{
	case QEvent::MouseButtonPress:
	case QEvent::MouseButtonRelease:
	case QEvent::MouseButtonDblClick:
	case QEvent::KeyPress:
	case QEvent::KeyRelease:
	case QEvent::Wheel:          // 滚轮
	case QEvent::ShortcutOverride:// 快捷键
	case QEvent::FocusIn:        // 禁止获得焦点
	return true; // 吃掉事件 = 不响应
	default:
		break;
	}

	return QWidget::eventFilter(watched, event);
}

void WidgetBasicFrac::setDefault()
{

}

void WidgetBasicFrac::setLocked(bool locked)
{
	m_locked = locked;
}

QString WidgetBasicFrac::getFracType() const
{
	return ui.comboBoxfraopera->currentText();
}

QString WidgetBasicFrac::getFracAgent() const
{
	return ui.comboBoxpstype->currentText();
}

DataMap WidgetBasicFrac::getDataMap() const
{
	DataMap datamap;
	datamap[s_emulsionContent] =ui.doubleSpinBoxemulsion->value();
	datamap[s_powderContent] = ui.doubleSpinBoxpowder->value();
	datamap[s_slickWater] = ui.doubleSpinBoxslickwater->value();
	datamap[s_linearGel] = ui.doubleSpinBoxlineargel->value();
	datamap[s_crosslinkedFluid] = ui.doubleSpinBoxCfluid->value();
	datamap[s_clusterCount] = ui.spinBoxper->value();
	datamap[s_perfPerCluster] = ui.spinBoxpercount->value();
	return datamap;
}

StringMap WidgetBasicFrac::getStringMap() const
{
	StringMap stringmap;
	stringmap[s_startTime] = ui.dateTimeEdittime->dateTime().toString(s_datetimeformat);
	stringmap[s_fracProcess] = getFracType();
	stringmap[s_agentType] = getFracAgent();
	return stringmap;
}

void WidgetBasicFrac::setCalDataVisible(bool visible)
{
	ui.spinBoxallper->setVisible(visible);
}

void WidgetBasicFrac::setData(const DataMap&datamap, const StringMap&stringmap)
{
	ui.doubleSpinBoxemulsion->setValue(datamap[s_emulsionContent]);
	ui.doubleSpinBoxpowder->setValue(datamap[s_powderContent]);
	ui.doubleSpinBoxslickwater->setValue(datamap[s_slickWater]);
	ui.doubleSpinBoxlineargel->setValue(datamap[s_linearGel]);
	ui.doubleSpinBoxCfluid->setValue(datamap[s_crosslinkedFluid]);

	ui.spinBoxper->setValue(datamap[s_clusterCount]);
	ui.spinBoxpercount->setValue(datamap[s_perfPerCluster]);

	double allfluid = datamap[s_slickWater] + datamap[s_linearGel] + datamap[s_crosslinkedFluid];

	ui.doubleSpinBoxall->setValue(allfluid);
	double allper = datamap[s_clusterCount] * datamap[s_perfPerCluster];
	ui.spinBoxallper->setValue(allper);

	ui.comboBoxfraopera->setCurrentText(stringmap[s_fracProcess]);
	ui.comboBoxpstype->setCurrentText(stringmap[s_agentType]);

	ui.dateTimeEdittime->setDateTime(QDateTime::fromString(stringmap[s_startTime],s_datetimeformat));

}


