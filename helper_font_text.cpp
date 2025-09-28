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

#include "helper_font_text.h"

QFont font;


//---------------------------------------------
// Style value extraction functions
//---------------------------------------------
QString helper_font_text::getStyleValue(const QString& text, const QString& styleName)
{
    QRegularExpression styleRegex(
        QString("%1\\s*:\\s*([^;]*)").arg(styleName),
        QRegularExpression::CaseInsensitiveOption
        );

    QRegularExpressionMatch match = styleRegex.match(text);
    if (match.hasMatch()) {
        return match.captured(1).trimmed().remove('"').remove('\'');
    }

    return "";
}

QColor helper_font_text::getTextColor(const QString& text)
{
    QString colorStr = getStyleValue(text, "color");
    if (!colorStr.isEmpty())
        return QColor(colorStr);


    // Check for hex colors
    QRegularExpression hexRegex("#[0-9a-fA-F]{6}");
    QRegularExpressionMatch hexMatch = hexRegex.match(text);
    if (hexMatch.hasMatch())
        return QColor(hexMatch.captured());


    return QColor(); // Invalid color
}

QColor helper_font_text::getBackgroundColor(const QString& text)
{
    QString colorStr = getStyleValue(text, "background-color");
    if (!colorStr.isEmpty())
        return QColor(colorStr);

    return QColor(); // Invalid color
}

QString helper_font_text::getFontFamily(const QString& text)
{
    return getStyleValue(text, "font-family");
}

int helper_font_text::getFontSize(const QString& text)
{
    QString sizeStr = getStyleValue(text, "font-size");
    if (sizeStr.endsWith("pt")) {
        return sizeStr.left(sizeStr.length() - 2).toInt();
    }
    return 0;
}

//---------------------------------------------
// Specific formatting style checks
//---------------------------------------------
////
/// \brief helper_font_text::isBoldStyled
/// \param you need to write a textEdit->textCursor for cursor
/// \return true or false
///
bool helper_font_text::isBoldStyled(const QTextCursor& text_cursor)
{
    QTextCursor cursor = text_cursor;
    QTextCharFormat currentFormat = cursor.charFormat();

    return currentFormat.fontWeight() > QFont::Normal;
}

////
/// \brief helper_font_text::isItalicStyled
/// \param you need to write a textEdit->textCursor for cursor
/// \return true or false
///
bool helper_font_text::isItalicStyled(const QTextCursor& text_cursor)
{
    QTextCursor cursor = text_cursor;
    QTextCharFormat currentFormat = cursor.charFormat();

    return currentFormat.fontItalic();
}

////
/// \brief helper_font_text::isUnderlineStyled
/// \param you need to write a textEdit->textCursor for cursor
/// \return true or false
///
bool helper_font_text::isUnderlineStyled(const QTextCursor& text_cursor)
{
    QTextCursor cursor = text_cursor;
    QTextCharFormat currentFormat = cursor.charFormat();

    return currentFormat.fontUnderline();
}

////
/// \brief helper_font_text::isStrikeOutStyled
/// \param you need to write a textEdit->textCursor for cursor
/// \return true or false
///
bool helper_font_text::isStrikeOutStyled(const QTextCursor& text_cursor)
{
    QTextCursor cursor = text_cursor;
    QTextCharFormat currentFormat = cursor.charFormat();

    return currentFormat.fontStrikeOut();
}

//---------------------------------------------
// Default font family
//---------------------------------------------
void helper_font_text::set_default_ff(QTextCursor cursor, bool enable)
{
    QTextCharFormat format;
    format.setFontWeight(enable);
    cursor.mergeCharFormat(format);
}

void helper_font_text::clear_bold_italic_underline_strikethrough(QTextEdit* textEdit)
{
    QTextCursor cursor = textEdit->textCursor();
    QFont currentFont = textEdit->font();
    QTextCharFormat format;

    format.setFontWeight(QFont::Normal);
    format.setFontUnderline(false);
    format.setFontItalic(false);
    format.setFontStrikeOut(false);


    textEdit->setCurrentCharFormat(format);

}

