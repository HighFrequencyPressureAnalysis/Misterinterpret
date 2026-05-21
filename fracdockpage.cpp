#include "fracdockpage.h"

#include <QDockWidget>
#include <QMainWindow>
#include <QShowEvent>
#include <QSizePolicy>
#include <QTimer>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QCloseEvent>

#include "dockwidgets/paneltitlebarwidget.h"

namespace {
QString rectToString(const QRect& r)
{
	return QStringLiteral("[%1,%2 %3x%4]")
		.arg(r.x())
		.arg(r.y())
		.arg(r.width())
		.arg(r.height());
}

QString sizeToString(const QSize& s)
{
	return QStringLiteral("[%1x%2]").arg(s.width()).arg(s.height());
}


void logDockState(const char* tag, const QWidget* page)
{
	qDebug().noquote()
		<< QStringLiteral("[FracDockPage] %1 size=%2 rect=%3 visible=%4 hidden=%5 central=%6")
			.arg(QString::fromLatin1(tag))
			.arg(sizeToString(page->size()))
			.arg(rectToString(page->rect()))
			.arg(page->isVisible())
			.arg(page->isHidden())
			.arg(page->findChild<QWidget*>(QString(), Qt::FindDirectChildrenOnly) ? QStringLiteral("[direct-child-present]") : QStringLiteral("[no-direct-child]"));
}

void logDockGeometry(const char* tag, const QMainWindow* page, const QDockWidget* basicDock, const QDockWidget* perDock, const QDockWidget* operaDock, const QDockWidget* whDock)
{
	qDebug().noquote()
		<< QStringLiteral("[FracDockPage] %1 size=%2 rect=%3 central=%4 basic=%5 per=%6 opera=%7 wh=%8")
			.arg(QString::fromLatin1(tag))
			.arg(sizeToString(page->size()))
			.arg(rectToString(page->rect()))
			.arg(page->centralWidget() ? sizeToString(page->centralWidget()->size()) : QStringLiteral("[-1x-1]"))
			.arg(basicDock ? rectToString(basicDock->geometry()) : QStringLiteral("[null]"))
			.arg(perDock ? rectToString(perDock->geometry()) : QStringLiteral("[null]"))
			.arg(operaDock ? rectToString(operaDock->geometry()) : QStringLiteral("[null]"))
			.arg(whDock ? rectToString(whDock->geometry()) : QStringLiteral("[null]"));
}
}

#include "dockwidgets/basicfracdockwidget.h"
#include "dockwidgets/perforationdockwidget.h"
#include "dockwidgets/operadockwidget.h"
#include "dockwidgets/whdockwidget.h"
#include "widgetbasicfrac.h"
#include "widgetfracper.h"
#include "plotopera.h"
#include "plotwh.h"
#include "HistoryDateModel.h"
#include "SingleTemplate.h"

FracDockPage::FracDockPage(QWidget *parent)
	: QMainWindow(parent)
{
	setDockNestingEnabled(true);
	setDocumentMode(true);
	setDockOptions(QMainWindow::AllowNestedDocks
		| QMainWindow::AllowTabbedDocks
		| QMainWindow::AnimatedDocks);
	setContentsMargins(0, 0, 0, 0);

	auto *central = new QWidget(this);
	central->setContentsMargins(0, 0, 0, 0);
	setCentralWidget(central);

	createDockWidgets();
}

FracDockPage::~FracDockPage() = default;

