#pragma once

#include <QWidget>

class PlotWh;

class WhDockWidget : public QWidget
{
	Q_OBJECT

public:
	explicit WhDockWidget(QWidget *parent = nullptr);
	~WhDockWidget();

	PlotWh* contentWidget() const;

private:
	PlotWh *m_widget = nullptr;
};