QFont helper_font_text::get_default_ff()
{
    QFont font("Arial", 20);
    return font;
}

//---------------------------------------------
// Bold font family with style checking
//---------------------------------------------
void helper_font_text::set_bold_ff(QTextEdit* textEdit, QTextCursor& cursor, const QString& selected_text, bool enable)
{
    QString selectedText = cursor.selectedText();

    if (selected_text.isEmpty()) return;

    //---------------------------------------------
    // Check current styles
    //---------------------------------------------
    QTextCharFormat currentFormat = cursor.charFormat();
    bool hasBold = currentFormat.fontWeight() > QFont::Normal;
    bool hasItalic = currentFormat.fontItalic();
    bool hasUnderline = currentFormat.fontUnderline();
    bool hasStrikeThrough = currentFormat.fontStrikeOut();

    QString newHtml;

    if (enable && !hasBold)
    {
        //---------------------------------------------
        // Enable bold
        //---------------------------------------------
        if (hasItalic && hasUnderline && hasStrikeThrough)
            newHtml = "<b><i><u><s>" + selectedText + "</s></u></i></b>";


        else if (hasItalic && hasUnderline)
            newHtml = "<b><i><u>" + selectedText + "</u></i></b>";


        else if (hasItalic && hasStrikeThrough)
            newHtml = "<b><i><s>" + selectedText + "</b></i></s>";


        else if (hasUnderline && hasStrikeThrough)
            newHtml = "<b><u><s>" + selectedText + "</b></u></s>";


        else if (hasUnderline)
            newHtml = "<b><u>" + selectedText + "</u></b>";


        else if (hasItalic)
            newHtml = "<b><i>" + selectedText + "</i></b>";


        else if (hasStrikeThrough)
            newHtml = "<b><s>" + selectedText + "</s></b>";


        else
            newHtml = "<b>" + selectedText + "</b>";


    } else if (!enable && hasBold){
        //---------------------------------------------
        // Disable bold
        //---------------------------------------------
        if (hasItalic && hasUnderline && hasStrikeThrough)
            newHtml = "<i><u><s>" + selectedText + "</s></u></i>";


        else if (hasItalic && hasUnderline)
            newHtml = "<i><u>" + selectedText + "</u></i>";

        else if (hasItalic && hasStrikeThrough)
            newHtml = "<i><s>" + selectedText + "</i></s>";

        else if (hasUnderline && hasStrikeThrough)
            newHtml = "<u><s>" + selectedText + "</u></s>";


        else if (hasUnderline)
            newHtml = "<u>" + selectedText + "</u>";

        else if (hasItalic)
            newHtml = "<i>" + selectedText + "</i>";

        else if (hasStrikeThrough)
            newHtml = "<s>" + selectedText + "</s>";

        else
            newHtml = selectedText;
    }
    else
        return;


    cursor.insertHtml(newHtml);

    cursor.setPosition(cursor.selectionEnd());
}

