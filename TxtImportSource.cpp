#include "TxtImportSource.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QRegularExpression>
#include <QTextStream>

static StringVectorVector parseTextToTable(const QString& text)
{
	StringVectorVector result;
	const QStringList lines = text.split(QRegularExpression("[\r\n]+"));

	for (const QString& line : lines) {
		if (line.trimmed().isEmpty()) {
			continue;
		}
		const QStringList cols = line.split(QRegularExpression("[\t,;\\s]+"));
		StringVector row;
		for (const QString& col : cols) {
			const QString item = col.trimmed();
			if (!item.isEmpty()) {
				row.push_back(item);
			}
		}
		if (!row.isEmpty()) {
			result.push_back(row);
		}
	}

	return result;
}

QString TxtImportSource::sourceId() const
{
	return QStringLiteral("txt");
}

QString TxtImportSource::sourceName() const
{
	return QStringLiteral("文本文件");
}

bool TxtImportSource::canLoad(const ImportContext& context) const
{
	Q_UNUSED(context)
	return true;
}

bool TxtImportSource::load(ImportContext& context, QWidget* parent)
{
	const QString filename = QFileDialog::getOpenFileName(
		parent,
		QStringLiteral("打开文件"),
		QDir::currentPath(),
		QStringLiteral("Txt Files (*.txt);;All Files (*.*)")
	);

	if (filename.isEmpty()) {
		return false;
	}

	QFile file(filename);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		return false;
	}

	QTextStream in(&file);
	const QString text = in.readAll();

	context.sourceType = sourceId();
	context.filePath = filename;
	context.rawText = text;
	context.tableData = parseTextToTable(text);
	return !context.tableData.isEmpty();
}
