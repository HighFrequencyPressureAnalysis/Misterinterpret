#pragma once
#include <QThread>

class ThreadExportData  : public QThread
{
	Q_OBJECT

public:
	ThreadExportData(QObject *parent=nullptr);
	~ThreadExportData();
private:
	void run() Q_DECL_OVERRIDE;
};
