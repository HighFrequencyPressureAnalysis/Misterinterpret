#pragma once

#include "IImportHandler.h"

class FracImportHandler : public IImportHandler
{
public:
	QString handlerId() const override;
	QString handlerName() const override;

	bool canHandle(const ImportContext& context) const override;
	bool handle(const ImportResult& result) override;
};
