/****************************************************************************
** Meta object code from reading C++ file 'CDayPayDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CDayPayDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CDayPayDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CDayPayDlg_t {
    QByteArrayData data[12];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDayPayDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDayPayDlg_t qt_meta_stringdata_CDayPayDlg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CDayPayDlg"
QT_MOC_LITERAL(1, 11, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "pdata"
QT_MOC_LITERAL(4, 28, 9), // "st_CalBak"
QT_MOC_LITERAL(5, 38, 9), // "st_BtnMax"
QT_MOC_LITERAL(6, 48, 9), // "st_BtnAdd"
QT_MOC_LITERAL(7, 58, 10), // "st_BtnSave"
QT_MOC_LITERAL(8, 69, 9), // "st_BtnDel"
QT_MOC_LITERAL(9, 79, 15), // "st_comboChanged"
QT_MOC_LITERAL(10, 95, 20), // "st_numberEditChanged"
QT_MOC_LITERAL(11, 116, 16) // "st_SetAllPayCtrl"

    },
    "CDayPayDlg\0sg_CalBak\0\0pdata\0st_CalBak\0"
    "st_BtnMax\0st_BtnAdd\0st_BtnSave\0st_BtnDel\0"
    "st_comboChanged\0st_numberEditChanged\0"
    "st_SetAllPayCtrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDayPayDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   62,    2, 0x0a /* Public */,
       5,    0,   65,    2, 0x0a /* Public */,
       6,    0,   66,    2, 0x0a /* Public */,
       7,    0,   67,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      11,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void CDayPayDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CDayPayDlg *_t = static_cast<CDayPayDlg *>(_o);
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 2: _t->st_BtnMax(); break;
        case 3: _t->st_BtnAdd(); break;
        case 4: _t->st_BtnSave(); break;
        case 5: _t->st_BtnDel(); break;
        case 6: _t->st_comboChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->st_numberEditChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->st_SetAllPayCtrl(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CDayPayDlg::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CDayPayDlg::sg_CalBak)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CDayPayDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDayPayDlg.data,
      qt_meta_data_CDayPayDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CDayPayDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDayPayDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CDayPayDlg.stringdata))
        return static_cast<void*>(const_cast< CDayPayDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDayPayDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CDayPayDlg::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
