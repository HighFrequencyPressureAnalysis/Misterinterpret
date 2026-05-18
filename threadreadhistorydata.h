#pragma once
#include <QThread>


//线程读取历史数据

class ThreadReadHistoryData : public QThread
{
	Q_OBJECT
signals:
	void sendMaxIter(int);
	void sendReadProgress(int);
public:
	ThreadReadHistoryData(QObject *parent=nullptr);
	~ThreadReadHistoryData();

	void setMaxRowcount();
	void startRead();
	void stopThread();
protected:
	void run() Q_DECL_OVERRIDE;
private:
	bool stop = true;
	int rowcount;

};
