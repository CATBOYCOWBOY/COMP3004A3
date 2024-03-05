/****************************************************************************
** Meta object code from reading C++ file 'elevatorcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ElevatorApplication/elevatorcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elevatorcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ElevatorController_t {
    QByteArrayData data[20];
    char stringdata0[387];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ElevatorController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ElevatorController_t qt_meta_stringdata_ElevatorController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ElevatorController"
QT_MOC_LITERAL(1, 19, 7), // "shutOff"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "elevatorFloorChanged"
QT_MOC_LITERAL(4, 49, 21), // "onElevatorIndexChange"
QT_MOC_LITERAL(5, 71, 18), // "onFloorIndexChange"
QT_MOC_LITERAL(6, 90, 22), // "onElevatorPanelRequest"
QT_MOC_LITERAL(7, 113, 21), // "onElevatorOpenRequest"
QT_MOC_LITERAL(8, 135, 22), // "onElevatorCloseRequest"
QT_MOC_LITERAL(9, 158, 20), // "onFloorButtonRequest"
QT_MOC_LITERAL(10, 179, 20), // "onElevatorFireButton"
QT_MOC_LITERAL(11, 200, 20), // "onElevatorHelpButton"
QT_MOC_LITERAL(12, 221, 20), // "onElevatorOverButton"
QT_MOC_LITERAL(13, 242, 21), // "onElevatorBlockButton"
QT_MOC_LITERAL(14, 264, 21), // "onElevatorResetButton"
QT_MOC_LITERAL(15, 286, 20), // "onBuildingFireButton"
QT_MOC_LITERAL(16, 307, 22), // "onBuildingOutageButton"
QT_MOC_LITERAL(17, 330, 12), // "onHelpButton"
QT_MOC_LITERAL(18, 343, 21), // "onBuildingResetButton"
QT_MOC_LITERAL(19, 365, 21) // "onElevatorFLoorChange"

    },
    "ElevatorController\0shutOff\0\0"
    "elevatorFloorChanged\0onElevatorIndexChange\0"
    "onFloorIndexChange\0onElevatorPanelRequest\0"
    "onElevatorOpenRequest\0onElevatorCloseRequest\0"
    "onFloorButtonRequest\0onElevatorFireButton\0"
    "onElevatorHelpButton\0onElevatorOverButton\0"
    "onElevatorBlockButton\0onElevatorResetButton\0"
    "onBuildingFireButton\0onBuildingOutageButton\0"
    "onHelpButton\0onBuildingResetButton\0"
    "onElevatorFLoorChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ElevatorController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  106,    2, 0x0a /* Public */,
       5,    1,  109,    2, 0x0a /* Public */,
       6,    1,  112,    2, 0x0a /* Public */,
       7,    1,  115,    2, 0x0a /* Public */,
       8,    0,  118,    2, 0x0a /* Public */,
       9,    0,  119,    2, 0x0a /* Public */,
      10,    0,  120,    2, 0x0a /* Public */,
      11,    0,  121,    2, 0x0a /* Public */,
      12,    0,  122,    2, 0x0a /* Public */,
      13,    0,  123,    2, 0x0a /* Public */,
      14,    0,  124,    2, 0x0a /* Public */,
      15,    0,  125,    2, 0x0a /* Public */,
      16,    0,  126,    2, 0x0a /* Public */,
      17,    0,  127,    2, 0x0a /* Public */,
      18,    0,  128,    2, 0x0a /* Public */,
      19,    1,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ElevatorController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ElevatorController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shutOff(); break;
        case 1: _t->elevatorFloorChanged(); break;
        case 2: _t->onElevatorIndexChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onFloorIndexChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onElevatorPanelRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onElevatorOpenRequest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onElevatorCloseRequest(); break;
        case 7: _t->onFloorButtonRequest(); break;
        case 8: _t->onElevatorFireButton(); break;
        case 9: _t->onElevatorHelpButton(); break;
        case 10: _t->onElevatorOverButton(); break;
        case 11: _t->onElevatorBlockButton(); break;
        case 12: _t->onElevatorResetButton(); break;
        case 13: _t->onBuildingFireButton(); break;
        case 14: _t->onBuildingOutageButton(); break;
        case 15: _t->onHelpButton(); break;
        case 16: _t->onBuildingResetButton(); break;
        case 17: _t->onElevatorFLoorChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ElevatorController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ElevatorController::shutOff)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ElevatorController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ElevatorController::elevatorFloorChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ElevatorController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ElevatorController.data,
    qt_meta_data_ElevatorController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ElevatorController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ElevatorController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ElevatorController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ElevatorController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ElevatorController::shutOff()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ElevatorController::elevatorFloorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
