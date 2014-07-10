/****************************************************************************
** Meta object code from reading C++ file 'addpeopledialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juntos/addpeopledialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addpeopledialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addPeopleDialog_t {
    QByteArrayData data[6];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addPeopleDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addPeopleDialog_t qt_meta_stringdata_addPeopleDialog = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 19),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 19),
QT_MOC_LITERAL(4, 57, 14),
QT_MOC_LITERAL(5, 72, 15)
    },
    "addPeopleDialog\0sigAddUserToProject\0"
    "\0sigDelUserToProject\0on_add_clicked\0"
    "on_dell_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addPeopleDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x08 /* Private */,
       5,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addPeopleDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addPeopleDialog *_t = static_cast<addPeopleDialog *>(_o);
        switch (_id) {
        case 0: _t->sigAddUserToProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigDelUserToProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_add_clicked(); break;
        case 3: _t->on_dell_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (addPeopleDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addPeopleDialog::sigAddUserToProject)) {
                *result = 0;
            }
        }
        {
            typedef void (addPeopleDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addPeopleDialog::sigDelUserToProject)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject addPeopleDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addPeopleDialog.data,
      qt_meta_data_addPeopleDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *addPeopleDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addPeopleDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addPeopleDialog.stringdata))
        return static_cast<void*>(const_cast< addPeopleDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int addPeopleDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void addPeopleDialog::sigAddUserToProject(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void addPeopleDialog::sigDelUserToProject(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
