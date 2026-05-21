#pragma once

#include <QWidget>

class QLabel;
class QToolButton;

class PanelTitleBarWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PanelTitleBarWidget(const QString& title, QWidget* parent = nullptr);
	~PanelTitleBarWidget() override;

	void setTitle(const QString& title);
	void setMaximized(bool maximized);
	bool isMaximized() const;

signals:
	void requestToggleMaximize();
	void requestClose();

protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;

private:
	void updateMaxButtonIcon();

private:
	QLabel* m_titleLabel = nullptr;
	QToolButton* m_maxButton = nullptr;
	QToolButton* m_collapseButton = nullptr;
	bool m_dragging = false;
	bool m_maximized = false;
	QPoint m_dragStartPos;
};
