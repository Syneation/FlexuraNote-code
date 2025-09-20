/****************************************************************************
** Meta object code from reading C++ file 'replacewindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../replacewindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replacewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
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
struct qt_meta_tag_ZN13ReplaceWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto ReplaceWindow::qt_create_metaobjectdata<qt_meta_tag_ZN13ReplaceWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ReplaceWindow",
        "findRequested_replace",
        "",
        "find_replace_work",
        "work",
        "matchesFound_replace",
        "count",
        "replace_text",
        "new_text",
        "replace_all_text",
        "on_textEdit_textChanged",
        "on_pushButton_2_clicked",
        "on_find_next_btn_clicked",
        "on_checkBox_stateChanged",
        "arg1",
        "on_checkBox_2_stateChanged",
        "on_checkBox_3_stateChanged",
        "on_replace_btn_clicked",
        "on_textEdit_2_textChanged",
        "on_replace_all_btn_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'findRequested_replace'
        QtMocHelpers::SignalData<void(const find_replace_work &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'matchesFound_replace'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'replace_text'
        QtMocHelpers::SignalData<void(const find_replace_work &, const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 8 },
        }}),
        // Signal 'replace_all_text'
        QtMocHelpers::SignalData<void(const find_replace_work &, const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::QString, 8 },
        }}),
        // Slot 'on_textEdit_textChanged'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButton_2_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_find_next_btn_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_checkBox_stateChanged'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'on_checkBox_2_stateChanged'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'on_checkBox_3_stateChanged'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'on_replace_btn_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_textEdit_2_textChanged'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_replace_all_btn_clicked'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ReplaceWindow, qt_meta_tag_ZN13ReplaceWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ReplaceWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ReplaceWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ReplaceWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ReplaceWindowE_t>.metaTypes,
    nullptr
} };

void ReplaceWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ReplaceWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->findRequested_replace((*reinterpret_cast< std::add_pointer_t<find_replace_work>>(_a[1]))); break;
        case 1: _t->matchesFound_replace((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->replace_text((*reinterpret_cast< std::add_pointer_t<find_replace_work>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->replace_all_text((*reinterpret_cast< std::add_pointer_t<find_replace_work>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->on_textEdit_textChanged(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_find_next_btn_clicked(); break;
        case 7: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_checkBox_2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_checkBox_3_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_replace_btn_clicked(); break;
        case 11: _t->on_textEdit_2_textChanged(); break;
        case 12: _t->on_replace_all_btn_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ReplaceWindow::*)(const find_replace_work & )>(_a, &ReplaceWindow::findRequested_replace, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ReplaceWindow::*)(int )>(_a, &ReplaceWindow::matchesFound_replace, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ReplaceWindow::*)(const find_replace_work & , const QString & )>(_a, &ReplaceWindow::replace_text, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ReplaceWindow::*)(const find_replace_work & , const QString & )>(_a, &ReplaceWindow::replace_all_text, 3))
            return;
    }
}

const QMetaObject *ReplaceWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReplaceWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ReplaceWindowE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ReplaceWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ReplaceWindow::findRequested_replace(const find_replace_work & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void ReplaceWindow::matchesFound_replace(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void ReplaceWindow::replace_text(const find_replace_work & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void ReplaceWindow::replace_all_text(const find_replace_work & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
