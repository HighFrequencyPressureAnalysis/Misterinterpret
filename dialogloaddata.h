#pragma once

#include "ImportDialogBase.h"

class DialogLoadData : public ImportDialogBase
{
	Q_OBJECT

public:
	explicit DialogLoadData(const QString& edittype, QWidget* parent = nullptr);
	~DialogLoadData() override;

private:
	void setupImportModules();
};
