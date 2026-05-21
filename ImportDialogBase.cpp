#include "ImportDialogBase.h"

#include "IImportHandler.h"
#include "IImportSource.h"

#include <QComboBox>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QToolButton>
#include <QVBoxLayout>

ImportDialogBase::ImportDialogBase(QWidget* parent)
	: QDialog(parent)
{
	rebuildUi();
}

ImportDialogBase::~ImportDialogBase() = default;

void ImportDialogBase::setConfig(const ImportDialogConfig& config)
{
	m_config = config;
	setWindowTexts();
	updateDateTimeUi();
	updateFrequencyUi();
	updateSheetList();
	updateRowColumnUi();
}

ImportDialogConfig ImportDialogBase::config() const
{
	return m_config;
}

void ImportDialogBase::addSource(IImportSource* source)
{
	if (!source) {
		return;
	}
	m_sources.push_back(source);
	refreshSourceButtons();
}

void ImportDialogBase::clearSources()
{
	m_sources.clear();
	refreshSourceButtons();
}

void ImportDialogBase::setHandler(IImportHandler* handler)
{
	m_handler = handler;
}

ImportContext& ImportDialogBase::context()
{
	return m_context;
}

const ImportContext& ImportDialogBase::context() const
{
	return m_context;
}

ImportResult ImportDialogBase::lastResult() const
{
	return m_lastResult;
}

void ImportDialogBase::onSourceClicked()
{
	auto* btn = qobject_cast<QToolButton*>(sender());
	if (!btn) {
		return;
	}
	m_selectedSourceId = btn->property("sourceId").toString();
	if (runSelectedSource(m_selectedSourceId)) {
		setTableFromContext();
		updateSheetList();
	}
}

void ImportDialogBase::onSheetChanged(int index)
{
	Q_UNUSED(index)
	m_context.sheetName = m_sheetCombo ? m_sheetCombo->currentText() : QString();
}

void ImportDialogBase::onApplyRowColumnClicked()
{
	if (!m_previewTable) {
		return;
	}
	const int rows = m_rowSpin ? m_rowSpin->value() : 0;
	const int cols = m_columnSpin ? m_columnSpin->value() : 0;
	m_previewTable->setRowCount(rows);
	m_previewTable->setColumnCount(cols);
	m_previewTable->clearContents();
}

bool ImportDialogBase::runSelectedSource(const QString& sourceId)
{
	for (auto* source : m_sources) {
		if (source && source->sourceId() == sourceId && source->canLoad(m_context)) {
			const bool ok = source->load(m_context, this);
			if (ok) {
				updateDateTimeUi();
				updateFrequencyUi();
				updateRowColumnUi();
			}
			return ok;
		}
	}
	return false;
}

void ImportDialogBase::updateResultFromContext()
{
	m_lastResult.success = true;
	m_lastResult.sourceType = m_context.sourceType;
	m_lastResult.editType = m_context.editType;
	m_lastResult.dateTime = m_datetimeEdit ? m_datetimeEdit->dateTime() : m_context.dateTime;
	m_lastResult.frequency = m_frequencySpin ? static_cast<int>(m_frequencySpin->value()) : m_context.frequency;
	m_lastResult.tableData = m_context.tableData;
	m_lastResult.headerTypes = m_context.sheetNames;
}

bool ImportDialogBase::finishImport()
{
	updateResultFromContext();
	if (m_handler && m_handler->canHandle(m_context)) {
		return m_handler->handle(m_lastResult);
	}
	return false;
}

void ImportDialogBase::onConfirmClicked()
{
	finishImport();
	accept();
}

void ImportDialogBase::onCancelClicked()
{
	reject();
}

void ImportDialogBase::rebuildUi()
{
	setWindowTexts();

	m_rootLayout = new QVBoxLayout(this);
	m_reminderLabel = new QLabel(this);
	m_rootLayout->addWidget(m_reminderLabel);

	m_sourcePanel = new QWidget(this);
	m_sourceLayout = new QVBoxLayout(m_sourcePanel);
	m_sourceLayout->setContentsMargins(0, 0, 0, 0);
	m_rootLayout->addWidget(m_sourcePanel);

	auto* optionRow = new QHBoxLayout();
	m_sheetCombo = new QComboBox(this);
	m_datetimeEdit = new QDateTimeEdit(this);
	m_frequencySpin = new QDoubleSpinBox(this);
	m_frequencySpin->setDecimals(0);
	m_frequencySpin->setRange(0, 1000000);
	optionRow->addWidget(m_sheetCombo);
	optionRow->addWidget(m_datetimeEdit);
	optionRow->addWidget(m_frequencySpin);
	m_rootLayout->addLayout(optionRow);

	auto* rowColumnRow = new QHBoxLayout();
	m_rowSpin = new QSpinBox(this);
	m_rowSpin->setRange(0, 1000000);
	m_columnSpin = new QSpinBox(this);
	m_columnSpin->setRange(0, 1000000);
	m_applyRowColumnButton = new QPushButton(QStringLiteral("应用行列"), this);
	rowColumnRow->addWidget(m_rowSpin);
	rowColumnRow->addWidget(m_columnSpin);
	rowColumnRow->addWidget(m_applyRowColumnButton);
	m_rootLayout->addLayout(rowColumnRow);

	m_previewTable = new QTableWidget(this);
	m_previewTable->horizontalHeader()->setStretchLastSection(true);
	m_rootLayout->addWidget(m_previewTable);

	auto* buttonRow = new QHBoxLayout();
	buttonRow->addStretch();
	m_confirmButton = new QPushButton(QStringLiteral("确定"), this);
	m_cancelButton = new QPushButton(QStringLiteral("取消"), this);
	buttonRow->addWidget(m_confirmButton);
	buttonRow->addWidget(m_cancelButton);
	m_rootLayout->addLayout(buttonRow);

	connect(m_confirmButton, &QPushButton::clicked, this, &ImportDialogBase::onConfirmClicked);
	connect(m_cancelButton, &QPushButton::clicked, this, &ImportDialogBase::onCancelClicked);
	connect(m_sheetCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ImportDialogBase::onSheetChanged);
	connect(m_applyRowColumnButton, &QPushButton::clicked, this, &ImportDialogBase::onApplyRowColumnClicked);

	setLayout(m_rootLayout);
	setMinimumSize(1200, 800);
	updateDateTimeUi();
	updateFrequencyUi();
	updateRowColumnUi();
	refreshSourceButtons();
	refreshPreviewTable();
}

