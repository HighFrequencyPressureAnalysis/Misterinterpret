#include "dialogexportplotdata.h"
#include"ExportPlotDataModel.h"
#include"ConstBasic.h"
#include"ConstUnit.h"
#include"MessageBoxControler.h"
#include"ConstCharacter.h"
#include"dialogparallelexport.h"

DialogExportPlotData::DialogExportPlotData(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowTitle("导出数据");

	buttongroupsavetype = new QButtonGroup();
	buttongroupsavetype->addButton(ui.radioButtonfile, 0);
	buttongroupsavetype->addButton(ui.radioButtonclipboard, 1);
	connect(buttongroupsavetype, SIGNAL(buttonClicked(int)), this, SLOT(setSaveType()));

	buttongroupfiletype = new QButtonGroup();
	buttongroupfiletype->addButton(ui.radioButtonexcel, 0);
	buttongroupfiletype->addButton(ui.radioButtontxt, 1);
	connect(buttongroupfiletype, SIGNAL(buttonClicked(int)), this, SLOT(setSaveFileType()));
	setSaveFileType();

	ui.radioButtonfile->setChecked(true);
	ui.radioButtontxt->setChecked(true);
	ui.radioButtonexcel->setEnabled(false);
	

	

	

	ExportPlotDataModel* exportplotdatamodel = SingleTemplate<ExportPlotDataModel>::getInstance();
	ExportDataInfor infor=exportplotdatamodel->getExportDataInfor();
	QStringList types = infor.types;
	bool iscontainq = false;
	for (int i = 0; i < types.size(); i++) {
		if (types[i].contains(s_qpump)) {
			iscontainq = true;
			break;
		}
	}
	ui.groupBoxratetime->setVisible(iscontainq);
	//ui.groupBoxratetime->setEnabled(false);
	if (infor.datetime.isValid()) {
		ui.groupBoxdatetime->setVisible(true);
		ui.dateTimeEdit->setDisplayFormat(s_datetimeformat);
		ui.dateTimeEdit->setDateTime(infor.datetime);
	}
	else {
		ui.groupBoxdatetime->setVisible(false);
	}

	DoubleVector currentrange, range;
	currentrange = infor.currentrange;
	range = infor.range;

	ui.labeltmin->setText(QString::number(range.first()));
	ui.labeltmax->setText(QString::number(range.last()));
	ui.doubleSpinBoxtmin->setValue(currentrange.first());
	ui.doubleSpinBoxtmax->setValue(currentrange.last());

	ui.tableWidget->setTable(types);
	
	connect(ui.toolButtontxt, &QToolButton::clicked, this, &DialogExportPlotData::setSaveTxtPath);
	connect(ui.toolButtonexcel, &QToolButton::clicked, this, &DialogExportPlotData::setSaveExcelPath);

	connect(ui.pushButtonsure, &QToolButton::clicked, this, &DialogExportPlotData::exportData);
	connect(ui.pushButtonclose, &QToolButton::clicked, this, &DialogExportPlotData::close);
}

DialogExportPlotData::~DialogExportPlotData()
{
	ExportPlotDataModel* exportplotdatamodel = SingleTemplate<ExportPlotDataModel>::getInstance();
	exportplotdatamodel->clear();
}


QString DialogExportPlotData::getFileName(const QString&filepath)
{
	QFile file(filepath);
	QFileInfo fileinfo(file);
	QString filename = fileinfo.fileName();
	return filename;
}

void DialogExportPlotData::setSaveTxtPath()
{
	QDir dir;
	QString filepath;
	
	filepath = QFileDialog::getOpenFileName(this, "打开文件", dir.absolutePath(), "Txt Files (*.txt)");
	


	if (!filepath.isEmpty()) {
		
		ExportPlotDataModel* model = SingleTemplate<ExportPlotDataModel>::getInstance();
		model->setSaveFileInfor(s_txt, filepath);
		ui.labelfilename->setText(getFileName(filepath));
	}
	else {
		
	}
}

void DialogExportPlotData::setSaveExcelPath()
{
	QDir dir;
	QString filepath;
	
	filepath = QFileDialog::getOpenFileName(this, "打开文件", dir.absolutePath(), "Excel Files (*.xls *.xlsx)");
	
	
	if (!filepath.isEmpty()) {
	
		ExportPlotDataModel* model = SingleTemplate<ExportPlotDataModel>::getInstance();
		model->setSaveFileInfor(s_excel, filepath);
		ui.labelfilename->setText(getFileName(filepath));
	}
}

void DialogExportPlotData::setSaveFileType()
{
	if (ui.radioButtonexcel->isChecked()) {
		ui.toolButtonexcel->setEnabled(true);
		ui.toolButtontxt->setEnabled(false);
	}else {
		ui.toolButtonexcel->setEnabled(false);
		ui.toolButtontxt->setEnabled(true);
	}
}

bool DialogExportPlotData::exportData()
{
	ExportPlotDataModel* model = SingleTemplate<ExportPlotDataModel>::getInstance();
	model->clearExportGraphDataVector();
	ui.tableWidget->setExportDataVector();
	
	double tmin = ui.doubleSpinBoxtmin->value();
	double tmax = ui.doubleSpinBoxtmax->value();
	model->setCurrentRange(tmin, tmax);
	bool containdatetime = ui.checkBoxdatetime->isChecked();
	model->setContainDateTime(containdatetime);
	if (containdatetime) {
		model->setDateTime(ui.dateTimeEdit->dateTime());
	}
	
	if (ui.radioButtonfile->isChecked()) {
		QString filepath = model->getFilePath();
		if (filepath.isEmpty()) {
			MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
			messageboxcontroler->showCriticalMessageBox("未设置文件路径");
			return false;
		}
	}
	int count = model->getExportDataVectorCount();
	if (count == 0) {
		MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
		messageboxcontroler->showCriticalMessageBox("未设置需要保存数据");
		return false;
	}
	int maxrowcount = model->getMaxRowCount();
	const int exportmaxrowcount = 2000000;
	if (maxrowcount > exportmaxrowcount) {
		MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
		messageboxcontroler->showCriticalMessageBox("导出数据超过限制");
		return false;
	}
	if (1) {
		if(ui.radioButtonperiod->isChecked()){
			model->changeQData();
		}
	}
	DialogParallelExport* dialog = new DialogParallelExport();
	dialog->exec();
	QString content = model->getStringContent();
	if (ui.radioButtonclipboard->isChecked()) {
		QClipboard* clipboard = QApplication::clipboard();
		clipboard->clear();
		clipboard->setText(content);
	}
	else {
		QString path=model->getFilePath();
		QFile file(path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
			MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
			messageboxcontroler->showCriticalMessageBox("文件存在问题");
			return false;
		}
		// 文件流
		QTextStream stream(&file);
		// 输入内容
		stream << content;
		file.close();
		
	}
	model->clear();
	MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
	messageboxcontroler->showInformationMessageBox("数据保存成功");
	close();
	return true;
}

void DialogExportPlotData::setSaveType()
{
	if (ui.radioButtonclipboard->isChecked()) {
		ui.groupBoxfile->setVisible(false);
	}
	else {
		ui.groupBoxfile->setVisible(true);
	}
}