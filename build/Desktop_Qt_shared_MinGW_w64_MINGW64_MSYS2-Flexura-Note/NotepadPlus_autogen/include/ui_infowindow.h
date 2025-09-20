/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InfoWindow)
    {
        if (InfoWindow->objectName().isEmpty())
            InfoWindow->setObjectName("InfoWindow");
        InfoWindow->setWindowModality(Qt::NonModal);
        InfoWindow->setEnabled(true);
        InfoWindow->resize(426, 301);
        InfoWindow->setMinimumSize(QSize(420, 301));
        InfoWindow->setMaximumSize(QSize(449, 301));
        InfoWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/image/icon_program.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        InfoWindow->setWindowIcon(icon);
        centralwidget = new QWidget(InfoWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 161, 41));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 220, 211, 41));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 180, 181, 41));
        label_3->setFont(font1);
        label_3->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 180, 181, 41));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 50, 411, 91));
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(false);
        label_5->setWordWrap(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 130, 301, 41));
        QFont font2;
        font2.setPointSize(12);
        label_6->setFont(font2);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 50, 451, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        InfoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InfoWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 426, 22));
        InfoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(InfoWindow);
        statusbar->setObjectName("statusbar");
        InfoWindow->setStatusBar(statusbar);

        retranslateUi(InfoWindow);

        QMetaObject::connectSlotsByName(InfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InfoWindow)
    {
        InfoWindow->setWindowTitle(QCoreApplication::translate("InfoWindow", "Info", nullptr));
        label->setText(QCoreApplication::translate("InfoWindow", "<html><head/><body><p align=\"center\"><a style=\"text-decoration: none\" href=\"https://github.com/Syneation/notepad-plus\"><span style=\" color:black;\">Flexura Note</span></a></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("InfoWindow", "version: 1.0 (beta test)", nullptr));
        label_3->setText(QCoreApplication::translate("InfoWindow", "<html><head/><body><p><a style=\"text-decoration: none\" href=\"https://github.com/Syneation\"><span style=\" color:blue;\">GitHub: Syneation</span></a></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("InfoWindow", "Created: Alexander", nullptr));
        label_5->setText(QCoreApplication::translate("InfoWindow", "Flexura Note is designed for quick notes or anything with advanced features. Enjoy :)", nullptr));
        label_6->setText(QCoreApplication::translate("InfoWindow", "if you find a bug, please feedback with me!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindow: public Ui_InfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
