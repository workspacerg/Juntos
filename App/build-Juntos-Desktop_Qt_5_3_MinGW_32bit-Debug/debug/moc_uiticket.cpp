/****************************************************************************
** Meta object code from reading C++ file 'uiticket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juntos/uiticket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiticket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiTicket_t {
    QByteArrayData data[17];
    char stringdata[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uiTicket_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uiTicket_t qt_meta_stringdata_uiTicket = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 17),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 17),
QT_MOC_LITERAL(4, 46, 17),
QT_MOC_LITERAL(5, 64, 17),
QT_MOC_LITERAL(6, 82, 17),
QT_MOC_LITERAL(7, 100, 38),
QT_MOC_LITERAL(8, 139, 17),
QT_MOC_LITERAL(9, 157, 4),
QT_MOC_LITERAL(10, 162, 21),
QT_MOC_LITERAL(11, 184, 23),
QT_MOC_LITERAL(12, 208, 4),
QT_MOC_LITERAL(13, 213, 16),
QT_MOC_LITERAL(14, 230, 18),
QT_MOC_LITERAL(15, 249, 18),
QT_MOC_LITERAL(16, 268, 20)
    },
    "uiTicket\0displayFormAddBug\0\0"
    "displayFormDelBug\0displayFormUpdBug\0"
    "on_addBug_clicked\0on_delBug_clicked\0"
    "on_tableWidgetTicket_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_confirmDel_clicked\0"
    "on_lineEdit_textChanged\0arg1\0"
    "on_mesTk_clicked\0on_autreTk_clicked\0"
    "on_resolus_clicked\0on_nonAssign_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiTicket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       4,    2,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void uiTicket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiTicket *_t = static_cast<uiTicket *>(_o);
        switch (_id) {
        case 0: _t->displayFormAddBug(); break;
        case 1: _t->displayFormDelBug((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->displayFormUpdBug((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_addBug_clicked(); break;
        case 4: _t->on_delBug_clicked(); break;
        case 5: _t->on_tableWidgetTicket_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_confirmDel_clicked(); break;
        case 7: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_mesTk_clicked(); break;
        case 9: _t->on_autreTk_clicked(); break;
        case 10: _t->on_resolus_clicked(); break;
        case 11: _t->on_nonAssign_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (uiTicket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiTicket::displayFormAddBug)) {
                *result = 0;
            }
        }
        {
            typedef void (uiTicket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiTicket::displayFormDelBug)) {
                *result = 1;
            }
        }
        {
            typedef void (uiTicket::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiTicket::displayFormUpdBug)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject uiTicket::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_uiTicket.data,
      qt_meta_data_uiTicket,  qt_static_metacall, 0, 0}
};


const QMetaObject *uiTicket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiTicket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiTicket.stringdata))
        return static_cast<void*>(const_cast< uiTicket*>(this));
    return QWidget::qt_metacast(_clname);
}

int uiTicket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void uiTicket::displayFormAddBug()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void uiTicket::displayFormDelBug(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void uiTicket::displayFormUpdBug(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
