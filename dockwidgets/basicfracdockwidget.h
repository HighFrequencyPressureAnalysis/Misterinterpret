#pragma once

#include <QWidget>

class WidgetBasicFrac;

class BasicFracDockWidget : public QWidget
{
	Q_OBJECT

public:
	explicit BasicFracDockWidget(QWidget *parent = nullptr);
	~BasicFracDockWidget();

	WidgetBasicFrac* contentWidget() const;

private:
	WidgetBasicFrac *m_widget = nullptr;
};
