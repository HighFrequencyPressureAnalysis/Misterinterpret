#include "fracdockpage.h"

#include <QAction>
#include <QApplication>
#include <QDateTime>
#include <QDockWidget>
#include <QFile>
#include <QSizePolicy>
#include <QSettings>
#include <QTimer>
#include <QToolBar>
#include <QTextStream>

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
	setDockOptions(QMainWindow::AllowNestedDocks | QMainWindow::AnimatedDocks);
	setContentsMargins(0, 0, 0, 0);
	setCentralWidget(new QWidget(this));

	createDockWidgets();
	createDockLayout();
	setupDefaultLayout();
}

FracDockPage::~FracDockPage() = default;

void FracDockPage::createDockWidgets()
{
	m_basicWidget = new BasicFracDockWidget(this);
	m_perWidget = new PerforationDockWidget(this);
	m_operaWidget = new OperaDockWidget(this);
	m_whWidget = new WhDockWidget(this);

	m_basicDock = new QDockWidget("Basic Info", this);
	m_perDock = new QDockWidget("Perforation", this);
	m_operaDock = new QDockWidget("Opera Curve", this);
	m_whDock = new QDockWidget("WH Curve", this);

	m_basicDock->setObjectName(QStringLiteral("FracDockBasic"));
	m_perDock->setObjectName(QStringLiteral("FracDockPerforation"));
	m_operaDock->setObjectName(QStringLiteral("FracDockOpera"));
	m_whDock->setObjectName(QStringLiteral("FracDockWH"));

	m_basicWidget->setObjectName(QStringLiteral("FracDockBasicWidget"));
	m_perWidget->setObjectName(QStringLiteral("FracDockPerWidget"));
	m_operaWidget->setObjectName(QStringLiteral("FracDockOperaWidget"));
	m_whWidget->setObjectName(QStringLiteral("FracDockWHWidget"));

	m_basicDock->setWidget(m_basicWidget);
	m_perDock->setWidget(m_perWidget);
	m_operaDock->setWidget(m_operaWidget);
	m_whDock->setWidget(m_whWidget);

	m_basicDock->setAllowedAreas(Qt::AllDockWidgetAreas);
	m_perDock->setAllowedAreas(Qt::AllDockWidgetAreas);
	m_operaDock->setAllowedAreas(Qt::AllDockWidgetAreas);
	m_whDock->setAllowedAreas(Qt::AllDockWidgetAreas);

	m_basicDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	m_perDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	m_operaDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	m_whDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

}

void FracDockPage::createDockLayout()
{
	addDockWidget(Qt::LeftDockWidgetArea, m_basicDock);
	addDockWidget(Qt::LeftDockWidgetArea, m_perDock);
	addDockWidget(Qt::RightDockWidgetArea, m_operaDock);
	addDockWidget(Qt::RightDockWidgetArea, m_whDock);

	// 左侧：基础信息 + 射孔信息（上下）
	splitDockWidget(m_basicDock, m_perDock, Qt::Vertical);
	// 右侧：施工曲线 + 停泵水击（上下）
	splitDockWidget(m_operaDock, m_whDock, Qt::Vertical);
	// 左右两列分开
	splitDockWidget(m_basicDock, m_operaDock, Qt::Horizontal);

	setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
	setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
	setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
	setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

	m_basicDock->raise();
	m_perDock->raise();
	m_operaDock->raise();
	m_whDock->raise();
}

void FracDockPage::setupDefaultLayout()
{
	m_basicDock->setMinimumWidth(480);
	m_perDock->setMinimumWidth(480);
	m_operaDock->setMinimumWidth(360);
	m_whDock->setMinimumWidth(360);

	m_basicDock->setMaximumHeight(100000);
	m_perDock->setMaximumHeight(100000);
	m_operaDock->setMaximumHeight(100000);
	m_whDock->setMaximumHeight(100000);

	m_basicDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	m_perDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	m_operaDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	m_whDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

	setContentsMargins(0, 0, 0, 0);
	setCentralWidget(new QWidget(this));
	setMinimumSize(1400, 800);
	resize(1400, 800);

	setStyleSheet(R"(
		QDockWidget {
			border: 1px solid #cfcfcf;
			background: #ffffff;
		}
		QDockWidget::title {
			background: #f4f4f4;
			padding: 4px 8px;
			font-weight: 600;
			border-bottom: 1px solid #d9d9d9;
		}
	)");

	createLayoutToolbar();

	m_basicDock->setFloating(false);
	m_perDock->setFloating(false);
	m_operaDock->setFloating(false);
	m_whDock->setFloating(false);
}

void FracDockPage::setDockInteractionEnabled(bool enabled)
{
	auto features = enabled
		? QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable
		: QDockWidget::NoDockWidgetFeatures;

	m_basicDock->setFeatures(features);
	m_perDock->setFeatures(features);
	m_operaDock->setFeatures(features);
	m_whDock->setFeatures(features);
}

