#include "WellDataControler.h"
#include"MessageBoxControler.h"
#include"dialogloaddata.h"
#pragma execution_character_set("utf-8")
#include"HistoryDateModel.h"
#include"DataProcess.h"

WellDataManager::WellDataManager()
{
    wellDataPath = QDir::current().filePath("WellData");
}

WellDataManager::~WellDataManager()
{}

void WellDataManager::loadFromFolder(const QString& rootPath)
{
    QDir rootDir(rootPath);

    // ========== 第1级：区块 ==========
    QStringList blocks = rootDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (QString blockName : blocks) {

        Block block;
        block.id = g_id++;
        block.name = blockName;
        mapBlock[block.id] = block;

        QDir platformDir(rootDir.filePath(blockName));

        // ========== 第2级：平台 ==========
        QStringList platforms = platformDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        for (QString platformName : platforms) {
            Platform platform;
            platform.id = g_id++;
            platform.name = platformName;
            platform.blockId = block.id;   // 父级：区块ID
            mapPlatform[platform.id] = platform;

            QDir wellDir(platformDir.filePath(platformName));

            // ========== 第3级：井 ==========
            QStringList wells = wellDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
            for (QString wellName : wells) {
                Well well;
                well.id = g_id++;
                well.name = wellName;
                well.platformId = platform.id; // 父级：平台ID
                mapWell[well.id] = well;

                QDir sectionDir(wellDir.filePath(wellName));

                // ========== 第4级：段 ==========
                QStringList sections = sectionDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
                for (QString sectionName : sections) {
                    Segment section;
                    section.id = g_id++;
                    section.name = sectionName;
                    section.wellId = well.id;    // 父级：井ID
                    mapSegment[section.id] = section;
                }
            }
        }
    }
}

void WellDataManager::getFoldersInPathAndName(const QString & targetPath, QStringList& path, QStringList& names)
{
    QDir dir(targetPath);

    // 设置过滤：只找文件夹，不找文件
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    // 获取所有文件夹名称
    QStringList folderNames = dir.entryList();

    // 拼接成完整路径
    for (const QString& name : folderNames) {
        path.append(dir.filePath(name)); // 自动拼接成完整路径
        names.append(QFileInfo(name).fileName());
    }
}

void WellDataManager::showInTree()
{
    if (tree) {
        tree->clear();
        // 区块
        QIcon iconblock(":/HighFrequencyPressureAnalysis/res/Icon/block.jpg");
        QIcon iconflat(":/HighFrequencyPressureAnalysis/res/Icon/station.jpeg");
        QIcon iconwell(":/HighFrequencyPressureAnalysis/res/Icon/well.jpeg");
        QIcon iconstage(":/HighFrequencyPressureAnalysis/res/Icon/fracstage.jpeg");
        for (Block b : mapBlock) {
            QTreeWidgetItem* itemB = new QTreeWidgetItem(tree);
            itemB->setText(0,  b.name);
            itemB->setIcon(0,iconblock);
            // 平台
            for (Platform p : mapPlatform) {
                if (p.blockId != b.id) continue;
                QTreeWidgetItem* itemP = new QTreeWidgetItem(itemB);
                itemP->setText(0, p.name);
                itemP->setIcon(0, iconflat);
                // 井
                for (Well w : mapWell) {
                    if (w.platformId != p.id) continue;
                    QTreeWidgetItem* itemW = new QTreeWidgetItem(itemP);
                    itemW->setText(0,w.name);
                    itemW->setIcon(0, iconwell);
                    // 段
                    for (Segment s : mapSegment) {
                        if (s.wellId != w.id) continue;
                        QTreeWidgetItem* itemS = new QTreeWidgetItem(itemW);
                        itemS->setText(0, s.name);
                        itemS->setIcon(0, iconstage);
                    }
                }
            }
        }
        tree->expandAll(); // 全部展开
    }
}