void FracDockPage::createDockWidgets()
{
	m_basicWidget = new BasicFracDockWidget(this);
	m_perWidget = new PerforationDockWidget(this);
	m_operaWidget = new OperaDockWidget(this);
	m_whWidget = new WhDockWidget(this);

	m_basicEntry.content = m_basicWidget;
	m_perEntry.content = m_perWidget;
	m_operaEntry.content = m_operaWidget;
	m_whEntry.content = m_whWidget;

	m_basicEntry.dock = new QDockWidget(QStringLiteral("Basic Info"), this);
	m_perEntry.dock = new QDockWidget(QStringLiteral("Perforation"), this);
	m_operaEntry.dock = new QDockWidget(QStringLiteral("Opera Curve"), this);
	m_whEntry.dock = new QDockWidget(QStringLiteral("WH Curve"), this);

	m_basicEntry.dock->setObjectName(QStringLiteral("FracDockBasic"));
	m_perEntry.dock->setObjectName(QStringLiteral("FracDockPerforation"));
	m_operaEntry.dock->setObjectName(QStringLiteral("FracDockOpera"));
	m_whEntry.dock->setObjectName(QStringLiteral("FracDockWH"));

	m_basicEntry.dock->setWidget(m_basicWidget);
	m_perEntry.dock->setWidget(m_perWidget);
	m_operaEntry.dock->setWidget(m_operaWidget);
	m_whEntry.dock->setWidget(m_whWidget);

	m_basicEntry.dock->setAllowedAreas(Qt::AllDockWidgetAreas);
	m_perEntry.dock->setAllowedAreas(Qt::AllDockWidgetAreas);
	m_operaEntry.dock->setAllowedAreas(Qt::AllDockWidgetAreas);
	m_whEntry.dock->setAllowedAreas(Qt::AllDockWidgetAreas);

	m_basicEntry.titleBar = new PanelTitleBarWidget(QStringLiteral("Basic Info"), this);
	m_perEntry.titleBar = new PanelTitleBarWidget(QStringLiteral("Perforation"), this);
	m_operaEntry.titleBar = new PanelTitleBarWidget(QStringLiteral("Opera Curve"), this);
	m_whEntry.titleBar = new PanelTitleBarWidget(QStringLiteral("WH Curve"), this);

	QObject::connect(m_basicEntry.titleBar, &PanelTitleBarWidget::requestToggleMaximize, this, [this]() { toggleDockPopup(&m_basicEntry); });
	QObject::connect(m_basicEntry.titleBar, &PanelTitleBarWidget::requestClose, this, [this]() { restoreDockPopup(&m_basicEntry); });
	QObject::connect(m_perEntry.titleBar, &PanelTitleBarWidget::requestToggleMaximize, this, [this]() { toggleDockPopup(&m_perEntry); });
	QObject::connect(m_perEntry.titleBar, &PanelTitleBarWidget::requestClose, this, [this]() { restoreDockPopup(&m_perEntry); });
	QObject::connect(m_operaEntry.titleBar, &PanelTitleBarWidget::requestToggleMaximize, this, [this]() { toggleDockPopup(&m_operaEntry); });
	QObject::connect(m_operaEntry.titleBar, &PanelTitleBarWidget::requestClose, this, [this]() { restoreDockPopup(&m_operaEntry); });
	QObject::connect(m_whEntry.titleBar, &PanelTitleBarWidget::requestToggleMaximize, this, [this]() { toggleDockPopup(&m_whEntry); });
	QObject::connect(m_whEntry.titleBar, &PanelTitleBarWidget::requestClose, this, [this]() { restoreDockPopup(&m_whEntry); });

	m_basicEntry.dock->setTitleBarWidget(m_basicEntry.titleBar);
	m_perEntry.dock->setTitleBarWidget(m_perEntry.titleBar);
	m_operaEntry.dock->setTitleBarWidget(m_operaEntry.titleBar);
	m_whEntry.dock->setTitleBarWidget(m_whEntry.titleBar);

	setDockInteractionEnabled(true);
}

void FracDockPage::createDockLayout()
{
	addDockWidget(Qt::LeftDockWidgetArea, m_basicEntry.dock);
	addDockWidget(Qt::LeftDockWidgetArea, m_perEntry.dock);
	addDockWidget(Qt::RightDockWidgetArea, m_operaEntry.dock);
	addDockWidget(Qt::RightDockWidgetArea, m_whEntry.dock);

	splitDockWidget(m_basicEntry.dock, m_perEntry.dock, Qt::Vertical);
	splitDockWidget(m_operaEntry.dock, m_whEntry.dock, Qt::Vertical);
	splitDockWidget(m_basicEntry.dock, m_operaEntry.dock, Qt::Horizontal);

	setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
	setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
	setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
	setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

	m_basicEntry.dock->show();
	m_perEntry.dock->show();
	m_operaEntry.dock->show();
	m_whEntry.dock->show();
	m_basicEntry.dock->raise();
	m_perEntry.dock->raise();
	m_operaEntry.dock->raise();
	m_whEntry.dock->raise();
}

void FracDockPage::setupDefaultLayout()
{
	m_basicEntry.dock->setMinimumWidth(480);
	m_perEntry.dock->setMinimumWidth(480);
	m_operaEntry.dock->setMinimumWidth(360);
	m_whEntry.dock->setMinimumWidth(360);

	m_basicEntry.dock->setMaximumHeight(100000);
	m_perEntry.dock->setMaximumHeight(100000);
	m_operaEntry.dock->setMaximumHeight(100000);
	m_whEntry.dock->setMaximumHeight(100000);

	setContentsMargins(0, 0, 0, 0);
	setMinimumSize(1400, 800);
	resize(1400, 800);
}

