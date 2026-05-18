#include "AppVersion.h"



AppVersion::AppVersion()
{
    setAppVersion();
}

AppVersion::~AppVersion()
{}

void AppVersion::setAppVersion()
{
    QSettings reg(company, appName);
    reg.setValue(versionKey, currentversion);
}

QString AppVersion::getVersion() const
{
    return currentversion;
}

QString AppVersion::getAppVersion() const
{   
    QSettings reg(company, appName);

    // 读取，默认值 "1.0.0"（不存在时返回）
    QString version = reg.value(versionKey, "1.0").toString();

    return version;
  
}
