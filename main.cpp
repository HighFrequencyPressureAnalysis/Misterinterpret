#include "HighFrequencyPressureAnalysis.h"
#include <QtWidgets/QApplication>
#include<QTranslator>
#include "SARibbonBar.h"
#include<qtextcodec.h>
#include <windows.h> 
#include"ConstFileConfig.h"


int main(int argc, char *argv[])
{
	// 以下是针对高分屏的设置，有高分屏需求都需要按照下面进行设置
	
	

    QApplication app(argc, argv);

    SetConsoleOutputCP(CP_UTF8);
    

    


    app.setStyle("Fusion");
    
   
    QFont font("Microsoft YaHei", 10); // 微软雅黑，Windows 必支持
    QApplication::setFont(font);


    

    HighFrequencyPressureAnalysis w;
    //qDebug() << "window build cost:" << cost.elapsed() << " ms";
    w.showMaximized();

    return app.exec();
	
	
	


	
}
