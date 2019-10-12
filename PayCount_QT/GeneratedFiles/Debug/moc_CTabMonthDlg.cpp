/****************************************************************************
** Meta object code from reading C++ file 'CTabMonthDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CTabMonthDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTabMonthDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTabMonthDlg_t {
    QByteArrayData data[16];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTabMonthDlg_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTabMonthDlg_t qt_meta_stringdata_CTabMonthDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CTabMonthDlg"
QT_MOC_LITERAL(1, 13, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "pdata"
QT_MOC_LITERAL(4, 30, 8), // "sg_ThCal"
QT_MOC_LITERAL(5, 39, 11), // "EM_SOCK_CMD"
QT_MOC_LITERAL(6, 51, 3), // "cmd"
QT_MOC_LITERAL(7, 55, 10), // "EM_CMD_RET"
QT_MOC_LITERAL(8, 66, 3), // "ret"
QT_MOC_LITERAL(9, 70, 3), // "rst"
QT_MOC_LITERAL(10, 74, 6), // "strPay"
QT_MOC_LITERAL(11, 81, 9), // "st_CalBak"
QT_MOC_LITERAL(12, 91, 9), // "BtnUpdate"
QT_MOC_LITERAL(13, 101, 16), // "st_ComboxChanged"
QT_MOC_LITERAL(14, 118, 17), // "st_KeyWordChanged"
QT_MOC_LITERAL(15, 136, 8) // "st_ThCal"

    },
    "CTabMonthDlg\0sg_CalBak\0\0pdata\0sg_ThCal\0"
    "EM_SOCK_CMD\0cmd\0EM_CMD_RET\0ret\0rst\0"
    "strPay\0st_CalBak\0BtnUpdate\0st_ComboxChanged\0"
    "st_KeyWordChanged\0st_ThCal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTabMonthDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    4,   72,    2, 0x06 /* Public */,
       4,    3,   81,    2, 0x26 /* Public | MethodCloned */,
       4,    2,   88,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   93,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    1,   97,    2, 0x0a /* Public */,
      14,    1,  100,    2, 0x0a /* Public */,
      15,    4,  103,    2, 0x0a /* Public */,
      15,    3,  112,    2, 0x2a /* Public | MethodCloned */,
      15,    2,  119,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, QMetaType::Bool, QMetaType::QString,    6,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, QMetaType::Bool,    6,    8,    9,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, QMetaType::Bool, QMetaType::QString,    6,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, QMetaType::Bool,    6,    8,    9,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    8,

       0        // eod
};

void CTabMonthDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTabMonthDlg *_t = static_cast<CTabMonthDlg *>(_o);
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->sg_ThCal((*reinterpret_cast< EM_SOCK_CMD(*)>(_a[1])),(*reinterpret_cast< EM_CMD_RET(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->sg_ThCal((*reinterpret_cast< EM_SOCK_CMD(*)>(_a[1])),(*reinterpret_cast< EM_CMD_RET(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->sg_ThCal((*reinterpret_cast< EM_SOCK_CMD(*)>(_a[1])),(*reinterpret_cast< EM_CMD_RET(*)>(_a[2]))); break;
        case 4: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 5: _t->BtnUpdate(); break;
        case 6: _t->st_ComboxChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->st_KeyWordChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->st_ThCal((*reinterpret_cast< EM_SOCK_CMD(*)>(_a[1])),(*reinterpret_cast< EM_CMD_RET(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->st_ThCal((*reinterpret_cast< EM_SOCK_CMD(*)>(_a[1])),(*reinterpret_cast< EM_CMD_RET(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->st_ThCal((*reinterpret_cast< EM_SOCK_CMD(*)>(_a[1])),(*reinterpret_cast< EM_CMD_RET(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CTabMonthDlg::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTabMonthDlg::sg_CalBak)) {
                *result = 0;
            }
        }
        {
            typedef void (CTabMonthDlg::*_t)(EM_SOCK_CMD , EM_CMD_RET , bool , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTabMonthDlg::sg_ThCal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CTabMonthDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CTabMonthDlg.data,
      qt_meta_data_CTabMonthDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CTabMonthDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTabMonthDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CTabMonthDlg.stringdata))
        return static_cast<void*>(const_cast< CTabMonthDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int CTabMonthDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CTabMonthDlg::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CTabMonthDlg::sg_ThCal(EM_SOCK_CMD _t1, EM_CMD_RET _t2, bool _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
