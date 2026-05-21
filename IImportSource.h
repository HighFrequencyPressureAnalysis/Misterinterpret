#pragma once

#include <QString>

#include "ImportTypes.h"

class QWidget;

class IImportSource
{
public:
	virtual ~IImportSource() = default;

	virtual QString sourceId() const = 0;
	virtual QString sourceName() const = 0;
	virtual bool canLoad(const ImportContext& context) const = 0;
	virtual bool load(ImportContext& context, QWidget* parent = nullptr) = 0;
};
