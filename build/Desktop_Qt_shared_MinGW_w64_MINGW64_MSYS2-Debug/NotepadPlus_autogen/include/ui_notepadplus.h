/********************************************************************************
** Form generated from reading UI file 'notepadplus.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPADPLUS_H
#define UI_NOTEPADPLUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotepadPlus
{
public:
    QAction *actionOpen;
    QAction *actionNew_File;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionCancel;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete_All;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionSelect_All;
    QAction *actionDateTime;
    QAction *actionCopyright;
    QAction *actionTrademark;
    QAction *actionLine_Break;
    QAction *actionAutosave;
    QAction *actionReset_Text_Settings;
    QAction *actionnewFileIcon;
    QAction *actionopenFileIcon;
    QAction *actionsaveIcon;
    QAction *actionSaveAsIcon;
    QAction *actionprintIcon;
    QAction *actioncopy;
    QAction *actionpasteIcon;
    QAction *actioncutIcon;
    QAction *actionfindIcon;
    QAction *actionreplaceIcon;
    QAction *actionbackIcon;
    QAction *actionboldIcon;
    QAction *actionitalicsIcon;
    QAction *actionunderlineIcon;
    QAction *actioncrossouttextIcon;
    QAction *actionleftTextIcon;
    QAction *actioncenterTextIcon;
    QAction *actionrightTextIcon;
    QAction *actiontextByWidthIcon;
    QAction *actionfillTheTextBgIcon;
    QAction *actioncolorTextIcon;
    QAction *actionincreaseIcon;
    QAction *actionreduceIcon;
    QAction *actioninfoIcon;
    QAction *actionforwardIcon;
    QAction *actionWhite;
    QAction *actionDark;
    QAction *actionExit;
    QAction *actionTrademark_2;
    QAction *actionfontFamilyIcon;
    QAction *actionZoom_Reset;
    QAction *actionAbout_Program;
    QAction *actionGit_Hub;
    QWidget *centralwidget;
    QTextEdit *textEditor;
    QLabel *label_file_path;
    QLabel *label_notifications;
    QLabel *label_len_lines;
    QLabel *label_ln_col_pos;
    QLabel *label_encoding;
    QLabel *label_zoom;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuIcon;
    QMenu *menuSetting;
    QMenu *menuTheme;
    QMenu *menuAbout;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *NotepadPlus)
    {
        if (NotepadPlus->objectName().isEmpty())
            NotepadPlus->setObjectName("NotepadPlus");
        NotepadPlus->resize(962, 512);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/image/main_icon.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        NotepadPlus->setWindowIcon(icon);
        actionOpen = new QAction(NotepadPlus);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionOpen->setIcon(icon1);
        actionNew_File = new QAction(NotepadPlus);
        actionNew_File->setObjectName("actionNew_File");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        actionNew_File->setIcon(icon2);
        actionSave = new QAction(NotepadPlus);
        actionSave->setObjectName("actionSave");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        actionSave->setIcon(icon3);
        actionSave_As = new QAction(NotepadPlus);
        actionSave_As->setObjectName("actionSave_As");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSaveAs));
        actionSave_As->setIcon(icon4);
        actionPrint = new QAction(NotepadPlus);
        actionPrint->setObjectName("actionPrint");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPrint));
        actionPrint->setIcon(icon5);
        actionCancel = new QAction(NotepadPlus);
        actionCancel->setObjectName("actionCancel");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rec/image/back.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionCancel->setIcon(icon6);
        actionCut = new QAction(NotepadPlus);
        actionCut->setObjectName("actionCut");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        actionCut->setIcon(icon7);
        actionCopy = new QAction(NotepadPlus);
        actionCopy->setObjectName("actionCopy");
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        actionCopy->setIcon(icon8);
        actionPaste = new QAction(NotepadPlus);
        actionPaste->setObjectName("actionPaste");
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::EditPaste));
        actionPaste->setIcon(icon9);
        actionDelete_All = new QAction(NotepadPlus);
        actionDelete_All->setObjectName("actionDelete_All");
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        actionDelete_All->setIcon(icon10);
        actionFind = new QAction(NotepadPlus);
        actionFind->setObjectName("actionFind");
        QIcon icon11(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        actionFind->setIcon(icon11);
        actionReplace = new QAction(NotepadPlus);
        actionReplace->setObjectName("actionReplace");
        actionSelect_All = new QAction(NotepadPlus);
        actionSelect_All->setObjectName("actionSelect_All");
        QIcon icon12(QIcon::fromTheme(QIcon::ThemeIcon::EditSelectAll));
        actionSelect_All->setIcon(icon12);
        actionDateTime = new QAction(NotepadPlus);
        actionDateTime->setObjectName("actionDateTime");
        actionCopyright = new QAction(NotepadPlus);
        actionCopyright->setObjectName("actionCopyright");
        actionTrademark = new QAction(NotepadPlus);
        actionTrademark->setObjectName("actionTrademark");
        actionLine_Break = new QAction(NotepadPlus);
        actionLine_Break->setObjectName("actionLine_Break");
        actionLine_Break->setCheckable(true);
        actionAutosave = new QAction(NotepadPlus);
        actionAutosave->setObjectName("actionAutosave");
        actionAutosave->setCheckable(true);
        actionReset_Text_Settings = new QAction(NotepadPlus);
        actionReset_Text_Settings->setObjectName("actionReset_Text_Settings");
        actionnewFileIcon = new QAction(NotepadPlus);
        actionnewFileIcon->setObjectName("actionnewFileIcon");
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/rec/image/newFile.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionnewFileIcon->setIcon(icon13);
        actionnewFileIcon->setMenuRole(QAction::NoRole);
        actionopenFileIcon = new QAction(NotepadPlus);
        actionopenFileIcon->setObjectName("actionopenFileIcon");
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/rec/image/openFile.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionopenFileIcon->setIcon(icon14);
        actionopenFileIcon->setMenuRole(QAction::NoRole);
        actionsaveIcon = new QAction(NotepadPlus);
        actionsaveIcon->setObjectName("actionsaveIcon");
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/rec/image/saveFile.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionsaveIcon->setIcon(icon15);
        actionsaveIcon->setMenuRole(QAction::NoRole);
        actionSaveAsIcon = new QAction(NotepadPlus);
        actionSaveAsIcon->setObjectName("actionSaveAsIcon");
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/rec/image/saveAs.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveAsIcon->setIcon(icon16);
        actionSaveAsIcon->setMenuRole(QAction::NoRole);
        actionprintIcon = new QAction(NotepadPlus);
        actionprintIcon->setObjectName("actionprintIcon");
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/rec/image/print.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionprintIcon->setIcon(icon17);
        actionprintIcon->setMenuRole(QAction::NoRole);
        actioncopy = new QAction(NotepadPlus);
        actioncopy->setObjectName("actioncopy");
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/rec/image/copy.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioncopy->setIcon(icon18);
        actioncopy->setMenuRole(QAction::NoRole);
        actionpasteIcon = new QAction(NotepadPlus);
        actionpasteIcon->setObjectName("actionpasteIcon");
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/rec/image/paste.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionpasteIcon->setIcon(icon19);
        actionpasteIcon->setMenuRole(QAction::NoRole);
        actioncutIcon = new QAction(NotepadPlus);
        actioncutIcon->setObjectName("actioncutIcon");
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/rec/image/cut.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioncutIcon->setIcon(icon20);
        actioncutIcon->setMenuRole(QAction::NoRole);
        actionfindIcon = new QAction(NotepadPlus);
        actionfindIcon->setObjectName("actionfindIcon");
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/rec/image/loup.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionfindIcon->setIcon(icon21);
        actionfindIcon->setMenuRole(QAction::NoRole);
        actionreplaceIcon = new QAction(NotepadPlus);
        actionreplaceIcon->setObjectName("actionreplaceIcon");
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/rec/image/replace.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionreplaceIcon->setIcon(icon22);
        actionreplaceIcon->setMenuRole(QAction::NoRole);
        actionbackIcon = new QAction(NotepadPlus);
        actionbackIcon->setObjectName("actionbackIcon");
        actionbackIcon->setIcon(icon6);
        actionbackIcon->setMenuRole(QAction::NoRole);
        actionboldIcon = new QAction(NotepadPlus);
        actionboldIcon->setObjectName("actionboldIcon");
        actionboldIcon->setCheckable(true);
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/rec/image/logo_B.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionboldIcon->setIcon(icon23);
        actionboldIcon->setMenuRole(QAction::NoRole);
        actionitalicsIcon = new QAction(NotepadPlus);
        actionitalicsIcon->setObjectName("actionitalicsIcon");
        actionitalicsIcon->setCheckable(true);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/rec/image/cursive.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionitalicsIcon->setIcon(icon24);
        actionitalicsIcon->setMenuRole(QAction::NoRole);
        actionunderlineIcon = new QAction(NotepadPlus);
        actionunderlineIcon->setObjectName("actionunderlineIcon");
        actionunderlineIcon->setCheckable(true);
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/rec/image/logo_Und.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionunderlineIcon->setIcon(icon25);
        actionunderlineIcon->setMenuRole(QAction::NoRole);
        actioncrossouttextIcon = new QAction(NotepadPlus);
        actioncrossouttextIcon->setObjectName("actioncrossouttextIcon");
        actioncrossouttextIcon->setCheckable(true);
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/rec/image/through.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioncrossouttextIcon->setIcon(icon26);
        actioncrossouttextIcon->setMenuRole(QAction::NoRole);
        actionleftTextIcon = new QAction(NotepadPlus);
        actionleftTextIcon->setObjectName("actionleftTextIcon");
        actionleftTextIcon->setCheckable(false);
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/rec/image/left.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionleftTextIcon->setIcon(icon27);
        actionleftTextIcon->setMenuRole(QAction::NoRole);
        actioncenterTextIcon = new QAction(NotepadPlus);
        actioncenterTextIcon->setObjectName("actioncenterTextIcon");
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/rec/image/center.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioncenterTextIcon->setIcon(icon28);
        actioncenterTextIcon->setMenuRole(QAction::NoRole);
        actionrightTextIcon = new QAction(NotepadPlus);
        actionrightTextIcon->setObjectName("actionrightTextIcon");
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/rec/image/right.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionrightTextIcon->setIcon(icon29);
        actionrightTextIcon->setMenuRole(QAction::NoRole);
        actiontextByWidthIcon = new QAction(NotepadPlus);
        actiontextByWidthIcon->setObjectName("actiontextByWidthIcon");
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/rec/image/by_width.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actiontextByWidthIcon->setIcon(icon30);
        actiontextByWidthIcon->setMenuRole(QAction::NoRole);
        actionfillTheTextBgIcon = new QAction(NotepadPlus);
        actionfillTheTextBgIcon->setObjectName("actionfillTheTextBgIcon");
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/rec/image/text_fill_color.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionfillTheTextBgIcon->setIcon(icon31);
        actionfillTheTextBgIcon->setMenuRole(QAction::NoRole);
        actioncolorTextIcon = new QAction(NotepadPlus);
        actioncolorTextIcon->setObjectName("actioncolorTextIcon");
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/rec/image/color.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioncolorTextIcon->setIcon(icon32);
        actioncolorTextIcon->setMenuRole(QAction::NoRole);
        actionincreaseIcon = new QAction(NotepadPlus);
        actionincreaseIcon->setObjectName("actionincreaseIcon");
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/rec/image/plus.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionincreaseIcon->setIcon(icon33);
        actionincreaseIcon->setMenuRole(QAction::NoRole);
        actionreduceIcon = new QAction(NotepadPlus);
        actionreduceIcon->setObjectName("actionreduceIcon");
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/rec/image/minus.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionreduceIcon->setIcon(icon34);
        actionreduceIcon->setMenuRole(QAction::NoRole);
        actioninfoIcon = new QAction(NotepadPlus);
        actioninfoIcon->setObjectName("actioninfoIcon");
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/rec/image/logo_info.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioninfoIcon->setIcon(icon35);
        actioninfoIcon->setMenuRole(QAction::NoRole);
        actionforwardIcon = new QAction(NotepadPlus);
        actionforwardIcon->setObjectName("actionforwardIcon");
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/rec/image/replay.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionforwardIcon->setIcon(icon36);
        actionforwardIcon->setMenuRole(QAction::NoRole);
        actionWhite = new QAction(NotepadPlus);
        actionWhite->setObjectName("actionWhite");
        actionDark = new QAction(NotepadPlus);
        actionDark->setObjectName("actionDark");
        actionExit = new QAction(NotepadPlus);
        actionExit->setObjectName("actionExit");
        QIcon icon37(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionExit->setIcon(icon37);
        actionTrademark_2 = new QAction(NotepadPlus);
        actionTrademark_2->setObjectName("actionTrademark_2");
        actionfontFamilyIcon = new QAction(NotepadPlus);
        actionfontFamilyIcon->setObjectName("actionfontFamilyIcon");
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/rec/image/font_size.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionfontFamilyIcon->setIcon(icon38);
        actionfontFamilyIcon->setMenuRole(QAction::NoRole);
        actionZoom_Reset = new QAction(NotepadPlus);
        actionZoom_Reset->setObjectName("actionZoom_Reset");
        actionAbout_Program = new QAction(NotepadPlus);
        actionAbout_Program->setObjectName("actionAbout_Program");
        actionGit_Hub = new QAction(NotepadPlus);
        actionGit_Hub->setObjectName("actionGit_Hub");
        centralwidget = new QWidget(NotepadPlus);
        centralwidget->setObjectName("centralwidget");
        textEditor = new QTextEdit(centralwidget);
        textEditor->setObjectName("textEditor");
        textEditor->setGeometry(QRect(0, 0, 951, 411));
        textEditor->setMinimumSize(QSize(811, 0));
        QFont font;
        font.setPointSize(20);
        textEditor->setFont(font);
        textEditor->setLayoutDirection(Qt::LeftToRight);
        textEditor->setAutoFillBackground(true);
        label_file_path = new QLabel(centralwidget);
        label_file_path->setObjectName("label_file_path");
        label_file_path->setGeometry(QRect(10, 420, 161, 16));
        label_notifications = new QLabel(centralwidget);
        label_notifications->setObjectName("label_notifications");
        label_notifications->setGeometry(QRect(180, 420, 261, 16));
        label_len_lines = new QLabel(centralwidget);
        label_len_lines->setObjectName("label_len_lines");
        label_len_lines->setGeometry(QRect(450, 420, 131, 16));
        label_ln_col_pos = new QLabel(centralwidget);
        label_ln_col_pos->setObjectName("label_ln_col_pos");
        label_ln_col_pos->setGeometry(QRect(600, 420, 141, 16));
        label_encoding = new QLabel(centralwidget);
        label_encoding->setObjectName("label_encoding");
        label_encoding->setGeometry(QRect(840, 420, 121, 16));
        label_zoom = new QLabel(centralwidget);
        label_zoom->setObjectName("label_zoom");
        label_zoom->setGeometry(QRect(750, 420, 81, 16));
        NotepadPlus->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NotepadPlus);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 962, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuIcon = new QMenu(menuEdit);
        menuIcon->setObjectName("menuIcon");
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName("menuSetting");
        menuTheme = new QMenu(menuSetting);
        menuTheme->setObjectName("menuTheme");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        NotepadPlus->setMenuBar(menubar);
        toolBar = new QToolBar(NotepadPlus);
        toolBar->setObjectName("toolBar");
        NotepadPlus->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(NotepadPlus);
        statusBar->setObjectName("statusBar");
        NotepadPlus->setStatusBar(statusBar);
        toolBar_2 = new QToolBar(NotepadPlus);
        toolBar_2->setObjectName("toolBar_2");
        NotepadPlus->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar_2);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew_File);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCancel);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionDelete_All);
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuEdit->addSeparator();
        menuEdit->addAction(menuIcon->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionDateTime);
        menuIcon->addAction(actionCopyright);
        menuIcon->addAction(actionTrademark);
        menuIcon->addAction(actionTrademark_2);
        menuSetting->addAction(actionLine_Break);
        menuSetting->addAction(actionAutosave);
        menuSetting->addAction(menuTheme->menuAction());
        menuSetting->addSeparator();
        menuSetting->addAction(actionZoom_Reset);
        menuSetting->addAction(actionReset_Text_Settings);
        menuSetting->addSeparator();
        menuTheme->addAction(actionWhite);
        menuTheme->addAction(actionDark);
        menuAbout->addAction(actionGit_Hub);
        menuAbout->addSeparator();
        menuAbout->addAction(actionAbout_Program);
        toolBar->addAction(actionnewFileIcon);
        toolBar->addAction(actionopenFileIcon);
        toolBar->addAction(actionsaveIcon);
        toolBar->addAction(actionSaveAsIcon);
        toolBar->addAction(actionprintIcon);
        toolBar->addAction(actioncopy);
        toolBar->addAction(actionpasteIcon);
        toolBar->addAction(actioncutIcon);
        toolBar->addAction(actionfindIcon);
        toolBar->addAction(actionreplaceIcon);
        toolBar->addAction(actionbackIcon);
        toolBar->addAction(actionforwardIcon);
        toolBar->addAction(actionboldIcon);
        toolBar->addAction(actionitalicsIcon);
        toolBar->addAction(actionunderlineIcon);
        toolBar->addAction(actioncrossouttextIcon);
        toolBar->addAction(actionleftTextIcon);
        toolBar->addAction(actiontextByWidthIcon);
        toolBar->addAction(actioncenterTextIcon);
        toolBar->addAction(actionrightTextIcon);
        toolBar->addAction(actionfontFamilyIcon);
        toolBar->addAction(actionfillTheTextBgIcon);
        toolBar->addAction(actioncolorTextIcon);
        toolBar->addAction(actionincreaseIcon);
        toolBar->addAction(actionreduceIcon);
        toolBar->addAction(actioninfoIcon);

        retranslateUi(NotepadPlus);

        QMetaObject::connectSlotsByName(NotepadPlus);
    } // setupUi

    void retranslateUi(QMainWindow *NotepadPlus)
    {
        NotepadPlus->setWindowTitle(QCoreApplication::translate("NotepadPlus", "FusionNote", nullptr));
        actionOpen->setText(QCoreApplication::translate("NotepadPlus", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setProperty("Action Editor", QVariant(QString()));
        actionNew_File->setText(QCoreApplication::translate("NotepadPlus", "New File", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_File->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("NotepadPlus", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("NotepadPlus", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("NotepadPlus", "Print...", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCancel->setText(QCoreApplication::translate("NotepadPlus", "Cancel", nullptr));
        actionCut->setText(QCoreApplication::translate("NotepadPlus", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("NotepadPlus", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("NotepadPlus", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_All->setText(QCoreApplication::translate("NotepadPlus", "Delete All", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete_All->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("NotepadPlus", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("NotepadPlus", "Replace", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_All->setText(QCoreApplication::translate("NotepadPlus", "Select All", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_All->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDateTime->setText(QCoreApplication::translate("NotepadPlus", "DateTime", nullptr));
        actionCopyright->setText(QCoreApplication::translate("NotepadPlus", "Copyright(\302\251)", nullptr));
        actionTrademark->setText(QCoreApplication::translate("NotepadPlus", "Trademark(\342\204\242)", nullptr));
        actionLine_Break->setText(QCoreApplication::translate("NotepadPlus", "Line Break", nullptr));
        actionAutosave->setText(QCoreApplication::translate("NotepadPlus", "AutoSave", nullptr));
        actionReset_Text_Settings->setText(QCoreApplication::translate("NotepadPlus", "Reset Text Settings", nullptr));
        actionnewFileIcon->setText(QCoreApplication::translate("NotepadPlus", "newFileIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionnewFileIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "New File", nullptr));
#endif // QT_CONFIG(tooltip)
        actionopenFileIcon->setText(QCoreApplication::translate("NotepadPlus", "openFileIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionopenFileIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Open File", nullptr));
#endif // QT_CONFIG(tooltip)
        actionsaveIcon->setText(QCoreApplication::translate("NotepadPlus", "saveIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionsaveIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Save File", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSaveAsIcon->setText(QCoreApplication::translate("NotepadPlus", "SaveAsIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionSaveAsIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Save As...", nullptr));
#endif // QT_CONFIG(tooltip)
        actionprintIcon->setText(QCoreApplication::translate("NotepadPlus", "printIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionprintIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Print", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncopy->setText(QCoreApplication::translate("NotepadPlus", "copyIcon", nullptr));
#if QT_CONFIG(tooltip)
        actioncopy->setToolTip(QCoreApplication::translate("NotepadPlus", "Copy", nullptr));
#endif // QT_CONFIG(tooltip)
        actionpasteIcon->setText(QCoreApplication::translate("NotepadPlus", "pasteIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionpasteIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Paste", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncutIcon->setText(QCoreApplication::translate("NotepadPlus", "cutIcon", nullptr));
#if QT_CONFIG(tooltip)
        actioncutIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Cut", nullptr));
#endif // QT_CONFIG(tooltip)
        actionfindIcon->setText(QCoreApplication::translate("NotepadPlus", "findIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionfindIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Find", nullptr));
#endif // QT_CONFIG(tooltip)
        actionreplaceIcon->setText(QCoreApplication::translate("NotepadPlus", "replaceIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionreplaceIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Replace", nullptr));
#endif // QT_CONFIG(tooltip)
        actionbackIcon->setText(QCoreApplication::translate("NotepadPlus", "backIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionbackIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Undo", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionbackIcon->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionboldIcon->setText(QCoreApplication::translate("NotepadPlus", "boldIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionboldIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Text Bold", nullptr));
#endif // QT_CONFIG(tooltip)
        actionitalicsIcon->setText(QCoreApplication::translate("NotepadPlus", "italicsIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionitalicsIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Text Italics", nullptr));
#endif // QT_CONFIG(tooltip)
        actionunderlineIcon->setText(QCoreApplication::translate("NotepadPlus", "underlineIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionunderlineIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Underline", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncrossouttextIcon->setText(QCoreApplication::translate("NotepadPlus", "crossouttextIcon", nullptr));
#if QT_CONFIG(tooltip)
        actioncrossouttextIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Cross Out The Text", nullptr));
#endif // QT_CONFIG(tooltip)
        actionleftTextIcon->setText(QCoreApplication::translate("NotepadPlus", "leftTextIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionleftTextIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Left Text", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncenterTextIcon->setText(QCoreApplication::translate("NotepadPlus", "centerTextIcon", nullptr));
#if QT_CONFIG(tooltip)
        actioncenterTextIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Center Text", nullptr));
#endif // QT_CONFIG(tooltip)
        actionrightTextIcon->setText(QCoreApplication::translate("NotepadPlus", "rightTextIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionrightTextIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Right Text", nullptr));
#endif // QT_CONFIG(tooltip)
        actiontextByWidthIcon->setText(QCoreApplication::translate("NotepadPlus", "textByWidthIcon", nullptr));
#if QT_CONFIG(tooltip)
        actiontextByWidthIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Text By Width", nullptr));
#endif // QT_CONFIG(tooltip)
        actionfillTheTextBgIcon->setText(QCoreApplication::translate("NotepadPlus", "fillTheTextBgIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionfillTheTextBgIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Filling Text Background", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncolorTextIcon->setText(QCoreApplication::translate("NotepadPlus", "colorTextIcon", nullptr));
#if QT_CONFIG(tooltip)
        actioncolorTextIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Color Text", nullptr));
#endif // QT_CONFIG(tooltip)
        actionincreaseIcon->setText(QCoreApplication::translate("NotepadPlus", "increaseIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionincreaseIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Increase", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionincreaseIcon->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl++", nullptr));
#endif // QT_CONFIG(shortcut)
        actionreduceIcon->setText(QCoreApplication::translate("NotepadPlus", "reduceIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionreduceIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Reduce", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionreduceIcon->setShortcut(QCoreApplication::translate("NotepadPlus", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actioninfoIcon->setText(QCoreApplication::translate("NotepadPlus", "infoIcon", nullptr));
#if QT_CONFIG(tooltip)
        actioninfoIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Info", nullptr));
#endif // QT_CONFIG(tooltip)
        actionforwardIcon->setText(QCoreApplication::translate("NotepadPlus", "forwardIcon", nullptr));
#if QT_CONFIG(tooltip)
        actionforwardIcon->setToolTip(QCoreApplication::translate("NotepadPlus", "Redo", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWhite->setText(QCoreApplication::translate("NotepadPlus", "White", nullptr));
        actionDark->setText(QCoreApplication::translate("NotepadPlus", "Dark", nullptr));
        actionExit->setText(QCoreApplication::translate("NotepadPlus", "Exit", nullptr));
        actionTrademark_2->setText(QCoreApplication::translate("NotepadPlus", "Registered Trademark(\302\256)", nullptr));
        actionfontFamilyIcon->setText(QCoreApplication::translate("NotepadPlus", "fontFamilyIcon", nullptr));
        actionZoom_Reset->setText(QCoreApplication::translate("NotepadPlus", "Zoom Reset", nullptr));
        actionAbout_Program->setText(QCoreApplication::translate("NotepadPlus", "About Program", nullptr));
        actionGit_Hub->setText(QCoreApplication::translate("NotepadPlus", "GitHub", nullptr));
        label_file_path->setText(QCoreApplication::translate("NotepadPlus", "No File", nullptr));
        label_notifications->setText(QCoreApplication::translate("NotepadPlus", "notifications: None", nullptr));
        label_len_lines->setText(QCoreApplication::translate("NotepadPlus", "length: 0 lines: 0", nullptr));
        label_ln_col_pos->setText(QCoreApplication::translate("NotepadPlus", "Ln: 0 Col: 0 Pos: 0", nullptr));
        label_encoding->setText(QCoreApplication::translate("NotepadPlus", "encoding: None", nullptr));
        label_zoom->setText(QCoreApplication::translate("NotepadPlus", "zoom: 100%", nullptr));
        menuFile->setTitle(QCoreApplication::translate("NotepadPlus", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("NotepadPlus", "Edit", nullptr));
        menuIcon->setTitle(QCoreApplication::translate("NotepadPlus", "Icon", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("NotepadPlus", "Setting", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("NotepadPlus", "Theme", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("NotepadPlus", "About", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("NotepadPlus", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("NotepadPlus", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotepadPlus: public Ui_NotepadPlus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPADPLUS_H
