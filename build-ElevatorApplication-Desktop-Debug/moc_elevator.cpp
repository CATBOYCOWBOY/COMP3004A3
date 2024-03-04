/****************************************************************************
** Meta object code from reading C++ file 'elevator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ElevatorApplication/elevator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Elevator_t {
    QByteArrayData data[18];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Elevator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Elevator_t qt_meta_stringdata_Elevator = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Elevator"
QT_MOC_LITERAL(1, 9, 12), // "floorChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "doorOpened"
QT_MOC_LITERAL(4, 34, 22), // "elevatorMessageChanged"
QT_MOC_LITERAL(5, 57, 11), // "std::string"
QT_MOC_LITERAL(6, 69, 7), // "shutOff"
QT_MOC_LITERAL(7, 77, 9), // "eventLoop"
QT_MOC_LITERAL(8, 87, 15), // "addFloorToQueue"
QT_MOC_LITERAL(9, 103, 16), // "handleOpenButton"
QT_MOC_LITERAL(10, 120, 17), // "handleCloseButton"
QT_MOC_LITERAL(11, 138, 10), // "handleFire"
QT_MOC_LITERAL(12, 149, 16), // "handleHelpButton"
QT_MOC_LITERAL(13, 166, 14), // "handleOverload"
QT_MOC_LITERAL(14, 181, 11), // "handleBlock"
QT_MOC_LITERAL(15, 193, 12), // "handleOutage"
QT_MOC_LITERAL(16, 206, 11), // "resolveHelp"
QT_MOC_LITERAL(17, 218, 5) // "reset"

    },
    "Elevator\0floorChanged\0\0doorOpened\0"
    "elevatorMessageChanged\0std::string\0"
    "shutOff\0eventLoop\0addFloorToQueue\0"
    "handleOpenButton\0handleCloseButton\0"
    "handleFire\0handleHelpButton\0handleOverload\0"
    "handleBlock\0handleOutage\0resolveHelp\0"
    "reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Elevator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       4,    1,   95,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   99,    2, 0x0a /* Public */,
       8,    1,  100,    2, 0x0a /* Public */,
       9,    1,  103,    2, 0x0a /* Public */,
      10,    0,  106,    2, 0x0a /* Public */,
      11,    0,  107,    2, 0x0a /* Public */,
      12,    0,  108,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x0a /* Public */,
      14,    0,  110,    2, 0x0a /* Public */,
      15,    0,  111,    2, 0x0a /* Public */,
      16,    0,  112,    2, 0x0a /* Public */,
      17,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
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

void Elevator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Elevator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->floorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->doorOpened((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->elevatorMessageChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->shutOff(); break;
        case 4: _t->eventLoop(); break;
        case 5: _t->addFloorToQueue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->handleOpenButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->handleCloseButton(); break;
        case 8: _t->handleFire(); break;
        case 9: _t->handleHelpButton(); break;
        case 10: _t->handleOverload(); break;
        case 11: _t->handleBlock(); break;
        case 12: _t->handleOutage(); break;
        case 13: _t->resolveHelp(); break;
        case 14: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Elevator::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::floorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::doorOpened)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Elevator::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::elevatorMessageChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Elevator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Elevator::shutOff)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Elevator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Elevator.data,
    qt_meta_data_Elevator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Elevator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Elevator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Elevator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Elevator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Elevator::floorChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Elevator::doorOpened(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Elevator::elevatorMessageChanged(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Elevator::shutOff()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
