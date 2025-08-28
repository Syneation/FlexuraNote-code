/********************************************************************************
** Form generated from reading UI file 'findwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDWINDOW_H
#define UI_FINDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FindWindow
{
public:
    QLabel *label_1;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *find_next_btn;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox_3;

    void setupUi(QDialog *FindWindow)
    {
        if (FindWindow->objectName().isEmpty())
            FindWindow->setObjectName("FindWindow");
        FindWindow->resize(452, 161);
        FindWindow->setMinimumSize(QSize(452, 161));
        FindWindow->setMaximumSize(QSize(452, 161));
        label_1 = new QLabel(FindWindow);
        label_1->setObjectName("label_1");
        label_1->setGeometry(QRect(0, 30, 61, 25));
        label_1->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(18);
        label_1->setFont(font);
        textEdit = new QTextEdit(FindWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(70, 30, 271, 31));
        QFont font1;
        font1.setPointSize(16);
        textEdit->setFont(font1);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setLineWidth(0);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        label = new QLabel(FindWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 0, 61, 31));
        QFont font2;
        font2.setPointSize(20);
        label->setFont(font2);
        find_next_btn = new QPushButton(FindWindow);
        find_next_btn->setObjectName("find_next_btn");
        find_next_btn->setGeometry(QRect(350, 30, 81, 31));
        pushButton_2 = new QPushButton(FindWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 70, 81, 31));
        label_2 = new QLabel(FindWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 80, 49, 16));
        checkBox = new QCheckBox(FindWindow);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 80, 101, 21));
        checkBox_2 = new QCheckBox(FindWindow);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(10, 110, 101, 21));
        radioButton = new QRadioButton(FindWindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(210, 100, 41, 20));
        radioButton_2 = new QRadioButton(FindWindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(270, 100, 61, 20));
        radioButton_2->setChecked(true);
        checkBox_3 = new QCheckBox(FindWindow);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(10, 140, 151, 20));

        retranslateUi(FindWindow);

        QMetaObject::connectSlotsByName(FindWindow);
    } // setupUi

    void retranslateUi(QDialog *FindWindow)
    {
        FindWindow->setWindowTitle(QCoreApplication::translate("FindWindow", " Find", nullptr));
        label_1->setText(QCoreApplication::translate("FindWindow", "What:", nullptr));
        label->setText(QCoreApplication::translate("FindWindow", "FIND", nullptr));
        find_next_btn->setText(QCoreApplication::translate("FindWindow", "Find Next", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FindWindow", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("FindWindow", "Direction", nullptr));
        checkBox->setText(QCoreApplication::translate("FindWindow", "Case-sensitive", nullptr));
        checkBox_2->setText(QCoreApplication::translate("FindWindow", "Text Wrapping", nullptr));
        radioButton->setText(QCoreApplication::translate("FindWindow", "Top", nullptr));
        radioButton_2->setText(QCoreApplication::translate("FindWindow", "Down", nullptr));
        checkBox_3->setText(QCoreApplication::translate("FindWindow", "search for whole words", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindWindow: public Ui_FindWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWINDOW_H
