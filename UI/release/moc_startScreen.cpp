/****************************************************************************
** Meta object code from reading C++ file 'startScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../startScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_startScreen_t {
    QByteArrayData data[12];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_startScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_startScreen_t qt_meta_stringdata_startScreen = {
    {
QT_MOC_LITERAL(0, 0, 11), // "startScreen"
QT_MOC_LITERAL(1, 12, 14), // "button1Clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "checked"
QT_MOC_LITERAL(4, 36, 14), // "button2Clicked"
QT_MOC_LITERAL(5, 51, 12), // "fileOpened3D"
QT_MOC_LITERAL(6, 64, 12), // "fileOpened2D"
QT_MOC_LITERAL(7, 77, 14), // "rotateXClicked"
QT_MOC_LITERAL(8, 92, 14), // "rotateYClicked"
QT_MOC_LITERAL(9, 107, 14), // "rotateZClicked"
QT_MOC_LITERAL(10, 122, 16), // "setRotationAngle"
QT_MOC_LITERAL(11, 139, 5) // "angle"

    },
    "startScreen\0button1Clicked\0\0checked\0"
    "button2Clicked\0fileOpened3D\0fileOpened2D\0"
    "rotateXClicked\0rotateYClicked\0"
    "rotateZClicked\0setRotationAngle\0angle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_startScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void startScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        startScreen *_t = static_cast<startScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->button1Clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->button2Clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->fileOpened3D(); break;
        case 3: _t->fileOpened2D(); break;
        case 4: _t->rotateXClicked(); break;
        case 5: _t->rotateYClicked(); break;
        case 6: _t->rotateZClicked(); break;
        case 7: _t->setRotationAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject startScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_startScreen.data,
      qt_meta_data_startScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *startScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *startScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_startScreen.stringdata0))
        return static_cast<void*>(const_cast< startScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int startScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
