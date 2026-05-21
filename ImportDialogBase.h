#pragma once

#include <QDialog>
#include <QVector>

#include "ImportTypes.h"

class IImportSource;
class IImportHandler;
class QComboBox;
class QDateTimeEdit;
class QDoubleSpinBox;
class QLabel;
class QPushButton;
class QSpinBox;
class QTableWidget;
class QToolButton;
class QVBoxLayout;

class ImportDialogBase : public QDialog
{
	Q_OBJECT

public:
	explicit ImportDialogBase(QWidget* parent = nullptr);
	~ImportDialogBase() override;

	void setConfig(const ImportDialogConfig& config);
	ImportDialogConfig config() const;

	void addSource(IImportSource* source);
	void clearSources();
	void setHandler(IImportHandler* handler);

	ImportContext& context();
	const ImportContext& context() const;
	ImportResult lastResult() const;

protected slots:
	void onConfirmClicked();
	void onCancelClicked();
	void onSourceClicked();
	void onSheetChanged(int index);
	void onApplyRowColumnClicked();

protected:
	bool runSelectedSource(const QString& sourceId);
	bool finishImport();
	void updateResultFromContext();
	void rebuildUi();
	void refreshSourceButtons();
	void refreshPreviewTable();
	void updateSheetList();
	void updateDateTimeUi();
	void updateFrequencyUi();
	void updateRowColumnUi();
	void setTableFromContext();
	void setWindowTexts();

protected:
	ImportDialogConfig m_config;
	ImportContext m_context;
	ImportResult m_lastResult;
	QVector<IImportSource*> m_sources;
	IImportHandler* m_handler = nullptr;

	QVBoxLayout* m_rootLayout = nullptr;
	QLabel* m_reminderLabel = nullptr;
	QWidget* m_sourcePanel = nullptr;
	QVBoxLayout* m_sourceLayout = nullptr;
	QComboBox* m_sheetCombo = nullptr;
	QDateTimeEdit* m_datetimeEdit = nullptr;
	QDoubleSpinBox* m_frequencySpin = nullptr;
	QSpinBox* m_rowSpin = nullptr;
	QSpinBox* m_columnSpin = nullptr;
	QPushButton* m_applyRowColumnButton = nullptr;
	QTableWidget* m_previewTable = nullptr;
	QPushButton* m_confirmButton = nullptr;
	QPushButton* m_cancelButton = nullptr;
	QVector<QToolButton*> m_sourceButtons;
	QString m_selectedSourceId;
};
