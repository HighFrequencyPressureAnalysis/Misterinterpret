#include "workareafracbasic.h"
#include "fracdockpage.h"
#include "WellDataControler.h"

#include <QVBoxLayout>
#include <QSizePolicy>
#include <QTimer>
#include <QDebug>
#include <QShowEvent>

WorkAreaFracBasic::WorkAreaFracBasic(QWidget *parent)
	: QWidget(parent)
{
	auto *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);

	m_page = new FracDockPage(this);
	m_page->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	layout->addWidget(m_page);
	layout->setStretch(0, 1);
	m_page->show();

	qDebug() << "WorkAreaFracBasic create FracDockPage" << m_page;
	QTimer::singleShot(0, this, [this]() {
		qDebug() << "WorkAreaFracBasic 0ms update" << m_page << (m_page ? m_page->size() : QSize(-1, -1));
		if (m_page) {
			m_page->updateGeometry();
			m_page->update();
		}
	});
	QTimer::singleShot(100, this, [this]() {
		qDebug() << "WorkAreaFracBasic 100ms update" << m_page << (m_page ? m_page->size() : QSize(-1, -1));
		if (m_page) {
			m_page->updateGeometry();
			m_page->update();
		}
	});

	WellDataManager* welldatamanger = SingleTemplate<WellDataManager>::getInstance();
	welldatamanger->setWorkAreaBasic(this);
}

WorkAreaFracBasic::~WorkAreaFracBasic()
{}

void WorkAreaFracBasic::renewFracBasicData(const DataMap&datamap, const StringMap&stringmap)
{
	m_page->renewFracBasicData(datamap, stringmap);
}

void WorkAreaFracBasic::renewFracPerData(const double&bgvalue, const DoubleVector&perdata)
{
	m_page->renewFracPerData(bgvalue, perdata);
}

void WorkAreaFracBasic::renewFracOperaData(const QString&sdatetime,const DoubleVectorMap&data)
{
	m_page->renewFracOperaData(sdatetime, data);
}

void WorkAreaFracBasic::renewFracTestData(const QString&datetime, const DoubleVectorMap&data)
{
	m_page->renewFracTestData(datetime, data);
}

void WorkAreaFracBasic::renewFracWHData(const int&freq, const DoubleVector&vp)
{
	m_page->renewFracWHData(freq, vp);
}

void WorkAreaFracBasic::renewFracMergeData(const DoubleVector&t, const DoubleVector&p)
{
	m_page->renewFracMergeData(t, p);
}

void WorkAreaFracBasic::showEvent(QShowEvent *event)
{
	qDebug() << "WorkAreaFracBasic showEvent" << this << size() << isVisible() << isHidden();
	QWidget::showEvent(event);
	QTimer::singleShot(0, this, [this]() {
		qDebug() << "WorkAreaFracBasic showEvent 0ms" << this << size() << isVisible() << isHidden();
	});
	QTimer::singleShot(100, this, [this]() {
		qDebug() << "WorkAreaFracBasic showEvent 100ms" << this << size() << isVisible() << isHidden();
	});
}

void WorkAreaFracBasic::clear()
{
	m_page->clear();
}
