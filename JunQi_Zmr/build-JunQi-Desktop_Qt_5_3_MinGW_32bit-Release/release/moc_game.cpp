/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JunQia/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[22];
    char stringdata[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 23),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 11),
QT_MOC_LITERAL(4, 42, 1),
QT_MOC_LITERAL(5, 44, 21),
QT_MOC_LITERAL(6, 66, 7),
QT_MOC_LITERAL(7, 74, 22),
QT_MOC_LITERAL(8, 97, 9),
QT_MOC_LITERAL(9, 107, 8),
QT_MOC_LITERAL(10, 116, 10),
QT_MOC_LITERAL(11, 127, 34),
QT_MOC_LITERAL(12, 162, 9),
QT_MOC_LITERAL(13, 172, 23),
QT_MOC_LITERAL(14, 196, 8),
QT_MOC_LITERAL(15, 205, 5),
QT_MOC_LITERAL(16, 211, 23),
QT_MOC_LITERAL(17, 235, 7),
QT_MOC_LITERAL(18, 243, 10),
QT_MOC_LITERAL(19, 254, 21),
QT_MOC_LITERAL(20, 276, 12),
QT_MOC_LITERAL(21, 289, 21)
    },
    "Game\0on_pushButton_2_clicked\0\0updateLabel\0"
    "i\0on_pushButton_clicked\0timeOUT\0"
    "on_actionNew_triggered\0starttime\0"
    "stoptime\0updatetime\0"
    "on_actionAdd_to_existing_triggered\0"
    "playagain\0on_pushButton_5_clicked\0"
    "kaishile\0state\0on_pushButton_6_clicked\0"
    "xianshi\0remotename\0on_action_2_triggered\0"
    "setconnected\0on_action_3_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    1,  100,    2, 0x08 /* Private */,
       5,    0,  103,    2, 0x08 /* Private */,
       6,    0,  104,    2, 0x08 /* Private */,
       7,    0,  105,    2, 0x08 /* Private */,
       8,    0,  106,    2, 0x08 /* Private */,
       9,    0,  107,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    1,  112,    2, 0x08 /* Private */,
      16,    0,  115,    2, 0x08 /* Private */,
      17,    1,  116,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Game *_t = static_cast<Game *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->updateLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->timeOUT(); break;
        case 4: _t->on_actionNew_triggered(); break;
        case 5: _t->starttime(); break;
        case 6: _t->stoptime(); break;
        case 7: _t->updatetime(); break;
        case 8: _t->on_actionAdd_to_existing_triggered(); break;
        case 9: _t->playagain(); break;
        case 10: _t->on_pushButton_5_clicked(); break;
        case 11: _t->kaishile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_6_clicked(); break;
        case 13: _t->xianshi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->on_action_2_triggered(); break;
        case 15: _t->setconnected(); break;
        case 16: _t->on_action_3_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject Game::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Game.data,
      qt_meta_data_Game,  qt_static_metacall, 0, 0}
};


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata))
        return static_cast<void*>(const_cast< Game*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
