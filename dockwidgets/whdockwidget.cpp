#include "whdockwidget.h"
#include "plotwh.h"

#include <QSizePolicy>
#include <QVBoxLayout>

WhDockWidget::WhDockWidget(QWidget *parent)
	: QWidget(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(0, 0);
	setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	auto *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	m_widget = new PlotWh(this);
	m_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_widget->setMinimumSize(0, 0);
	m_widget->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	layout->addWidget(m_widget);
}

WhDockWidget::~WhDockWidget() = default;

PlotWh* WhDockWidget::contentWidget() const
{
	return m_widget;
}
