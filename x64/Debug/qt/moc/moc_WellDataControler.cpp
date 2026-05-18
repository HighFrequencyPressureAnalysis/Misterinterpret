/****************************************************************************
** Meta object code from reading C++ file 'WellDataControler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../WellDataControler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WellDataControler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WellDataManager_t {
    QByteArrayData data[18];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WellDataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WellDataManager_t qt_meta_stringdata_WellDataManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "WellDataManager"
QT_MOC_LITERAL(1, 16, 17), // "onTreeItemClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 52, 4), // "item"
QT_MOC_LITERAL(5, 57, 6), // "column"
QT_MOC_LITERAL(6, 64, 11), // "addNewBlock"
QT_MOC_LITERAL(7, 76, 13), // "addNewStation"
QT_MOC_LITERAL(8, 90, 10), // "addNewWell"
QT_MOC_LITERAL(9, 101, 11), // "addNewStage"
QT_MOC_LITERAL(10, 113, 13), // "removeContent"
QT_MOC_LITERAL(11, 127, 13), // "renameContent"
QT_MOC_LITERAL(12, 141, 19), // "showFracBasicDialog"
QT_MOC_LITERAL(13, 161, 17), // "showFracPerDialog"
QT_MOC_LITERAL(14, 179, 19), // "showFracOperaDialog"
QT_MOC_LITERAL(15, 199, 18), // "showFracTestDialog"
QT_MOC_LITERAL(16, 218, 13), // "autoMergeData"
QT_MOC_LITERAL(17, 232, 16) // "showFracWhDialog"

    },
    "WellDataManager\0onTreeItemClicked\0\0"
    "QTreeWidgetItem*\0item\0column\0addNewBlock\0"
    "addNewStation\0addNewWell\0addNewStage\0"
    "removeContent\0renameContent\0"
    "showFracBasicDialog\0showFracPerDialog\0"
    "showFracOperaDialog\0showFracTestDialog\0"
    "autoMergeData\0showFracWhDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WellDataManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WellDataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WellDataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTreeItemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->addNewBlock(); break;
        case 2: _t->addNewStation(); break;
        case 3: _t->addNewWell(); break;
        case 4: _t->addNewStage(); break;
        case 5: _t->removeContent(); break;
        case 6: _t->renameContent(); break;
        case 7: _t->showFracBasicDialog(); break;
        case 8: _t->showFracPerDialog(); break;
        case 9: _t->showFracOperaDialog(); break;
        case 10: _t->showFracTestDialog(); break;
        case 11: _t->autoMergeData(); break;
        case 12: _t->showFracWhDialog(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WellDataManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WellDataManager.data,
    qt_meta_data_WellDataManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WellDataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WellDataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WellDataManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WellDataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
