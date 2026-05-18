#pragma once
#include <QtWidgets/QMainWindow>
#include<SARibbonMainWindow.h>
#include<SARibbonApplicationButton.h>
#include<SARibbonComboBox.h>
#include<SARibbonCheckBox.h>
#include<SARibbonCategory.h>
#include<SARibbonActionsManager.h>
#include<SARibbonQuickAccessBar.h>
#include<SARibbonPannel.h>
#include<SARibbonLineEdit.h>
#include<SARibbonButtonGroupWidget.h>
#include<SARibbonSystemButtonBar.h>
#include"category.h"
#include"cpumemorylabel.h"
#include<qstatusbar.h>
#include"workarea.h"

class HighFrequencyPressureAnalysis : public SARibbonMainWindow
{
    Q_OBJECT

public:
    HighFrequencyPressureAnalysis(QWidget *parent = nullptr);
    ~HighFrequencyPressureAnalysis();
private:
    Category* category;
    WorkArea* workarea;
private slots:
};
