#pragma once
#include"SingleTemplate.h"
#include"ConstBasic.h"
#include"ConstDataType.h"
//数据类型转换,根据相同类型进行数据转换//

//数据类型转换,根据相同类型进行数据转换//

class DataTypeMap
{
	DECLARE_SINGLEON(DataTypeMap);
public:
	QString getType(const QString&);

private:
	DataTypeMap();
	~DataTypeMap();
	StringListMap datatypesmap;
};