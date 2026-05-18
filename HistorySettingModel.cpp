#include "HistorySettingModel.h"



HistorySettingModel::HistorySettingModel()
{
}


HistorySettingModel::~HistorySettingModel()
{
}


void HistorySettingModel::setEditType(const QString&s_editype)
{
	edittype = s_editype;
}

void HistorySettingModel::setColumn(const int i_column)
{
	column = i_column;
}

int HistorySettingModel::getColumn()const
{
	return column;
}

void HistorySettingModel::setType(const QString&s_type)
{
	type = s_type;
}

QString HistorySettingModel::getType()const
{
	return type;
}

void HistorySettingModel::setUnit(const QString&s_unit)
{
	unit = s_unit;
}

QString HistorySettingModel::getUnit()const
{
	return unit;
}



QString HistorySettingModel::getEditType()const
{
	return edittype;
}