/****************************************************************************
** Meta object code from reading C++ file 'uitask.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juntos/uitask.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uitask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiTask_t {
    QByteArrayData data[17];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uiTask_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uiTask_t qt_meta_stringdata_uiTask = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 15),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 6),
QT_MOC_LITERAL(4, 31, 8),
QT_MOC_LITERAL(5, 40, 8),
QT_MOC_LITERAL(6, 49, 18),
QT_MOC_LITERAL(7, 68, 18),
QT_MOC_LITERAL(8, 87, 36),
QT_MOC_LITERAL(9, 124, 17),
QT_MOC_LITERAL(10, 142, 4),
QT_MOC_LITERAL(11, 147, 23),
QT_MOC_LITERAL(12, 171, 4),
QT_MOC_LITERAL(13, 176, 20),
QT_MOC_LITERAL(14, 197, 21),
QT_MOC_LITERAL(15, 219, 20),
QT_MOC_LITERAL(16, 240, 21)
    },
    "uiTask\0delSelectedTask\0\0idTask\0add_task\0"
    "upd_task\0on_DelTask_clicked\0"
    "on_addTask_clicked\0"
    "on_tableWidgetTask_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_lineEdit_textChanged\0"
    "arg1\0on_mesTaches_clicked\0"
    "on_autreTache_clicked\0on_nonAssign_clicked\0"
    "on_confirmDel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiTask[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    2,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    1,   80,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    0,   88,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void uiTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiTask *_t = static_cast<uiTask *>(_o);
        switch (_id) {
        case 0: _t->delSelectedTask((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->add_task(); break;
        case 2: _t->upd_task((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_DelTask_clicked(); break;
        case 4: _t->on_addTask_clicked(); break;
        case 5: _t->on_tableWidgetTask_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_mesTaches_clicked(); break;
        case 8: _t->on_autreTache_clicked(); break;
        case 9: _t->on_nonAssign_clicked(); break;
        case 10: _t->on_confirmDel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (uiTask::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiTask::delSelectedTask)) {
                *result = 0;
            }
        }
        {
            typedef void (uiTask::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiTask::add_task)) {
                *result = 1;
            }
        }
        {
            typedef void (uiTask::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiTask::upd_task)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject uiTask::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_uiTask.data,
      qt_meta_data_uiTask,  qt_static_metacall, 0, 0}
};


const QMetaObject *uiTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiTask::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiTask.stringdata))
        return static_cast<void*>(const_cast< uiTask*>(this));
    return QWidget::qt_metacast(_clname);
}

int uiTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void uiTask::delSelectedTask(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void uiTask::add_task()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void uiTask::upd_task(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
