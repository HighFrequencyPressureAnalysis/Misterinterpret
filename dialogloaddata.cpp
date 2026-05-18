#include "dialogloaddata.h"
#include<Windows.h>
#include"MessageBoxControler.h"
#include"HistorySettingModel.h"
#include"HistoryLoadDataModel.h"
#include<QDir>
#include<QFileDialog>
#include<qclipboard.h>
#include"dialogwaitingreaddata.h"
#include"DataProcess.h"
#include<qtextstream.h>
#include"ConstBasic.h"
#include"TableViewControler.h"
#include"ConstUnit.h"
#include"WellDataControler.h"

DialogLoadData::DialogLoadData(const QString&edittype,QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	HistorySettingModel* historysettingmodel = SingleTemplate<HistorySettingModel>::getInstance();
	historysettingmodel->setEditType(edittype);
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	historyloaddatamodel->setEditType(edittype);
	QString windowtitle;
	windowtitle = "导入" + edittype + "数据";
	setWindowTitle(windowtitle);
	ui.labelreminder->setText(windowtitle);

	if (edittype == s_waterhammerpress) {
		QStringList freqtypes;
		freqtypes << "1000" << "2000" << "5000";
		ui.comboBoxfre->addItems(freqtypes);
		ui.groupBoxfre->setVisible(true);
	}
	else {
		ui.groupBoxfre->setVisible(false);
	}
	QString referencetime;
	QString index;
	
	if (referencetime.isEmpty()) {
		ui.dateTimeEdit->setDateTime(QDateTime::currentDateTime());
	}
	else {
		ui.dateTimeEdit->setDateTime(QDateTime::fromString(referencetime, s_datetimeformat));
	}
	ui.lineEditindex->setText("未定义");
	
	TableViewControler* tableviewcontroler = SingleTemplate<TableViewControler>::getInstance();
	tableviewcontroler->setTableViewLoad(ui.tableView);

	buttongroup = new QButtonGroup();
	buttongroup->addButton(ui.pushButtontxt, 0);
	buttongroup->addButton(ui.pushButtonexcel, 1);
	buttongroup->addButton(ui.pushButtonclipboard, 2);
	buttongroup->addButton(ui.pushButtontable, 3);

	ui.groupBoxexcel->setVisible(false);
	ui.groupBoxtable->setVisible(false);

	ui.pushButtonclipboard->setCheckable(true);
	ui.pushButtontxt->setCheckable(true);
	ui.pushButtonexcel->setCheckable(true);
	ui.pushButtontable->setCheckable(true);

	buttongroup->setExclusive(true);

	connect(buttongroup, SIGNAL(buttonClicked(int)), this, SLOT(setLoadType()));
	connect(ui.pushButtontable, &QPushButton::clicked, this, &DialogLoadData::showTableLoad);
	connect(ui.pushButtonclipboard, &QPushButton::clicked, this, &DialogLoadData::sendClipboardData);
	connect(ui.pushButtontxt, &QPushButton::clicked, this, &DialogLoadData::sendTxtData);
	connect(ui.pushButtonexcel, &QPushButton::clicked, this, &DialogLoadData::sendExcelData);


	connect(ui.pushButtonclose, &QPushButton::clicked, this, &QDialog::close);
	connect(ui.comboBoxsheet, SIGNAL(currentIndexChanged(int)), this, SLOT(readExcelSheet(int)));
	connect(ui.spinBoxrow, SIGNAL(valueChanged(int)), ui.tableView, SLOT(setTableRowCount(int)));
	connect(ui.spinBoxcolumn, SIGNAL(valueChanged(int)), ui.tableView, SLOT(setTableColumnCount(int)));

	connect(ui.pushButtonnext, &QPushButton::clicked, this, &DialogLoadData::loadData);

	
}

DialogLoadData::~DialogLoadData()
{
	if (excel) {
		if (workbook) {
			workbook->dynamicCall("Close(Boolean)", false);
			delete workbook;
		}
		excel->dynamicCall("Quit(void)");
		delete excel;
	}
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	historyloaddatamodel->clear();
}




