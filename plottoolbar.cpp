#include "plottoolbar.h"

PlotToolBar::PlotToolBar(QWidget *parent)
	: QToolBar(parent)
{
	setOrientation(Qt::Vertical);
	zoomin = new QAction(s_zoomin, this);
	QIcon icon_zoomin(":/HighFrequencyPressureAnalysis/res/Icon/zoomin.jpg");
	zoomin->setIcon(icon_zoomin);
	zoomin->setCheckable(true);
	addAction(zoomin);

	zoomout = new QAction(s_zoomout, this);
	QIcon icon_zoomout(":/HighFrequencyPressureAnalysis/res/Icon/zoomout.jpg");
	zoomout->setIcon(icon_zoomout);
	addAction(zoomout);



	init = new QAction(s_init, this);
	QIcon icon_init(":/HighFrequencyPressureAnalysis/res/Icon/init.jpg");
	init->setIcon(icon_init);
	addAction(init);

	manual = new QAction(s_manual, this);
	QIcon icon_setting(":/HighFrequencyPressureAnalysis/res/Icon/setting.jpg");
	manual->setIcon(icon_setting);
	addAction(manual);

	zoom = new QAction(s_zoom, this);
	QIcon icon_zoom(":/HighFrequencyPressureAnalysis/res/Icon/zoom_mouse.jpg");
	zoom->setIcon(icon_zoom);
	zoom->setCheckable(true);
	addAction(zoom);



	drag = new QAction(s_drag, this);
	QIcon icon_drag(":/HighFrequencyPressureAnalysis/res/Icon/drag_mouse.jpg");
	drag->setCheckable(true);
	drag->setIcon(icon_drag);
	addAction(drag);

	lengend = new QAction(s_legend, this);
	QIcon icon_legend(":/HighFrequencyPressureAnalysis/res/Icon/legend.jpg");
	lengend->setCheckable(true);
	lengend->setIcon(icon_legend);
	addAction(lengend);

	showdata = new QAction(s_showdata, this);
	QIcon icon_showdata(":/HighFrequencyPressureAnalysis/res/Icon/showdata.png");
	showdata->setCheckable(true);
	showdata->setIcon(icon_showdata);
	addAction(showdata);

	

	showdatetime = new QAction(s_showdatetime, this);
	QIcon icon_datetime(":/HighFrequencyPressureAnalysis/res/Icon/date.png");
	showdatetime->setCheckable(true);
	showdatetime->setIcon(icon_datetime);
	addAction(showdatetime);

}

PlotToolBar::~PlotToolBar()
{}

void PlotToolBar::removePlotAction()
{
	removeAction(manual);
	removeAction(lengend);
	removeAction(showdata);
	removeAction(showdatetime);

}

void PlotToolBar::setDragAndZoomUnable()
{
	zoom->setChecked(false);
	drag->setChecked(false);
	zoomin->setChecked(false);
}

void PlotToolBar::setDataTimeVisible(bool visible)
{
	showdatetime->setVisible(visible);
	showdatetime->setChecked(visible);
}

void PlotToolBar::addCloudSetting()
{
	cloud = new QAction(s_cloud, this);
	QIcon icon_cloud(":/HighFrequencyPressureAnalysis/icon/cloudsetting.png");
	cloud->setIcon(icon_cloud);
	addAction(cloud);
}

QAction* PlotToolBar::getAction(const QString&type)
{
	if (type == s_zoomin) {
		return zoomin;
	}
	else if (type == s_zoomout) {
		return zoomout;
	}
	else if (type == s_init) {
		return init;
	}
	else if (type == s_manual) {
		return manual;
	}
	else if (type == s_zoom) {
		return zoom;
	}
	else if (type == s_drag) {
		return drag;
	}
	else if (type == s_legend) {
		return lengend;
	}
	else if (type == s_showdata) {
		return showdata;
	}
	else if (type == s_showdatetime) {
		return showdatetime;
	}
	else if (type == s_cloud) {
		return cloud;
	}
	else {
		return nullptr;
	}
}
