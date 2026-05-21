#include "FracImportHandler.h"

#include "ConstBasic.h"
#include "SingleTemplate.h"
#include "WellDataControler.h"

QString FracImportHandler::handlerId() const
{
	return QStringLiteral("frac");
}

QString FracImportHandler::handlerName() const
{
	return QStringLiteral("FracImportHandler");
}

bool FracImportHandler::canHandle(const ImportContext& context) const
{
	return !context.editType.isEmpty();
}

bool FracImportHandler::handle(const ImportResult& result)
{
	WellDataManager* welldatamanager = SingleTemplate<WellDataManager>::getInstance();
	if (!welldatamanager) {
		return false;
	}

	const QString datetime = result.dateTime.isValid()
		? result.dateTime.toString(QStringLiteral("yyyy-MM-dd HH:mm:ss"))
		: QString();

	if (result.editType == s_fracopratedata) {
		welldatamanager->setOperaData(datetime, result.numericData);
		return true;
	}

	if (result.editType == s_fractestdata) {
		welldatamanager->setTestData(datetime, result.numericData);
		return true;
	}

	if (result.editType == s_waterhammerpress) {
		if (result.numericData.contains(s_pressure)) {
			welldatamanager->setFracWHData(result.frequency, result.numericData[s_pressure]);
			return true;
		}
		if (!result.tableData.isEmpty()) {
			DoubleVector values;
			for (const auto& row : result.tableData) {
				if (row.size() < 2) {
					continue;
				}
				bool ok = false;
				double v = row[1].toDouble(&ok);
				if (ok) {
					values.push_back(v);
				}
			}
			if (!values.isEmpty()) {
				welldatamanager->setFracWHData(result.frequency, values);
				return true;
			}
		}
	}

	return false;
}
