#include "basicfracdockwidget.h"
#include "widgetbasicfrac.h"

#include <QSizePolicy>
#include <QVBoxLayout>

BasicFracDockWidget::BasicFracDockWidget(QWidget *parent)
	: QWidget(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(0, 0);
	setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	auto *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	m_widget = new WidgetBasicFrac(this);
	m_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_widget->setMinimumSize(0, 0);
	m_widget->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	layout->addWidget(m_widget);
}

BasicFracDockWidget::~BasicFracDockWidget() = default;

WidgetBasicFrac* BasicFracDockWidget::contentWidget() const
{
	return m_widget;
}
