#pragma once

#include "IImportSource.h"

class TxtImportSource : public IImportSource
{
public:
	QString sourceId() const override;
	QString sourceName() const override;

	bool canLoad(const ImportContext& context) const override;
	bool load(ImportContext& context, QWidget* parent = nullptr) override;
};