void FracDockPage::setDockInteractionEnabled(bool enabled)
{
	auto features = enabled
		? QDockWidget::DockWidgetMovable
		  | QDockWidget::DockWidgetClosable
		  | QDockWidget::DockWidgetFloatable
		: QDockWidget::NoDockWidgetFeatures;

	m_basicEntry.dock->setFeatures(features);
	m_perEntry.dock->setFeatures(features);
	m_operaEntry.dock->setFeatures(features);
	m_whEntry.dock->setFeatures(features);
}

void FracDockPage::showEvent(QShowEvent *event)
{
	logDockState("showEvent", this);

	QMainWindow::showEvent(event);

	logDockState("showEvent after base", this);

	if (!m_layoutInitialized) {
		m_layoutInitialized = true;
		logDockState("init layout start", this);
		createDockLayout();
		setupDefaultLayout();
		applyInitialDockSizes();
		logDockGeometry("init layout done", this, m_basicEntry.dock, m_perEntry.dock, m_operaEntry.dock, m_whEntry.dock);
	}

	QTimer::singleShot(0, this, [this]() {
		logDockGeometry("deferred correction 0ms", this, m_basicEntry.dock, m_perEntry.dock, m_operaEntry.dock, m_whEntry.dock);
		applyDeferredLayoutCorrection();
	});
	QTimer::singleShot(100, this, [this]() {
		logDockGeometry("deferred correction 100ms", this, m_basicEntry.dock, m_perEntry.dock, m_operaEntry.dock, m_whEntry.dock);
		applyDeferredLayoutCorrection();
	});
}

void FracDockPage::closeEvent(QCloseEvent *event)
{
	QMainWindow::closeEvent(event);
}

void FracDockPage::toggleDockPopup(DockEntry* entry)
{
	if (!entry || !entry->dock) {
		return;
	}
	if (entry->popup) {
		entry->popup->showNormal();
		entry->popup->resize(1000, 700);
		entry->popup->raise();
		entry->popup->activateWindow();
		updateDockTitleBarState(entry, true);
		return;
	}

	entry->originalArea = dockWidgetArea(entry->dock);
	if (entry->originalArea == Qt::NoDockWidgetArea) {
		entry->originalArea = Qt::LeftDockWidgetArea;
	}

	QWidget* content = entry->dock->widget();
	if (!content) {
		content = entry->content;
	}
	entry->dock->setWidget(nullptr);

	entry->popup = new QMainWindow(this);
	entry->popup->setAttribute(Qt::WA_DeleteOnClose, true);
	entry->popup->setWindowTitle(entry->dock->windowTitle());
	entry->popupHost = new QWidget(entry->popup);
	auto* popupLayout = new QVBoxLayout(entry->popupHost);
	popupLayout->setContentsMargins(0, 0, 0, 0);
	popupLayout->setSpacing(0);
	entry->popup->setCentralWidget(entry->popupHost);
	QObject::connect(entry->popup, &QMainWindow::destroyed, this, [this, entry]() {
		if (entry) {
			entry->popup = nullptr;
			entry->popupHost = nullptr;
			updateDockTitleBarState(entry, false);
		}
	});
	if (entry->titleBar) {
		entry->titleBar->setParent(entry->popupHost);
		popupLayout->addWidget(entry->titleBar);
		entry->titleBar->show();
	}
	if (content) {
		content->setParent(entry->popupHost);
		popupLayout->addWidget(content);
		content->show();
	}
	entry->popup->resize(1000, 700);
	entry->popup->showFullScreen();
	updateDockTitleBarState(entry, true);
}

void FracDockPage::restoreDockPopup(DockEntry* entry)
{
	if (!entry || !entry->dock || !entry->popup) {
		return;
	}

	QMainWindow* popup = entry->popup;
	entry->popup = nullptr;
	popup->setCentralWidget(nullptr);
	if (entry->popupHost) {
		entry->popupHost->deleteLater();
		entry->popupHost = nullptr;
	}

	if (dockWidgetArea(entry->dock) == Qt::NoDockWidgetArea) {
		addDockWidget(entry->originalArea, entry->dock);
	}
	if (entry->content) {
		entry->content->setParent(entry->dock);
		entry->dock->setWidget(entry->content);
		entry->content->show();
	}
	entry->dock->show();
	entry->dock->raise();
	if (entry->titleBar) {
		entry->titleBar->setParent(entry->dock);
		entry->dock->setTitleBarWidget(entry->titleBar);
		entry->titleBar->show();
	}

	popup->close();
	updateDockTitleBarState(entry, false);
}

