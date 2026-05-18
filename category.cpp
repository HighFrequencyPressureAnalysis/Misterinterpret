#include "category.h"

Category::Category(QWidget *parent)
	: SARibbonCategory(parent)
{
	createCategory();
	renewCategoryEnble(QStringList());

}

Category::~Category()
{}

void Category::setCategoryEnble(bool enble)
{	
	int count = pannelList().size();
	if (count) {
		for (int i = 1; i < count; i++) {
			pannelList()[i]->setEnabled(enble);
		}
	}
	
}

void Category::renewCategoryEnble(const QStringList&types)
{
	int count = types.size();
	getAction(strNewBlock)->setEnabled(false);
	getAction(strNewStation)->setEnabled(false);
	getAction(strNewWell)->setEnabled(false);
	getAction(strNewStage)->setEnabled(false);
	pannelfrac->setEnabled(false);
	if (count == 0) {
		getAction(strNewBlock)->setEnabled(true);
	}
	else if (count == 1) {
		getAction(strNewStation)->setEnabled(true);
	}
	else if (count == 2) {
		getAction(strNewWell)->setEnabled(true);
	}
	else if (count == 3) {
		getAction(strNewStage)->setEnabled(true);
		
	}
	else{
		pannelfrac->setEnabled(true);
		
		
	}
}

QAction* Category::getAction(const QString&actionName) const
{
	if (actionName == strNewBlock) {
		return actblock;
	}
	if (actionName == strNewStation) {
		return actstation;
	}
	else if (actionName == strNewWell) {
		return actwell;
	}
	else if (actionName == strNewStage) {
		return actstage;
	}
	else if (actionName == strFracBasic) {
		return actbasicdata;
	}
	else if (actionName == strFracOpera) {
		return actfracopera;
	}
	else if (actionName == strFracTest) {
		return actfractest;
	}
	else if (actionName == strFracPer) {
		return actfracper;
	}
	else if (actionName == strFracWh) {
		return actfracwh;
	}
	else if (actionName == strEnsFile) {
		return actens;
	}
	else if (actionName == strDefineFile) {
		return actdefine;
	}
	else if (actionName == strRemove) {
		return actremove;
	}
	else if (actionName == strRename) {
		return actrename;
	}
	else if (actionName == strFracMerge) {
		return actfracmerge;
	}
	return nullptr;
}



QAction* Category::createAction(const QString & text, const QString & iconurl, const QString & objName)
{
	QAction* act = new QAction(this);
	act->setText(text);
	act->setIcon(QIcon(iconurl));
	act->setObjectName(objName);
	return act;
	
}

QAction* Category::createAction(const QString& text, const QString& iconurl)
{
	QAction* act = new QAction(this);
	act->setText(text);
	act->setIcon(QIcon(iconurl));
	act->setObjectName(text);
	return act;
}

void Category::createCategory()
{
	panneldata = addPannel(strPannelBasicData);
	actblock = createAction(strNewBlock, ":/HighFrequencyPressureAnalysis/res/Icon/block.jpg");
	panneldata->addMediumAction(actblock);

	actstation = createAction(strNewStation, ":/HighFrequencyPressureAnalysis/res/Icon/station.jpeg");
	panneldata->addMediumAction(actstation);

	actwell = createAction(strNewWell, ":/HighFrequencyPressureAnalysis/res/Icon/well.jpeg");
	panneldata->addMediumAction(actwell);

	actstage = createAction(strNewStage, ":/HighFrequencyPressureAnalysis/res/Icon/fracstage.jpeg");
	panneldata->addMediumAction(actstage);

	actremove = createAction(strRemove, ":/HighFrequencyPressureAnalysis/res/Icon/delete.jpg");
	panneldata->addMediumAction(actremove);

	actrename = createAction(strRename, ":/HighFrequencyPressureAnalysis/res/Icon/rename.jpg");
	panneldata->addMediumAction(actrename);

	pannelfrac = addPannel(strPannelFracData);

	actbasicdata = createAction(strFracBasic, ":/HighFrequencyPressureAnalysis/res/Icon/fracbasic.jpeg");
	pannelfrac->addMediumAction(actbasicdata);

	actfracper = createAction(strFracPer, ":/HighFrequencyPressureAnalysis/res/Icon/bgpos.jpg");
	pannelfrac->addMediumAction(actfracper);

	actfracopera = createAction(strFracOpera, ":/HighFrequencyPressureAnalysis/res/Icon/operaplot.jpeg");
	pannelfrac->addMediumAction(actfracopera);

	actfractest = createAction(strFracTest, ":/HighFrequencyPressureAnalysis/res/Icon/choose_press.png");
	pannelfrac->addMediumAction(actfractest);

	actfracwh = createAction(strFracWh, ":/HighFrequencyPressureAnalysis/res/Icon/autocal.jpg");
	pannelfrac->addMediumAction(actfracwh);

	actfracmerge = createAction(strFracMerge, ":/HighFrequencyPressureAnalysis/res/Icon/mergedata.jpg");
	pannelfrac->addMediumAction(actfracmerge);

	

	pannelhighfre = addPannel(strPannelHighFrequency);

	actens = createAction(strEnsFile, ":/HighFrequencyPressureAnalysis/res/Icon/loadensdata.jpg");
	pannelhighfre->addLargeAction(actens);

	actdefine = createAction(strDefineFile, ":/HighFrequencyPressureAnalysis/res/Icon/loaddefinedata.jpg");
	pannelhighfre->addLargeAction(actdefine);

	pannelshowtype = addPannel(strPannelSegment);
	chk_BasicData = new QCheckBox(strFracBasic);      // 基础数据
	chk_PerforationData = new QCheckBox(strFracPer);      // 射孔数据
	chk_FractureData = new QCheckBox(strFracOpera);  // 压裂施工数据
	chk_TestData = new QCheckBox(strFracTest);      // 测试数据
	pannelshowtype->addSmallWidget(chk_BasicData);
	pannelshowtype->addSmallWidget(chk_PerforationData);
	pannelshowtype->addSmallWidget(chk_FractureData);
	pannelshowtype->addSmallWidget(chk_TestData);


}