void WellDataManager::setFracBasicData(const DataMap&datamap, const StringMap&stringmap)
{
    DataModelFracBasic datamodelfracbasic;
    datamodelfracbasic.setData(datamap, stringmap);
    QString temppath = currentsavapath + s_slash + s_fracbasicfile;
    QFile file(temppath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out << datamodelfracbasic;
    file.close();
    renewFracBasicData();
    
}

void WellDataManager::setPerData(const double&bgvalue, const DoubleVector&perdata)
{
    DataModelFracPer datamodel;
    datamodel.setData(bgvalue, perdata);
    QString temppath = currentsavapath + s_slash + s_fracperfile;
    QFile file(temppath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out << datamodel;
    file.close();
    renewFracPerData();
}

void WellDataManager::renewFracPerData()
{
    QString temppath = currentsavapath + s_slash + s_fracperfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracPer datamodel;
        in >> datamodel;
        double bgvalue;
        DoubleVector perdata;
        datamodel.getData(bgvalue, perdata);
        file.close();
        workareafracbasic->renewFracPerData(bgvalue, perdata);
    }
   
}

void WellDataManager::getFracPerData(double&bgvalue, DoubleVector&perdata)
{
    QString temppath = currentsavapath + s_slash + s_fracperfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracPer datamodel;
        in >> datamodel;
        datamodel.getData(bgvalue,perdata);
        file.close();
    }
}

void WellDataManager::setOperaData(const QString&datetime, const DoubleVectorMap&vectormap)
{
    DataModelFracOpera datamodel;
    datamodel.setData(datetime, vectormap);
    QString temppath = currentsavapath + s_slash + s_fracoperafile;
    QFile file(temppath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out << datamodel;
    file.close();
    renewFracOperaData();
}

void WellDataManager::renewFracOperaData()
{
    QString temppath = currentsavapath + s_slash + s_fracoperafile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracOpera datamodel;
        in >> datamodel;
        QString datetime;
        DoubleVectorMap vectormap;
        datamodel.getData(datetime, vectormap);
        file.close();
        workareafracbasic->renewFracOperaData(datetime,vectormap);
    }
}

void WellDataManager::getFracOperaData(QString&datetime, DoubleVectorMap&vectormap)
{
    QString temppath = currentsavapath + s_slash + s_fracoperafile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracOpera datamodel;
        in >> datamodel;
        datamodel.getData(datetime, vectormap);
        file.close();
    }
}

void WellDataManager::setTestData(const QString&datetime, const DoubleVectorMap&vectormap)
{
    DataModelFracTest datamodel;
    datamodel.setData(datetime, vectormap);
    QString temppath = currentsavapath + s_slash + s_fractestfile;
    QFile file(temppath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out << datamodel;
    file.close();
    renewFracTestData();
}

void WellDataManager::renewFracTestData()
{
    QString temppath = currentsavapath + s_slash + s_fractestfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracTest datamodel;
        in >> datamodel;
        QString datetime;
        DoubleVectorMap vectormap;
        datamodel.getData(datetime, vectormap);
        file.close();
        workareafracbasic->renewFracTestData(datetime, vectormap);
    }
}

void WellDataManager::getFracTestData(QString&datetime, DoubleVectorMap&vectormap)
{
    QString temppath = currentsavapath + s_slash + s_fractestfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracTest datamodel;
        in >> datamodel;
        datamodel.getData(datetime, vectormap);
        file.close();
    }
}

void WellDataManager::setFracWHData(const int&freq, const DoubleVector&vp)
{
    DataModelFracWH datamodel;
    datamodel.setData(freq, vp);
    QString temppath = currentsavapath + s_slash + s_fracwhfile;
    QFile file(temppath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out << datamodel;
    file.close();
    renewFracWHData();

}

void WellDataManager::renewFracWHData()
{
    QString temppath = currentsavapath + s_slash + s_fracwhfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracWH datamodel;
        in >> datamodel;
        int freq;
        DoubleVector vp;
        datamodel.getData(freq, vp);
        file.close();
        workareafracbasic->renewFracWHData(freq,vp);
    }
}

