/****************************************************************************
** Meta object code from reading C++ file 'Controlwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Chess/Controlwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controlwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ControlWidget_t {
    QByteArrayData data[11];
    char stringdata[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlWidget_t qt_meta_stringdata_ControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ControlWidget"
QT_MOC_LITERAL(1, 14, 20), // "on_peace_btn_pressed"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_peace_btn_released"
QT_MOC_LITERAL(4, 58, 24), // "on_surrender_btn_pressed"
QT_MOC_LITERAL(5, 83, 25), // "on_surrender_btn_released"
QT_MOC_LITERAL(6, 109, 19), // "on_undo_btn_pressed"
QT_MOC_LITERAL(7, 129, 20), // "on_undo_btn_released"
QT_MOC_LITERAL(8, 150, 20), // "on_peace_btn_clicked"
QT_MOC_LITERAL(9, 171, 24), // "on_surrender_btn_clicked"
QT_MOC_LITERAL(10, 196, 19) // "on_undo_btn_clicked"

    },
    "ControlWidget\0on_peace_btn_pressed\0\0"
    "on_peace_btn_released\0on_surrender_btn_pressed\0"
    "on_surrender_btn_released\0on_undo_btn_pressed\0"
    "on_undo_btn_released\0on_peace_btn_clicked\0"
    "on_surrender_btn_clicked\0on_undo_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlWidget *_t = static_cast<ControlWidget *>(_o);
        switch (_id) {
        case 0: _t->on_peace_btn_pressed(); break;
        case 1: _t->on_peace_btn_released(); break;
        case 2: _t->on_surrender_btn_pressed(); break;
        case 3: _t->on_surrender_btn_released(); break;
        case 4: _t->on_undo_btn_pressed(); break;
        case 5: _t->on_undo_btn_released(); break;
        case 6: _t->on_peace_btn_clicked(); break;
        case 7: _t->on_surrender_btn_clicked(); break;
        case 8: _t->on_undo_btn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ControlWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlWidget.data,
      qt_meta_data_ControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ControlWidget.stringdata))
        return static_cast<void*>(const_cast< ControlWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
