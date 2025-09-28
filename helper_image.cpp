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
#include "helper_image.h"

// Insert Image From File
bool helper_image::insertImageFromFile(NotepadPlus *notepad, QTextCursor cursor)
{
    QString fileImageName = QFileDialog::getOpenFileName(notepad, "Open the file", QString(), "Image files (*.png *.jpg *.jpeg *.bmp);; Gif (*.gif)");

    QTextImageFormat imageFormat;
    QImage image(fileImageName);

    //
    // check image
    //
    if (image.isNull())
    {
        QMessageBox::warning(notepad, "Image", "Error: 404 (image not found)");
        return false;
    }

    if (!isImageFormatSupport(fileImageName))
    {
        QMessageBox::warning(notepad, "Image", "The image format is not supported!");
        return false;
    }
    //
    // End check Image
    //

    imageFormat.setName(fileImageName);

    // dialog choose size image
    bool ok;
    int maxWidth = 1000;

    int selectedWidth = QInputDialog::getInt(notepad, "Image Size",
                                            "Image Size Image width (pixels):",
                                             qMin(image.width(), maxWidth),
                                             10, 2000, 1, &ok);

    // If the user deselects the image size, code will set the default image size.
    if (!ok)
    {
        if (image.width() > maxWidth)
        {
            double ratio = (double) maxWidth / image.width();
            imageFormat.setWidth(500);
            imageFormat.setHeight(image.height() * ratio);
            return true;
        }
        cursor.insertImage(imageFormat);
        return true;
    }

    if (selectedWidth > 0)
    {
        double ratio = (double) selectedWidth / image.width();
        int newHeight = image.height() * ratio;

        imageFormat.setWidth(selectedWidth);
        imageFormat.setHeight(newHeight);
    }

    cursor.insertImage(imageFormat);
    return true;
}

//
// insert image
//
bool helper_image::insertImage(NotepadPlus *notepad, QTextCursor cursor, QString pathImage)
{
    QTextImageFormat imageFormat;
    QImage image(pathImage);
    //
    // check image
    //

    if (!isImageFormatSupport(pathImage))
    {
        QMessageBox::warning(notepad, "Image", "The image format is not supported!");
        return false;
    }
    //
    // End check Image
    //

    imageFormat.setName(pathImage);

    // dialog choose size image
    bool ok;
    int maxWidth = 1000;

    int selectedWidth = QInputDialog::getInt(notepad, "Image Size",
                                             "Image Size Image width (pixels):",
                                             qMin(image.width(), maxWidth),
                                             10, 2000, 1, &ok);

    // If the user deselects the image size, code will set the default image size.
    if (!ok)
    {
        if (image.width() > maxWidth)
        {
            double ratio = (double) maxWidth / image.width();
            imageFormat.setWidth(500);
            imageFormat.setHeight(image.height() * ratio);
            return true;
        }
        cursor.insertImage(imageFormat);
        return true;
    }

    if (selectedWidth > 0)
    {
        double ratio = (double) selectedWidth / image.width();
        int newHeight = image.height() * ratio;

        imageFormat.setWidth(selectedWidth);
        imageFormat.setHeight(newHeight);
    }

    cursor.insertImage(imageFormat);
    return true;
}

//
// check for image format
//
bool helper_image::isImageFormatSupport(QString fileNameImage)
{
    return (fileNameImage.endsWith(".png") || fileNameImage.endsWith(".jpg") || fileNameImage.endsWith(".jpeg")
            || fileNameImage.endsWith(".bmp") || fileNameImage.endsWith(".gif"));
}

