/********************************************************************************
** Form generated from reading UI file 'advancedsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDSETTINGS_H
#define UI_ADVANCEDSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_advancedsettings
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QSpinBox *time_for_autosave;

    void setupUi(QDialog *advancedsettings)
    {
        if (advancedsettings->objectName().isEmpty())
            advancedsettings->setObjectName("advancedsettings");
        advancedsettings->resize(400, 300);
        buttonBox = new QDialogButtonBox(advancedsettings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(advancedsettings);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 0, 241, 71));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        line = new QFrame(advancedsettings);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 50, 401, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_2 = new QLabel(advancedsettings);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 131, 21));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        time_for_autosave = new QSpinBox(advancedsettings);
        time_for_autosave->setObjectName("time_for_autosave");
        time_for_autosave->setGeometry(QRect(150, 70, 42, 22));
        time_for_autosave->setMinimum(3);
        time_for_autosave->setMaximum(30);
        time_for_autosave->setValue(5);

        retranslateUi(advancedsettings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, advancedsettings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, advancedsettings, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(advancedsettings);
    } // setupUi

    void retranslateUi(QDialog *advancedsettings)
    {
        advancedsettings->setWindowTitle(QCoreApplication::translate("advancedsettings", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("advancedsettings", "Advanced Settings", nullptr));
        label_2->setText(QCoreApplication::translate("advancedsettings", "time for AutoSave:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class advancedsettings: public Ui_advancedsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDSETTINGS_H
