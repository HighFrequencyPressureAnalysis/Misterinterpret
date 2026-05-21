#include "ClipboardImportSource.h"

#include <QApplication>
#include <QClipboard>
#include <QRegularExpression>

static StringVectorVector parseClipboardTextToTable(const QString& text)
{
	StringVectorVector result;
	const QStringList lines = text.split(QRegularExpression(QStringLiteral("[\\r\\n]+")));

	for (const QString& line : lines) {
		if (line.trimmed().isEmpty()) {
			continue;
		}
		const QStringList cols = line.split('\t');
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

QString ClipboardImportSource::sourceId() const
{
	return QStringLiteral("clipboard");
}

QString ClipboardImportSource::sourceName() const
{
	return QStringLiteral("Clipboard");
}

bool ClipboardImportSource::canLoad(const ImportContext& context) const
{
	Q_UNUSED(context)
	return true;
}

bool ClipboardImportSource::load(ImportContext& context, QWidget* parent)
{
	Q_UNUSED(parent)

	QClipboard* clipboard = QApplication::clipboard();
	if (!clipboard) {
		return false;
	}

	const QString text = clipboard->text();
	if (text.isEmpty()) {
		return false;
	}

	context.sourceType = sourceId();
	context.rawText = text;
	context.tableData = parseClipboardTextToTable(text);
	return !context.tableData.isEmpty();
}
