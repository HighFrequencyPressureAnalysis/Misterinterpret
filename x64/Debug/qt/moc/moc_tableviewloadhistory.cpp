/****************************************************************************
** Meta object code from reading C++ file 'tableviewloadhistory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../tableviewloadhistory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableviewloadhistory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableViewLoadHistory_t {
    QByteArrayData data[7];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableViewLoadHistory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableViewLoadHistory_t qt_meta_stringdata_TableViewLoadHistory = {
    {
QT_MOC_LITERAL(0, 0, 20), // "TableViewLoadHistory"
QT_MOC_LITERAL(1, 21, 16), // "setTableRowCount"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 19), // "setTableColumnCount"
QT_MOC_LITERAL(4, 59, 15), // "showDataSetting"
QT_MOC_LITERAL(5, 75, 11), // "clearHeader"
QT_MOC_LITERAL(6, 87, 32) // "columncustomContextMenuRequested"

    },
    "TableViewLoadHistory\0setTableRowCount\0"
    "\0setTableColumnCount\0showDataSetting\0"
    "clearHeader\0columncustomContextMenuRequested"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableViewLoadHistory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    1,   42,    2, 0x0a /* Public */,
       4,    1,   45,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

void TableViewLoadHistory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TableViewLoadHistory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTableRowCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setTableColumnCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->showDataSetting((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->clearHeader(); break;
        case 4: _t->columncustomContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TableViewLoadHistory::staticMetaObject = { {
    &TableView::staticMetaObject,
    qt_meta_stringdata_TableViewLoadHistory.data,
    qt_meta_data_TableViewLoadHistory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TableViewLoadHistory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableViewLoadHistory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableViewLoadHistory.stringdata0))
        return static_cast<void*>(this);
    return TableView::qt_metacast(_clname);
}

int TableViewLoadHistory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
