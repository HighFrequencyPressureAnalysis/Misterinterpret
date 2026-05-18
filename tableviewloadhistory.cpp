#include "tableviewloadhistory.h"
#include"ConstBasic.h"
#include"ConstCharacter.h"
#include<QMessageBox>
#include"DataProcess.h"
#include<QTime>
#include"HistorySettingModel.h"
#include"MessageBoxControler.h"
#include"HistoryLoadDataModel.h"
#include"ConstBasic.h"
#include"dialoghistorysetting.h"

TableViewLoadHistory::TableViewLoadHistory(QWidget *parent)
	: TableView(parent)
{	
	
	loaditemmodel = new LoadTableModel(this);
	setModel(loaditemmodel);
	horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
	
	connect(horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(showDataSetting(int)));
	connect(horizontalHeader(), SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(columncustomContextMenuRequested(QPoint)));
}

TableViewLoadHistory::~TableViewLoadHistory()
{
}


void TableViewLoadHistory::stopRead()
{
	loaditemmodel->stopRead();
}

void TableViewLoadHistory::setRowAndColumn(const int rowcount, const int coluncount)
{
	loaditemmodel->setRowAndColumn(rowcount, coluncount);
	loaditemmodel->updateModel();
}


void TableViewLoadHistory::setTableRowCount(int rowcount)
{
	loaditemmodel->setRowCount(rowcount);
	loaditemmodel->updateModel();
}

void TableViewLoadHistory::setTableColumnCount(int columncount)
{
	loaditemmodel->setColumnCount(columncount);
	loaditemmodel->updateModel();
}

void TableViewLoadHistory::setLoadData(const QString&text)
{
	loaditemmodel->setLoadData(text);
	loaditemmodel->updateModel();
}

void TableViewLoadHistory::setStringList(const StringVectorVector&stringlist)
{
	loaditemmodel->setStringList(stringlist);
	loaditemmodel->updateModel();
}


void TableViewLoadHistory::checkHeader(QStringList& types,const int column)
{
	QStringList datatypes = loaditemmodel->getDataTypes();
	QString type;
	for (int i = 0; i < datatypes.size(); i++) {
		type = datatypes[i];
		if (type == s_t) {
			types.removeOne(s_date);
			types.removeOne(s_time);
			types.removeOne(s_datetime);
		}
		if (type == s_datetime) {
			types.removeOne(s_date);
			types.removeOne(s_time);
			types.removeOne(s_t);
		}
		if (type == s_date || type == s_time) {
			types.removeOne(s_datetime);
			types.removeOne(s_t);
		}
		types.removeOne(type);
		
	}
	QString currenttype = loaditemmodel->getCurrentType(column);
	if (!currenttype.isEmpty()) {
		types.push_back(currenttype);
	}
	
}

void TableViewLoadHistory::setHeader(const QString&type, const QString&unit, const int column) 
{
	if (type == s_undefined) {
		loaditemmodel->setHeader(column,QString());
	}
	else {
		QString text = type;
		if (!unit.isEmpty()) {
			text += s_interval + unit;
		}
		loaditemmodel->setHeader(column, text);
	}
	
}

bool TableViewLoadHistory::checkTableState(const QString&edittype)
{	
	const QStringList types = loaditemmodel->getDataTypes();
	MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
	QString text;
	if (edittype != s_waterhammerpress) {
		if (types.size() < 1) {
			text = "数据行数据不够";
			messageboxcontroler->showWarningMessageBox(text);
			return false;
		}
		if (!types.isEmpty()) {
			if (types.size() < 2) {
				text = "数据类型不够";
				messageboxcontroler->showWarningMessageBox(text);
				return false;
			}
			if (!types.contains(s_t) && !types.contains(s_datetime) && !types.contains(s_time)) {
				text = "必须包含进制时间或者日期时间";
				messageboxcontroler->showWarningMessageBox(text);
				return false;
			}
			HistorySettingModel* historymodel = SingleTemplate<HistorySettingModel>::getInstance();
			QString keyword = historymodel->getEditType();
			QString text;

			if (keyword == s_fracopratedata) {
				if (!types.contains(s_qpump)|| !types.contains(s_pressure)) {
					text = "必须包含泵注入、压力、砂浓度数据";
					messageboxcontroler->showWarningMessageBox(text);
					return false;
				}
			}
			else {
				if (!types.contains(s_pressure)) {
					text = "必须包含压力数据";
					messageboxcontroler->showWarningMessageBox(text);
					return false;
				}
			}
		}
	}
	else {
		if (!types.contains(s_pressure)) {
			text = "必须包含压力数据";
			messageboxcontroler->showWarningMessageBox(text);
			return false;
		}
	}
	return true;
}

QStringList TableViewLoadHistory::getHeaderAllDataTypes() const
{
	return loaditemmodel->getAllDataTypes();
}

StringVectorVector TableViewLoadHistory::getTableStringVectorVector() const
{
	return loaditemmodel->getTableStringVectorVector();
}




void TableViewLoadHistory::clearHeader()
{
	int column = currentIndex().column();
	loaditemmodel->clearAppointHeader(column);
}

void TableViewLoadHistory::columncustomContextMenuRequested(QPoint)
{
	menucolumn = new QMenu(this);
	menucolumn->setAttribute(Qt::WA_DeleteOnClose);
	menucolumn->addAction("清空表头", this, [this]() {this->clearHeader(); });
	menucolumn->exec(QCursor::pos());
}

void TableViewLoadHistory::showDataSetting(int column)
{
	HistorySettingModel* settingmodel = SingleTemplate<HistorySettingModel>::getInstance();
	const QString edittype = settingmodel->getEditType();
	QStringList types;
	if (edittype == s_fracopratedata) {
		types << s_t << s_datetime << s_time<<s_date << s_pressure<<s_qpump <<s_sandCon<< s_undefined;
	}
	if (edittype == s_fractestdata) {
		types << s_t << s_datetime << s_time<<s_date<<s_undefined<<s_pressure;
	}
	if (edittype == s_waterhammerpress) {
		types << s_pressure;
	}
	checkHeader(types,column);
	settingmodel->setColumn(column);
	DialogHistorySetting* dialog = new DialogHistorySetting(types);
	dialog->exec();
}