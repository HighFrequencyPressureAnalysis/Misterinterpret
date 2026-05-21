#pragma once

#include <QMainWindow>
#include <QDockWidget>
#include <QShowEvent>
#include <QEvent>
#include "ConstDataType.h"

class PanelTitleBarWidget;
class QWidget;
class BasicFracDockWidget;
class PerforationDockWidget;
class OperaDockWidget;
class WhDockWidget;

class FracDockPage : public QMainWindow
{
	Q_OBJECT

public:
	explicit FracDockPage(QWidget *parent = nullptr);
	~FracDockPage();

	void renewFracBasicData(const DataMap&, const StringMap&);
	void renewFracPerData(const double&, const DoubleVector&);
	void renewFracOperaData(const QString&, const DoubleVectorMap&);
	void renewFracTestData(const QString&, const DoubleVectorMap&);
	void renewFracWHData(const int&, const DoubleVector&);
	void renewFracMergeData(const DoubleVector&, const DoubleVector&);
	void clear();

	void setDockInteractionEnabled(bool enabled);

protected:
	void showEvent(QShowEvent *event) override;
	bool eventFilter(QObject *watched, QEvent *event) override;

public:
	struct DockEntry
	{
		QDockWidget* dock = nullptr;
		PanelTitleBarWidget* titleBar = nullptr;
		QWidget* content = nullptr;
		QMainWindow* popup = nullptr;
		QWidget* popupHost = nullptr;
		Qt::DockWidgetArea originalArea = Qt::LeftDockWidgetArea;
	};

	QWidget* createDockTitleBar(const QString& title, DockEntry* entry);
	void toggleDockPopup(DockEntry* entry);
	void restoreDockPopup(DockEntry* entry);
	void updateDockTitleBarState(DockEntry* entry, bool maximized);
	void createDockWidgets();
	void createDockLayout();
	void setupDefaultLayout();
	void applyInitialDockSizes();
	void applyDeferredLayoutCorrection();
	void refreshDockLayout();
	void closeEvent(QCloseEvent *event) override;

private:
	DockEntry m_basicEntry;
	DockEntry m_perEntry;
	DockEntry m_operaEntry;
	DockEntry m_whEntry;
	bool m_initialLayoutApplied = false;
	bool m_layoutInitialized = false;

	BasicFracDockWidget *m_basicWidget = nullptr;
	PerforationDockWidget *m_perWidget = nullptr;
	OperaDockWidget *m_operaWidget = nullptr;
	WhDockWidget *m_whWidget = nullptr;
};
