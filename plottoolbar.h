#pragma once
#pragma execution_character_set("utf-8")
#include <QToolBar>

const QString s_zoomin = "放大";
const QString s_zoomout = "缩小";
const QString s_init = "初始化";
const QString s_drag = "拖曳坐标轴";
const QString s_zoom = "鼠标缩放";
const QString s_manual = "手工设置";
const QString s_legend = "图例";
const QString s_showdata = "显示数据";
const QString s_showdatetime = "日期时间";
const QString s_cloud = "云图设置";

class PlotToolBar  : public QToolBar
{
	Q_OBJECT

public:
	PlotToolBar(QWidget *parent);
	~PlotToolBar();
	
	void removePlotAction();
	void setDragAndZoomUnable();
	void setDataTimeVisible(bool visible);
	void addCloudSetting();
	QAction* getAction(const QString&);
private:
	//放大
	QAction* zoomin;
	//缩小
	QAction* zoomout;
	//手工
	QAction* manual;
	//初始化
	QAction* init;
	//缩放
	QAction* zoom;
	//拉拽
	QAction* drag;
	//图例
	QAction* lengend;
	//显示数据
	QAction* showdata;
	//显示数据
	QAction* showdatetime;
	//云图
	QAction* cloud;
};