void WellDataManager::getFracWHData(int&freq, DoubleVector&vp)
{
    QString temppath = currentsavapath + s_slash + s_fracwhfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracWH datamodel;
        in >> datamodel;
        datamodel.getData(freq, vp);
        file.close();
    }
}

void WellDataManager::setFracMergeData(const DoubleVector&t, const DoubleVector&p)
{
    DataModelFracMerge datamodel;
    datamodel.setData(t, p);
    QString temppath = currentsavapath + s_slash + s_fracmergefile;
    QFile file(temppath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out << datamodel;
    file.close();
    renewFracMergeData();
}

void WellDataManager::renewFracMergeData()
{
    QString temppath = currentsavapath + s_slash + s_fracmergefile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracMerge datamodel;
        in >> datamodel;
        DoubleVector t;
        DoubleVector p;
        datamodel.getData(t,p);
        file.close();
        workareafracbasic->renewFracMergeData(t,p);
    }
}

void WellDataManager::getFracMergeData(DoubleVector&t, DoubleVector&p)
{
    QString temppath = currentsavapath + s_slash + s_fracmergefile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracMerge datamodel;
        in >> datamodel;
        datamodel.getData(t,p);
        file.close();
    }
}

void WellDataManager::renewFracBasicData()
{
    QString temppath = currentsavapath + s_slash + s_fracbasicfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracBasic datamodelfracbasic;
        in >> datamodelfracbasic;
        DataMap datamap;
        StringMap stringmap;
        datamodelfracbasic.getData(datamap, stringmap);
        file.close();
        workareafracbasic->renewFracBasicData(datamap, stringmap);
    }
    
}

void WellDataManager::getFracBasicData(DataMap&datamap, StringMap&stringmap)
{

    QString temppath = currentsavapath + s_slash + s_fracbasicfile;
    bool isFileExists = QFile::exists(temppath);
    if (isFileExists) {
        QFile file(temppath);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        DataModelFracBasic datamodelfracbasic;
        in >> datamodelfracbasic;
        datamodelfracbasic.getData(datamap, stringmap);
        file.close();
    }
}



void WellDataManager::addNewBlock()
{
    // 1. 弹出输入框
    MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
    QString blockName = messageboxcontroler->showInputMessageBox("BlockName", "inputblock");
    // 3. 输入为空
    if (blockName.trimmed().isEmpty()) {
        const QString text = "No name";
        messageboxcontroler->showWarningMessageBox(text);
        return;
    }

    // 4. 检查重名（可选）
    for (Block& b : mapBlock) {
        if (b.name == blockName.trimmed()) {
            const QString text = "Exist";
            messageboxcontroler->showWarningMessageBox(text);
            return;
        }
    }

    // 5. 添加到 QMap
    Block block;
    block.id = g_id++;
    block.name = blockName;
    mapBlock[block.id] = block;



    // 3. 拼接要创建的文件夹路径
    QString newBlockPath = wellDataPath + "/" + blockName;

    // 4. 创建文件夹
    QDir dir;
    if (!dir.mkpath(newBlockPath)) {
        QString text = "FileClipExist";
       messageboxcontroler->showWarningMessageBox(text);
        return;
    }
    QTreeWidgetItem* item = new QTreeWidgetItem(tree);
    item->setText(0, blockName);
    item->setData(0, Qt::UserRole, block.id);
    item->setData(0, Qt::UserRole + 1, "Block");
    QIcon iconblock(":/HighFrequencyPressureAnalysis/res/Icon/block.jpg");
    item->setIcon(0,iconblock);
}