//---------------------------------------------
// Italics font family with style checking
//---------------------------------------------
void helper_font_text::set_italics_ff(QTextEdit* textEdit, const QString& selected_text, bool enable)
{
    QTextCursor cursor = textEdit->textCursor();
    QString selectedText = cursor.selectedText();

    if (selected_text.isEmpty()) return;

    // Check current styles
    QTextCharFormat currentFormat = cursor.charFormat();
    bool hasBold = currentFormat.fontWeight() > QFont::Normal;
    bool hasItalic = currentFormat.fontItalic();
    bool hasUnderline = currentFormat.fontUnderline();
    bool hasStrikeThrough = currentFormat.fontStrikeOut();

    QString newHtml;

    if (enable && !hasItalic)
    {
        // Enable bold
        if (hasBold && hasUnderline && hasStrikeThrough)
            newHtml = "<b><i><u><s>" + selectedText + "</s></u></i></b>";


        else if (hasBold && hasUnderline)
            newHtml = "<b><i><u>" + selectedText + "</u></i></b>";

        else if (hasBold && hasStrikeThrough)
            newHtml = "<b><i><s>" + selectedText + "</b></i></s>";

        else if (hasUnderline && hasStrikeThrough)
            newHtml = "<i><u><s>" + selectedText + "</i></u></s>";


        else if (hasUnderline)
            newHtml = "<i><u>" + selectedText + "</i></i>";

        else if (hasBold)
            newHtml = "<b><i>" + selectedText + "</i></b>";

        else if (hasStrikeThrough)
            newHtml = "<i><s>" + selectedText + "</s></i>";

        else
            newHtml = "<i>" + selectedText + "</i>";

    }
    else if (!enable && hasItalic)
    {
        // Disable bold
        if (hasBold && hasUnderline && hasStrikeThrough)
            newHtml = "<b><u><s>" + selectedText + "</s></u></b>";


        else if (hasBold && hasUnderline)
            newHtml = "<b><u>" + selectedText + "</b></u>";

        else if (hasItalic && hasStrikeThrough)
            newHtml = "<b><s>" + selectedText + "</b></s>";

        else if (hasUnderline && hasStrikeThrough)
            newHtml = "<u><s>" + selectedText + "</u></s>";


        else if (hasUnderline)
            newHtml = "<u>" + selectedText + "</u>";

        else if (hasBold)
            newHtml = "<b>" + selectedText + "</b>";

        else if (hasStrikeThrough)
            newHtml = "<s>" + selectedText + "</s>";

        else
            newHtml = selectedText;

    }

    else
        return;


    cursor.insertHtml(newHtml);
}

//
// Underline font family with style checking
//
void helper_font_text::set_underline_ff(QTextEdit* textEdit, const QString& selected_text, bool enable)
{
    QTextCursor cursor = textEdit->textCursor();
    QString selectedText = cursor.selectedText();

    if (selected_text.isEmpty()) return;

    // Check current styles
    QTextCharFormat currentFormat = cursor.charFormat();
    bool hasBold = currentFormat.fontWeight() > QFont::Normal;
    bool hasItalic = currentFormat.fontItalic();
    bool hasUnderline = currentFormat.fontUnderline();
    bool hasStrikeThrough = currentFormat.fontStrikeOut();

    QString newHtml;

    if (enable && !hasUnderline)
    {
        // Enable bold
        if (hasBold && hasUnderline && hasStrikeThrough)
            newHtml = "<b><i><u><s>" + selectedText + "</s></u></i></b>";


        else if (hasBold && hasItalic)
            newHtml = "<b><i><u>" + selectedText + "</u></i></b>";

        else if (hasItalic && hasStrikeThrough)
            newHtml = "<u><i><s>" + selectedText + "</u></i></s>";

        else if (hasBold && hasStrikeThrough)
            newHtml = "<b><u><s>" + selectedText + "</b></u></s>";


        else if (hasItalic)
            newHtml = "<i><u>" + selectedText + "</i></u>";

        else if (hasBold)
            newHtml = "<b><u>" + selectedText + "</b></u>";

        else if (hasStrikeThrough)
            newHtml = "<u><s>" + selectedText + "</s></u>";

        else
            newHtml = "<u>" + selectedText + "</u>";

    }
    else if (!enable && hasUnderline)
    {
        // Disable bold
        if (hasBold && hasItalic && hasStrikeThrough)
            newHtml = "<b><i><s>" + selectedText + "</s></i></b>";


        else if (hasBold && hasItalic)
            newHtml = "<b><i>" + selectedText + "</b></i>";

        else if (hasItalic && hasStrikeThrough)
            newHtml = "<i><s>" + selectedText + "</i></s>";

        else if (hasBold && hasStrikeThrough)
            newHtml = "<b><s>" + selectedText + "</b></s>";


        else if (hasItalic)
            newHtml = "<i>" + selectedText + "</i>";

        else if (hasBold)
            newHtml = "<b>" + selectedText + "</i>";

        else if (hasStrikeThrough)
            newHtml = "<s>" + selectedText + "</s>";

        else
            newHtml = selectedText;

    }

    else
        return;


    cursor.insertHtml(newHtml);
}

