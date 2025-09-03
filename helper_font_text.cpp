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

//
// HTML tags checking
//
bool helper_font_text::containsHtml(const QString& text)
{
    if (text.isEmpty()) return false;

    // Quick check for < and > symbols
    if (!text.contains('<') || !text.contains('>'))
        return false;

    // More accurate verification using regex
    QRegularExpression htmlRegex(
        "<(\\/?)([a-zA-Z]+)([^>]*)>",
        QRegularExpression::CaseInsensitiveOption
        );

    return htmlRegex.match(text).hasMatch();
}

bool helper_font_text::containsTag(const QString &text, const QString &tagName)
{
    QRegularExpression tagRegex(
        QString("<(\\/?)%1([^>]*)>").arg(tagName),
        QRegularExpression::CaseInsensitiveOption
        );

    return tagRegex.match(text).hasMatch();
}

//
// Style checking functions
//
bool helper_font_text::hasStyle(const QString& text, const QString& styleName, const QString& styleValue)
{
    if (text.isEmpty()) return false;

    QRegularExpression styleRegex(
        QString("%1\\s*:\\s*%2").arg(styleName).arg(styleValue.isEmpty() ? "[^;]*" : styleValue),
        QRegularExpression::CaseInsensitiveOption
        );

    return styleRegex.match(text).hasMatch();
}

bool helper_font_text::hasColor(const QString& text, const QColor& color)
{
    QString colorStr = color.name();
    QRegularExpression colorRegex(
        QString("color\\s*:\\s*%1").arg(colorStr),
        QRegularExpression::CaseInsensitiveOption
        );

    return colorRegex.match(text).hasMatch();
}

bool helper_font_text::hasBackgroundColor(const QString& text, const QColor& color)
{
    QString colorStr = color.name();
    QRegularExpression bgRegex(
        QString("background-color\\s*:\\s*%1").arg(colorStr),
        QRegularExpression::CaseInsensitiveOption
        );

    return bgRegex.match(text).hasMatch();
}

bool helper_font_text::hasFontFamily(const QString& text, const QString& fontFamily)
{
    QRegularExpression fontRegex(
        QString("font-family\\s*:\\s*['\"]?%1['\"]?").arg(QRegularExpression::escape(fontFamily)),
        QRegularExpression::CaseInsensitiveOption
        );

    return fontRegex.match(text).hasMatch();
}

bool helper_font_text::hasFontSize(const QString& text, int fontSize)
{
    QRegularExpression sizeRegex(
        QString("font-size\\s*:\\s*%1pt").arg(fontSize),
        QRegularExpression::CaseInsensitiveOption
        );

    return sizeRegex.match(text).hasMatch();
}

//
// Style value extraction functions
//
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

//
// Specific formatting style checks
//
bool helper_font_text::isBoldStyled(const QString& text)
{
    return hasStyle(text, "font-weight", "bold") ||
           hasStyle(text, "font-weight", "700") ||
           text.contains("font-weight:bold") ||
           text.contains("font-weight:700");
}

bool helper_font_text::isItalicStyled(const QString& text)
{
    return hasStyle(text, "font-style", "italic") ||
           text.contains("font-style:italic");
}

bool helper_font_text::isUnderlineStyled(const QString& text)
{
    return hasStyle(text, "text-decoration", "underline") ||
           text.contains("text-decoration:underline");
}

bool helper_font_text::isStrikeOutStyled(const QString& text)
{
    return hasStyle(text, "text-decoration", "line-through") ||
           text.contains("text-decoration:line-through");
}

//
// Default font family
//
void helper_font_text::set_default_ff(QTextCursor cursor, bool enable)
{
    QTextCharFormat format;
    format.setFontWeight(enable);
    cursor.mergeCharFormat(format);
}

QFont helper_font_text::get_default_ff()
{
    QFont font("Arial", 20);
    return font;
}