void WellDataManager::addNewStation()
{
    
    MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
    QTreeWidgetItem* currentItem = tree->currentItem();
    // 2. 判断层级：顶层节点 = 区块（最稳）
    


    // 3. 获取区块信息
    int blockId = currentItem->data(0, Qt::UserRole).toInt();
    QString blockName = currentItem->text(0);

    // 4. 输入平台名称
   
    QString platformName = messageboxcontroler->showInputMessageBox("PlatformName", "InputPlatform");

    if ( platformName.trimmed().isEmpty()) {
        return;
    }

    // ==================== 关键：创建文件夹 ====================
    bool isExist = false;
    foreach(const Platform & platform, mapPlatform) {
        // 同一个区块下，平台名称不能重复
        if (platform.blockId == blockId && platform.name == platformName) {
            isExist = true;
            break;
        }
    }
    if (isExist) {
        // 提示：平台已存在（英文）
        messageboxcontroler->showWarningMessageBox("The platform already exists!");
        return;
    }

    // 区块文件夹路径
    QString blockFolder = wellDataPath + "/" + blockName;

    // 平台文件夹路径
    QString platformFolder = blockFolder + "/" + platformName;

    QDir dir;
    if (!dir.mkpath(platformFolder)) {
        messageboxcontroler->showWarningMessageBox("FileClip exists");
        return;
    }

    // ==================== 存入 QMap ====================
    Platform platform;
    platform.id = g_id++;
    platform.name = platformName;
    platform.blockId = blockId;       // 归属当前区块
    mapPlatform[platform.id] = platform;

    // ==================== 添加到 TreeWidget ====================
   
    QTreeWidgetItem* item = new QTreeWidgetItem(currentItem);
    item->setText(0, platform.name);
    item->setData(0, Qt::UserRole, platform.id);
    QIcon iconflat(":/HighFrequencyPressureAnalysis/res/Icon/station.jpeg");
    item->setIcon(0, iconflat);
    // 提示成功
    messageboxcontroler->showInformationMessageBox("sucessful");
}

void WellDataManager::addNewWell()
{
    MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
    QTreeWidgetItem* currentItem = tree->currentItem();

    // 1. 判断必须选中 平台节点（父节点是区块，自己是平台）
    if (!currentItem || currentItem->parent() == nullptr) {
        messageboxcontroler->showWarningMessageBox("Please select a platform first!");
        return;
    }

    // 2. 获取 平台 信息
    int platformId = currentItem->data(0, Qt::UserRole).toInt();
    QString platformName = currentItem->text(0);
    int blockId = currentItem->parent()->data(0, Qt::UserRole).toInt(); // 所属区块ID
    QString blockName = currentItem->parent()->text(0);

    // 3. 输入井名称
    QString wellName = messageboxcontroler->showInputMessageBox("WellName", "Input Well Name");

    if (wellName.trimmed().isEmpty()) {
        return;
    }

    // ==================== 🔥 判断井是否已存在（同平台下不能重名） ====================
    bool isExist = false;
    foreach(const Well & well, mapWell) {
        // 只判断：同一个平台ID + 井名相同 → 才重复
        if (well.platformId == platformId && well.name == wellName) {
            isExist = true;
            break;
        }
    }

    if (isExist) {
        messageboxcontroler->showWarningMessageBox("The well already exists!");
        return;
    }

    // ==================== 创建井文件夹 ====================
    QString wellFolder = wellDataPath + "/" + blockName + "/" + platformName + "/" + wellName;

    QDir dir;
    if (!dir.mkpath(wellFolder)) {
        messageboxcontroler->showWarningMessageBox("Folder already exists or create failed!");
        return;
    }

    // ==================== 存入 QMap ====================
    Well well;
    well.id = g_id++;
    well.name = wellName;
    well.blockId = blockId;
    well.platformId = platformId;  // 归属当前平台
    mapWell[well.id] = well;

    // ==================== 添加到 TreeWidget ====================
    QTreeWidgetItem* item = new QTreeWidgetItem(currentItem);
    item->setText(0, well.name);
    item->setData(0, Qt::UserRole, well.id);
    QIcon iconwell(":/HighFrequencyPressureAnalysis/res/Icon/well.jpeg");
    item->setIcon(0, iconwell);
    // 提示成功
    messageboxcontroler->showInformationMessageBox("Well created successfully!");
}

