#pragma once

#include <QWidget>

class WidgetFracPer;

class PerforationDockWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PerforationDockWidget(QWidget *parent = nullptr);
	~PerforationDockWidget();

	WidgetFracPer* contentWidget() const;

private:
	WidgetFracPer *m_widget = nullptr;
};
