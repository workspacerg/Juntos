/****************************************************************************
** Meta object code from reading C++ file 'uitestunitaire.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juntos/uitestunitaire.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uitestunitaire.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UiTestUnitaire_t {
    QByteArrayData data[21];
    char stringdata[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiTestUnitaire_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiTestUnitaire_t qt_meta_stringdata_UiTestUnitaire = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 8),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 8),
QT_MOC_LITERAL(4, 34, 6),
QT_MOC_LITERAL(5, 41, 8),
QT_MOC_LITERAL(6, 50, 18),
QT_MOC_LITERAL(7, 69, 18),
QT_MOC_LITERAL(8, 88, 36),
QT_MOC_LITERAL(9, 125, 17),
QT_MOC_LITERAL(10, 143, 4),
QT_MOC_LITERAL(11, 148, 21),
QT_MOC_LITERAL(12, 170, 20),
QT_MOC_LITERAL(13, 191, 24),
QT_MOC_LITERAL(14, 216, 30),
QT_MOC_LITERAL(15, 247, 30),
QT_MOC_LITERAL(16, 278, 13),
QT_MOC_LITERAL(17, 292, 8),
QT_MOC_LITERAL(18, 301, 17),
QT_MOC_LITERAL(19, 319, 23),
QT_MOC_LITERAL(20, 343, 4)
    },
    "UiTestUnitaire\0add_test\0\0del_test\0"
    "idTest\0upd_test\0on_addTest_clicked\0"
    "on_DelTest_clicked\0"
    "on_tableWidgetTest_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_confirmDel_clicked\0"
    "on_save_test_clicked\0on_save_test_upd_clicked\0"
    "on_tableWidgetTest_itemChanged\0"
    "on_tableWidgetTest_itemClicked\0"
    "on_ok_clicked\0updTable\0on_failed_clicked\0"
    "on_lineEdit_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiTestUnitaire[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   89,    2, 0x06 /* Public */,
       3,    1,   98,    2, 0x06 /* Public */,
       5,    5,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  112,    2, 0x08 /* Private */,
       7,    0,  113,    2, 0x08 /* Private */,
       8,    1,  114,    2, 0x08 /* Private */,
      11,    0,  117,    2, 0x08 /* Private */,
      12,    0,  118,    2, 0x08 /* Private */,
      13,    0,  119,    2, 0x08 /* Private */,
      14,    1,  120,    2, 0x08 /* Private */,
      15,    1,  123,    2, 0x08 /* Private */,
      16,    0,  126,    2, 0x08 /* Private */,
      17,    0,  127,    2, 0x08 /* Private */,
      18,    0,  128,    2, 0x08 /* Private */,
      19,    1,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void UiTestUnitaire::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UiTestUnitaire *_t = static_cast<UiTestUnitaire *>(_o);
        switch (_id) {
        case 0: _t->add_test((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->del_test((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->upd_test((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 3: _t->on_addTest_clicked(); break;
        case 4: _t->on_DelTest_clicked(); break;
        case 5: _t->on_tableWidgetTest_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_confirmDel_clicked(); break;
        case 7: _t->on_save_test_clicked(); break;
        case 8: _t->on_save_test_upd_clicked(); break;
        case 9: _t->on_tableWidgetTest_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->on_tableWidgetTest_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->on_ok_clicked(); break;
        case 12: _t->updTable(); break;
        case 13: _t->on_failed_clicked(); break;
        case 14: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UiTestUnitaire::*_t)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiTestUnitaire::add_test)) {
                *result = 0;
            }
        }
        {
            typedef void (UiTestUnitaire::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiTestUnitaire::del_test)) {
                *result = 1;
            }
        }
        {
            typedef void (UiTestUnitaire::*_t)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiTestUnitaire::upd_test)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UiTestUnitaire::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UiTestUnitaire.data,
      qt_meta_data_UiTestUnitaire,  qt_static_metacall, 0, 0}
};


const QMetaObject *UiTestUnitaire::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiTestUnitaire::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UiTestUnitaire.stringdata))
        return static_cast<void*>(const_cast< UiTestUnitaire*>(this));
    return QDialog::qt_metacast(_clname);
}

int UiTestUnitaire::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void UiTestUnitaire::add_test(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UiTestUnitaire::del_test(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UiTestUnitaire::upd_test(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
