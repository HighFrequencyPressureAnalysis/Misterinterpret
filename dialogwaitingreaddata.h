#pragma once
#include<QMovie>
#include "dialogwaiting.h"
#include"threadreadhistorydata.h"
#pragma execution_character_set("utf-8")

//数据读取窗口界面//

class DialogWaitingReadData : public DialogWaiting
{
	Q_OBJECT

public:
	DialogWaitingReadData(QWidget *parent = nullptr);
	~DialogWaitingReadData();


private:
	ThreadReadHistoryData thread;
};
