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

#include "helper_file.h"

//
// find out the encoding
//
QString helper_file::get_encoding(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return "UNKNOWN";

    // Read first 64 bytes for quick analysis
    QByteArray data = file.read(64);
    file.close();

    // 1. Check for BOM (Byte Order Mark)
    if (data.startsWith("\xEF\xBB\xBF"))
        return "UTF-8 with BOM";

    else if (data.startsWith("\xFF\xFE"))
        return "UTF-16 LE";

    else if (data.startsWith("\xFE\xFF"))
        return "UTF-16 BE";


    // 2. Check for UTF-8 without BOM
    bool isUtf8 = true;
    int continuationBytes = 0;

    for (char c : data)
    {
        unsigned char uc = static_cast<unsigned char>(c);

        if (continuationBytes > 0)
        {
            // Check for valid continuation byte (10xxxxxx)
            if ((uc & 0xC0) != 0x80)
            {
                isUtf8 = false;
                break;
            }
            continuationBytes--;
        }
        else
        {
            // Check for UTF-8 start byte patterns
            if (uc < 0x80)
                continue; // ASCII character (0xxxxxxx)

            else if ((uc & 0xE0) == 0xC0)
                continuationBytes = 1; // 110xxxxx (2-byte sequence)

            else if ((uc & 0xF0) == 0xE0)
                continuationBytes = 2; // 1110xxxx (3-byte sequence)

            else if ((uc & 0xF8) == 0xF0)
                continuationBytes = 3; // 11110xxx (4-byte sequence)

            else
            {
                isUtf8 = false;
                break;
            }
        }
    }

    if (isUtf8 && continuationBytes == 0)
        return "UTF-8";

    // 3. If not UTF, assume ANSI encoding
    return "ANSI";

}

//
// open file
//
QString helper_file::get_text_from_file(NotepadPlus *notepad, const QString path)
{
    notepad->currentFile = path;

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "File is not open!";
        return "[ERROR] FILE NOT OPEN";
    }

    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    return text;
}

bool helper_file::open_file(NotepadPlus *notepad, QString& status_bar_path, QTextEdit* textEdit)
{
    QString fileName = QFileDialog::getOpenFileName(notepad, "Open the file", QString(), "Simple text file (*.txt);; Advanced text file (*.html);; All files (*.*)");
    if (fileName.isEmpty()) return false;

    QFile file(fileName);
    status_bar_path = fileName;
    notepad->currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(notepad, "Warning", "Cannot open file: " + file.errorString());
        return false;
    }

    // check type file
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    if (fileName.endsWith(".html"))
        textEdit->setHtml(text);
    else
        textEdit->setPlainText(text);

    return true;
}

bool helper_file::open_file(NotepadPlus *notepad, QString& status_bar_path, const QString path, QTextEdit* textEdit)
{
    status_bar_path = path;
    notepad->currentFile = path;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(notepad, "Warning", "Cannot open file: " + file.errorString());
        return false;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    if (path.endsWith(".html"))
        textEdit->setHtml(text);
    else
        textEdit->setPlainText(text);
    return true;
}

//
// save_file
//
void helper_file::save_file(NotepadPlus *notepad, QString& currentFile)
{
    QString fileName;

    // if we don't have a filename from before, get one
    if (currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(notepad, "Save", QDir::currentPath(), "Simple text file (*.txt);; Advanced text file (*.html);; All files (*.*)");
        if (fileName.isEmpty()) return;
        currentFile = fileName;
    }
    else
        fileName = currentFile;

    notepad->updateSaveText(fileName);
}


//
// Save As...
//
void helper_file::save_as_file(NotepadPlus *notepad, QString& currentFile)
{
    QString fileName = fileName = QFileDialog::getSaveFileName(notepad, "Save As...", QDir::currentPath(), "Simple text file (*.txt);; Advanced text file (*.html);; All files (*.*)");;
    if (fileName.isEmpty()) return;

    notepad->updateSaveAsText(fileName);
}
