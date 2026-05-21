#include "paneltitlebarwidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QStyle>
#include <QToolButton>

PanelTitleBarWidget::PanelTitleBarWidget(const QString& title, QWidget* parent)
	: QWidget(parent)
{
	auto* layout = new QHBoxLayout(this);
	layout->setContentsMargins(3, 0, 3, 0);
	layout->setSpacing(1);

	m_titleLabel = new QLabel(title, this);
	m_titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	m_maxButton = new QToolButton(this);
	m_maxButton->setAutoRaise(true);
	m_maxButton->setToolTip(QStringLiteral("Toggle full screen"));
	m_maxButton->setIcon(style()->standardIcon(QStyle::SP_TitleBarMaxButton));
	m_maxButton->setIconSize(QSize(14, 14));
	updateMaxButtonIcon();
	connect(m_maxButton, &QToolButton::clicked, this, &PanelTitleBarWidget::requestToggleMaximize);

	auto* closeButton = new QToolButton(this);
	closeButton->setAutoRaise(true);
	closeButton->setToolTip(QStringLiteral("Restore to tab"));
	closeButton->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
	closeButton->setIconSize(QSize(14, 14));
	connect(closeButton, &QToolButton::clicked, this, &PanelTitleBarWidget::requestClose);

	layout->addWidget(m_titleLabel);
	layout->addWidget(m_maxButton);
	layout->addWidget(closeButton);

	setCursor(Qt::SizeAllCursor);
}

PanelTitleBarWidget::~PanelTitleBarWidget() = default;

void PanelTitleBarWidget::setTitle(const QString& title)
{
	if (m_titleLabel) {
		m_titleLabel->setText(title);
	}
}

void PanelTitleBarWidget::setMaximized(bool maximized)
{
	if (m_maximized == maximized) {
		return;
	}
	m_maximized = maximized;
	updateMaxButtonIcon();
}

bool PanelTitleBarWidget::isMaximized() const
{
	return m_maximized;
}

void PanelTitleBarWidget::updateMaxButtonIcon()
{
	if (!m_maxButton) {
		return;
	}
	m_maxButton->setIcon(style()->standardIcon(m_maximized ? QStyle::SP_TitleBarNormalButton : QStyle::SP_TitleBarMaxButton));
	m_maxButton->setToolTip(m_maximized ? QStringLiteral("Exit full screen") : QStringLiteral("Toggle full screen"));
}

void PanelTitleBarWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		m_dragging = true;
		m_dragStartPos = event->globalPos();
	}
	QWidget::mousePressEvent(event);
}

void PanelTitleBarWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (m_dragging) {
		Q_UNUSED(event)
	}
	QWidget::mouseMoveEvent(event);
}

void PanelTitleBarWidget::mouseReleaseEvent(QMouseEvent* event)
{
	m_dragging = false;
	QWidget::mouseReleaseEvent(event);
}
