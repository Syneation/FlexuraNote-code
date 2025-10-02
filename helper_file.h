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

#ifndef HELPER_FILE_H
#define HELPER_FILE_H

#include "FlexuraNote.h"
#include "rtfparser.h"

#include <QByteArray>
#include <QFileDialog>
#include <QTextCodec>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QTextDocumentFragment>
#include <QRegularExpression>
#include <QTextDocumentWriter>

class helper_file
{
public:

    static QString get_encoding(const QString& filePath);
    static QString get_text_from_file(NotepadPlus *notepad, const QString path);

    static bool open_file(NotepadPlus *notepad, QString& status_bar_path, QTextEdit* textEdit);
    static bool open_file(NotepadPlus *notepad, QString& status_bar_path, const QString path, QTextEdit* textEdit);

    static void save_file(NotepadPlus *notepad, QString& currentFile);
    static void save_as_file(NotepadPlus *notepad, QString& currentFile);


};

#endif // HELPER_FILE_H
