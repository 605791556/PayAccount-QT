/****************************************************************************
** Meta object code from reading C++ file 'CTabWorkDayDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CTabWorkDayDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTabWorkDayDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CTabWorkDayDlg_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CTabWorkDayDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CTabWorkDayDlg_t qt_meta_stringdata_CTabWorkDayDlg = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CTabWorkDayDlg"
QT_MOC_LITERAL(1, 15, 9), // "sg_CalBak"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "pdata"
QT_MOC_LITERAL(4, 32, 9), // "st_CalBak"
QT_MOC_LITERAL(5, 42, 17), // "st_KeyWordChanged"
QT_MOC_LITERAL(6, 60, 14), // "st_DateChanged"
QT_MOC_LITERAL(7, 75, 4), // "date"
QT_MOC_LITERAL(8, 80, 19), // "st_RowDoubleClicked"
QT_MOC_LITERAL(9, 100, 12) // "st_BtnUpdate"

    },
    "CTabWorkDayDlg\0sg_CalBak\0\0pdata\0"
    "st_CalBak\0st_KeyWordChanged\0st_DateChanged\0"
    "date\0st_RowDoubleClicked\0st_BtnUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CTabWorkDayDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QDate,    7,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,

       0        // eod
};

void CTabWorkDayDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CTabWorkDayDlg *_t = static_cast<CTabWorkDayDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sg_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 1: _t->st_CalBak((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 2: _t->st_KeyWordChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->st_DateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 4: _t->st_RowDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->st_BtnUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CTabWorkDayDlg::*_t)(void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CTabWorkDayDlg::sg_CalBak)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CTabWorkDayDlg::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CTabWorkDayDlg.data,
      qt_meta_data_CTabWorkDayDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CTabWorkDayDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CTabWorkDayDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CTabWorkDayDlg.stringdata0))
        return static_cast<void*>(const_cast< CTabWorkDayDlg*>(this));
    return QWidget::qt_metacast(_clname);
}

int CTabWorkDayDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CTabWorkDayDlg::sg_CalBak(void * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE