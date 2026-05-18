#pragma once
#include"SingleTemplate.h"
#include"ConstFileConfig.h"
#include<qsettings.h>

class AppVersion
{
	DECLARE_SINGLEON(AppVersion);
public:
	QString getVersion()const;
	QString getAppVersion()const;
private:
	AppVersion();
	~AppVersion();
	void setAppVersion();
	QString currentversion = "1.0";
};