void WellDataManager::addNewStage()
{
    MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
    QTreeWidgetItem* currentItem = tree->currentItem();

    // 1. 判断必须选中 井节点（父节点是平台，自己是井）
    if (!currentItem || currentItem->parent() == nullptr) {
        messageboxcontroler->showWarningMessageBox("Please select a well first!");
        return;
    }

    // 2. 获取 井 信息
    int wellId = currentItem->data(0, Qt::UserRole).toInt();
    QString wellName = currentItem->text(0);
    QString platformName = currentItem->parent()->text(0);
    QString blockName = currentItem->parent()->parent()->text(0);

    // 3. 输入段名称
    QString segmentName = messageboxcontroler->showInputMessageBox("SegmentName", "Input Segment Name");

    if (segmentName.trimmed().isEmpty()) {
        return;
    }

    // ==================== 🔥 判断：同一口井下不能有相同段名 ====================
    bool isExist = false;
    for (const auto& segment : mapSegment) {
        if (segment.wellId == wellId && segment.name == segmentName) {
            isExist = true;
            break;
        }
    }

    if (isExist) {
        messageboxcontroler->showWarningMessageBox("The segment already exists under this well!");
        return;
    }

    // ==================== 创建段文件夹 ====================
    QString segmentFolder = wellDataPath + "/" + blockName + "/" + platformName + "/" + wellName + "/" + segmentName;

    QDir dir;
    if (!dir.mkpath(segmentFolder)) {
        messageboxcontroler->showWarningMessageBox("Folder already exists or create failed!");
        return;
    }

    // ==================== 存入 QMap ====================
    Segment segment;
    segment.id = g_id++;
    segment.name = segmentName;
    segment.wellId = wellId;  // 归属当前井
    mapSegment[segment.id] = segment;

    // ==================== 添加到 TreeWidget ====================
    QTreeWidgetItem* item = new QTreeWidgetItem(currentItem);
    item->setText(0, segment.name);
    item->setData(0, Qt::UserRole, segment.id);
    QIcon iconstage(":/HighFrequencyPressureAnalysis/res/Icon/fracstage.jpeg");
    item->setIcon(0, iconstage);
    // 提示成功
    messageboxcontroler->showInformationMessageBox("Segment created successfully!");
}

