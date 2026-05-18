#pragma once
#include"SingleTemplate.h"
#include <QLabel>
#include<QProcess>
#pragma execution_character_set("utf-8")
#ifdef Q_OS_WIN
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x502
#endif
#include "windows.h"
#endif

#define MB (1024 * 1024)
#define KB (1024)

class QProcess;



class CpuMemCal
{
	DECLARE_SINGLEON(CpuMemCal);
public:

    void getCPU();          //获取cpu
    void getMemory();       //获取内存
    void readData();        //读取数据
   
    QString getMsg()const;
    QProcess* getProcess();
    void close();
    double getUseMem()const;
private:
	CpuMemCal();
	~CpuMemCal();

    void setData();         //设置数据
private:
    quint64 totalNew, idleNew, totalOld, idleOld;

    quint64 cpuPercent;     //CPU百分比
    quint64 memoryPercent;  //内存百分比
    quint64 memoryAll;      //所有内存
    quint64 memoryUse;      //已用内存
    quint64 memoryFree;     //空闲内存
    QString msg;
    QProcess* process;      //执行命令行
};

