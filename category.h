#pragma once
#pragma execution_character_set("utf-8")
#include "SARibbonCategory.h"
#include<qcheckbox.h>

const QString strPannelBasicData = "基础数据";
const QString strPannelFracData = "压裂数据";
const QString strPannelHighFrequency = "高频数据";
const QString strPannelSegment = "单段数据";
const QString strNewBlock = "新建区块";
const QString strNewStation = "新建平台";
const QString strNewWell = "新建井";
const QString strNewStage = "新建段";
const QString strFracBasic = "压裂信息";
const QString strFracPer = "射孔信息";
const QString strFracOpera = "施工数据";
const QString strFracWh = "停泵水击";
const QString strFracMerge = "合并数据";

const QString strFracTest = "测试数据";
const QString strEnsFile = "Ens文件";
const QString strDefineFile = "自定义文件";
const QString strRemove = "删除";
const QString strRename = "重命名";

class Category  : public SARibbonCategory
{
	Q_OBJECT

public:
	Category(QWidget *parent=nullptr);
	~Category();

	void setCategoryEnble(bool);
	void renewCategoryEnble(const QStringList&);
	QAction* getAction(const QString&)const;
protected:
	SARibbonPannel* panneldata;
	SARibbonPannel* pannelfrac;
	SARibbonPannel* pannelhighfre;
	SARibbonPannel* pannelshowtype;

	QAction* createAction(const QString& text, const QString& iconurl, const QString& objName);
	QAction* createAction(const QString& text, const QString& iconurl);
	QAction* actblock;
	QAction* actstation;
	QAction* actwell;
	QAction* actstage;
	QAction* actrename;
	QAction* actremove;

	QAction* actbasicdata;
	QAction* actfracper;
	QAction* actfracopera;
	QAction* actfractest;
	QAction* actfracwh;

	QAction* actfracmerge;

	QAction* actens;
	QAction* actdefine;

	QCheckBox* chk_BasicData;      // 基础数据
	QCheckBox* chk_PerforationData;      // 射孔数据
	QCheckBox* chk_FractureData;  // 压裂施工数据
	QCheckBox* chk_TestData ;      // 测试数据

	void createCategory();

	
};

