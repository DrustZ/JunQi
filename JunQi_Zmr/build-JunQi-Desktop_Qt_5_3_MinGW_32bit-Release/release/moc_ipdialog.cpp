/****************************************************************************
** Meta object code from reading C++ file 'ipdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JunQia/ipdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ipdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IPDialog_t {
    QByteArrayData data[17];
    char stringdata[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IPDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IPDialog_t qt_meta_stringdata_IPDialog = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 21),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 24),
QT_MOC_LITERAL(4, 57, 23),
QT_MOC_LITERAL(5, 81, 23),
QT_MOC_LITERAL(6, 105, 23),
QT_MOC_LITERAL(7, 129, 23),
QT_MOC_LITERAL(8, 153, 23),
QT_MOC_LITERAL(9, 177, 23),
QT_MOC_LITERAL(10, 201, 23),
QT_MOC_LITERAL(11, 225, 23),
QT_MOC_LITERAL(12, 249, 24),
QT_MOC_LITERAL(13, 274, 24),
QT_MOC_LITERAL(14, 299, 24),
QT_MOC_LITERAL(15, 324, 23),
QT_MOC_LITERAL(16, 348, 4)
    },
    "IPDialog\0on_pushButton_clicked\0\0"
    "on_pushButton_11_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked\0on_pushButton_7_clicked\0"
    "on_pushButton_8_clicked\0on_pushButton_9_clicked\0"
    "on_pushButton_12_clicked\0"
    "on_pushButton_10_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_lineEdit_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IPDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void IPDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IPDialog *_t = static_cast<IPDialog *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_11_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_5_clicked(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->on_pushButton_7_clicked(); break;
        case 8: _t->on_pushButton_8_clicked(); break;
        case 9: _t->on_pushButton_9_clicked(); break;
        case 10: _t->on_pushButton_12_clicked(); break;
        case 11: _t->on_pushButton_10_clicked(); break;
        case 12: _t->on_pushButton_13_clicked(); break;
        case 13: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject IPDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IPDialog.data,
      qt_meta_data_IPDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *IPDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IPDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IPDialog.stringdata))
        return static_cast<void*>(const_cast< IPDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int IPDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
