/****************************************************************************
** Meta object code from reading C++ file 'uifile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Juntos/uifile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uifile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiFile_t {
    QByteArrayData data[11];
    char stringdata[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_uiFile_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_uiFile_t qt_meta_stringdata_uiFile = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 9),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 11),
QT_MOC_LITERAL(4, 30, 23),
QT_MOC_LITERAL(5, 54, 23),
QT_MOC_LITERAL(6, 78, 25),
QT_MOC_LITERAL(7, 104, 31),
QT_MOC_LITERAL(8, 136, 17),
QT_MOC_LITERAL(9, 154, 4),
QT_MOC_LITERAL(10, 159, 40)
    },
    "uiFile\0add_share\0\0std::string\0"
    "on_BrowseButton_clicked\0on_uploadButton_clicked\0"
    "on_DownloadButton_clicked\0"
    "on_tableWidgetShare_itemClicked\0"
    "QTableWidgetItem*\0item\0"
    "on_tableWidgetShare_itemSelectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiFile[] = {

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
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   49,    2, 0x08 /* Private */,
       5,    0,   50,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    1,   52,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void uiFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiFile *_t = static_cast<uiFile *>(_o);
        switch (_id) {
        case 0: _t->add_share((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->on_BrowseButton_clicked(); break;
        case 2: _t->on_uploadButton_clicked(); break;
        case 3: _t->on_DownloadButton_clicked(); break;
        case 4: _t->on_tableWidgetShare_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_tableWidgetShare_itemSelectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (uiFile::*_t)(std::string , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiFile::add_share)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject uiFile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_uiFile.data,
      qt_meta_data_uiFile,  qt_static_metacall, 0, 0}
};


const QMetaObject *uiFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiFile.stringdata))
        return static_cast<void*>(const_cast< uiFile*>(this));
    return QDialog::qt_metacast(_clname);
}

int uiFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void uiFile::add_share(std::string _t1, QByteArray _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