void FracDockPage::updateDockTitleBarState(DockEntry* entry, bool maximized)
{
	if (!entry || !entry->titleBar) {
		return;
	}
	entry->titleBar->setMaximized(maximized);
}

bool FracDockPage::eventFilter(QObject *watched, QEvent *event)
{
	return QMainWindow::eventFilter(watched, event);
}

void FracDockPage::applyInitialDockSizes()
{
	resizeDocks({m_basicEntry.dock, m_perEntry.dock, m_operaEntry.dock, m_whEntry.dock}, {500, 500, 500, 500}, Qt::Horizontal);
	resizeDocks({m_basicEntry.dock, m_perEntry.dock}, {400, 400}, Qt::Vertical);
	resizeDocks({m_operaEntry.dock, m_whEntry.dock}, {400, 400}, Qt::Vertical);
}

void FracDockPage::applyDeferredLayoutCorrection()
{
	if (!isVisible()) {
		qDebug() << "FracDockPage deferred correction skipped: invisible";
		return;
	}

	refreshDockLayout();
	applyInitialDockSizes();
}

void FracDockPage::refreshDockLayout()
{
	if (!m_basicEntry.dock || !m_perEntry.dock || !m_operaEntry.dock || !m_whEntry.dock) {
		qDebug() << "FracDockPage refresh skipped: docks missing";
		return;
	}

	logDockGeometry("refreshDockLayout before", this, m_basicEntry.dock, m_perEntry.dock, m_operaEntry.dock, m_whEntry.dock);

	m_basicEntry.dock->updateGeometry();
	m_perEntry.dock->updateGeometry();
	m_operaEntry.dock->updateGeometry();
	m_whEntry.dock->updateGeometry();

	if (centralWidget()) {
		centralWidget()->updateGeometry();
	}
	updateGeometry();
	if (layout()) {
		layout()->invalidate();
		layout()->activate();
	}
	update();

	logDockGeometry("refreshDockLayout after", this, m_basicEntry.dock, m_perEntry.dock, m_operaEntry.dock, m_whEntry.dock);
}

void FracDockPage::renewFracBasicData(const DataMap& datamap, const StringMap& stringmap)
{
	m_basicWidget->contentWidget()->setData(datamap, stringmap);
}

void FracDockPage::renewFracPerData(const double& bgvalue, const DoubleVector& perdata)
{
	m_perWidget->contentWidget()->setData(bgvalue, perdata);
}

void FracDockPage::renewFracOperaData(const QString& sdatetime, const DoubleVectorMap& data)
{
	HistoryDateModel* datemodel = SingleTemplate<HistoryDateModel>::getInstance();
	datemodel->setFracDateTimeString(sdatetime);
	m_operaWidget->contentWidget()->setDateTime(sdatetime);
	m_operaWidget->contentWidget()->drawOperaGraph(data);
}

void FracDockPage::renewFracTestData(const QString& datetime, const DoubleVectorMap& data)
{
	HistoryDateModel* datemodel = SingleTemplate<HistoryDateModel>::getInstance();
	datemodel->setTestDateTimeString(datetime);
	DoubleVectorMap plotdata = data;
	m_operaWidget->contentWidget()->drawTestGraph(plotdata);
}

void FracDockPage::renewFracWHData(const int& freq, const DoubleVector& vp)
{
	m_whWidget->contentWidget()->drawPressGraph(freq, vp);
}

void FracDockPage::renewFracMergeData(const DoubleVector& t, const DoubleVector& p)
{
	m_operaWidget->contentWidget()->drawMergeGraph(t, p);
}

void FracDockPage::clear()
{
	m_basicWidget->contentWidget()->setDefault();
	m_perWidget->contentWidget()->clearTable();
	m_operaWidget->contentWidget()->clearPlot();
	m_operaWidget->contentWidget()->setGraphNull();
	m_whWidget->contentWidget()->clearPlot();
	m_whWidget->contentWidget()->setGraphNull();
}
