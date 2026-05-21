#pragma once

#include <QDateTime>
#include <QString>
#include <QStringList>

#include "ConstBasic.h"
#include "ConstDataType.h"

struct ImportContext
{
	QString sourceType;
	QString filePath;
	QString sheetName;
	QDateTime dateTime;
	QString editType;
	int frequency = 0;
	bool editable = true;

	QString rawText;
	QStringList sheetNames;
	StringVectorVector tableData;
};

struct ImportResult
{
	bool success = false;
	QString errorMessage;

	QString sourceType;
	QString editType;
	QDateTime dateTime;
	int frequency = 0;

	StringVectorVector tableData;
	DoubleVectorMap numericData;
	QStringList headerTypes;
};

struct ImportDialogConfig
{
	QString windowTitle;
	QString reminderText;
	QString editType;

	bool allowTxt = true;
	bool allowExcel = true;
	bool allowClipboard = true;
	bool allowTableEdit = true;

	bool showDateTime = true;
	bool showFrequency = false;
	bool showSheetSelector = true;
	bool showRowColumnEditor = false;

	QString defaultDateTimeFormat = QStringLiteral("yyyy-MM-dd HH:mm:ss");
};
