/****************************************************************************
** Meta object code from reading C++ file 'receivethread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JunQia/receivethread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receivethread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Receivethread_t {
    QByteArrayData data[17];
    char stringdata[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Receivethread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Receivethread_t qt_meta_stringdata_Receivethread = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 6),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 5),
QT_MOC_LITERAL(4, 28, 9),
QT_MOC_LITERAL(5, 38, 5),
QT_MOC_LITERAL(6, 44, 11),
QT_MOC_LITERAL(7, 56, 6),
QT_MOC_LITERAL(8, 63, 8),
QT_MOC_LITERAL(9, 72, 14),
QT_MOC_LITERAL(10, 87, 11),
QT_MOC_LITERAL(11, 99, 8),
QT_MOC_LITERAL(12, 108, 9),
QT_MOC_LITERAL(13, 118, 6),
QT_MOC_LITERAL(14, 125, 6),
QT_MOC_LITERAL(15, 132, 13),
QT_MOC_LITERAL(16, 146, 13)
    },
    "Receivethread\0Recmeg\0\0char*\0recinimeg\0"
    "shule\0tachaoshile\0yingle\0yaoqiuhe\0"
    "qiuhechenggong\0qiuheshibai\0renshule\0"
    "getSocket\0SOCKET\0kaishi\0shoudaotupian\0"
    "shoudaomingzi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Receivethread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,
       6,    0,   86,    2, 0x06 /* Public */,
       7,    0,   87,    2, 0x06 /* Public */,
       8,    0,   88,    2, 0x06 /* Public */,
       9,    0,   89,    2, 0x06 /* Public */,
      10,    0,   90,    2, 0x06 /* Public */,
      11,    0,   91,    2, 0x06 /* Public */,
      12,    1,   92,    2, 0x06 /* Public */,
      14,    0,   95,    2, 0x06 /* Public */,
      15,    1,   96,    2, 0x06 /* Public */,
      16,    1,   99,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void Receivethread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Receivethread *_t = static_cast<Receivethread *>(_o);
        switch (_id) {
        case 0: _t->Recmeg((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->recinimeg((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->shule(); break;
        case 3: _t->tachaoshile(); break;
        case 4: _t->yingle(); break;
        case 5: _t->yaoqiuhe(); break;
        case 6: _t->qiuhechenggong(); break;
        case 7: _t->qiuheshibai(); break;
        case 8: _t->renshule(); break;
        case 9: _t->getSocket((*reinterpret_cast< SOCKET(*)>(_a[1]))); break;
        case 10: _t->kaishi(); break;
        case 11: _t->shoudaotupian((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 12: _t->shoudaomingzi((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Receivethread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::Recmeg)) {
                *result = 0;
            }
        }
        {
            typedef void (Receivethread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::recinimeg)) {
                *result = 1;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::shule)) {
                *result = 2;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::tachaoshile)) {
                *result = 3;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::yingle)) {
                *result = 4;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::yaoqiuhe)) {
                *result = 5;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::qiuhechenggong)) {
                *result = 6;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::qiuheshibai)) {
                *result = 7;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::renshule)) {
                *result = 8;
            }
        }
        {
            typedef void (Receivethread::*_t)(SOCKET );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::getSocket)) {
                *result = 9;
            }
        }
        {
            typedef void (Receivethread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::kaishi)) {
                *result = 10;
            }
        }
        {
            typedef void (Receivethread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::shoudaotupian)) {
                *result = 11;
            }
        }
        {
            typedef void (Receivethread::*_t)(char * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Receivethread::shoudaomingzi)) {
                *result = 12;
            }
        }
    }
}

const QMetaObject Receivethread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Receivethread.data,
      qt_meta_data_Receivethread,  qt_static_metacall, 0, 0}
};


const QMetaObject *Receivethread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Receivethread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Receivethread.stringdata))
        return static_cast<void*>(const_cast< Receivethread*>(this));
    return QThread::qt_metacast(_clname);
}

int Receivethread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Receivethread::Recmeg(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Receivethread::recinimeg(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Receivethread::shule()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Receivethread::tachaoshile()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Receivethread::yingle()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Receivethread::yaoqiuhe()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Receivethread::qiuhechenggong()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Receivethread::qiuheshibai()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Receivethread::renshule()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Receivethread::getSocket(SOCKET _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Receivethread::kaishi()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void Receivethread::shoudaotupian(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Receivethread::shoudaomingzi(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
