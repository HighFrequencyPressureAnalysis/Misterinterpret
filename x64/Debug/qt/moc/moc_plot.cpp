/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[19];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 13), // "initAxisValue"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "outputPic"
QT_MOC_LITERAL(4, 30, 10), // "zoomInPlot"
QT_MOC_LITERAL(5, 41, 7), // "checked"
QT_MOC_LITERAL(6, 49, 11), // "zoomOutPlot"
QT_MOC_LITERAL(7, 61, 16), // "setLegendVisible"
QT_MOC_LITERAL(8, 78, 12), // "removeRubber"
QT_MOC_LITERAL(9, 91, 12), // "setDragModel"
QT_MOC_LITERAL(10, 104, 12), // "setZoomModel"
QT_MOC_LITERAL(11, 117, 11), // "setShowData"
QT_MOC_LITERAL(12, 129, 8), // "showMenu"
QT_MOC_LITERAL(13, 138, 12), // "QMouseEvent*"
QT_MOC_LITERAL(14, 151, 20), // "showExportDataDialog"
QT_MOC_LITERAL(15, 172, 18), // "resetLocalDateTime"
QT_MOC_LITERAL(16, 191, 8), // "QCPRange"
QT_MOC_LITERAL(17, 200, 22), // "setDataTimeAxisVisible"
QT_MOC_LITERAL(18, 223, 14) // "showChooseData"

    },
    "Plot\0initAxisValue\0\0outputPic\0zoomInPlot\0"
    "checked\0zoomOutPlot\0setLegendVisible\0"
    "removeRubber\0setDragModel\0setZoomModel\0"
    "setShowData\0showMenu\0QMouseEvent*\0"
    "showExportDataDialog\0resetLocalDateTime\0"
    "QCPRange\0setDataTimeAxisVisible\0"
    "showChooseData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    1,   90,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    1,   94,    2, 0x08 /* Private */,
      10,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      12,    1,  103,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      18,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 13,    2,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initAxisValue(); break;
        case 1: _t->outputPic(); break;
        case 2: _t->zoomInPlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->zoomOutPlot(); break;
        case 4: _t->setLegendVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->removeRubber(); break;
        case 6: _t->setDragModel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setZoomModel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setShowData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->showMenu((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: _t->showExportDataDialog(); break;
        case 11: _t->resetLocalDateTime((*reinterpret_cast< const QCPRange(*)>(_a[1]))); break;
        case 12: _t->setDataTimeAxisVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->showChooseData((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Plot::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Plot.data,
    qt_meta_data_Plot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
