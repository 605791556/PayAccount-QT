/****************************************************************************
** Meta object code from reading C++ file 'CAddProDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CAddProDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CAddProDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CAddProDlg_t {
    QByteArrayData data[6];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAddProDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAddProDlg_t qt_meta_stringdata_CAddProDlg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CAddProDlg"
QT_MOC_LITERAL(1, 11, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "pdata"
QT_MOC_LITERAL(4, 28, 9), // "st_CalBak"
QT_MOC_LITERAL(5, 38, 10) // "st_BtnSave"

    },
    "CAddProDlg\0sg_CalBak\0\0pdata\0st_CalBak\0"
    "st_BtnSave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAddProDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       5,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void,

       0        // eod
};

void CAddProDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAddProDlg *_t = static_cast<CAddProDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 2: _t->st_BtnSave(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAddProDlg::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAddProDlg::sg_CalBak)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CAddProDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CAddProDlg.data,
      qt_meta_data_CAddProDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CAddProDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAddProDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CAddProDlg.stringdata0))
        return static_cast<void*>(const_cast< CAddProDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CAddProDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CAddProDlg::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
