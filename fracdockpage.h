#pragma once

#include <QMainWindow>
#include <QDockWidget>
#include "ConstDataType.h"

class BasicFracDockWidget;
class PerforationDockWidget;
class OperaDockWidget;
class WhDockWidget;
class QToolBar;
class QAction;

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
	QByteArray saveLayoutState() const;
	bool restoreLayoutState(const QByteArray& state);
	void saveCurrentLayoutState();
	void resetSavedLayoutState();
	static QString layoutSettingsKey();
	static QString firstRunKey();
	static QString debugLogPath();

protected:
	void showEvent(QShowEvent *event) override;
	void closeEvent(QCloseEvent *event) override;

private:
	void createDockWidgets();
	void createDockLayout();
	void setupDefaultLayout();
	void applyInitialDockSizes();
	void createLayoutToolbar();

private slots:
	void resetLayoutToDefault();

private:
	QDockWidget *m_basicDock = nullptr;
	QDockWidget *m_perDock = nullptr;
	QDockWidget *m_operaDock = nullptr;
	QDockWidget *m_whDock = nullptr;
	QToolBar *m_layoutToolbar = nullptr;
	QAction *m_resetLayoutAction = nullptr;
	bool m_initialLayoutApplied = false;

	BasicFracDockWidget *m_basicWidget = nullptr;
	PerforationDockWidget *m_perWidget = nullptr;
	OperaDockWidget *m_operaWidget = nullptr;
	WhDockWidget *m_whWidget = nullptr;
};
