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

// This code is under development

#include "rtfparser.h"
#include <QRegularExpressionMatchIterator>
#include <QHash>

QString rtfParser::simpleRtfToHtml(const QString& rtfContent)
{
    QString html;
    QHash<int, QString> colorTable;
    QHash<int, QString> highlightTable;

    // Парсим таблицу цветов
    QRegularExpression colorTableRe("\\\\colortbl\\s*;(.*?)(?=\\\\)");
    QRegularExpressionMatch colorMatch = colorTableRe.match(rtfContent);
    if (colorMatch.hasMatch()) {
        QString colors = colorMatch.captured(1);
        QRegularExpression colorRe("\\\\red(\\d+)\\\\green(\\d+)\\\\blue(\\d+)");
        QRegularExpressionMatchIterator colorIter = colorRe.globalMatch(colors);
        int colorIndex = 1;
        while (colorIter.hasNext()) {
            QRegularExpressionMatch match = colorIter.next();
            int red = match.captured(1).toInt();
            int green = match.captured(2).toInt();
            int blue = match.captured(3).toInt();
            colorTable[colorIndex++] = QString("color:rgb(%1,%2,%3);").arg(red).arg(green).arg(blue);
        }
    }

    // Парсим таблицу подсветки (фона)
    QRegularExpression highlightTableRe("\\\\highlight(\\d+)");
    QRegularExpressionMatchIterator highlightIter = highlightTableRe.globalMatch(rtfContent);
    while (highlightIter.hasNext()) {
        QRegularExpressionMatch match = highlightIter.next();
        int highlightIndex = match.captured(1).toInt();
        // Создаем стандартные цвета для подсветки
        switch (highlightIndex) {
        case 1: highlightTable[highlightIndex] = "background-color:black;"; break;
        case 2: highlightTable[highlightIndex] = "background-color:white;"; break;
        case 3: highlightTable[highlightIndex] = "background-color:red;"; break;
        case 4: highlightTable[highlightIndex] = "background-color:green;"; break;
        case 5: highlightTable[highlightIndex] = "background-color:blue;"; break;
        case 6: highlightTable[highlightIndex] = "background-color:yellow;"; break;
        case 7: highlightTable[highlightIndex] = "background-color:magenta;"; break;
        case 8: highlightTable[highlightIndex] = "background-color:cyan;"; break;
        case 9: highlightTable[highlightIndex] = "background-color:darkRed;"; break;
        case 10: highlightTable[highlightIndex] = "background-color:darkGreen;"; break;
        default: highlightTable[highlightIndex] = "background-color:gray;"; break;
        }
    }

    QStringList lines = rtfContent.split("\\par");
    QHash<QString, QString> styleStack;

    for (const QString& line : lines) {
        if (line.trimmed().isEmpty()) continue;

        QString processedLine = line;
        QString currentStyle;

        // Обработка цветов текста
        QRegularExpression cfRe("\\\\cf(\\d+)");
        QRegularExpressionMatchIterator cfIter = cfRe.globalMatch(processedLine);
        while (cfIter.hasNext()) {
            QRegularExpressionMatch match = cfIter.next();
            int colorIndex = match.captured(1).toInt();
            if (colorTable.contains(colorIndex)) {
                currentStyle += colorTable[colorIndex];
            }
        }
        processedLine.remove(cfRe);

        // Обработка подсветки (фона)
        QRegularExpression hlRe("\\\\highlight(\\d+)");
        QRegularExpressionMatchIterator hlIter = hlRe.globalMatch(processedLine);
        while (hlIter.hasNext()) {
            QRegularExpressionMatch match = hlIter.next();
            int hlIndex = match.captured(1).toInt();
            if (highlightTable.contains(hlIndex)) {
                currentStyle += highlightTable[hlIndex];
            }
        }
        processedLine.remove(hlRe);

        // Обработка размера шрифта
        QRegularExpression fsRe("\\\\fs(\\d+)");
        QRegularExpressionMatchIterator fsIter = fsRe.globalMatch(processedLine);
        while (fsIter.hasNext()) {
            QRegularExpressionMatch match = fsIter.next();
            int size = match.captured(1).toInt() / 2; // RTF uses half-points
            currentStyle += QString("font-size:%1pt;").arg(size);
        }
        processedLine.remove(fsRe);

        // Обработка шрифтов
        QRegularExpression fontRe("\\\\f(\\d+)");
        QRegularExpressionMatchIterator fontIter = fontRe.globalMatch(processedLine);
        while (fontIter.hasNext()) {
            QRegularExpressionMatch match = fontIter.next();
            int fontIndex = match.captured(1).toInt();
            currentStyle += "font-family:Arial,sans-serif;"; // Базовый шрифт
        }
        processedLine.remove(fontRe);

        // Обработка жирного текста
        bool isBold = processedLine.contains("\\b");
        if (isBold) {
            currentStyle += "font-weight:bold;";
        }
        processedLine.replace("\\b", "");
        processedLine.replace("\\b0", "");

        // Обработка курсива
        bool isItalic = processedLine.contains("\\i");
        if (isItalic) {
            currentStyle += "font-style:italic;";
        }
        processedLine.replace("\\i", "");
        processedLine.replace("\\i0", "");

        // Обработка подчеркивания
        bool isUnderline = processedLine.contains("\\ul");
        if (isUnderline) {
            currentStyle += "text-decoration:underline;";
        }
        processedLine.replace("\\ul", "");
        processedLine.replace("\\ul0", "");

        // Обработка зачеркивания
        bool isStrike = processedLine.contains("\\strike");
        if (isStrike) {
            currentStyle += "text-decoration:line-through;";
        }
        processedLine.replace("\\strike", "");
        processedLine.replace("\\strike0", "");

        // Обработка надстрочного текста
        bool isSuperScript = processedLine.contains("\\super");
        if (isSuperScript) {
            currentStyle += "vertical-align:super;";
        }
        processedLine.replace("\\super", "");
        processedLine.replace("\\nosupersub", "");

        // Обработка подстрочного текста
        bool isSubScript = processedLine.contains("\\sub");
        if (isSubScript) {
            currentStyle += "vertical-align:sub;";
        }
        processedLine.replace("\\sub", "");
        processedLine.replace("\\nosupersub", "");

        // Обработка выравнивания
        if (processedLine.contains("\\qc")) {
            currentStyle += "text-align:center;";
        } else if (processedLine.contains("\\qr")) {
            currentStyle += "text-align:right;";
        } else if (processedLine.contains("\\qj")) {
            currentStyle += "text-align:justify;";
        } else {
            currentStyle += "text-align:left;";
        }
        processedLine.replace("\\qc", "");
        processedLine.replace("\\qr", "");
        processedLine.replace("\\qj", "");
        processedLine.replace("\\ql", "");

        // Обработка Unicode символов
        QRegularExpression unicodeRe("\\\\'([0-9a-fA-F]{2})");
        QRegularExpressionMatchIterator uniIter = unicodeRe.globalMatch(processedLine);
        while (uniIter.hasNext()) {
            QRegularExpressionMatch match = uniIter.next();
            QString hex = match.captured(1);
            bool ok;
            ushort unicodeChar = hex.toUShort(&ok, 16);
            if (ok) {
                processedLine.replace("\\'" + hex, QChar(unicodeChar));
            }
        }

        // Очистка от других RTF управляющих символов
        processedLine.remove(QRegularExpression("\\\\[a-zA-Z]+[0-9]*"));
        processedLine.remove("{");
        processedLine.remove("}");
        processedLine.remove("\\~"); // Неразрывный пробел
        processedLine.remove("\\-"); // Необязательный перенос
        processedLine.remove("\\_"); // Неразрывный дефис

        // Удаление лишних пробелов
        processedLine = processedLine.simplified();

        if (!processedLine.isEmpty()) {
            if (!currentStyle.isEmpty()) {
                html += QString("<p style='%1'>%2</p>").arg(currentStyle).arg(processedLine);
            } else {
                html += QString("<p>%1</p>").arg(processedLine);
            }
        }
    }

    return QString("<html><body style='font-family:Arial,sans-serif;font-size:12pt;'>%1</body></html>").arg(html);
}

