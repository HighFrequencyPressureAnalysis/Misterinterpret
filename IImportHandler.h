#pragma once

#include <QString>

#include "ImportTypes.h"

class IImportHandler
{
public:
	virtual ~IImportHandler() = default;

	virtual QString handlerId() const = 0;
	virtual QString handlerName() const = 0;

	virtual bool canHandle(const ImportContext& context) const = 0;
	virtual bool handle(const ImportResult& result) = 0;
};
