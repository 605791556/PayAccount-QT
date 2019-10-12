/****************************************************************************
** Meta object code from reading C++ file 'paycount_qt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../paycount_qt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paycount_qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PayCount_QT_t {
    QByteArrayData data[21];
    char stringdata[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PayCount_QT_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PayCount_QT_t qt_meta_stringdata_PayCount_QT = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PayCount_QT"
QT_MOC_LITERAL(1, 12, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "pdata"
QT_MOC_LITERAL(4, 29, 6), // "BtnMax"
QT_MOC_LITERAL(5, 36, 12), // "ConnectState"
QT_MOC_LITERAL(6, 49, 9), // "NET_STATE"
QT_MOC_LITERAL(7, 59, 5), // "state"
QT_MOC_LITERAL(8, 65, 9), // "st_CalBak"
QT_MOC_LITERAL(9, 75, 13), // "st_tabChanged"
QT_MOC_LITERAL(10, 89, 5), // "index"
QT_MOC_LITERAL(11, 95, 7), // "BtnInit"
QT_MOC_LITERAL(12, 103, 10), // "BtnAccount"
QT_MOC_LITERAL(13, 114, 6), // "BtnPwd"
QT_MOC_LITERAL(14, 121, 8), // "BtnStaff"
QT_MOC_LITERAL(15, 130, 7), // "BtnBook"
QT_MOC_LITERAL(16, 138, 10), // "BtnProject"
QT_MOC_LITERAL(17, 149, 6), // "BtnPay"
QT_MOC_LITERAL(18, 156, 6), // "BtnLog"
QT_MOC_LITERAL(19, 163, 7), // "BtnLock"
QT_MOC_LITERAL(20, 171, 8) // "BtnClose"

    },
    "PayCount_QT\0sg_CalBak\0\0pdata\0BtnMax\0"
    "ConnectState\0NET_STATE\0state\0st_CalBak\0"
    "st_tabChanged\0index\0BtnInit\0BtnAccount\0"
    "BtnPwd\0BtnStaff\0BtnBook\0BtnProject\0"
    "BtnPay\0BtnLog\0BtnLock\0BtnClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PayCount_QT[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   92,    2, 0x0a /* Public */,
       5,    1,   93,    2, 0x0a /* Public */,
       8,    1,   96,    2, 0x0a /* Public */,
       9,    1,   99,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    0,  103,    2, 0x0a /* Public */,
      13,    0,  104,    2, 0x0a /* Public */,
      14,    0,  105,    2, 0x0a /* Public */,
      15,    0,  106,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x0a /* Public */,
      17,    0,  108,    2, 0x0a /* Public */,
      18,    0,  109,    2, 0x0a /* Public */,
      19,    0,  110,    2, 0x0a /* Public */,
      20,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void, QMetaType::Int,   10,
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

void PayCount_QT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PayCount_QT *_t = static_cast<PayCount_QT *>(_o);
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->BtnMax(); break;
        case 2: _t->ConnectState((*reinterpret_cast< NET_STATE(*)>(_a[1]))); break;
        case 3: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 4: _t->st_tabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->BtnInit(); break;
        case 6: _t->BtnAccount(); break;
        case 7: _t->BtnPwd(); break;
        case 8: _t->BtnStaff(); break;
        case 9: _t->BtnBook(); break;
        case 10: _t->BtnProject(); break;
        case 11: _t->BtnPay(); break;
        case 12: _t->BtnLog(); break;
        case 13: _t->BtnLock(); break;
        case 14: _t->BtnClose(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NET_STATE >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PayCount_QT::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PayCount_QT::sg_CalBak)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PayCount_QT::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PayCount_QT.data,
      qt_meta_data_PayCount_QT,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PayCount_QT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PayCount_QT::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PayCount_QT.stringdata))
        return static_cast<void*>(const_cast< PayCount_QT*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PayCount_QT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void PayCount_QT::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