// Альтернативная версия с построчным парсингом
QString rtfParser::advancedRtfToHtml(const QString& rtfContent)
{
    QString html;
    QHash<int, QString> colorTable;

    // Парсим таблицу цветов более точно
    QRegularExpression colorTableRe("\\\\colortbl\\s*;(.*?)(?=\\\\[a-zA-Z]|$)");
    QRegularExpressionMatch colorMatch = colorTableRe.match(rtfContent);
    if (colorMatch.hasMatch()) {
        QString colorsStr = colorMatch.captured(1);
        QStringList colors = colorsStr.split(";", Qt::SkipEmptyParts);

        for (int i = 0; i < colors.size(); ++i) {
            if (colors[i].contains("\\red")) {
                QRegularExpression colorRe("\\\\red(\\d+)\\\\green(\\d+)\\\\blue(\\d+)");
                QRegularExpressionMatch match = colorRe.match(colors[i]);
                if (match.hasMatch()) {
                    int red = match.captured(1).toInt();
                    int green = match.captured(2).toInt();
                    int blue = match.captured(3).toInt();
                    colorTable[i + 1] = QString("rgb(%1,%2,%3)").arg(red).arg(green).arg(blue);
                }
            }
        }
    }

    // Разбиваем на токены
    QStringList tokens;
    QString currentToken;
    bool inControl = false;
    bool inGroup = false;

    for (int i = 0; i < rtfContent.length(); ++i) {
        QChar c = rtfContent[i];

        if (c == '\\') {
            if (!currentToken.isEmpty()) tokens.append(currentToken);
            currentToken = "\\";
            inControl = true;
        } else if (c == '{') {
            if (!currentToken.isEmpty()) tokens.append(currentToken);
            tokens.append("{");
            currentToken.clear();
            inGroup = true;
        } else if (c == '}') {
            if (!currentToken.isEmpty()) tokens.append(currentToken);
            tokens.append("}");
            currentToken.clear();
            inGroup = false;
        } else if (c == ' ' && inControl) {
            tokens.append(currentToken);
            currentToken.clear();
            inControl = false;
        } else {
            currentToken += c;
        }
    }

    if (!currentToken.isEmpty()) tokens.append(currentToken);

    // Парсим токены
    QString currentText;
    QString currentStyle;
    int currentColor = 0;
    int currentHighlight = 0;
    bool currentBold = false;
    bool currentItalic = false;
    bool currentUnderline = false;

    for (const QString& token : tokens) {
        if (token.startsWith("\\")) {
            // Обработка управляющих слов
            if (token.startsWith("\\cf")) {
                currentColor = token.mid(3).toInt();
            } else if (token.startsWith("\\highlight")) {
                currentHighlight = token.mid(10).toInt();
            } else if (token == "\\b") {
                currentBold = true;
            } else if (token == "\\b0") {
                currentBold = false;
            } else if (token == "\\i") {
                currentItalic = true;
            } else if (token == "\\i0") {
                currentItalic = false;
            } else if (token == "\\ul") {
                currentUnderline = true;
            } else if (token == "\\ul0") {
                currentUnderline = false;
            }
        } else if (token != "{" && token != "}") {
            currentText += token;
        }

        // Когда встречаем параграф или конец группы
        if (token == "\\par" || token == "}") {
            if (!currentText.isEmpty()) {
                QString style;
                if (currentColor > 0 && colorTable.contains(currentColor)) {
                    style += QString("color:%1;").arg(colorTable[currentColor]);
                }
                if (currentHighlight > 0) {
                    style += QString("background-color:%1;").arg(getHighlightColor(currentHighlight));
                }
                if (currentBold) style += "font-weight:bold;";
                if (currentItalic) style += "font-style:italic;";
                if (currentUnderline) style += "text-decoration:underline;";

                if (!style.isEmpty()) {
                    html += QString("<p style='%1'>%2</p>").arg(style).arg(currentText);
                } else {
                    html += QString("<p>%1</p>").arg(currentText);
                }

                currentText.clear();
            }
        }
    }

    return QString("<html><body>%1</body></html>").arg(html);
}

QString rtfParser::getHighlightColor(int index)
{
    switch (index) {
    case 1: return "black";
    case 2: return "white";
    case 3: return "red";
    case 4: return "green";
    case 5: return "blue";
    case 6: return "yellow";
    case 7: return "magenta";
    case 8: return "cyan";
    case 9: return "darkred";
    case 10: return "darkgreen";
    case 11: return "darkblue";
    case 12: return "darkyellow";
    case 13: return "purple";
    case 14: return "orange";
    case 15: return "pink";
    case 16: return "brown";
    case 17: return "gray";
    case 18: return "lightgray";
    case 19: return "darkgray";
    case 20: return "lightblue";
    default: return index % 2 == 0 ? "lightyellow" : "lightcyan";
    }
}
