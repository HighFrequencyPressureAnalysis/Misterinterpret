#include "dialogloaddata.h"

#include "ClipboardImportSource.h"
#include "ExcelImportSource.h"
#include "FracImportHandler.h"
#include "TxtImportSource.h"

DialogLoadData::DialogLoadData(const QString& edittype, QWidget* parent)
	: ImportDialogBase(parent)
{
	ImportDialogConfig cfg;
	cfg.editType = edittype;
	cfg.windowTitle = QStringLiteral("����") + edittype + QStringLiteral("����");
	cfg.reminderText = cfg.windowTitle;
	cfg.showDateTime = true;
	cfg.showFrequency = (edittype == s_waterhammerpress);
	cfg.showSheetSelector = true;
	cfg.showRowColumnEditor = true;
	setConfig(cfg);

	m_context.editType = edittype;
	m_context.dateTime = QDateTime::currentDateTime();

	setupImportModules();
}

DialogLoadData::~DialogLoadData() = default;

void DialogLoadData::setupImportModules()
{
	clearSources();
	addSource(new TxtImportSource());
	addSource(new ExcelImportSource());
	addSource(new ClipboardImportSource());
	setHandler(new FracImportHandler());
}
