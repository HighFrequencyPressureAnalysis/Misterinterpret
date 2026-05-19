#include "operadockwidget.h"
#include "plotopera.h"

#include <QSizePolicy>
#include <QVBoxLayout>

OperaDockWidget::OperaDockWidget(QWidget *parent)
	: QWidget(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(0, 0);
	setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	auto *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	m_widget = new PlotOpera(this);
	m_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_widget->setMinimumSize(0, 0);
	m_widget->setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
	layout->addWidget(m_widget);
}

OperaDockWidget::~OperaDockWidget() = default;

PlotOpera* OperaDockWidget::contentWidget() const
{
	return m_widget;
}