//
// Bold font family with style checking
//
void helper_font_text::set_bold_ff(QTextEdit* textEdit, bool enable)
{
    QTextCursor cursor = textEdit->textCursor();
    QString selectedText = cursor.selectedText();
    QString htmlContext = textEdit->toHtml();

    if (selectedText.isEmpty()) return;

    // Check current styles
    bool hasItalic = isItalicStyled(htmlContext) || containsTag(htmlContext, "i");
    bool hasUnderline = isUnderlineStyled(htmlContext) || containsTag(htmlContext, "u");
    bool hasBold = isBoldStyled(htmlContext) || containsTag(htmlContext, "b");

    QString newHtml;

    if (enable)
    {
        // Enable bold
        if (hasItalic && hasUnderline) {
            newHtml = "<b><i><u>" + selectedText + "</b></i></u>";
        } else if (hasItalic) {
            newHtml = "<b><i>" + selectedText + "</b></i>";
        } else if (hasUnderline) {
            newHtml = "<b><u>" + selectedText + "</b></u>";
        } else {
            newHtml = "<b>" + selectedText + "</b>";
        }
    } else {
        // Disable bold
        if (hasItalic && hasUnderline) {
            newHtml = "<i><u>" + selectedText + "</i></u>";
        } else if (hasItalic) {
            newHtml = "<i>" + selectedText + "</i>";
        } else if (hasUnderline) {
            newHtml = "<u>" + selectedText + "</u>";
        } else {
            newHtml = selectedText;
        }
    }

    cursor.insertHtml(newHtml);
}

//
// Italics font family with style checking
//
void helper_font_text::set_italics_ff(QTextEdit* textEdit, bool enable)
{
    QTextCursor cursor = textEdit->textCursor();
    QString selectedText = cursor.selectedText();
    QString htmlContext = textEdit->toHtml();

    if (selectedText.isEmpty()) return;

    // Check current styles
    bool hasBold = isBoldStyled(htmlContext) || containsTag(htmlContext, "b");
    bool hasUnderline = isUnderlineStyled(htmlContext) || containsTag(htmlContext, "u");
    bool hasItalic = isItalicStyled(htmlContext) || containsTag(htmlContext, "i");

    QString newHtml;

    if (enable) {
        // Enable italic
        if (hasBold && hasUnderline) {
            newHtml = "<b><i><u>" + selectedText + "</b></i></u>";
        } else if (hasBold) {
            newHtml = "<b><i>" + selectedText + "</b></i>";
        } else if (hasUnderline) {
            newHtml = "<i><u>" + selectedText + "</i></u>";
        } else {
            newHtml = "<i>" + selectedText + "</i>";
        }
    } else {
        // Disable italic
        if (hasBold && hasUnderline) {
            newHtml = "<b><u>" + selectedText + "</b></u>";
        } else if (hasBold) {
            newHtml = "<b>" + selectedText + "</b>";
        } else if (hasUnderline) {
            newHtml = "<u>" + selectedText + "</u>";
        } else {
            newHtml = selectedText;
        }
    }

    cursor.insertHtml(newHtml);
}

//
// Underline font family with style checking
//
void helper_font_text::set_underline_ff(QTextEdit* textEdit, bool enable)
{
    QTextCursor cursor = textEdit->textCursor();
    QString selectedText = cursor.selectedText();
    QString htmlContext = textEdit->toHtml();

    if (selectedText.isEmpty()) return;

    // Check current styles
    bool hasBold = isBoldStyled(htmlContext) || containsTag(htmlContext, "b");
    bool hasItalic = isItalicStyled(htmlContext) || containsTag(htmlContext, "i");
    bool hasUnderline = isUnderlineStyled(htmlContext) || containsTag(htmlContext, "u");

    QString newHtml;

    if (enable) {
        // Enable underline
        if (hasBold && hasItalic) {
            newHtml = "<b><i><u>" + selectedText + "</b></i></u>";
        } else if (hasBold) {
            newHtml = "<b><u>" + selectedText + "</b></u>";
        } else if (hasItalic) {
            newHtml = "<i><u>" + selectedText + "</i></u>";
        } else {
            newHtml = "<u>" + selectedText + "</u>";
        }
    } else {
        // Disable underline
        if (hasBold && hasItalic) {
            newHtml = "<b><i>" + selectedText + "</b></i>";
        } else if (hasBold) {
            newHtml = "<b>" + selectedText + "</b>";
        } else if (hasItalic) {
            newHtml = "<i>" + selectedText + "</i>";
        } else {
            newHtml = selectedText;
        }
    }

    cursor.insertHtml(newHtml);
}

//
// Strike through font family
//
void helper_font_text::set_strike_through_ff(QTextCursor cursor, bool enable)
{
    QTextCharFormat format;
    format.setFontStrikeOut(enable);
    cursor.mergeCharFormat(format);
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

