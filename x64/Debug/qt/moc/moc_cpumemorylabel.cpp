/****************************************************************************
** Meta object code from reading C++ file 'cpumemorylabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cpumemorylabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cpumemorylabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CpuMemoryLabel_t {
    QByteArrayData data[18];
    char stringdata0[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CpuMemoryLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CpuMemoryLabel_t qt_meta_stringdata_CpuMemoryLabel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CpuMemoryLabel"
QT_MOC_LITERAL(1, 15, 10), // "sendMemCal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "textChanged"
QT_MOC_LITERAL(4, 39, 4), // "text"
QT_MOC_LITERAL(5, 44, 12), // "valueChanged"
QT_MOC_LITERAL(6, 57, 10), // "cpuPercent"
QT_MOC_LITERAL(7, 68, 13), // "memoryPercent"
QT_MOC_LITERAL(8, 82, 9), // "memoryAll"
QT_MOC_LITERAL(9, 92, 9), // "memoryUse"
QT_MOC_LITERAL(10, 102, 10), // "memoryFree"
QT_MOC_LITERAL(11, 113, 6), // "getCPU"
QT_MOC_LITERAL(12, 120, 9), // "getMemory"
QT_MOC_LITERAL(13, 130, 8), // "readData"
QT_MOC_LITERAL(14, 139, 5), // "start"
QT_MOC_LITERAL(15, 145, 8), // "interval"
QT_MOC_LITERAL(16, 154, 4), // "stop"
QT_MOC_LITERAL(17, 159, 8) // "showText"

    },
    "CpuMemoryLabel\0sendMemCal\0\0textChanged\0"
    "text\0valueChanged\0cpuPercent\0memoryPercent\0"
    "memoryAll\0memoryUse\0memoryFree\0getCPU\0"
    "getMemory\0readData\0start\0interval\0"
    "stop\0showText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CpuMemoryLabel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    5,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   69,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,
      14,    1,   72,    2, 0x0a /* Public */,
      16,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::ULongLong, QMetaType::ULongLong, QMetaType::ULongLong, QMetaType::ULongLong,    6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

 // properties: name, type, flags
      17, QMetaType::Bool, 0x00095103,

       0        // eod
};

void CpuMemoryLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CpuMemoryLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMemCal(); break;
        case 1: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->valueChanged((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3])),(*reinterpret_cast< quint64(*)>(_a[4])),(*reinterpret_cast< quint64(*)>(_a[5]))); break;
        case 3: _t->getCPU(); break;
        case 4: _t->getMemory(); break;
        case 5: _t->readData(); break;
        case 6: _t->start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CpuMemoryLabel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CpuMemoryLabel::sendMemCal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CpuMemoryLabel::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CpuMemoryLabel::textChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CpuMemoryLabel::*)(quint64 , quint64 , quint64 , quint64 , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CpuMemoryLabel::valueChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CpuMemoryLabel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getShowText(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CpuMemoryLabel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowText(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CpuMemoryLabel::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_CpuMemoryLabel.data,
    qt_meta_data_CpuMemoryLabel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CpuMemoryLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CpuMemoryLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CpuMemoryLabel.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int CpuMemoryLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CpuMemoryLabel::sendMemCal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CpuMemoryLabel::textChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CpuMemoryLabel::valueChanged(quint64 _t1, quint64 _t2, quint64 _t3, quint64 _t4, quint64 _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
