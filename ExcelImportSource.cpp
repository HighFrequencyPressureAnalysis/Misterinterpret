#include "ExcelImportSource.h"

#include <QAxObject>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QVariantList>
#include <QWidget>

static StringVectorVector variantListToTable(const QVariantList& varlist)
{
	StringVectorVector table;
	for (const QVariant& rowVar : varlist) {
		QStringList rowItems;
		if (rowVar.type() == QVariant::StringList) {
			rowItems = rowVar.toStringList();
		}
		else if (rowVar.canConvert<QVariantList>()) {
			const QVariantList cols = rowVar.toList();
			for (const QVariant& colVar : cols) {
				rowItems.push_back(colVar.toString());
			}
		}
		else {
			rowItems.push_back(rowVar.toString());
		}

		StringVector row;
		for (const QString& item : rowItems) {
			row.push_back(item.trimmed());
		}
		if (!row.isEmpty()) {
			table.push_back(row);
		}
	}
	return table;
}

QString ExcelImportSource::sourceId() const
{
	return QStringLiteral("excel");
}

QString ExcelImportSource::sourceName() const
{
	return QStringLiteral("Excel文件");
}

bool ExcelImportSource::canLoad(const ImportContext& context) const
{
	Q_UNUSED(context)
	return true;
}

bool ExcelImportSource::load(ImportContext& context, QWidget* parent)
{
	const QString filename = QFileDialog::getOpenFileName(
		parent,
		QStringLiteral("打开文件"),
		QDir::currentPath(),
		QStringLiteral("Excel Files (*.xls *.xlsx)")
	);
	if (filename.isEmpty()) {
		return false;
	}

	QAxObject excel(QStringLiteral("Excel.Application"));
	if (excel.isNull()) {
		QMessageBox::warning(parent, QStringLiteral("警告"), QStringLiteral("Excel未安装或无法启动"));
		return false;
	}

	excel.dynamicCall("SetVisible(bool)", false);
	QAxObject* workbooks = excel.querySubObject("WorkBooks");
	if (!workbooks) {
		return false;
	}
	workbooks->dynamicCall("Open(const QString&)", filename);
	QAxObject* workbook = excel.querySubObject("ActiveWorkBook");
	if (!workbook) {
		excel.dynamicCall("Quit()");
		return false;
	}

	QAxObject* worksheets = workbook->querySubObject("WorkSheets");
	if (!worksheets) {
		workbook->dynamicCall("Close(Boolean)", false);
		excel.dynamicCall("Quit()");
		return false;
	}

	const int sheetCount = worksheets->property("Count").toInt();
	QStringList sheetNames;
	QString firstSheetName;
	StringVectorVector firstTable;

	for (int i = 1; i <= sheetCount; ++i) {
		QAxObject* sheet = workbook->querySubObject("WorkSheets(int)", i);
		if (!sheet) {
			continue;
		}
		const QString sheetName = sheet->property("Name").toString();
		QAxObject* usedRange = sheet->querySubObject("UsedRange");
		if (!usedRange) {
			continue;
		}
		QVariant value = usedRange->dynamicCall("Value");
		if (!value.isValid()) {
			continue;
		}

		sheetNames.push_back(sheetName);
		if (firstSheetName.isEmpty()) {
			firstSheetName = sheetName;
			QVariantList rows = value.toList();
			firstTable = variantListToTable(rows);
		}
	}

	context.sourceType = sourceId();
	context.filePath = filename;
	context.sheetNames = sheetNames;
	context.sheetName = firstSheetName;
	context.tableData = firstTable;
	context.rawText.clear();

	workbook->dynamicCall("Close(Boolean)", false);
	excel.dynamicCall("Quit()");

	return !context.tableData.isEmpty();
}
