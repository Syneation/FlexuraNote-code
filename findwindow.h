/**
 * FusionNote - Text Editor
 * Copyright (c) 2024 Alexander (GitHub: Syneation)
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

#ifndef FINDWINDOW_H
#define FINDWINDOW_H

#include <QDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCharFormat>

namespace Ui {
class FindWindow;
}


class FindWindow : public QDialog
{
    Q_OBJECT

public:
    struct find_work {
        QString text_find;

        bool check_case_sensitive = false;
        bool check_text_wrapping = false;
        bool check_whole_word = false;

        bool check_click_button_find_next = false;

        bool check_find_top = false;
        bool check_find_down = false;
    };

    explicit FindWindow(QWidget *parent = nullptr);
    ~FindWindow();

    void show_find_window();
    find_work get_find_work() const;

signals:
    void findRequested(const find_work& work);
    void matchesFound(int count); // to calculate the found search result

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1);

    void on_textEdit_textChanged();

    void on_find_next_btn_clicked();

    void on_radioButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_checkBox_3_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::FindWindow *ui;
    find_work m_find_work;

};

#endif // FINDWINDOW_H
