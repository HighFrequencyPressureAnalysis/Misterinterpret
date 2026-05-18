/****************************************************************************
** Meta object code from reading C++ file 'dialogexportplotdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../dialogexportplotdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogexportplotdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogExportPlotData_t {
    QByteArrayData data[7];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogExportPlotData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogExportPlotData_t qt_meta_stringdata_DialogExportPlotData = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DialogExportPlotData"
QT_MOC_LITERAL(1, 21, 11), // "setSaveType"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "setSaveTxtPath"
QT_MOC_LITERAL(4, 49, 16), // "setSaveExcelPath"
QT_MOC_LITERAL(5, 66, 15), // "setSaveFileType"
QT_MOC_LITERAL(6, 82, 10) // "exportData"

    },
    "DialogExportPlotData\0setSaveType\0\0"
    "setSaveTxtPath\0setSaveExcelPath\0"
    "setSaveFileType\0exportData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogExportPlotData[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void DialogExportPlotData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogExportPlotData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSaveType(); break;
        case 1: _t->setSaveTxtPath(); break;
        case 2: _t->setSaveExcelPath(); break;
        case 3: _t->setSaveFileType(); break;
        case 4: { bool _r = _t->exportData();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogExportPlotData::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_DialogExportPlotData.data,
    qt_meta_data_DialogExportPlotData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogExportPlotData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogExportPlotData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogExportPlotData.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogExportPlotData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
