<<<<<<< HEAD
/**
 * Flexura Note - Text Editor
 * Copyright (c) 2025 Alexander (GitHub: Syneation)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * COMMERCIAL USE EXCEPTION:
 * Notwithstanding the terms of the GNU GPL v2, commercial use of this
 * software is permitted ONLY with explicit written permission from the author.
 *
 * Commercial use includes, but is not limited to:
 * - Selling the Software or derivative works
 * - Incorporating into paid products or services
 * - Distribution as part of commercial packages
 * - Any monetization related to the Software
 *
 * For commercial licensing inquiries, contact:
 * GitHub: https://github.com/Syneation
 *
 * DISCLAIMER:
 * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS
 * TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.
 */

#include "findwindow.h"
#include "ui_findwindow.h"

#include <QDebug>

FindWindow::FindWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindWindow)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);

}

FindWindow::~FindWindow()
{
    delete ui;
}

void FindWindow::show_find_window()
{
    this->show();
    this->raise();
    this->activateWindow();
}

//
// find next
//
//
// is clicked btn find next
//
void FindWindow::on_find_next_btn_clicked()
{
    if (ui->textEdit->document()->isEmpty())
    {
        ui->find_next_btn->setEnabled(false);
        return;
    }
    else
        ui->find_next_btn->setEnabled(true);

    m_find_work.text_find = ui->textEdit->toPlainText();
    m_find_work.check_click_button_find_next = true;

    emit findRequested(m_find_work);
}

// btn close
void FindWindow::on_pushButton_2_clicked()
{
    this->close();
}

//
// checking is clicked on Enter to push on btn find next
//
bool FindWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        // if any Enter
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
        {
            ui->find_next_btn->click();
            return true;
        }
    }

    return QDialog::eventFilter(watched, event);
}

//
// check case-sensitive
//
void FindWindow::on_checkBox_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        m_find_work.check_case_sensitive = true;

    else
        m_find_work.check_case_sensitive = false;

}

//
// check text wrapping
//
void FindWindow::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        m_find_work.check_text_wrapping = true;

    else
        m_find_work.check_text_wrapping = false;
}

//
// check search for whole words
//
void FindWindow::on_checkBox_3_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        m_find_work.check_whole_word = true;
    else
        m_find_work.check_whole_word = false;
}

//
// radio buttons (top or down)
//
void FindWindow::on_radioButton_toggled(bool checked)
{
    if (checked)
    {
        m_find_work.check_find_down = false;
        m_find_work.check_find_top = true;
    }
    else
    {
        m_find_work.check_find_down = true;
        m_find_work.check_find_top = false;
    }
}

//
// text edit
//
void FindWindow::on_textEdit_textChanged()
{
    if (ui->textEdit->document()->isModified())
        ui->find_next_btn->setEnabled(true);
}


void FindWindow::on_radioButton_clicked()
{

}

=======
/**
 * Flexura Note - Text Editor
 * Copyright (c) 2025 Alexander (GitHub: Syneation)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * COMMERCIAL USE EXCEPTION:
 * Notwithstanding the terms of the GNU GPL v2, commercial use of this
 * software is permitted ONLY with explicit written permission from the author.
 *
 * Commercial use includes, but is not limited to:
 * - Selling the Software or derivative works
 * - Incorporating into paid products or services
 * - Distribution as part of commercial packages
 * - Any monetization related to the Software
 *
 * For commercial licensing inquiries, contact:
 * GitHub: https://github.com/Syneation
 *
 * DISCLAIMER:
 * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS
 * TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.
 */

#include "findwindow.h"
#include "ui_findwindow.h"

#include <QDebug>

FindWindow::FindWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindWindow)
{
    ui->setupUi(this);

    ui->textEdit->installEventFilter(this);

}

FindWindow::~FindWindow()
{
    delete ui;
}

void FindWindow::show_find_window()
{
    this->show();
    this->raise();
    this->activateWindow();
}

//
// find next
//
//
// is clicked btn find next
//
void FindWindow::on_find_next_btn_clicked()
{
    if (ui->textEdit->document()->isEmpty())
    {
        ui->find_next_btn->setEnabled(false);
        return;
    }
    else
        ui->find_next_btn->setEnabled(true);

    m_find_work.text_find = ui->textEdit->toPlainText();
    m_find_work.check_click_button_find_next = true;

    emit findRequested(m_find_work);
}

// btn close
void FindWindow::on_pushButton_2_clicked()
{
    this->close();
}

//
// checking is clicked on Enter to push on btn find next
//
bool FindWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->textEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        // if any Enter
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
        {
            ui->find_next_btn->click();
            return true;
        }
    }

    return QDialog::eventFilter(watched, event);
}

//
// check case-sensitive
//
void FindWindow::on_checkBox_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        m_find_work.check_case_sensitive = true;

    else
        m_find_work.check_case_sensitive = false;

}

//
// check text wrapping
//
void FindWindow::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        m_find_work.check_text_wrapping = true;

    else
        m_find_work.check_text_wrapping = false;
}

//
// check search for whole words
//
void FindWindow::on_checkBox_3_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        m_find_work.check_whole_word = true;
    else
        m_find_work.check_whole_word = false;
}

//
// radio buttons (top or down)
//
void FindWindow::on_radioButton_toggled(bool checked)
{
    if (checked)
    {
        m_find_work.check_find_down = false;
        m_find_work.check_find_top = true;
    }
    else
    {
        m_find_work.check_find_down = true;
        m_find_work.check_find_top = false;
    }
}

//
// text edit
//
void FindWindow::on_textEdit_textChanged()
{
    if (ui->textEdit->document()->isModified())
        ui->find_next_btn->setEnabled(true);
}


void FindWindow::on_radioButton_clicked()
{

}

>>>>>>> e23c008 (connect git)
