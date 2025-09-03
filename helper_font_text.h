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

#ifndef HELPER_FONT_TEXT_H
#define HELPER_FONT_TEXT_H

#include <QFont>
#include <QTextCursor>
#include <QFontDialog>
#include <QTextCharFormat>
#include <QTextEdit>
#include <QRegularExpression>

class helper_font_text
{
public:
    static bool containsHtml(const QString& text);
    static bool containsTag(const QString& text, const QString& tagName);
    static bool isStrikeOutStyled(const QString& text);
    static bool isBoldStyled(const QString& text);
    static bool isItalicStyled(const QString& text);
    static bool isUnderlineStyled(const QString& text);
    static QColor getBackgroundColor(const QString& text);
    static QString getFontFamily(const QString& text);
    static int getFontSize(const QString& text);
    static bool hasStyle(const QString& text, const QString& styleName, const QString& styleValue);
    static bool hasColor(const QString& text, const QColor& color);
    static bool hasBackgroundColor(const QString& text, const QColor& color);
    static bool hasFontFamily(const QString& text, const QString& fontFamily);
    static bool hasFontSize(const QString& text, int fontSize);
    static QString getStyleValue(const QString& text, const QString& styleName);
    static QColor getTextColor(const QString& text);

    static void Reset_Text_Format(QTextEdit* textEdit);
    static void set_default_ff(QTextCursor cursor, bool enable);

    static QFont get_default_ff();
    static void set_bold_ff(QTextEdit* textEdit, bool enable);
    static void set_italics_ff(QTextEdit* textEdit, bool enable);
    static void set_underline_ff(QTextEdit* textEdit, bool enable);
    static void set_strike_through_ff(QTextCursor cursor, bool enable);
    static void set_selected_text_ff(const QFont& font, QTextCursor cursor);
};

#endif // HELPER_FONT_TEXT_H