void WellDataManager::removeContent()
{
    MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
    QTreeWidgetItem* currentItem = tree->currentItem();

    // 1. 判断是否选中节点
    if (!currentItem) {
        messageboxcontroler->showWarningMessageBox("Please select a node to delete!");
        return;
    }

    // 2. 删除确认
    auto reply = messageboxcontroler->showQuestionMessageBox(
         "Move to recycle bin? This can be restored!");
    if (!reply) {
        return;
    }

    // 3. 自动拼接 完整文件夹路径（区块/平台/井/段）
    QString fullPath = wellDataPath;
    QStringList pathParts;
    QTreeWidgetItem* p = currentItem;

    // 向上遍历所有父节点，拿到完整路径
    while (p) {
        pathParts.prepend(p->text(0));
        p = p->parent();
    }

    // 拼接最终路径
    for (QString part : pathParts) {
        fullPath += "/" + part;
    }

    // 4. 先把文件夹移动到回收站 ✅ 安全不删除
    std::wstring path = fullPath.toStdWString();
    WCHAR szPath[MAX_PATH] = { 0 };
    memcpy(szPath, path.data(), path.size() * sizeof(WCHAR));

    SHFILEOPSTRUCTW fileOp = { 0 };
    fileOp.wFunc = FO_DELETE;
    fileOp.pFrom = szPath;
    fileOp.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION | FOF_SILENT;

    bool ret = (SHFileOperationW(&fileOp) == 0);

    if (!ret) {
        messageboxcontroler->showWarningMessageBox("Warning");
        return;
    }

    // 5. 获取当前节点 ID
    int id = currentItem->data(0, Qt::UserRole).toInt();

    // 6. 判断节点类型，删除内存数据（map）
    if (!currentItem->parent()) {
        // ========== 删除 区块：级联删除所有子节点 ==========
        // 删除平台
        QMap<int, Platform> tempPlatform = mapPlatform;
        for (auto it = tempPlatform.begin(); it != tempPlatform.end(); ++it) {
            if (it.value().blockId == id) {
                int pid = it.key();
                // 删除井
                QMap<int, Well> tempWell = mapWell;
                for (auto wit = tempWell.begin(); wit != tempWell.end(); ++wit) {
                    if (wit.value().platformId == pid) {
                        int wid = wit.key();
                        // 删除段
                        QMap<int, Segment> tempSeg = mapSegment;
                        for (auto sit = tempSeg.begin(); sit != tempSeg.end(); ++sit) {
                            if (sit.value().wellId == wid)
                                mapSegment.remove(sit.key());
                        }
                        mapWell.remove(wid);
                    }
                }
                mapPlatform.remove(pid);
            }
        }
        mapBlock.remove(id);
    }
    else if (!currentItem->parent()->parent()) {
        // ========== 删除 平台 ==========
        QMap<int, Well> tempWell = mapWell;
        for (auto it = tempWell.begin(); it != tempWell.end(); ++it) {
            if (it.value().platformId == id) {
                int wid = it.key();
                QMap<int, Segment> tempSeg = mapSegment;
                for (auto sit = tempSeg.begin(); sit != tempSeg.end(); ++sit) {
                    if (sit.value().wellId == wid)
                        mapSegment.remove(sit.key());
                }
                mapWell.remove(wid);
            }
        }
        mapPlatform.remove(id);
    }
    else if (!currentItem->parent()->parent()->parent()) {
        // ========== 删除 井 ==========
        QMap<int, Segment> tempSeg = mapSegment;
        for (auto it = tempSeg.begin(); it != tempSeg.end(); ++it) {
            if (it.value().wellId == id)
                mapSegment.remove(it.key());
        }
        mapWell.remove(id);
    }
    else {
        // ========== 删除 段 ==========
        mapSegment.remove(id);
    }

    // 7. 删除树节点
    delete currentItem;

    // 8. 成功提示
    messageboxcontroler->showInformationMessageBox( "Moved to trash successfully!");
}

void WellDataManager::renameContent()
{
    MessageBoxControler* messageboxcontroler = SingleTemplate<MessageBoxControler>::getInstance();
    QTreeWidgetItem* currentItem = tree->currentItem();

    // 1. 判断是否选中节点
    if (!currentItem) {
        messageboxcontroler->showWarningMessageBox("Please select an item to rename!");
        return;
    }

    // 2. 获取旧名称
    QString oldName = currentItem->text(0);
    int id = currentItem->data(0, Qt::UserRole).toInt();

    // 3. 弹出输入框
    QString newName = messageboxcontroler->showInputMessageBox("new name:","Enter new name:");

    if (newName.trimmed().isEmpty()) {
        return;
    }

    if (newName == oldName) {
        messageboxcontroler->showWarningMessageBox("Name is the same, no change!");
        return;
    }

    // ==================== 4. 重名判断（核心） ====================
    bool isExist = false;

    // 判断节点层级
    if (!currentItem->parent()) {
        // 重命名 区块 → 判断所有区块是否重名
        for (const auto& block : mapBlock) {
            if (block.name == newName && block.id != id) {
                isExist = true;
                break;
            }
        }
    }
    else if (!currentItem->parent()->parent()) {
        // 重命名 平台 → 同一区块下不重名
        int blockId = currentItem->parent()->data(0, Qt::UserRole).toInt();
        for (const auto& platform : mapPlatform) {
            if (platform.blockId == blockId && platform.name == newName && platform.id != id) {
                isExist = true;
                break;
            }
        }
    }
    else if (!currentItem->parent()->parent()->parent()) {
        // 重命名 井 → 同一平台下不重名
        int platformId = currentItem->parent()->data(0, Qt::UserRole).toInt();
        for (const auto& well : mapWell) {
            if (well.platformId == platformId && well.name == newName && well.id != id) {
                isExist = true;
                break;
            }
        }
    }
    else {
        // 重命名 段 → 同一井下不重名
        int wellId = currentItem->parent()->data(0, Qt::UserRole).toInt();
        for (const auto& segment : mapSegment) {
            if (segment.wellId == wellId && segment.name == newName && segment.id != id) {
                isExist = true;
                break;
            }
        }
    }

    if (isExist) {
        messageboxcontroler->showWarningMessageBox("Name already exists in this level!");
        return;
    }

    // ==================== 5. 拼接文件夹路径 ====================
    QStringList pathParts;
    QTreeWidgetItem* p = currentItem;
    while (p) {
        pathParts.prepend(p->text(0));
        p = p->parent();
    }

    // 旧路径
    QString oldPath = wellDataPath;
    for (QString part : pathParts) {
        oldPath += "/" + part;
    }

    // 新路径
    pathParts.removeLast();
    pathParts.append(newName);

    QString newPath = wellDataPath;
    for (QString part : pathParts) {
        newPath += "/" + part;
    }

    // ==================== 6. 重命名文件夹 ====================
    if (!QDir().rename(oldPath, newPath)) {
        messageboxcontroler->showWarningMessageBox("Failed to rename folder!");
        return;
    }

    // ==================== 7. 更新数据结构 ====================
    if (!currentItem->parent()) {
        // 区块
        if (mapBlock.contains(id)) {
            mapBlock[id].name = newName;
        }
    }
    else if (!currentItem->parent()->parent()) {
        // 平台
        if (mapPlatform.contains(id)) {
            mapPlatform[id].name = newName;
        }
    }
    else if (!currentItem->parent()->parent()->parent()) {
        // 井
        if (mapWell.contains(id)) {
            mapWell[id].name = newName;
        }
    }
    else {
        // 段
        if (mapSegment.contains(id)) {
            mapSegment[id].name = newName;
        }
    }

    // ==================== 8. 更新树节点 ====================
    currentItem->setText(0, newName);

    messageboxcontroler->showInformationMessageBox("Renamed successfully!");
}

