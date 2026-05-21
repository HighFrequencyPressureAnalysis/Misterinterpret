#include "docktitlebarwidget.h"

#include <QApplication>
#include <QDockWidget>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QStyle>
#include <QToolButton>

DockTitleBarWidget::DockTitleBarWidget(QDockWidget *dock, QWidget *parent)
	: QWidget(parent)
	, m_dock(dock)
{
	auto *layout = new QHBoxLayout(this);
	layout->setContentsMargins(4, 2, 4, 2);
	layout->setSpacing(4);

	auto *spacer = new QWidget(this);
	spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	m_toggleButton = new QToolButton(this);
	m_toggleButton->setAutoRaise(true);
	m_toggleButton->setToolTip(QStringLiteral("Float / Maximize"));
	m_toggleButton->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));
	connect(m_toggleButton, &QToolButton::clicked, this, &DockTitleBarWidget::toggleFloatAndMaximize);

	layout->addWidget(spacer);
	layout->addWidget(m_toggleButton);
}

void DockTitleBarWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event)
	toggleFloatAndMaximize();
}

void DockTitleBarWidget::toggleFloatAndMaximize()
{
	if (!m_dock) {
		return;
	}

	if (!m_dock->isFloating()) {
		m_dock->setFloating(true);
		m_dock->showMaximized();
		m_toggleButton->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
	} else {
		m_dock->showNormal();
		m_dock->setFloating(false);
		m_toggleButton->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));
	}
}