//
// Strike through font family
//
void helper_font_text::set_strike_through_ff(QTextEdit* textEdit, const QString& selected_text, bool enable)
{
    QTextCursor cursor = textEdit->textCursor();
    QString selectedText = cursor.selectedText();

    if (selected_text.isEmpty()) return;

    // Check current styles
    QTextCharFormat currentFormat = cursor.charFormat();
    bool hasBold = currentFormat.fontWeight() > QFont::Normal;
    bool hasItalic = currentFormat.fontItalic();
    bool hasUnderline = currentFormat.fontUnderline();
    bool hasStrikeThrough = currentFormat.fontStrikeOut();

    QString newHtml;

    if (enable && !hasUnderline)
    {
        // Enable bold
        if (hasBold && hasUnderline && hasStrikeThrough)
            newHtml = "<b><i><u><s>" + selectedText + "</s></u></i></b>";


        else if (hasBold && hasItalic)
            newHtml = "<b><i><s>" + selectedText + "</s></i></b>";

        else if (hasItalic && hasUnderline)
            newHtml = "<u><i><s>" + selectedText + "</u></i></s>";

        else if (hasBold && hasUnderline)
            newHtml = "<b><u><s>" + selectedText + "</b></u></s>";


        else if (hasItalic)
            newHtml = "<i><s>" + selectedText + "</i></s>";

        else if (hasBold)
            newHtml = "<b><s>" + selectedText + "</b></s>";

        else if (hasUnderline)
            newHtml = "<u><s>" + selectedText + "</s></u>";

        else
            newHtml = "<s>" + selectedText + "</s>";

    }
    else if (!enable && hasUnderline)
    {
        // Disable bold
        if (hasBold && hasItalic && hasUnderline)
            newHtml = "<b><i><u>" + selectedText + "</u></i></b>";


        else if (hasBold && hasItalic)
            newHtml = "<b><i>" + selectedText + "</b></i>";

        else if (hasItalic && hasUnderline)
            newHtml = "<i><u>" + selectedText + "</i></u>";

        else if (hasBold && hasUnderline)
            newHtml = "<b><u>" + selectedText + "</b></u>";


        else if (hasItalic)
            newHtml = "<i>" + selectedText + "</i>";

        else if (hasBold)
            newHtml = "<b>" + selectedText + "</i>";

        else if (hasUnderline)
            newHtml = "<u>" + selectedText + "</u>";

        else
            newHtml = selectedText;

    }

    else
        return;
}

//
// Font family setting
//
void helper_font_text::set_selected_text_ff(const QFont& font, QTextCursor cursor)
{
    QTextCharFormat format;
    format.setFont(font);
    cursor.mergeCharFormat(format);
}

//
// Reset Styles
//
void helper_font_text::Reset_Text_Format(QTextEdit* textEdit)
{
    QTextCursor cursor = textEdit->textCursor();
    cursor.select(QTextCursor::Document);

    QTextCharFormat defaultFormat;
    defaultFormat.setFont(QFont("Arial", 20));
    defaultFormat.setFontWeight(QFont::Normal);
    defaultFormat.setFontItalic(false);
    defaultFormat.setFontUnderline(false);
    defaultFormat.setFontStrikeOut(false);
    defaultFormat.setForeground(QBrush(Qt::black));
    defaultFormat.setBackground(QBrush(Qt::white));
    defaultFormat.setVerticalAlignment(QTextCharFormat::AlignNormal);

    cursor.mergeCharFormat(defaultFormat);
    textEdit->setAlignment(Qt::AlignLeft);
}