QString FracDockPage::layoutSettingsKey()
{
	return QStringLiteral("UI/FracDockPage/LayoutStateV5");
}

QString FracDockPage::firstRunKey()
{
	return QStringLiteral("UI/FracDockPage/FirstRunDoneV5");
}

QString FracDockPage::debugLogPath()
{
	return QCoreApplication::applicationDirPath() + QStringLiteral("/fracdockpage.log");
}

void FracDockPage::resetSavedLayoutState()
{
	QSettings settings;
	settings.remove(layoutSettingsKey());
}

QByteArray FracDockPage::saveLayoutState() const
{
	return saveState();
}

bool FracDockPage::restoreLayoutState(const QByteArray& state)
{
	return restoreState(state);
}

void FracDockPage::createLayoutToolbar()
{
	if (m_layoutToolbar) {
		return;
	}
	m_layoutToolbar = new QToolBar(QStringLiteral("Layout"), this);
	m_layoutToolbar->setObjectName(QStringLiteral("FracDockLayoutToolbar"));
	m_layoutToolbar->setMovable(false);
	m_layoutToolbar->setFloatable(false);
	addToolBar(Qt::TopToolBarArea, m_layoutToolbar);
	m_resetLayoutAction = m_layoutToolbar->addAction(QStringLiteral("Reset Layout"));
	connect(m_resetLayoutAction, &QAction::triggered, this, &FracDockPage::resetLayoutToDefault);
}

void FracDockPage::saveCurrentLayoutState()
{
	QSettings settings;
	settings.setValue(layoutSettingsKey(), saveState());
	settings.setValue(firstRunKey(), true);
}

void FracDockPage::resetLayoutToDefault()
{
	QFile file(debugLogPath());
	if (file.open(QIODevice::Append | QIODevice::Text)) {
		QTextStream out(&file);
		out << QDateTime::currentDateTime().toString(Qt::ISODate) << " resetLayoutToDefault\n";
	}
	resetSavedLayoutState();
	QSettings settings;
	settings.remove(firstRunKey());
	m_initialLayoutApplied = false;
	QTimer::singleShot(0, this, [this]() {
		QTimer::singleShot(0, this, [this]() {
			QTimer::singleShot(0, this, [this]() {
				createDockLayout();
				applyInitialDockSizes();
				saveCurrentLayoutState();
				QFile file(debugLogPath());
				if (file.open(QIODevice::Append | QIODevice::Text)) {
					QTextStream out(&file);
					out << QDateTime::currentDateTime().toString(Qt::ISODate) << " resetLayoutToDefault saved " << saveState().size() << "\n";
				}
			});
		});
	});
}

void FracDockPage::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event);
	if (m_initialLayoutApplied) {
		return;
	}
	m_initialLayoutApplied = true;

	QFile file(debugLogPath());
	if (file.open(QIODevice::Append | QIODevice::Text)) {
		QTextStream out(&file);
		out << QDateTime::currentDateTime().toString(Qt::ISODate) << " showEvent\n";
	}

	QSettings settings;
	const bool firstRunDone = settings.value(firstRunKey(), false).toBool();
	const QByteArray saved = settings.value(layoutSettingsKey()).toByteArray();
	if (firstRunDone && !saved.isEmpty()) {
		if (file.open(QIODevice::Append | QIODevice::Text)) {
			QTextStream out(&file);
			out << QDateTime::currentDateTime().toString(Qt::ISODate) << " restore size=" << saved.size() << "\n";
		}
		if (restoreState(saved)) {
			if (file.open(QIODevice::Append | QIODevice::Text)) {
				QTextStream out(&file);
				out << QDateTime::currentDateTime().toString(Qt::ISODate) << " restore success\n";
			}
			return;
		}
		if (file.open(QIODevice::Append | QIODevice::Text)) {
			QTextStream out(&file);
			out << QDateTime::currentDateTime().toString(Qt::ISODate) << " restore failed\n";
		}
	}

	QTimer::singleShot(0, this, [this]() {
		QTimer::singleShot(0, this, [this]() {
			QTimer::singleShot(0, this, [this]() {
				createDockLayout();
				applyInitialDockSizes();
				saveCurrentLayoutState();
				QFile file(debugLogPath());
				if (file.open(QIODevice::Append | QIODevice::Text)) {
					QTextStream out(&file);
					out << QDateTime::currentDateTime().toString(Qt::ISODate) << " save size=" << saveState().size() << "\n";
				}
			});
		});
	});
}


void FracDockPage::applyInitialDockSizes()
{
	resizeDocks({m_basicDock, m_perDock, m_operaDock, m_whDock}, {500, 500, 500, 500}, Qt::Horizontal);
	resizeDocks({m_basicDock, m_perDock}, {400, 400}, Qt::Vertical);
	resizeDocks({m_operaDock, m_whDock}, {400, 400}, Qt::Vertical);
}

void FracDockPage::closeEvent(QCloseEvent *event)
{
	saveCurrentLayoutState();
	QMainWindow::closeEvent(event);
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
