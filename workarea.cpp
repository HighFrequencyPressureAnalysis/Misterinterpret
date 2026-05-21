#include "workarea.h"
#include "WellDataControler.h"

WorkArea::WorkArea(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.treeWidget->clear();

	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	welldatamanager->setTreeWidget(ui.treeWidget);
	welldatamanager->setLabelCurrent(ui.labelcurrent);
	welldatamanager->setFracDockPage(ui.tabfrac);

	ui.labelcurrent->clear();
	ui.treeWidget->setHeaderHidden(true);
	ui.tabWidgetcompare->setCurrentIndex(0);

	connect(ui.pushButton, &QPushButton::clicked, this, &WorkArea::clearChoose);
}

WorkArea::~WorkArea()
{}

void WorkArea::clearChoose()
{
	ui.treeWidget->clearSelection();
	ui.labelcurrent->clear();
}
