#include "workarea.h"
#include"WellDataControler.h"

WorkArea::WorkArea(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	int a = 0;
	ui.treeWidget->clear();
	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	welldatamanager->setTreeWidget(ui.treeWidget);
	welldatamanager->setLabelCurrent(ui.labelcurrent);
	ui.labelcurrent->clear();
	ui.treeWidget->setHeaderHidden(true);
	
	connect(ui.pushButton, &QPushButton::clicked, this, &WorkArea::clearChoose);
}

WorkArea::~WorkArea()
{}

void WorkArea::clearChoose()
{
	ui.treeWidget->clearSelection();
	ui.labelcurrent->clear();
}
