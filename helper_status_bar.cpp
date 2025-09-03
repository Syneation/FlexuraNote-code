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
#include "helper_status_bar.h"
#include "FlexuraNote.h"
#include "./ui_FlexuraNote.h"

void helper_status::set_path(NotepadPlus* notepad, QString& path_file, QString new_path)
{
    if (notepad)
    {
        path_file = new_path;
        notepad->updateFilePath(new_path);
    }
}

void helper_status::set_notifications(NotepadPlus* notepad, QString& notifications , QString text_notifications)
{
    if (notepad)
    {
        notifications = text_notifications;
        notepad->updateNotification(QString("notifications: %1").arg(text_notifications));
    }
}

void helper_status::set_len_lines(NotepadPlus* notepad, int len, int lines)
{
    if (notepad)
        notepad->updateLenLines(QString("length: %1 lines: %2").arg(len).arg(lines));

}

void helper_status::set_ln_col_pos(NotepadPlus* notepad, int ln, int col, int pos)
{
    if (notepad)
        notepad->updateLnColPos(QString("ln: %1 col: %2 pos: %3").arg(ln).arg(col).arg(pos));
}

void helper_status::set_encoding(NotepadPlus* notepad, QString encoding)
{
    if (notepad)
        notepad->updateEncoding(QString("encoding: %1").arg(encoding));
}
