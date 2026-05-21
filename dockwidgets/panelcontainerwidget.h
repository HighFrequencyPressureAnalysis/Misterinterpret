#pragma once

#include <QWidget>

class PanelTitleBarWidget;
class QVBoxLayout;

class PanelContainerWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PanelContainerWidget(const QString& title, QWidget* content, QWidget* parent = nullptr);
	~PanelContainerWidget() override;

	QWidget* contentWidget() const;
	void setContentWidget(QWidget* content);
	void setTitle(const QString& title);
	void setCollapsed(bool collapsed);
	bool isCollapsed() const;
	void setMaximized(bool maximized);
	bool isMaximized() const;

signals:
	void requestMaximizeChanged(PanelContainerWidget* sender, bool maximized);
	void requestCollapseChanged(PanelContainerWidget* sender, bool collapsed);

private slots:
	void onToggleMaximize();
	void onToggleCollapse();

private:
	void updateContentVisibility();
	void updateVisualState();

private:
	PanelTitleBarWidget* m_titleBar = nullptr;
	QWidget* m_content = nullptr;
	QVBoxLayout* m_layout = nullptr;
	bool m_collapsed = false;
	bool m_maximized = false;
};