void ImportDialogBase::refreshSourceButtons()
{
	if (!m_sourceLayout) {
		return;
	}

	while (auto* item = m_sourceLayout->takeAt(0)) {
		delete item->widget();
		delete item;
	}
	m_sourceButtons.clear();

	auto* row = new QHBoxLayout();
	for (auto* source : m_sources) {
		if (!source) {
			continue;
		}
		auto* btn = new QToolButton(this);
		btn->setText(source->sourceName());
		btn->setProperty("sourceId", source->sourceId());
		connect(btn, &QToolButton::clicked, this, &ImportDialogBase::onSourceClicked);
		row->addWidget(btn);
		m_sourceButtons.push_back(btn);
	}
	row->addStretch();
	m_sourceLayout->addLayout(row);
}

void ImportDialogBase::refreshPreviewTable()
{
	if (!m_previewTable) {
		return;
	}
	m_previewTable->setVisible(true);
	setTableFromContext();
}

void ImportDialogBase::updateSheetList()
{
	if (!m_sheetCombo) {
		return;
	}

	const bool show = m_config.showSheetSelector && !m_context.sheetNames.isEmpty();
	m_sheetCombo->setVisible(show);
	if (!show) {
		m_sheetCombo->clear();
		return;
	}

	m_sheetCombo->blockSignals(true);
	m_sheetCombo->clear();
	m_sheetCombo->addItems(m_context.sheetNames);
	if (!m_context.sheetName.isEmpty()) {
		m_sheetCombo->setCurrentText(m_context.sheetName);
	}
	m_sheetCombo->blockSignals(false);
}

void ImportDialogBase::updateDateTimeUi()
{
	if (!m_datetimeEdit) {
		return;
	}
	m_datetimeEdit->setVisible(m_config.showDateTime);
	m_datetimeEdit->setDisplayFormat(m_config.defaultDateTimeFormat);
	m_datetimeEdit->setDateTime(m_context.dateTime.isValid() ? m_context.dateTime : QDateTime::currentDateTime());
}

void ImportDialogBase::updateFrequencyUi()
{
	if (!m_frequencySpin) {
		return;
	}
	m_frequencySpin->setVisible(m_config.showFrequency);
	m_frequencySpin->setValue(m_context.frequency);
}

void ImportDialogBase::updateRowColumnUi()
{
	const bool show = m_config.showRowColumnEditor;
	if (m_rowSpin) {
		m_rowSpin->setVisible(show);
		m_rowSpin->setValue(qMax(0, static_cast<int>(m_context.tableData.size())));
	}
	if (m_columnSpin) {
		int cols = 0;
		for (const auto& row : m_context.tableData) {
			cols = qMax(cols, static_cast<int>(row.size()));
		}
		m_columnSpin->setVisible(show);
		m_columnSpin->setValue(cols);
	}
	if (m_applyRowColumnButton) {
		m_applyRowColumnButton->setVisible(show);
	}
}

void ImportDialogBase::setTableFromContext()
{
	if (!m_previewTable) {
		return;
	}

	m_previewTable->clear();
	const auto& data = m_context.tableData;
	if (data.isEmpty()) {
		return;
	}

	int rows = static_cast<int>(data.size());
	int cols = 0;
	for (const auto& row : data) {
		cols = qMax(cols, static_cast<int>(row.size()));
	}
	m_previewTable->setRowCount(rows);
	m_previewTable->setColumnCount(cols);

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < static_cast<int>(data[r].size()); ++c) {
			m_previewTable->setItem(r, c, new QTableWidgetItem(data[r][c]));
		}
	}
}

void ImportDialogBase::setWindowTexts()
{
	if (!m_config.windowTitle.isEmpty()) {
		setWindowTitle(m_config.windowTitle);
	}
	if (m_reminderLabel) {
		m_reminderLabel->setText(m_config.reminderText.isEmpty() ? m_config.windowTitle : m_config.reminderText);
	}
}
