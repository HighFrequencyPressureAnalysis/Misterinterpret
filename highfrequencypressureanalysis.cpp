#include "HighFrequencyPressureAnalysis.h"
#include<SARibbonBar.h>
#include"SARibbonMainWindow.h"
#include<QDockWidget>
#include<QListWidget>
#include<QVBoxLayout>
#include<QDebug>
#include"WellDataControler.h"


HighFrequencyPressureAnalysis::HighFrequencyPressureAnalysis(QWidget *parent)
    : SARibbonMainWindow(parent)
{
    
	int a = 0;
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);

    SARibbonBar* ribbon = ribbonBar();
    //! 通过setContentsMargins设置ribbon四周的间距
    ribbon->setContentsMargins(0, 0, 0, 0);

    category = new Category();
    category->setCategoryName("");
    category->setHidden(false);
    ribbon->addCategoryPage(category);

    CpuMemoryLabel* cpulabel = new CpuMemoryLabel();
    cpulabel->start(1000);
    statusBar()->addPermanentWidget(cpulabel);

    ribbonBar()->setTabDoubleClickToMinimumMode(false);

    workarea = new WorkArea(this);
    setCentralWidget(workarea);
    
    WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
    welldatamanager->setCateGory(category);
    welldatamanager->initDataInfor();
    welldatamanager->setConnect();
    

}

HighFrequencyPressureAnalysis::~HighFrequencyPressureAnalysis()
{}



