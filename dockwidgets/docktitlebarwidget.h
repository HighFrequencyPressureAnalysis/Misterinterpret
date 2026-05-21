#pragma once

#include <QDockWidget>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QSizePolicy>
#include <QStyle>
#include <QToolButton>
#include <QWidget>

class DockTitleBarWidget : public QWidget
{
public:
	explicit DockTitleBarWidget(QDockWidget *dock, QWidget *parent = nullptr)
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
		connect(m_toggleButton, &QToolButton::clicked, this, [this]() { toggleFloatAndMaximize(); });

		layout->addWidget(spacer);
		layout->addWidget(m_toggleButton);
	}

protected:
	void mouseDoubleClickEvent(QMouseEvent *event) override
	{
		Q_UNUSED(event)
		toggleFloatAndMaximize();
	}

private:
	void toggleFloatAndMaximize()
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

private:
	QDockWidget *m_dock = nullptr;
	QToolButton *m_toggleButton = nullptr;
};