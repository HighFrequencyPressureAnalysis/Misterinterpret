/****************************************************************************
** Meta object code from reading C++ file 'SARibbonBar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SARibbonBar.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SARibbonBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSARibbonBarENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSARibbonBarENDCLASS = QtMocHelpers::stringData(
    "SARibbonBar",
    "applicationButtonClicked",
    "",
    "currentRibbonTabChanged",
    "index",
    "ribbonModeChanged",
    "SARibbonBar::RibbonMode",
    "nowState",
    "ribbonStyleChanged",
    "SARibbonBar::RibbonStyles",
    "nowStyle",
    "titleBarHeightChanged",
    "oldHeight",
    "newHeight",
    "actionTriggered",
    "QAction*",
    "action",
    "onWindowTitleChanged",
    "title",
    "onWindowIconChanged",
    "i",
    "onCategoryWindowTitleChanged",
    "onStackWidgetHided",
    "onCurrentRibbonTabChanged",
    "onCurrentRibbonTabClicked",
    "onCurrentRibbonTabDoubleClicked",
    "onContextsCategoryPageAdded",
    "SARibbonCategory*",
    "category",
    "onContextsCategoryCategoryNameChanged",
    "onTabMoved",
    "from",
    "to",
    "addCategoryPage",
    "QWidget*",
    "ribbonStyle",
    "RibbonStyles",
    "minimumMode",
    "minimumModeButton",
    "windowTitleTextColor",
    "tabBarBaseLineColor",
    "windowTitleAligment",
    "Qt::Alignment",
    "enableWordWrap",
    "enableShowPannelTitle",
    "tabOnTitle",
    "pannelLayoutMode",
    "SARibbonPannel::PannelLayoutMode",
    "RibbonStyleFlag",
    "RibbonStyleLoose",
    "RibbonStyleCompact",
    "RibbonStyleThreeRow",
    "RibbonStyleTwoRow",
    "RibbonStyleLooseThreeRow",
    "RibbonStyleCompactThreeRow",
    "RibbonStyleLooseTwoRow",
    "RibbonStyleCompactTwoRow",
    "RibbonMode",
    "MinimumRibbonMode",
    "NormalRibbonMode"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSARibbonBarENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
      10,  169, // properties
       3,  219, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,   14 /* Public */,
       3,    1,  117,    2, 0x06,   15 /* Public */,
       5,    1,  120,    2, 0x06,   17 /* Public */,
       8,    1,  123,    2, 0x06,   19 /* Public */,
      11,    2,  126,    2, 0x06,   21 /* Public */,
      14,    1,  131,    2, 0x06,   24 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    1,  134,    2, 0x09,   26 /* Protected */,
      19,    1,  137,    2, 0x09,   28 /* Protected */,
      21,    1,  140,    2, 0x09,   30 /* Protected */,
      22,    0,  143,    2, 0x09,   32 /* Protected */,
      23,    1,  144,    2, 0x09,   33 /* Protected */,
      24,    1,  147,    2, 0x09,   35 /* Protected */,
      25,    1,  150,    2, 0x09,   37 /* Protected */,
      26,    1,  153,    2, 0x09,   39 /* Protected */,
      29,    2,  156,    2, 0x09,   41 /* Protected */,
      30,    2,  161,    2, 0x09,   44 /* Protected */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      33,    1,  166,    2, 0x02,   47 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QIcon,   20,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, 0x80000000 | 27, QMetaType::QString,   28,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   31,   32,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 34,   28,

 // properties: name, type, flags
      35, 0x80000000 | 36, 0x0001510b, uint(-1), 0,
      37, QMetaType::Bool, 0x00015103, uint(-1), 0,
      38, QMetaType::Bool, 0x00015003, uint(-1), 0,
      39, QMetaType::QColor, 0x00015103, uint(-1), 0,
      40, QMetaType::QColor, 0x00015103, uint(-1), 0,
      41, 0x80000000 | 42, 0x0001510b, uint(-1), 0,
      43, QMetaType::Bool, 0x00015103, uint(-1), 0,
      44, QMetaType::Bool, 0x00015103, uint(-1), 0,
      45, QMetaType::Bool, 0x00015103, uint(-1), 0,
      46, 0x80000000 | 47, 0x0001510b, uint(-1), 0,

 // enums: name, alias, flags, count, data
      48,   48, 0x0,    8,  234,
      36,   48, 0x1,    8,  250,
      57,   57, 0x0,    2,  266,

 // enum data: key, value
      49, uint(SARibbonBar::RibbonStyleLoose),
      50, uint(SARibbonBar::RibbonStyleCompact),
      51, uint(SARibbonBar::RibbonStyleThreeRow),
      52, uint(SARibbonBar::RibbonStyleTwoRow),
      53, uint(SARibbonBar::RibbonStyleLooseThreeRow),
      54, uint(SARibbonBar::RibbonStyleCompactThreeRow),
      55, uint(SARibbonBar::RibbonStyleLooseTwoRow),
      56, uint(SARibbonBar::RibbonStyleCompactTwoRow),
      49, uint(SARibbonBar::RibbonStyleLoose),
      50, uint(SARibbonBar::RibbonStyleCompact),
      51, uint(SARibbonBar::RibbonStyleThreeRow),
      52, uint(SARibbonBar::RibbonStyleTwoRow),
      53, uint(SARibbonBar::RibbonStyleLooseThreeRow),
      54, uint(SARibbonBar::RibbonStyleCompactThreeRow),
      55, uint(SARibbonBar::RibbonStyleLooseTwoRow),
      56, uint(SARibbonBar::RibbonStyleCompactTwoRow),
      58, uint(SARibbonBar::MinimumRibbonMode),
      59, uint(SARibbonBar::NormalRibbonMode),

       0        // eod
};

Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_CLASSSARibbonBarENDCLASS[] = {
    QMetaObject::SuperData::link<SARibbonPannel::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject SARibbonBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenuBar::staticMetaObject>(),
    qt_meta_stringdata_CLASSSARibbonBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSARibbonBarENDCLASS,
    qt_static_metacall,
    qt_meta_extradata_CLASSSARibbonBarENDCLASS,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSARibbonBarENDCLASS_t,
        // property 'ribbonStyle'
        QtPrivate::TypeAndForceComplete<RibbonStyles, std::true_type>,
        // property 'minimumMode'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'minimumModeButton'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'windowTitleTextColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'tabBarBaseLineColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'windowTitleAligment'
        QtPrivate::TypeAndForceComplete<Qt::Alignment, std::true_type>,
        // property 'enableWordWrap'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'enableShowPannelTitle'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'tabOnTitle'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'pannelLayoutMode'
        QtPrivate::TypeAndForceComplete<SARibbonPannel::PannelLayoutMode, std::true_type>,
        // enum 'RibbonStyleFlag'
        QtPrivate::TypeAndForceComplete<SARibbonBar::RibbonStyleFlag, std::true_type>,
        // enum 'RibbonStyles'
        QtPrivate::TypeAndForceComplete<SARibbonBar::RibbonStyles, std::true_type>,
        // enum 'RibbonMode'
        QtPrivate::TypeAndForceComplete<SARibbonBar::RibbonMode, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SARibbonBar, std::true_type>,
        // method 'applicationButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentRibbonTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'ribbonModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SARibbonBar::RibbonMode, std::false_type>,
        // method 'ribbonStyleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SARibbonBar::RibbonStyles, std::false_type>,
        // method 'titleBarHeightChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'actionTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'onWindowTitleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onWindowIconChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QIcon &, std::false_type>,
        // method 'onCategoryWindowTitleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onStackWidgetHided'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCurrentRibbonTabChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onCurrentRibbonTabClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onCurrentRibbonTabDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onContextsCategoryPageAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SARibbonCategory *, std::false_type>,
        // method 'onContextsCategoryCategoryNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<SARibbonCategory *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onTabMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addCategoryPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>
    >,
    nullptr
} };

void SARibbonBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SARibbonBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->applicationButtonClicked(); break;
        case 1: _t->currentRibbonTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->ribbonModeChanged((*reinterpret_cast< std::add_pointer_t<SARibbonBar::RibbonMode>>(_a[1]))); break;
        case 3: _t->ribbonStyleChanged((*reinterpret_cast< std::add_pointer_t<SARibbonBar::RibbonStyles>>(_a[1]))); break;
        case 4: _t->titleBarHeightChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->actionTriggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 6: _t->onWindowTitleChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onWindowIconChanged((*reinterpret_cast< std::add_pointer_t<QIcon>>(_a[1]))); break;
        case 8: _t->onCategoryWindowTitleChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->onStackWidgetHided(); break;
        case 10: _t->onCurrentRibbonTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->onCurrentRibbonTabClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->onCurrentRibbonTabDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->onContextsCategoryPageAdded((*reinterpret_cast< std::add_pointer_t<SARibbonCategory*>>(_a[1]))); break;
        case 14: _t->onContextsCategoryCategoryNameChanged((*reinterpret_cast< std::add_pointer_t<SARibbonCategory*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->onTabMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 16: _t->addCategoryPage((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SARibbonCategory* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< SARibbonCategory* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SARibbonBar::*)();
            if (_t _q_method = &SARibbonBar::applicationButtonClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SARibbonBar::*)(int );
            if (_t _q_method = &SARibbonBar::currentRibbonTabChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SARibbonBar::*)(SARibbonBar::RibbonMode );
            if (_t _q_method = &SARibbonBar::ribbonModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SARibbonBar::*)(SARibbonBar::RibbonStyles );
            if (_t _q_method = &SARibbonBar::ribbonStyleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SARibbonBar::*)(int , int );
            if (_t _q_method = &SARibbonBar::titleBarHeightChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SARibbonBar::*)(QAction * );
            if (_t _q_method = &SARibbonBar::actionTriggered; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SARibbonBar *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = QFlag(_t->currentRibbonStyle()); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isMinimumMode(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->haveShowMinimumModeButton(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->windowTitleTextColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->tabBarBaseLineColor(); break;
        case 5: *reinterpret_cast< Qt::Alignment*>(_v) = _t->windowTitleAligment(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isEnableWordWrap(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isEnableShowPannelTitle(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->isTabOnTitle(); break;
        case 9: *reinterpret_cast< SARibbonPannel::PannelLayoutMode*>(_v) = _t->pannelLayoutMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SARibbonBar *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRibbonStyle(QFlag(*reinterpret_cast<int*>(_v))); break;
        case 1: _t->setMinimumMode(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->showMinimumModeButton(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setWindowTitleTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setTabBarBaseLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setWindowTitleAligment(*reinterpret_cast< Qt::Alignment*>(_v)); break;
        case 6: _t->setEnableWordWrap(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setEnableShowPannelTitle(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setTabOnTitle(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setPannelLayoutMode(*reinterpret_cast< SARibbonPannel::PannelLayoutMode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SARibbonBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SARibbonBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSARibbonBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int SARibbonBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SARibbonBar::applicationButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SARibbonBar::currentRibbonTabChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SARibbonBar::ribbonModeChanged(SARibbonBar::RibbonMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SARibbonBar::ribbonStyleChanged(SARibbonBar::RibbonStyles _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SARibbonBar::titleBarHeightChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SARibbonBar::actionTriggered(QAction * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
