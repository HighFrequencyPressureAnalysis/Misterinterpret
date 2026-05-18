#pragma execution_character_set("utf-8")

#include "cpumemorylabel.h"
#include "qtimer.h"
#include "qprocess.h"
#include "qdebug.h"

#ifdef Q_OS_WIN
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x502
#endif
#include "windows.h"
#endif


CpuMemoryLabel::CpuMemoryLabel(QWidget *parent) : QLabel(parent)
{
   

    //获取CPU占用情况定时器
    timerCPU = new QTimer(this);
    connect(timerCPU, SIGNAL(timeout()), this, SLOT(getCPU()));

    //获取内存占用情况定时器
    timerMemory = new QTimer(this);
    connect(timerMemory, SIGNAL(timeout()), this, SLOT(getMemory()));

    //执行命令获取
    CpuMemCal* cpumemcal = SingleTemplate<CpuMemCal>::getInstance();
    QProcess* process = cpumemcal->getProcess();
    connect(process, SIGNAL(readyRead()), this, SLOT(readData()));

    showText = true;
}

CpuMemoryLabel::~CpuMemoryLabel()
{
    this->stop();
}

void CpuMemoryLabel::start(int interval)
{
    this->getCPU();
    this->getMemory();

    if (!timerCPU->isActive()) {
        timerCPU->start(interval);
    }
    if (!timerMemory->isActive()) {
        timerMemory->start(interval + 1000);
    }
}

void CpuMemoryLabel::stop()
{
    CpuMemCal* cpumemcal = SingleTemplate<CpuMemCal>::getInstance();
    cpumemcal->close();
    if (timerCPU->isActive()) {
        timerCPU->stop();
    }
    if (timerMemory->isActive()) {
        timerMemory->stop();
    }
}

void CpuMemoryLabel::getCPU()
{
    CpuMemCal* cpumemcal = SingleTemplate<CpuMemCal>::getInstance();
    cpumemcal->getCPU();
}

void CpuMemoryLabel::getMemory()
{
    CpuMemCal* cpumemcal = SingleTemplate<CpuMemCal>::getInstance();
    cpumemcal->getMemory();

}

void CpuMemoryLabel::readData()
{
    CpuMemCal* cpumemcal = SingleTemplate<CpuMemCal>::getInstance();
    cpumemcal->readData();
    QString msg = cpumemcal->getMsg();
    setText(msg);
    if (sendsignals) {
        emit sendMemCal();
    }
}




bool CpuMemoryLabel::getShowText() const
{
    return this->showText;
}

void CpuMemoryLabel::setShowText(bool showText)
{
    this->showText = showText;
}

void CpuMemoryLabel::setSendMemCal(bool issend)
{
    sendsignals = true;
}

double CpuMemoryLabel::getUseMem() const
{
    CpuMemCal* cpumemcal = SingleTemplate<CpuMemCal>::getInstance();
    return cpumemcal->getUseMem();
}