void WellDataManager::showFracBasicDialog()
{
    DialogFracBasic* dialog = new DialogFracBasic();
    dialog->exec();
}

void WellDataManager::showFracPerDialog()
{
    DialogFracPer* dialog = new DialogFracPer();
   dialog->exec();
}

void WellDataManager::showFracOperaDialog()
{
    DialogLoadData* dialog = new DialogLoadData(s_fracopratedata);
    dialog->exec();
}

void WellDataManager::showFracTestDialog()
{
    DialogLoadData* dialog = new DialogLoadData(s_fractestdata);
    dialog->exec();
}

void WellDataManager::autoMergeData()
{
    QString tempoperapath = currentsavapath + s_slash + s_fracoperafile;
    QString temptestpath = currentsavapath + s_slash + s_fractestfile;
    bool isFileOperaExists = QFile::exists(tempoperapath);
    bool isFileTestExists = QFile::exists(tempoperapath);
    if (isFileOperaExists&&isFileTestExists) {
        QString fracdatetime;
        DoubleVectorMap operavectormap;
        getFracOperaData(fracdatetime, operavectormap);
        DoubleVector operat, operap;
        operat = operavectormap[s_t];
        operap = operavectormap[s_pressure];
        
        QString testdatetime;
        DoubleVectorMap testvectormap;
        getFracTestData(testdatetime, testvectormap);
        DoubleVector testt, testp;
        testt = testvectormap[s_t];
        testp = testvectormap[s_pressure];

        HistoryDateModel* datemodel = SingleTemplate<HistoryDateModel>::getInstance();
        datemodel->setTestDateTimeString(testdatetime);
        datemodel->setFracDateTimeString(fracdatetime);
        datemodel->checkChangeTestTime(testt);
        testvectormap[s_t] = testt;

        DataProcess* dataprocess = SingleTemplate<DataProcess>::getInstance();
        DoubleVectorMap datamap=dataprocess->mergeData(operavectormap, testvectormap);
        setFracMergeData(datamap[s_t],datamap[s_pressure]);
        int a = 0;
    }
}

