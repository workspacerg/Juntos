/****************************************************************************
** Meta object code from reading C++ file 'uiacceuil.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juntos/uiacceuil.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiacceuil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiAcceuil_t {
    QByteArrayData data[18];
    char stringdata[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uiAcceuil_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uiAcceuil_t qt_meta_stringdata_uiAcceuil = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 22),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 12),
QT_MOC_LITERAL(4, 47, 9),
QT_MOC_LITERAL(5, 57, 7),
QT_MOC_LITERAL(6, 65, 9),
QT_MOC_LITERAL(7, 75, 19),
QT_MOC_LITERAL(8, 95, 17),
QT_MOC_LITERAL(9, 113, 21),
QT_MOC_LITERAL(10, 135, 19),
QT_MOC_LITERAL(11, 155, 23),
QT_MOC_LITERAL(12, 179, 19),
QT_MOC_LITERAL(13, 199, 39),
QT_MOC_LITERAL(14, 239, 17),
QT_MOC_LITERAL(15, 257, 4),
QT_MOC_LITERAL(16, 262, 20),
QT_MOC_LITERAL(17, 283, 21)
    },
    "uiAcceuil\0notifiactionNewProject\0\0"
    "sigLoadTable\0sigAddPro\0CProjet\0sigDelPro\0"
    "sigSelectCurrentPro\0sigGetParticipant\0"
    "on_addProject_clicked\0on_PBCreate_clicked\0"
    "on_PBDelProject_clicked\0on_updTable_clicked\0"
    "on_tableWidgetPtoject_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_addPeople_clicked\0"
    "on_confirmDel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiAcceuil[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       3,    0,   84,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,
       8,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void uiAcceuil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiAcceuil *_t = static_cast<uiAcceuil *>(_o);
        switch (_id) {
        case 0: _t->notifiactionNewProject((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sigLoadTable(); break;
        case 2: _t->sigAddPro((*reinterpret_cast< CProjet(*)>(_a[1]))); break;
        case 3: _t->sigDelPro((*reinterpret_cast< CProjet(*)>(_a[1]))); break;
        case 4: _t->sigSelectCurrentPro((*reinterpret_cast< CProjet(*)>(_a[1]))); break;
        case 5: _t->sigGetParticipant(); break;
        case 6: _t->on_addProject_clicked(); break;
        case 7: _t->on_PBCreate_clicked(); break;
        case 8: _t->on_PBDelProject_clicked(); break;
        case 9: _t->on_updTable_clicked(); break;
        case 10: _t->on_tableWidgetPtoject_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->on_addPeople_clicked(); break;
        case 12: _t->on_confirmDel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (uiAcceuil::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiAcceuil::notifiactionNewProject)) {
                *result = 0;
            }
        }
        {
            typedef void (uiAcceuil::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiAcceuil::sigLoadTable)) {
                *result = 1;
            }
        }
        {
            typedef void (uiAcceuil::*_t)(CProjet );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiAcceuil::sigAddPro)) {
                *result = 2;
            }
        }
        {
            typedef void (uiAcceuil::*_t)(CProjet );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiAcceuil::sigDelPro)) {
                *result = 3;
            }
        }
        {
            typedef void (uiAcceuil::*_t)(CProjet );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiAcceuil::sigSelectCurrentPro)) {
                *result = 4;
            }
        }
        {
            typedef void (uiAcceuil::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiAcceuil::sigGetParticipant)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject uiAcceuil::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_uiAcceuil.data,
      qt_meta_data_uiAcceuil,  qt_static_metacall, 0, 0}
};


const QMetaObject *uiAcceuil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiAcceuil::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiAcceuil.stringdata))
        return static_cast<void*>(const_cast< uiAcceuil*>(this));
    return QWidget::qt_metacast(_clname);
}

int uiAcceuil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void uiAcceuil::notifiactionNewProject(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void uiAcceuil::sigLoadTable()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void uiAcceuil::sigAddPro(CProjet _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void uiAcceuil::sigDelPro(CProjet _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void uiAcceuil::sigSelectCurrentPro(CProjet _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void uiAcceuil::sigGetParticipant()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
