/****************************************************************************
** Meta object code from reading C++ file 'file.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TcpClient/file.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSFileENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFileENDCLASS = QtMocHelpers::stringData(
    "File",
    "showFolder",
    "",
    "nameList",
    "on_AddFolder_Button_clicked",
    "onFolderIconClicked",
    "FolderIcon*",
    "icon",
    "onFolderIconChecked",
    "on_Delete_Button_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFileENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[5];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[28];
    char stringdata5[20];
    char stringdata6[12];
    char stringdata7[5];
    char stringdata8[20];
    char stringdata9[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFileENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFileENDCLASS_t qt_meta_stringdata_CLASSFileENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "File"
        QT_MOC_LITERAL(5, 10),  // "showFolder"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 8),  // "nameList"
        QT_MOC_LITERAL(26, 27),  // "on_AddFolder_Button_clicked"
        QT_MOC_LITERAL(54, 19),  // "onFolderIconClicked"
        QT_MOC_LITERAL(74, 11),  // "FolderIcon*"
        QT_MOC_LITERAL(86, 4),  // "icon"
        QT_MOC_LITERAL(91, 19),  // "onFolderIconChecked"
        QT_MOC_LITERAL(111, 24)   // "on_Delete_Button_clicked"
    },
    "File",
    "showFolder",
    "",
    "nameList",
    "on_AddFolder_Button_clicked",
    "onFolderIconClicked",
    "FolderIcon*",
    "icon",
    "onFolderIconChecked",
    "on_Delete_Button_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFileENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x08,    1 /* Private */,
       4,    0,   47,    2, 0x08,    3 /* Private */,
       5,    1,   48,    2, 0x08,    4 /* Private */,
       8,    0,   51,    2, 0x08,    6 /* Private */,
       9,    0,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject File::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFileENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFileENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFileENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<File, std::true_type>,
        // method 'showFolder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'on_AddFolder_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFolderIconClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<FolderIcon *, std::false_type>,
        // method 'onFolderIconChecked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Delete_Button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void File::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<File *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showFolder((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 1: _t->on_AddFolder_Button_clicked(); break;
        case 2: _t->onFolderIconClicked((*reinterpret_cast< std::add_pointer_t<FolderIcon*>>(_a[1]))); break;
        case 3: _t->onFolderIconChecked(); break;
        case 4: _t->on_Delete_Button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *File::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *File::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFileENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int File::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
