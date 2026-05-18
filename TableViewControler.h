#pragma once
#include"SingleTemplate.h"
#include"tableviewloadhistory.h"


//导入数据表格控制器


class TableViewControler
{
	DECLARE_SINGLEON(TableViewControler);
public:
	
	//设置表格指针
	void setTableViewLoad(TableViewLoadHistory*);
	//设置表头
	void setHeader();
	//更新表格数据
	

private:
	TableViewControler();
	~TableViewControler();

	//表格指针
	TableViewLoadHistory* tableviewloadhistory=nullptr;
	DoubleVector initt;
	DoubleVector initq;
};

