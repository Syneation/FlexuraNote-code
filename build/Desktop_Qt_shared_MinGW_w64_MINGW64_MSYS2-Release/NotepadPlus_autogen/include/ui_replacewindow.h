/********************************************************************************
** Form generated from reading UI file 'replacewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEWINDOW_H
#define UI_REPLACEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ReplaceWindow
{
public:
    QLabel *label_1;
    QLabel *label;
    QPushButton *find_next_btn;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QTextEdit *textEdit;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QPushButton *replace_btn;
    QPushButton *replace_all_btn;

    void setupUi(QDialog *ReplaceWindow)
    {
        if (ReplaceWindow->objectName().isEmpty())
            ReplaceWindow->setObjectName("ReplaceWindow");
        ReplaceWindow->resize(487, 248);
        ReplaceWindow->setMinimumSize(QSize(487, 248));
        ReplaceWindow->setMaximumSize(QSize(487, 248));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/image/icon_program.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ReplaceWindow->setWindowIcon(icon);
        label_1 = new QLabel(ReplaceWindow);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(10, 30, 61, 25));
        label_1->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(18);
        label_1->setFont(font);
        label = new QLabel(ReplaceWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 0, 111, 31));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        find_next_btn = new QPushButton(ReplaceWindow);
        find_next_btn->setObjectName("find_next_btn");
        find_next_btn->setGeometry(QRect(380, 30, 81, 31));
        checkBox_3 = new QCheckBox(ReplaceWindow);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(10, 210, 151, 20));
        pushButton_2 = new QPushButton(ReplaceWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(380, 150, 81, 31));
        checkBox_2 = new QCheckBox(ReplaceWindow);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(10, 180, 101, 21));
        checkBox = new QCheckBox(ReplaceWindow);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 150, 101, 21));
        textEdit = new QTextEdit(ReplaceWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(80, 30, 271, 31));
        QFont font2;
        font2.setPointSize(16);
        textEdit->setFont(font2);
        textEdit->setAcceptDrops(false);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setLineWidth(0);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        label_2 = new QLabel(ReplaceWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 61, 25));
        label_2->setMaximumSize(QSize(16777215, 25));
        label_2->setFont(font);
        textEdit_2 = new QTextEdit(ReplaceWindow);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(80, 80, 271, 31));
        textEdit_2->setFont(font2);
        textEdit_2->setAcceptDrops(false);
        textEdit_2->setFrameShadow(QFrame::Plain);
        textEdit_2->setLineWidth(0);
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        textEdit_2->setLineWrapMode(QTextEdit::NoWrap);
        replace_btn = new QPushButton(ReplaceWindow);
        replace_btn->setObjectName("replace_btn");
        replace_btn->setGeometry(QRect(380, 70, 81, 31));
        replace_all_btn = new QPushButton(ReplaceWindow);
        replace_all_btn->setObjectName("replace_all_btn");
        replace_all_btn->setGeometry(QRect(380, 110, 81, 31));

        retranslateUi(ReplaceWindow);

        QMetaObject::connectSlotsByName(ReplaceWindow);
    } // setupUi

    void retranslateUi(QDialog *ReplaceWindow)
    {
        ReplaceWindow->setWindowTitle(QCoreApplication::translate("ReplaceWindow", "Replace", nullptr));
        label_1->setText(QCoreApplication::translate("ReplaceWindow", "What:", nullptr));
        label->setText(QCoreApplication::translate("ReplaceWindow", "REPLACE", nullptr));
        find_next_btn->setText(QCoreApplication::translate("ReplaceWindow", "Find Next", nullptr));
        checkBox_3->setText(QCoreApplication::translate("ReplaceWindow", "search for whole words", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ReplaceWindow", "Cancel", nullptr));
        checkBox_2->setText(QCoreApplication::translate("ReplaceWindow", "Text Wrapping", nullptr));
        checkBox->setText(QCoreApplication::translate("ReplaceWindow", "Case-sensitive", nullptr));
        label_2->setText(QCoreApplication::translate("ReplaceWindow", "Than:", nullptr));
        replace_btn->setText(QCoreApplication::translate("ReplaceWindow", "Replace", nullptr));
        replace_all_btn->setText(QCoreApplication::translate("ReplaceWindow", "Replace All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceWindow: public Ui_ReplaceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEWINDOW_H
