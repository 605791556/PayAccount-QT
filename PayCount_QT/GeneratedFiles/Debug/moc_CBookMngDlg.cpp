/****************************************************************************
** Meta object code from reading C++ file 'CBookMngDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CBookMngDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CBookMngDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CBookMngDlg_t {
    QByteArrayData data[17];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBookMngDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBookMngDlg_t qt_meta_stringdata_CBookMngDlg = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CBookMngDlg"
QT_MOC_LITERAL(1, 12, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "pdata"
QT_MOC_LITERAL(4, 29, 9), // "st_CalBak"
QT_MOC_LITERAL(5, 39, 10), // "st_BtnEdit"
QT_MOC_LITERAL(6, 50, 9), // "st_BtnDel"
QT_MOC_LITERAL(7, 60, 7), // "BtnFind"
QT_MOC_LITERAL(8, 68, 6), // "BtnAdd"
QT_MOC_LITERAL(9, 75, 5), // "BtnGo"
QT_MOC_LITERAL(10, 81, 7), // "BtnLast"
QT_MOC_LITERAL(11, 89, 7), // "BtnNext"
QT_MOC_LITERAL(12, 97, 7), // "BtnPlRk"
QT_MOC_LITERAL(13, 105, 8), // "BtnPlDel"
QT_MOC_LITERAL(14, 114, 16), // "st_doubleClicked"
QT_MOC_LITERAL(15, 131, 3), // "row"
QT_MOC_LITERAL(16, 135, 6) // "column"

    },
    "CBookMngDlg\0sg_CalBak\0\0pdata\0st_CalBak\0"
    "st_BtnEdit\0st_BtnDel\0BtnFind\0BtnAdd\0"
    "BtnGo\0BtnLast\0BtnNext\0BtnPlRk\0BtnPlDel\0"
    "st_doubleClicked\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBookMngDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x0a /* Public */,
       5,    0,   80,    2, 0x0a /* Public */,
       6,    0,   81,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    2,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,

       0        // eod
};

void CBookMngDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CBookMngDlg *_t = static_cast<CBookMngDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 2: _t->st_BtnEdit(); break;
        case 3: _t->st_BtnDel(); break;
        case 4: _t->BtnFind(); break;
        case 5: _t->BtnAdd(); break;
        case 6: _t->BtnGo(); break;
        case 7: _t->BtnLast(); break;
        case 8: _t->BtnNext(); break;
        case 9: _t->BtnPlRk(); break;
        case 10: _t->BtnPlDel(); break;
        case 11: _t->st_doubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CBookMngDlg::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBookMngDlg::sg_CalBak)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CBookMngDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CBookMngDlg.data,
      qt_meta_data_CBookMngDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CBookMngDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBookMngDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CBookMngDlg.stringdata0))
        return static_cast<void*>(const_cast< CBookMngDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CBookMngDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CBookMngDlg::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
