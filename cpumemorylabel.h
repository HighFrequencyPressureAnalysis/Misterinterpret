#ifndef CPUMEMORYLABEL_H
#define CPUMEMORYLABEL_H

/**
 * CPU内存显示控件 
 * 1. 实时显示当前CPU占用率。
 * 2. 实时显示内存使用情况。
 * 3. 包括共多少内存、已使用多少内存。
 * 4. 全平台通用，包括windows、linux、ARM。
 * 5. 发出信号通知占用率和内存使用情况等，以便自行显示到其他地方。
 */

#include <QLabel>
#include"CpuMemCal.h"

#ifdef quc
class Q_DECL_EXPORT CpuMemoryLabel : public QLabel
#else
class CpuMemoryLabel : public QLabel
#endif

{
    Q_OBJECT

    Q_PROPERTY(bool showText READ getShowText WRITE setShowText)
signals:
    void sendMemCal();
public:
    explicit CpuMemoryLabel(QWidget *parent = 0);
    ~CpuMemoryLabel();

    //默认尺寸和最小尺寸
    

    //获取和设置是否显示文本
    bool getShowText() const;
    void setShowText(bool showText);
    void setSendMemCal(bool issend);
    double getUseMem()const;
private:
    

    QTimer *timerCPU;       //定时器获取CPU信息
    QTimer *timerMemory;    //定时器获取内存信息
    bool showText;          //自己显示值
    bool sendsignals=false;
   
private slots:
    void getCPU();          //获取cpu
    void getMemory();       //获取内存
    void readData();        //读取数据
    

   

public Q_SLOTS:
    //开始启动服务
    void start(int interval);
    //停止服务
    void stop();

Q_SIGNALS:
    //文本改变信号
    void textChanged(const QString &text);
    //cpu和内存占用情况数值改变信号
    void valueChanged(quint64 cpuPercent, quint64 memoryPercent, quint64 memoryAll, quint64 memoryUse, quint64 memoryFree);
};

#endif // CPUMEMORYLABEL_H
