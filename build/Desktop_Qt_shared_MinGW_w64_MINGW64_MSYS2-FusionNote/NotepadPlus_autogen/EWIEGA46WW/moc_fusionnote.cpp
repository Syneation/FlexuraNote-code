/****************************************************************************
** Meta object code from reading C++ file 'fusionnote.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../fusionnote.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fusionnote.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11NotepadPlusE_t {};
} // unnamed namespace

template <> constexpr inline auto NotepadPlus::qt_create_metaobjectdata<qt_meta_tag_ZN11NotepadPlusE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NotepadPlus",
        "handleFindRequest",
        "",
        "FindWindow::find_work",
        "work",
        "handleFindRequest_replace",
        "ReplaceWindow::find_replace_work",
        "handleReplace_text",
        "new_text",
        "handlerRepalce_all_text",
        "onInfoWindowClosed",
        "onFindWindowClosed",
        "onReplaceWindowClosed",
        "on_NotepadPlus_customContextMenuRequested",
        "pos",
        "autoSave",
        "on_actionOpen_triggered",
        "on_actionnewFileIcon_triggered",
        "on_actionNew_File_triggered",
        "on_actionopenFileIcon_triggered",
        "on_actionsaveIcon_triggered",
        "on_actionSave_triggered",
        "updateCursorStatus",
        "on_actionboldIcon_triggered",
        "on_actionSave_As_triggered",
        "on_actionSaveAsIcon_triggered",
        "on_actionPrint_triggered",
        "on_actionprintIcon_triggered",
        "on_actionExit_triggered",
        "on_actionCancel_triggered",
        "on_actionbackIcon_triggered",
        "on_actionCut_triggered",
        "on_actioncutIcon_triggered",
        "on_actiontextByWidthIcon_triggered",
        "on_actionCopy_triggered",
        "on_actioncopy_triggered",
        "on_actionPaste_triggered",
        "on_actionpasteIcon_triggered",
        "on_actionSelect_All_triggered",
        "on_actionDelete_All_triggered",
        "on_actionCopyright_triggered",
        "on_actionTrademark_triggered",
        "on_actionTrademark_2_triggered",
        "on_actionAutosave_triggered",
        "on_actionDateTime_triggered",
        "on_actionforwardIcon_triggered",
        "on_actionLine_Break_triggered",
        "on_actionitalicsIcon_triggered",
        "on_actionunderlineIcon_triggered",
        "on_actioncrossouttextIcon_triggered",
        "on_actionleftTextIcon_triggered",
        "on_actioncenterTextIcon_triggered",
        "on_actionrightTextIcon_triggered",
        "on_actionfontFamilyIcon_triggered",
        "on_actionfillTheTextBgIcon_triggered",
        "on_actioncolorTextIcon_triggered",
        "on_actionincreaseIcon_triggered",
        "on_actionreduceIcon_triggered",
        "on_actionReset_Text_Settings_triggered",
        "on_actionWhite_triggered",
        "on_actionDark_triggered",
        "on_actionZoom_Reset_triggered",
        "on_actioninfoIcon_triggered",
        "on_actionAbout_Program_triggered",
        "on_actionGit_Hub_triggered",
        "on_actionfindIcon_triggered",
        "on_actionFind_triggered",
        "on_actionReplace_triggered",
        "on_actionreplaceIcon_triggered",
        "on_actionAddImage_triggered",
        "on_actionStatus_Bar_triggered",
        "checked",
        "on_actionShow_Html_Code_triggered"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'handleFindRequest'
        QtMocHelpers::SlotData<void(const FindWindow::find_work &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'handleFindRequest_replace'
        QtMocHelpers::SlotData<void(const ReplaceWindow::find_replace_work &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 4 },
        }}),
        // Slot 'handleReplace_text'
        QtMocHelpers::SlotData<void(const ReplaceWindow::find_replace_work &, const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 4 }, { QMetaType::QString, 8 },
        }}),
        // Slot 'handlerRepalce_all_text'
        QtMocHelpers::SlotData<void(const ReplaceWindow::find_replace_work &, const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 4 }, { QMetaType::QString, 8 },
        }}),
        // Slot 'onInfoWindowClosed'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onFindWindowClosed'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onReplaceWindowClosed'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_NotepadPlus_customContextMenuRequested'
        QtMocHelpers::SlotData<void(const QPoint &)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QPoint, 14 },
        }}),
        // Slot 'autoSave'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionOpen_triggered'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionnewFileIcon_triggered'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionNew_File_triggered'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionopenFileIcon_triggered'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionsaveIcon_triggered'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSave_triggered'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateCursorStatus'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionboldIcon_triggered'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSave_As_triggered'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSaveAsIcon_triggered'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPrint_triggered'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionprintIcon_triggered'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionExit_triggered'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCancel_triggered'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionbackIcon_triggered'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCut_triggered'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actioncutIcon_triggered'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actiontextByWidthIcon_triggered'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCopy_triggered'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actioncopy_triggered'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionPaste_triggered'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionpasteIcon_triggered'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionSelect_All_triggered'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionDelete_All_triggered'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionCopyright_triggered'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTrademark_triggered'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionTrademark_2_triggered'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAutosave_triggered'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionDateTime_triggered'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionforwardIcon_triggered'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionLine_Break_triggered'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionitalicsIcon_triggered'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionunderlineIcon_triggered'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actioncrossouttextIcon_triggered'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionleftTextIcon_triggered'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actioncenterTextIcon_triggered'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionrightTextIcon_triggered'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionfontFamilyIcon_triggered'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionfillTheTextBgIcon_triggered'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actioncolorTextIcon_triggered'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionincreaseIcon_triggered'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionreduceIcon_triggered'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionReset_Text_Settings_triggered'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionWhite_triggered'
        QtMocHelpers::SlotData<void()>(59, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionDark_triggered'
        QtMocHelpers::SlotData<void()>(60, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionZoom_Reset_triggered'
        QtMocHelpers::SlotData<void()>(61, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actioninfoIcon_triggered'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAbout_Program_triggered'
        QtMocHelpers::SlotData<void()>(63, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionGit_Hub_triggered'
        QtMocHelpers::SlotData<void()>(64, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionfindIcon_triggered'
        QtMocHelpers::SlotData<void()>(65, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionFind_triggered'
        QtMocHelpers::SlotData<void()>(66, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionReplace_triggered'
        QtMocHelpers::SlotData<void()>(67, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionreplaceIcon_triggered'
        QtMocHelpers::SlotData<void()>(68, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionAddImage_triggered'
        QtMocHelpers::SlotData<void()>(69, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_actionStatus_Bar_triggered'
        QtMocHelpers::SlotData<void(bool)>(70, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 71 },
        }}),
        // Slot 'on_actionShow_Html_Code_triggered'
        QtMocHelpers::SlotData<void(bool)>(72, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 71 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NotepadPlus, qt_meta_tag_ZN11NotepadPlusE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NotepadPlus::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11NotepadPlusE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11NotepadPlusE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11NotepadPlusE_t>.metaTypes,
    nullptr
} };

void NotepadPlus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NotepadPlus *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->handleFindRequest((*reinterpret_cast< std::add_pointer_t<FindWindow::find_work>>(_a[1]))); break;
        case 1: _t->handleFindRequest_replace((*reinterpret_cast< std::add_pointer_t<ReplaceWindow::find_replace_work>>(_a[1]))); break;
        case 2: _t->handleReplace_text((*reinterpret_cast< std::add_pointer_t<ReplaceWindow::find_replace_work>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->handlerRepalce_all_text((*reinterpret_cast< std::add_pointer_t<ReplaceWindow::find_replace_work>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->onInfoWindowClosed(); break;
        case 5: _t->onFindWindowClosed(); break;
        case 6: _t->onReplaceWindowClosed(); break;
        case 7: _t->on_NotepadPlus_customContextMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 8: _t->autoSave(); break;
        case 9: _t->on_actionOpen_triggered(); break;
        case 10: _t->on_actionnewFileIcon_triggered(); break;
        case 11: _t->on_actionNew_File_triggered(); break;
        case 12: _t->on_actionopenFileIcon_triggered(); break;
        case 13: _t->on_actionsaveIcon_triggered(); break;
        case 14: _t->on_actionSave_triggered(); break;
        case 15: _t->updateCursorStatus(); break;
        case 16: _t->on_actionboldIcon_triggered(); break;
        case 17: _t->on_actionSave_As_triggered(); break;
        case 18: _t->on_actionSaveAsIcon_triggered(); break;
        case 19: _t->on_actionPrint_triggered(); break;
        case 20: _t->on_actionprintIcon_triggered(); break;
        case 21: _t->on_actionExit_triggered(); break;
        case 22: _t->on_actionCancel_triggered(); break;
        case 23: _t->on_actionbackIcon_triggered(); break;
        case 24: _t->on_actionCut_triggered(); break;
        case 25: _t->on_actioncutIcon_triggered(); break;
        case 26: _t->on_actiontextByWidthIcon_triggered(); break;
        case 27: _t->on_actionCopy_triggered(); break;
        case 28: _t->on_actioncopy_triggered(); break;
        case 29: _t->on_actionPaste_triggered(); break;
        case 30: _t->on_actionpasteIcon_triggered(); break;
        case 31: _t->on_actionSelect_All_triggered(); break;
        case 32: _t->on_actionDelete_All_triggered(); break;
        case 33: _t->on_actionCopyright_triggered(); break;
        case 34: _t->on_actionTrademark_triggered(); break;
        case 35: _t->on_actionTrademark_2_triggered(); break;
        case 36: _t->on_actionAutosave_triggered(); break;
        case 37: _t->on_actionDateTime_triggered(); break;
        case 38: _t->on_actionforwardIcon_triggered(); break;
        case 39: _t->on_actionLine_Break_triggered(); break;
        case 40: _t->on_actionitalicsIcon_triggered(); break;
        case 41: _t->on_actionunderlineIcon_triggered(); break;
        case 42: _t->on_actioncrossouttextIcon_triggered(); break;
        case 43: _t->on_actionleftTextIcon_triggered(); break;
        case 44: _t->on_actioncenterTextIcon_triggered(); break;
        case 45: _t->on_actionrightTextIcon_triggered(); break;
        case 46: _t->on_actionfontFamilyIcon_triggered(); break;
        case 47: _t->on_actionfillTheTextBgIcon_triggered(); break;
        case 48: _t->on_actioncolorTextIcon_triggered(); break;
        case 49: _t->on_actionincreaseIcon_triggered(); break;
        case 50: _t->on_actionreduceIcon_triggered(); break;
        case 51: _t->on_actionReset_Text_Settings_triggered(); break;
        case 52: _t->on_actionWhite_triggered(); break;
        case 53: _t->on_actionDark_triggered(); break;
        case 54: _t->on_actionZoom_Reset_triggered(); break;
        case 55: _t->on_actioninfoIcon_triggered(); break;
        case 56: _t->on_actionAbout_Program_triggered(); break;
        case 57: _t->on_actionGit_Hub_triggered(); break;
        case 58: _t->on_actionfindIcon_triggered(); break;
        case 59: _t->on_actionFind_triggered(); break;
        case 60: _t->on_actionReplace_triggered(); break;
        case 61: _t->on_actionreplaceIcon_triggered(); break;
        case 62: _t->on_actionAddImage_triggered(); break;
        case 63: _t->on_actionStatus_Bar_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 64: _t->on_actionShow_Html_Code_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *NotepadPlus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotepadPlus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11NotepadPlusE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int NotepadPlus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 65;
    }
    return _id;
}
QT_WARNING_POP
