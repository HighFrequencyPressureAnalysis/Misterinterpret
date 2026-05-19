#include "workareafracbasic.h"
#include "fracdockpage.h"
#include "WellDataControler.h"

#include <QVBoxLayout>

WorkAreaFracBasic::WorkAreaFracBasic(QWidget *parent)
	: QWidget(parent)
{
	auto *layout = new QVBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);

	m_page = new FracDockPage(this);
	layout->addWidget(m_page);

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

void WorkAreaFracBasic::clear()
{
	m_page->clear();
}


