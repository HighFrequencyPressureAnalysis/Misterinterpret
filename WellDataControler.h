#pragma once
#pragma execution_character_set("utf-8")
#include"SingleTemplate.h"
#include <QString>
#include <QList>
#include<QVector>
#include<QDir>
#include<qtreewidget.h>
#include<qobject.h>
#include<QDebug>
#include"ConstCharacter.h"
#include"category.h"
#include<QInputDialog>
#include<QMessageBox>
#include <windows.h>
#include <shellapi.h>
#include"dialogfracbasic.h"
#include"dialogfracper.h"
#include"WellDataModel.h"
#include<qdatastream.h>
#include"workareafracbasic.h"
#include"ConstDataType.h"



typedef struct Segment {
    int id;
    QString name;
    int wellId;     // 所属井ID
};

typedef struct Well {
    int id;
    int blockId;
    QString name;
    int platformId; // 所属平台ID
};

typedef struct Platform {
    int id;
    QString name;
    int blockId;    // 所属区块ID
};

typedef struct Block {
    int id;
    QString name;
};

// 自增 ID（保证唯一）
static int g_id = 1;

class WellDataManager:public QObject
{
    Q_OBJECT;
    DECLARE_SINGLEON(WellDataManager);
public:
    void initDataInfor();
    void setCateGory(Category*);
    void setTreeWidget(QTreeWidget*);
    void setLabelCurrent(QLabel*);
    void setWorkAreaBasic(WorkAreaFracBasic*);

    //压裂基础数据
    void setFracBasicData(const DataMap&, const StringMap&);
    void renewFracBasicData();
    void getFracBasicData(DataMap&,StringMap&);

    //压裂射孔数据
    void setPerData(const double&, const DoubleVector&);
    void renewFracPerData();
    void getFracPerData(double&, DoubleVector&);

    //压裂施工数据
    void setOperaData(const QString&, const DoubleVectorMap&);
    void renewFracOperaData();
    void getFracOperaData(QString&, DoubleVectorMap&);

    //压裂测试数据
    void setTestData(const QString&, const DoubleVectorMap&);
    void renewFracTestData();
    void getFracTestData(QString&, DoubleVectorMap&);

    //设置停泵水击数据
    void setFracWHData(const int&, const DoubleVector&);
    void renewFracWHData();
    void getFracWHData(int&, DoubleVector&);
    //设置合并数据
    void setFracMergeData(const DoubleVector&, const DoubleVector&);
    void renewFracMergeData();
    void getFracMergeData(DoubleVector&, DoubleVector&);



    void setConnect();
private:
    WellDataManager();
    ~WellDataManager();
    QString wellDataPath;

    QMap<int, Block>mapBlock;
    QMap<int, Platform>mapPlatform;
    QMap<int, Well>mapWell;
    QMap<int, Segment>mapSegment;

    QString currentsavapath;
    QLabel* labelcurrent = nullptr;
    QTreeWidget* tree=nullptr;
    WorkAreaFracBasic* workareafracbasic = nullptr;
    Category* category = nullptr;
    void loadFromFolder(const QString&rootPath);
 
    void getFoldersInPathAndName(const QString& targetPath,QStringList&path,QStringList&name);
    void showInTree();
 
private slots:
    void onTreeItemClicked(QTreeWidgetItem* item, int column);
    void addNewBlock();
    void addNewStation();
    void addNewWell();
    void addNewStage();
    void removeContent();
    void renameContent();
    void showFracBasicDialog();
    void showFracPerDialog();
    void showFracOperaDialog();
    void showFracTestDialog();
    void autoMergeData();
    void showFracWhDialog();
};