void DialogLoadData::setTableEditable(bool enble)
{
	if (!enble) {
		ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
	else {
		ui.tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
}

void DialogLoadData::sendTxtData()
{

	QDir dir;
	const QString filename = QFileDialog::getOpenFileName(this, "打开文件", dir.absolutePath(), "Txt Files (*.txt)");
	if (!filename.isEmpty()) {
		QFile file(filename);
		if (!file.open(QFile::ReadOnly | QFile::Text)) {
			QString text = "无法读取" + filename + "\n" + file.errorString();
			QMessageBox::warning(this, "读取数据失败", text);
			return;
		}
		else {
			setTableEditable(false);
			ui.labelfilepath->setText(filename);
			QFileInfo fileinfo(file);
			ui.lineEditindex->setText(fileinfo.baseName());
			QTextStream in(&file);
			QString text = in.readAll();
			ui.tableView->setLoadData(text);
			file.close();

			HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
			historyloaddatamodel->setLoadHistoryDataType(LoadHistoryDataType::txt);
			historyloaddatamodel->setText(text);

		}
	}
}

void DialogLoadData::sendExcelData()
{
	QDir dir;
	const QString filename = QFileDialog::getOpenFileName(this, "打开文件", dir.absolutePath(), "Excel Files (*.xls *.xlsx)");
	if (!filename.isEmpty()) {
		ui.labelfilepath->setText(filename);
		QFileInfo fileinfo(filename);
		ui.lineEditindex->setText(fileinfo.baseName());
		setTableEditable(false);
		readExcelData();
	}
	else {
		return;
	}

}

void DialogLoadData::sendClipboardData()
{
	setTableEditable(false);
	ui.labelfilepath->clear();
	QClipboard* board = QApplication::clipboard();
	QString text = board->text();
	ui.tableView->setLoadData(text);
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	historyloaddatamodel->setLoadHistoryDataType(LoadHistoryDataType::clipboard);
	historyloaddatamodel->setText(text);

}

void DialogLoadData::loadData()
{
	DoubleVectorMap vectormap;
	HistorySettingModel* settingmodel = SingleTemplate<HistorySettingModel>::getInstance();
	const QString datatype = settingmodel->getEditType();
	if (1) {
		bool fit = ui.tableView->checkTableState(datatype);
		if (fit) {
			HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
			bool tableload = historyloaddatamodel->isTableLoadData();
			if (tableload) {
				StringVectorVector content = ui.tableView->getTableStringVectorVector();
				historyloaddatamodel->setStringVectorVector(content);
			}
			QStringList headertypes = ui.tableView->getHeaderAllDataTypes();
			historyloaddatamodel->setHeaderDataTypes(headertypes);
			QDateTime datetime = ui.dateTimeEdit->dateTime();
			QString sdatetime = datetime.toString(s_datetimeformat);
			historyloaddatamodel->setDateTime(datetime);
			DialogWaitingReadData* dialog = new DialogWaitingReadData();
			dialog->exec();
			vectormap = historyloaddatamodel->getVectorMap();
			if (!vectormap.isEmpty()) {
				if (datatype == s_fracopratedata) {
					WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
					welldatamanager->setOperaData(sdatetime, vectormap);
				}
				if (datatype == s_fractestdata) {
					WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
					welldatamanager->setTestData(sdatetime, vectormap);
				}
				if (datatype == s_waterhammerpress) {
					int freq = ui.comboBoxfre->currentText().toInt();
					WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
					welldatamanager->setFracWHData(freq, vectormap[s_pressure]);
				}
				close();
			}
			//int a = 0;
		}
	}
	
	
	

}

void DialogLoadData::readExcelData()
{
	const QString filename = ui.labelfilepath->text();
	if (filename.isEmpty()) {

	}
	QAxObject* workbooks = nullptr;
	QAxObject* worksheet = nullptr;
	bool isexcel = isExcelInstalled();
	bool iswps = isWpsInstalled();
	MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
	if (!isexcel && !iswps) {
		messageboxcontroler->showWarningMessageBox("需要安装Office或者WPS");
		return;
	}
	if (isexcel) {
		excel = new QAxObject("Excel.Application", 0);
	}
	else {
		excel = new QAxObject("Ket.Application", 0);
	}



	if (!excel) {
		QMessageBox::warning(nullptr, "警告", "Excel未安装");
		return;
	}
	excel->dynamicCall("SetVisible(bool)", false);
	workbooks = excel->querySubObject("WorkBooks");
	workbooks->dynamicCall("Open(const QString&)", filename);
	workbook = excel->querySubObject("ActiveWorkBook");
	if (!workbook) {
		QMessageBox::warning(nullptr, "警告", "Excel未激活无法读取");
		workbook->dynamicCall("Close()"); //关闭工作簿 
		excel->dynamicCall("Quit()"); //退出进程
		return;
	}
	worksheet = workbook->querySubObject("WorkSheets");
	int countsheet = worksheet->property("Count").toInt();
	QAxObject* usedrange;
	QVariant var;
	QString text;
	QString name;
	QStringList sheetnames;
	for (int i = 1; i <= countsheet; i++) {
		worksheet = workbook->querySubObject("WorkSheets(int)", i);
		name = worksheet->property("Name").toString();
		usedrange = worksheet->querySubObject("UsedRange");
		var = usedrange->dynamicCall("Value");
		if (var.isValid()) {
			sheetnames.push_back(name);
		}

	}

	if (!sheetnames.isEmpty()) {
		ui.comboBoxsheet->blockSignals(true);
		ui.comboBoxsheet->clear();
		ui.comboBoxsheet->addItems(sheetnames);
		ui.comboBoxsheet->setCurrentIndex(-1);
		ui.comboBoxsheet->blockSignals(false);
		ui.comboBoxsheet->setCurrentIndex(0);
	}
	else {
		QMessageBox::warning(nullptr, "警告", "当前Excel没有Sheet");
		return;
	}

}

void DialogLoadData::showTableLoad()
{
	setTableEditable(true);
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	historyloaddatamodel->setLoadHistoryDataType(LoadHistoryDataType::table);
	int rowcount = ui.spinBoxrow->value();
	int columncount = ui.spinBoxcolumn->value();
	ui.tableView->setRowAndColumn(rowcount, columncount);
}


bool DialogLoadData::isExcelInstalled()
{
	QAxObject excel("Excel.Application");
	if (excel.isNull()) {
		return false;
	}
	return true;
	return false;
}

bool DialogLoadData::isWpsInstalled()
{
	QAxObject excel("Ket.Application");
	if (excel.isNull()) {
		return false;
	}
	return true;
	return false;
}

void DialogLoadData::setLoadType()
{
	ui.groupBoxtable->setVisible(ui.pushButtontable->isChecked());
	ui.groupBoxexcel->setVisible(ui.pushButtonexcel->isChecked());
}

void DialogLoadData::readExcelSheet(int index)
{
	QAxObject* usedrange;
	QAxObject* rows = nullptr;
	QAxObject* columns = nullptr;
	QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", index + 1);
	usedrange = worksheet->querySubObject("UsedRange");
	QVariant var = usedrange->dynamicCall("value");
	DataProcess* dataprocess = SingleTemplate<DataProcess>::getInstance();
	QVariantList varlist = var.toList();
	StringVectorVector stringvectorvector = dataprocess->changeQVariantListToStringVectorVector(varlist, true);
	ui.tableView->setStringList(stringvectorvector);
	HistoryLoadDataModel* historyloaddatamodel = SingleTemplate<HistoryLoadDataModel>::getInstance();
	historyloaddatamodel->setLoadHistoryDataType(LoadHistoryDataType::excel);
	historyloaddatamodel->setVariantList(varlist);
}



