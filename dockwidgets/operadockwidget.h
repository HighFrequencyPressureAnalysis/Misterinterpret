#pragma once

#include <QWidget>

class PlotOpera;

class OperaDockWidget : public QWidget
{
	Q_OBJECT

public:
	explicit OperaDockWidget(QWidget *parent = nullptr);
	~OperaDockWidget();

	PlotOpera* contentWidget() const;

private:
	PlotOpera *m_widget = nullptr;
};
