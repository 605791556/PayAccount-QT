/****************************************************************************
** Meta object code from reading C++ file 'CTabOtherSetDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CTabOtherSetDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTabOtherSetDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTabOtherSetDlg_t {
    QByteArrayData data[8];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTabOtherSetDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTabOtherSetDlg_t qt_meta_stringdata_CTabOtherSetDlg = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CTabOtherSetDlg"
QT_MOC_LITERAL(1, 16, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "pdata"
QT_MOC_LITERAL(4, 33, 9), // "st_CalBak"
QT_MOC_LITERAL(5, 43, 16), // "st_ComboxChanged"
QT_MOC_LITERAL(6, 60, 15), // "st_checkChanged"
QT_MOC_LITERAL(7, 76, 10) // "st_BtnSave"

    },
    "CTabOtherSetDlg\0sg_CalBak\0\0pdata\0"
    "st_CalBak\0st_ComboxChanged\0st_checkChanged\0"
    "st_BtnSave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTabOtherSetDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void CTabOtherSetDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTabOtherSetDlg *_t = static_cast<CTabOtherSetDlg *>(_o);
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 2: _t->st_ComboxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->st_checkChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->st_BtnSave(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CTabOtherSetDlg::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTabOtherSetDlg::sg_CalBak)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CTabOtherSetDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CTabOtherSetDlg.data,
      qt_meta_data_CTabOtherSetDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CTabOtherSetDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTabOtherSetDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CTabOtherSetDlg.stringdata))
        return static_cast<void*>(const_cast< CTabOtherSetDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int CTabOtherSetDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CTabOtherSetDlg::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
