#include "panelcontainerwidget.h"
#include "paneltitlebarwidget.h"

#include <QVBoxLayout>

PanelContainerWidget::PanelContainerWidget(const QString& title, QWidget* content, QWidget* parent)
	: QWidget(parent)
{
	m_layout = new QVBoxLayout(this);
	m_layout->setContentsMargins(1, 1, 1, 1);
	m_layout->setSpacing(0);

	m_titleBar = new PanelTitleBarWidget(title, this);
	m_content = content;

	m_layout->addWidget(m_titleBar);
	if (m_content) {
		m_content->setObjectName(QStringLiteral("panelContent"));
		m_layout->addWidget(m_content);
	}
	m_layout->setStretch(1, 1);

	setObjectName(QStringLiteral("panelContainer"));
	updateVisualState();

	connect(m_titleBar, &PanelTitleBarWidget::requestToggleMaximize, this, &PanelContainerWidget::onToggleMaximize);
}

PanelContainerWidget::~PanelContainerWidget() = default;

QWidget* PanelContainerWidget::contentWidget() const
{
	return m_content;
}

void PanelContainerWidget::setContentWidget(QWidget* content)
{
	if (m_content == content) {
		return;
	}
	if (m_content) {
		m_layout->removeWidget(m_content);
		m_content->setParent(nullptr);
	}
	m_content = content;
	if (m_content) {
		m_content->setObjectName(QStringLiteral("panelContent"));
		m_layout->addWidget(m_content);
		m_layout->setStretch(1, 1);
	}
}

void PanelContainerWidget::setTitle(const QString& title)
{
	if (m_titleBar) {
		m_titleBar->setTitle(title);
	}
}

void PanelContainerWidget::setCollapsed(bool collapsed)
{
	if (m_collapsed == collapsed) {
		return;
	}
	m_collapsed = collapsed;
	updateContentVisibility();
	updateVisualState();
}

bool PanelContainerWidget::isCollapsed() const
{
	return m_collapsed;
}

void PanelContainerWidget::setMaximized(bool maximized)
{
	if (m_maximized == maximized) {
		return;
	}
	m_maximized = maximized;
	if (m_titleBar) {
		m_titleBar->setMaximized(maximized);
	}
	updateVisualState();
}

bool PanelContainerWidget::isMaximized() const
{
	return m_maximized;
}

void PanelContainerWidget::onToggleMaximize()
{
	m_maximized = !m_maximized;
	if (m_titleBar) {
		m_titleBar->setMaximized(m_maximized);
	}
	updateVisualState();
	emit requestMaximizeChanged(this, m_maximized);
}

void PanelContainerWidget::onToggleCollapse()
{
	m_collapsed = !m_collapsed;
	updateContentVisibility();
	updateVisualState();
	emit requestCollapseChanged(this, m_collapsed);
}

void PanelContainerWidget::updateContentVisibility()
{
	if (m_content) {
		m_content->setVisible(!m_collapsed);
	}
}

void PanelContainerWidget::updateVisualState()
{
	if (m_maximized) {
		setStyleSheet("#panelContainer { border: 2px solid #3a7bd5; background: #f8fbff; } #panelContent { background: white; }");
	}
	else if (m_collapsed) {
		setStyleSheet("#panelContainer { border: 1px solid #c8c8c8; background: #fafafa; }");
	}
	else {
		setStyleSheet("#panelContainer { border: 1px solid #d6d6d6; background: #ffffff; } #panelContent { background: white; }");
	}
}
