#include "CpuMemCal.h"

CpuMemCal::CpuMemCal()
{
    process = new QProcess();
}

CpuMemCal::~CpuMemCal()
{
}

void CpuMemCal::getCPU()
{
#ifdef Q_OS_WIN
#if 0
    static FILETIME lastIdleTime;
    static FILETIME lastKernelTime;
    static FILETIME lastUserTime;

    FILETIME newIdleTime;
    FILETIME newKernelTime;
    FILETIME newUserTime;

    //采用GetSystemTimes获取的CPU占用和任务管理器的不一致
    GetSystemTimes(&newIdleTime, &newKernelTime, &newUserTime);

    int offset = 31;
    quint64 a, b;
    quint64 idle, kernel, user;

    a = (lastIdleTime.dwHighDateTime << offset) | lastIdleTime.dwLowDateTime;
    b = (newIdleTime.dwHighDateTime << offset) | newIdleTime.dwLowDateTime;
    idle = b - a;

    a = (lastKernelTime.dwHighDateTime << offset) | lastKernelTime.dwLowDateTime;
    b = (newKernelTime.dwHighDateTime << offset) | newKernelTime.dwLowDateTime;
    kernel = b - a;

    a = (lastUserTime.dwHighDateTime << offset) | lastUserTime.dwLowDateTime;
    b = (newUserTime.dwHighDateTime << offset) | newUserTime.dwLowDateTime;
    user = b - a;

    cpuPercent = float(kernel + user - idle) * 100 / float(kernel + user);

    lastIdleTime = newIdleTime;
    lastKernelTime = newKernelTime;
    lastUserTime = newUserTime;
    this->setData();
#else
    //获取系统版本区分win10
    bool win10 = false;
#if (QT_VERSION >= QT_VERSION_CHECK(5,4,0))
    win10 = (QSysInfo::productVersion().mid(0, 2).toInt() >= 10);
#else
    win10 = (QSysInfo::WindowsVersion >= 192);
#endif

    QString cmd = "\\Processor(_Total)\\% Processor Time";
    if (win10) {
        cmd = "\\Processor Information(_Total)\\% Processor Utility";
    }

    if (process->state() == QProcess::NotRunning) {
        process->start("typeperf", QStringList() << cmd);
    }
#endif

#elif defined(Q_OS_UNIX) && !defined(Q_OS_WASM)
    if (process->state() == QProcess::NotRunning) {
        totalNew = idleNew = 0;
        process->start("cat", QStringList() << "/proc/stat");
    }
#endif
}

void CpuMemCal::getMemory()
{
#ifdef Q_OS_WIN
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    memoryPercent = statex.dwMemoryLoad;
    memoryAll = statex.ullTotalPhys / MB;
    memoryFree = statex.ullAvailPhys / MB;
    memoryUse = memoryAll - memoryFree;
    this->setData();

#elif defined(Q_OS_UNIX) && !defined(Q_OS_WASM)
    if (process->state() == QProcess::NotRunning) {
        process->start("cat", QStringList() << "/proc/meminfo");
    }
#endif
}

void CpuMemCal::readData()
{
#ifdef Q_OS_WIN
    while (!process->atEnd()) {
        QString s = QLatin1String(process->readLine());
        s = s.split(",").last();
        s.replace("\r", "");
        s.replace("\n", "");
        s.replace("\"", "");
        if (!s.isEmpty() && s.length() < 10) {
            cpuPercent = qRound(s.toFloat());
        }
    }
#elif defined(Q_OS_UNIX) && !defined(Q_OS_WASM)
    while (!process->atEnd()) {
        QString s = QLatin1String(process->readLine());
        if (s.startsWith("cpu")) {
            QStringList list = s.split(" ");
            idleNew = list.at(5).toUInt();
            foreach(QString value, list) {
                totalNew += value.toUInt();
            }

            quint64 total = totalNew - totalOld;
            quint64 idle = idleNew - idleOld;
            cpuPercent = 100 * (total - idle) / total;
            totalOld = totalNew;
            idleOld = idleNew;
            break;
        }
        else if (s.startsWith("MemTotal")) {
            s.replace(" ", "");
            s = s.split(":").at(1);
            memoryAll = s.left(s.length() - 3).toUInt() / KB;
        }
        else if (s.startsWith("MemFree")) {
            s.replace(" ", "");
            s = s.split(":").at(1);
            memoryFree = s.left(s.length() - 3).toUInt() / KB;
        }
        else if (s.startsWith("Buffers")) {
            s.replace(" ", "");
            s = s.split(":").at(1);
            memoryFree += s.left(s.length() - 3).toUInt() / KB;
        }
        else if (s.startsWith("Cached")) {
            s.replace(" ", "");
            s = s.split(":").at(1);
            memoryFree += s.left(s.length() - 3).toUInt() / KB;
            memoryUse = memoryAll - memoryFree;
            memoryPercent = 100 * memoryUse / memoryAll;
            break;
        }
    }
#endif
    this->setData();
}

void CpuMemCal::setData()
{
    //cpuPercent = (cpuPercent < 0 ? 0 : cpuPercent);
    cpuPercent = (cpuPercent > 100 ? 0 : cpuPercent);
    msg = QString("CPU %1%  Mem %2%  已用 %3 MB / 共 %4 MB ").arg(cpuPercent).arg(memoryPercent).arg(memoryUse).arg(memoryAll);
}

QString CpuMemCal::getMsg() const
{
    return msg;
}

QProcess* CpuMemCal::getProcess()
{
    return process;
}

void CpuMemCal::close()
{
    process->close();
}

double CpuMemCal::getUseMem() const
{
    return memoryAll-memoryUse;
}