void WellDataManager::showFracWhDialog()
{
    DialogLoadData* dialog = new DialogLoadData(s_waterhammerpress);
    dialog->exec();
}

void WellDataManager::initDataInfor()
{
	QString wellDataPath = QDir::current().filePath("WellData");
    loadFromFolder(wellDataPath);
    showInTree();
    int a = 0;
}

void WellDataManager::setCateGory(Category*p_category)
{
    category = p_category;
}

void WellDataManager::setTreeWidget(QTreeWidget*p_treewidget)
{
    tree = p_treewidget;
    QObject::connect(tree, &QTreeWidget::itemClicked,
        this, &WellDataManager::onTreeItemClicked);
}

void WellDataManager::setLabelCurrent(QLabel*p_label)
{
    labelcurrent = p_label;
}

void WellDataManager::setWorkAreaBasic(WorkAreaFracBasic*workarea)
{
    workareafracbasic = workarea;
}

void WellDataManager::setConnect()
{
    QAction* actnewblock = category->getAction(strNewBlock);
    connect(actnewblock, &QAction::triggered, this, &WellDataManager::addNewBlock);

    QAction* actnewstation = category->getAction(strNewStation);
    connect(actnewstation, &QAction::triggered, this, &WellDataManager::addNewStation);

    QAction* actnewwell = category->getAction(strNewWell);
    connect(actnewwell, &QAction::triggered, this, &WellDataManager::addNewWell);

    QAction* actnewstage = category->getAction(strNewStage);
    connect(actnewstage, &QAction::triggered, this, &WellDataManager::addNewStage);

    QAction* actremove = category->getAction(strRemove);
    connect(actremove, &QAction::triggered, this, &WellDataManager::removeContent);

    QAction* actrename = category->getAction(strRename);
    connect(actrename, &QAction::triggered, this, &WellDataManager::renameContent);

    QAction* actfracbasic = category->getAction(strFracBasic);
    connect(actfracbasic, &QAction::triggered, this, &WellDataManager::showFracBasicDialog);

    QAction* actfracper = category->getAction(strFracPer);
    connect(actfracper, &QAction::triggered, this, &WellDataManager::showFracPerDialog);

    QAction* actfracopera = category->getAction(strFracOpera);
    connect(actfracopera, &QAction::triggered, this, &WellDataManager::showFracOperaDialog);

    QAction* actfractest = category->getAction(strFracTest);
    connect(actfractest, &QAction::triggered, this, &WellDataManager::showFracTestDialog);

    QAction* actfracmerge = category->getAction(strFracMerge);
    connect(actfracmerge, &QAction::triggered, this, &WellDataManager::autoMergeData);

    QAction* actfracwh = category->getAction(strFracWh);
    connect(actfracwh, &QAction::triggered, this, &WellDataManager::showFracWhDialog);
}

void WellDataManager::onTreeItemClicked(QTreeWidgetItem* item, int column)
{
    if (!item) return;

    // 从当前节点往上遍历，收集所有层级名称
    QStringList path;
    QTreeWidgetItem* current = item;

    QStringList strfullpath;
    
    while (current) {
        currentsavapath += s_slash + current->text(0);
        strfullpath.push_back(current->text(0));
        path.prepend(current->text(0)); // 往前插，保证顺序正确
        current = current->parent();    // 往上找父节点
    }
    // 拼接成：区块 → 平台 → 井 → 段
    QString fullPath = path.join(s_arrow);
    currentsavapath = wellDataPath;
    
    for (int i = strfullpath.size()-1; i >=0 ; i--) {
        currentsavapath += s_slash;
        currentsavapath += strfullpath[i];
    }

    if (labelcurrent) {
        labelcurrent->setText(fullPath);
    }
    
    if (category) {
        category->renewCategoryEnble(strfullpath);
    }
   
    if (strfullpath.size() == 4) {
        workareafracbasic->clear();
        renewFracBasicData();
        renewFracPerData();
        renewFracOperaData();
        renewFracTestData();
        renewFracWHData();
        renewFracMergeData();

    }
    else {

    }
}

