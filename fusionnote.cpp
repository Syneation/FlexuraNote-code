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

#include "fusionnote.h"
#include "./ui_fusionnote.h"

#include "helper_status_bar.h"
#include "helper_file.h"
#include "helper_font_text.h"
#include "helper_color_text.h"
#include "helper_theme.h"
#include "helper_image.h"
#include "rtfparser.h"

NotepadPlus::NotepadPlus(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotepadPlus)
    , infoWindow(nullptr)
    , findWindow(nullptr)
    , replaceWindow(nullptr)
    , searchHighlights()
{
    ui->setupUi(this);

    //
    // for find
    //

    if (!findWindow)
    {
        findWindow = new FindWindow(this);
        connect(findWindow, &FindWindow::findRequested, this, &NotepadPlus::handleFindRequest);
        connect(findWindow, &FindWindow::destroyed, this, &NotepadPlus::onFindWindowClosed);
    }
    //
    // End for find
    //

    //
    // for find
    //
    if (!replaceWindow)
    {
        replaceWindow = new ReplaceWindow(this);
        connect(replaceWindow, &ReplaceWindow::findRequested_replace, this, &NotepadPlus::handleFindRequest_replace);
        connect(replaceWindow, &ReplaceWindow::replace_text, this, &NotepadPlus::handleReplace_text);
        connect(replaceWindow, &ReplaceWindow::replace_all_text, this, &NotepadPlus::handlerRepalce_all_text);
        connect(replaceWindow, &ReplaceWindow::destroyed, this, &NotepadPlus::onReplaceWindowClosed);
    }
    //
    // End for find
    //


    setAcceptDrops(true); // For the main window
    ui->textEditor->setAcceptDrops(false); // For a text editor
    ui->textEditor->viewport()->setAcceptDrops(false); // For the viewport text editor

    ui->textEditor->installEventFilter(this);
    ui->textEditor->viewport()->installEventFilter(this);
    ui->textEditor->setLineWrapMode(QTextEdit::NoWrap);
    ui->actionLine_Break->setChecked(false);
    isLineWrapEnabled = false;

    //
    // status bar
    //
    ui->statusBar->addPermanentWidget(ui->label_file_path, 5);
    ui->statusBar->addPermanentWidget(ui->label_notifications, 6);
    ui->statusBar->addPermanentWidget(ui->label_len_lines, 4);
    ui->statusBar->addPermanentWidget(ui->label_ln_col_pos, 5);
    ui->statusBar->addPermanentWidget(ui->label_zoom, 3);
    ui->statusBar->addPermanentWidget(ui->label_encoding, 2);
    isStatusBarEnabled = true;
    //
    // End status bar
    //

    //
    // auto save timer
    //
    autoSaveTimer = new QTimer(this);  

    //
    // connecting signals to update the cursor position
    //
    connect(ui->textEditor, &QTextEdit::cursorPositionChanged, this, &NotepadPlus::updateCursorStatus);

    connect(autoSaveTimer, &QTimer::timeout, this, &NotepadPlus::autoSave);
    connect(ui->actionGit_Hub, &QAction::triggered, this, &NotepadPlus::on_actionGit_Hub_triggered);
    connect(ui->actionAbout_Program, &QAction::triggered, this, &NotepadPlus::on_actionAbout_Program_triggered);

    this->setCentralWidget(ui->textEditor);
}

NotepadPlus::~NotepadPlus()
{
    if (autoSaveTimer->isActive())
        autoSaveTimer->stop();

    ui->textEditor->removeEventFilter(this); // Removing the event filter

    delete ui;
}

//
// check close main window
//
void NotepadPlus::closeEvent(QCloseEvent *event)
{
    if (isAutoSaveEnabled)
        this->close();

    else if (m_statusBar.notifications == "Save file successfully" ||
             m_statusBar.notifications == QString("Save file successfully (%1)").arg(m_statusBar.tmp_count_save_file))
        this->close();

    else if (ui->textEditor->toPlainText().isEmpty())
        this->close();

    else
        switch (QMessageBox::question(this, tr("Exiting the program"), tr("Save the file before closing?"),
                                      QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            helper_file::save_file(this, currentFile);
            break;
        case QMessageBox::No:
            this->close();
            break;
        default:
            event->ignore();
            break;
        }
}

//
// for drag and drop files
//
void NotepadPlus::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
        helper_status::set_notifications(this, m_statusBar.notifications, "Drag detected");
    }
    else
        event->ignore();


}

void NotepadPlus::dropEvent(QDropEvent *event)
{
    QString filePath;

    if (event->mimeData()->hasUrls())
    {
        const QList<QUrl> urls = event->mimeData()->urls();
        for (const QUrl &url : urls)
        {
            if (url.isLocalFile())
            {
                QFont defaultFont = QFont("Arial", 20);
                QTextCharFormat format;
                format.setFont(defaultFont);

                QTextCursor cursor = ui->textEditor->textCursor();
                cursor.select(QTextCursor::Document);
                cursor.mergeCharFormat(format);

                ui->textEditor->setCurrentFont(defaultFont);
                ui->textEditor->setFont(defaultFont);

                filePath = url.toLocalFile();

                if (helper_image::isImageFormatSupport(filePath))
                {
                    if (helper_image::insertImage(this, cursor, filePath))
                    {
                        helper_status::set_notifications(this, m_statusBar.notifications, "Image inserted successfully!");
                        m_statusBar.path = "";
                        return;
                    }
                    else
                    {
                        helper_status::set_notifications(this, m_statusBar.notifications, "ERROR: Image inserted FAILED!");
                        m_statusBar.path = "";
                        return;
                    }

                }

                if (helper_file::open_file(this, m_statusBar.path, filePath, ui->textEditor))
                {

                    helper_status::set_notifications(this, m_statusBar.notifications, "Open file success");
                    setWindowTitle(m_statusBar.path + " - FusionNote");
                    helper_status::set_encoding(this, helper_file::get_encoding(m_statusBar.path));
                    helper_status::set_path(this, m_statusBar.path, m_statusBar.path);
                }
                break; // read only 1 file
            }
        }
        event->acceptProposedAction();
        helper_status::set_encoding(this, helper_file::get_encoding(filePath));

    }
    else
        event->ignore();

}


//
// for mouse zoom
//
void NotepadPlus::zoomIn()
{
    if (m_currentZoom >= 9.9)
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "the maximum has been reached!");
        QMessageBox::information(this, "zoom", "the maximum has been reached!");
        return;
    }

    m_currentZoom += 0.1; // increase for 10%
    ui->textEditor->zoomIn(2);
    updateZoom();
}

void NotepadPlus::zoomOut()
{
    if (m_currentZoom <= 0.1)
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "the maximum has been reached!");
        QMessageBox::information(this, "zoom", "the maximum has been reached!");
        return;
    }
    m_currentZoom -= 0.1; // decrease for 10%
    ui->textEditor->zoomOut(2);
    updateZoom();
}

void NotepadPlus::zoomReset()
{

    if (m_currentZoom == 1.0)
    {
        // already 100%
        QMessageBox::information(this, "zoom", "why?");
        helper_status::set_notifications(this, m_statusBar.notifications, "Zoom is already at 100%");
        return;
    }
    else if (m_currentZoom > 1.0)
    {
        float tmp = static_cast<float>(m_currentZoom);

        while (m_currentZoom >= 1.0)
        {
            if (m_currentZoom == 1.0 || m_currentZoom == 1.0000000000000009)
                break;


            m_currentZoom -= 0.1;
            ui->textEditor->zoomOut(2);
        }
        helper_status::set_notifications(this, m_statusBar.notifications, "Zoom reset to 100%");
    }
    else if (m_currentZoom < 1.0)
    {
        while (m_currentZoom <= 1.0)
        {
            m_currentZoom += 0.1;
            ui->textEditor->zoomIn(2);
        }
        helper_status::set_notifications(this, m_statusBar.notifications, "Zoom reset to 100%");
    }

    updateZoom();
}

bool NotepadPlus::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->textEditor && event->type() == QEvent::Wheel)
    {
        QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);

        if (wheelEvent->modifiers() & Qt::ControlModifier)
        {
            if (wheelEvent->angleDelta().y() > 0)
                zoomIn(); // Zoom in (Ctrl + up wheel)
            else
                zoomOut(); // Move away (Ctrl + down wheel)

            return true;
        }
    }

    // check click on image
    if (obj == ui->textEditor->viewport() && event->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        QTextImageFormat imageFormatLocal;
        if (is_Image_At_Position(mouseEvent->pos(), imageFormatLocal))
        {
            resizeImage(imageFormatLocal);
            return true;
        }
    }

    if (event->type() == QEvent::DragEnter || event->type() == QEvent::DragMove || event->type() == QEvent::Drop)
        return false;

    // All other events are handled as standard
    return QMainWindow::eventFilter(obj, event);
}

bool NotepadPlus::is_Image_At_Position(const QPoint &pos, QTextImageFormat &imageFormat)
{
    QTextCursor cursor = ui->textEditor->cursorForPosition(pos);

    // Checking the current position and adjacent characters
    for (int offset = -2; offset <= 2; offset++) {
        QTextCursor testCursor = cursor;
        if (testCursor.movePosition(QTextCursor::NextCharacter, QTextCursor::MoveAnchor, offset)) {
            QTextCharFormat charFormat = testCursor.charFormat();
            if (charFormat.isImageFormat()) {
                imageFormat = charFormat.toImageFormat();
                return true;
            }
        }
    }

    return false;
}

void NotepadPlus::resizeImage(QTextImageFormat &imageFormat)
{
    bool ok;
    int currentWidth = imageFormat.width();
    int newWidth = QInputDialog::getInt(this,
                                        "Changing the image size",
                                        "Enter a new width (pixels):",
                                        currentWidth,
                                        10, 2000, 1, &ok);

    if (ok && newWidth > 0)
    {
        // We keep the proportions
        int originalWidth = imageFormat.width();
        int originalHeight = imageFormat.height();
        double ratio = static_cast<double>(originalHeight) / originalWidth;
        int newHeight = static_cast<int>(newWidth * ratio);

        // Creating a new format with updated dimensions
        QTextImageFormat newFormat;
        newFormat.setName(imageFormat.name());
        newFormat.setWidth(newWidth);
        newFormat.setHeight(newHeight);

        // We find and replace all occurrences of this image
        QTextCursor cursor(ui->textEditor->document());
        cursor.beginEditBlock(); // Starting a group of changes

        while (!cursor.atEnd())
        {
            cursor.movePosition(QTextCursor::NextCharacter);
            QTextCharFormat format = cursor.charFormat();

            if (format.isImageFormat())
            {
                QTextImageFormat currentImageFormat = format.toImageFormat();
                if (currentImageFormat.name() == imageFormat.name())
                {
                    // Save pos cursor
                    int position = cursor.position();

                    // Deleting the old image symbol
                    cursor.deletePreviousChar();

                    // Inserting a new image with the updated size
                    cursor.insertImage(newFormat);

                    // Moving the cursor back to the correct position
                    cursor.setPosition(position);
                }
            }
        }

        cursor.endEditBlock(); // Завершаем группу изменений

        helper_status::set_notifications(this, m_statusBar.notifications, "Completing the group of changes");
    }
}

//
// for simple set text in status bar
//
void NotepadPlus::updateFilePath(const QString &path)
{
    if (ui) ui->label_file_path->setText(path);
}
void NotepadPlus::updateNotification(const QString &path)
{
    if (ui) ui->label_notifications->setText(path);
}
void NotepadPlus::updateLenLines(const QString &LenLines)
{
    if (ui) ui->label_len_lines->setText(LenLines);
}
void NotepadPlus::updateLnColPos(const QString &LnColPos)
{
    if (ui) ui->label_ln_col_pos->setText(LnColPos);
}
void NotepadPlus::updateZoom()
{
    int zoomPercent = qRound(m_currentZoom * 100);
    ui->label_zoom->setText(QString("zoom: %1%").arg(zoomPercent));
}
void NotepadPlus::updateEncoding(const QString& encoding)
{
    if (ui) ui->label_encoding->setText(encoding);
}


//
// Save
//
void NotepadPlus::updateSaveText(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        helper_status::set_notifications(this, m_statusBar.notifications, "Cannot save file");
        return;
    }

    QString tmp_notifications = QString("Save file successfully (%1)").arg(m_statusBar.tmp_count_save_file);

    //
    // check for text "Save file successfully" if we have then output "Save file successfully (count save)"
    // else "Save file successfully"
    //
    if (m_statusBar.notifications == "Save file successfully" ||
        m_statusBar.notifications == tmp_notifications)
    {
        m_statusBar.tmp_count_save_file++;
        helper_status::set_notifications(this, m_statusBar.notifications, QString("Save file successfully (%1)").arg(m_statusBar.tmp_count_save_file));
        setWindowTitle(fileName + " - FusionNote");
        QTextStream out(&file);
        QString text = ui->textEditor->toPlainText();
        out << text;
        file.close();
        helper_status::set_encoding(this, helper_file::get_encoding(m_statusBar.path));
    }
    else
    {
        m_statusBar.tmp_count_save_file = 0;
        helper_status::set_notifications(this, m_statusBar.notifications, "Save file successfully");
        setWindowTitle(fileName + " - FusionNote");
        m_statusBar.path = fileName;
        if (fileName.endsWith(".html"))
        {
            QTextStream out(&file);
            out << ui->textEditor->toHtml();
            file.close();
        }
        else
        {
            QTextStream out(&file);
            QString text = ui->textEditor->toPlainText();
            out << text;
            file.close();
        }
        helper_status::set_path(this, m_statusBar.path, m_statusBar.path);
    }

}
//
// Save As
//
void NotepadPlus::updateSaveAsText(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "Cannot save file");
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName + " - FusionNote");
    m_statusBar.path = fileName;
    helper_status::set_notifications(this, m_statusBar.notifications, "save as ... file successfully");

    if (fileName.endsWith(".html"))
    {
        QTextStream out(&file);
        out << ui->textEditor->toHtml();
        file.close();
    }
    else
    {
        QTextStream out(&file);
        QString text = ui->textEditor->toPlainText();
        out >> text;
        file.close();
    }

    helper_status::set_encoding(this, helper_file::get_encoding(m_statusBar.path));
    helper_status::set_path(this, m_statusBar.path, m_statusBar.path);
}

//
// print
//
void NotepadPlus::print_text()
{
    if (ui->textEditor->document()->isEmpty())
    {
        QMessageBox::information(this, "Print", "There is no text to print");
        helper_status::set_notifications(this, m_statusBar.notifications, "There is no text to print");
        return;
    }

    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle("Printing a document");

    if (printDialog.exec() == QDialog::Accepted)
    {
        try
        {
            ui->textEditor->print(&printer);
        } catch (...)
        {
            QMessageBox::critical(this, "Error", "Couldn't print");
        }
        helper_status::set_notifications(this, m_statusBar.notifications, "printing successfully");
    }
}

//
// Auto Save
//

void NotepadPlus::autoSave()
{
    if (currentFile.isEmpty())
    {
        QMessageBox::information(this, "autosave", "please open or save file for autosave!");
        helper_status::set_notifications(this, m_statusBar.notifications, "please open or save file for autosave!");
        autoSaveTimer->stop();

        if (ui->actionAutosave->isChecked())
        {
            ui->actionAutosave->setChecked(false);
            isAutoSaveEnabled = false;
        }

        return;
    }


    if (ui->textEditor->document()->isModified())
    {
        // if the text has been changed, save
        helper_file::save_file(this, currentFile);
        ui->textEditor->document()->setModified(false);
    }
}

//
// End helper
//

void NotepadPlus::on_NotepadPlus_customContextMenuRequested(const QPoint &pos)
{

}

//
//updating Ln Col Pos length and lines ( I don't know why i need 2 lines :] )
//
void NotepadPlus::updateCursorStatus()
{
    QTextCursor cursor = ui->textEditor->textCursor();
    int pos = cursor.position();
    QTextBlock block = ui->textEditor->document()->findBlock(pos);

    int line = block.blockNumber() + 1;
    int column = cursor.positionInBlock();
    int totalLines = ui->textEditor->document()->blockCount();
    int totalTextLength = ui->textEditor->toPlainText().length();

    helper_status::set_len_lines(this, totalTextLength, totalLines);
    helper_status::set_ln_col_pos(this, line, column, pos);

}

//
// The File tab
//

//
// open file (not icon!)
//
void NotepadPlus::on_actionOpen_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();
    bool check_open_file = helper_file::open_file(this, m_statusBar.path, ui->textEditor);

    if (check_open_file)
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "Open file success");
        setWindowTitle(m_statusBar.path + " - FusionNote");
        helper_status::set_encoding(this, helper_file::get_encoding(m_statusBar.path));
        helper_status::set_path(this, m_statusBar.path, m_statusBar.path);
    }
    else
        helper_status::set_notifications(this, m_statusBar.notifications, "Cannot open file");


}

//
// open file Icon
//
void NotepadPlus::on_actionopenFileIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();
    bool check_open_file = helper_file::open_file(this, m_statusBar.path, ui->textEditor);

    if (check_open_file)
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "Open file success");
        setWindowTitle(m_statusBar.path + " - FusionNote");
        helper_status::set_encoding(this, helper_file::get_encoding(m_statusBar.path));
        helper_status::set_path(this, m_statusBar.path, m_statusBar.path);
    }
    else
        helper_status::set_notifications(this, m_statusBar.notifications, "Cannot open file");


}
//
// End open file
//

//
// new File Icon
//
void NotepadPlus::on_actionnewFileIcon_triggered()
{
    currentFile.clear();
    ui->textEditor->setText(QString());
    setWindowTitle("FusionNote");
    helper_status::set_path(this, m_statusBar.path, "No File");
    helper_status::set_encoding(this, "None");
    helper_status::set_notifications(this, m_statusBar.notifications, "The new file created success");
}

//
// new File (not icon!)
//
void NotepadPlus::on_actionNew_File_triggered()
{
    currentFile.clear();
    ui->textEditor->setText(QString());
    setWindowTitle("FusionNote");
    helper_status::set_path(this, m_statusBar.path, "No File");
    helper_status::set_encoding(this, "None");
    helper_status::set_notifications(this, m_statusBar.notifications, "The new file created success");
}

//
// End new file
//



//
// save file Icon
//
void NotepadPlus::on_actionsaveIcon_triggered()
{
    helper_file::save_file(this, currentFile);
    helper_status::set_encoding(this, helper_file::get_encoding(currentFile));
}

//
// save file (not icon!)
//
void NotepadPlus::on_actionSave_triggered()
{
    helper_file::save_file(this, currentFile);
    helper_status::set_encoding(this, helper_file::get_encoding(currentFile));
}

//
// Save as ... (not icon)
//
void NotepadPlus::on_actionSave_As_triggered()
{
    helper_file::save_as_file(this, currentFile);
    helper_status::set_encoding(this, helper_file::get_encoding(currentFile));
}
//
// Save as ... (Icon)
//
void NotepadPlus::on_actionSaveAsIcon_triggered()
{
    helper_file::save_as_file(this, currentFile);
    helper_status::set_encoding(this, helper_file::get_encoding(currentFile));
}

//
// Print
//
// not icon
void NotepadPlus::on_actionPrint_triggered()
{
    print_text();
}
// icon
void NotepadPlus::on_actionprintIcon_triggered()
{
    print_text();
}

//
// End print
//

//
// Exit (icon)
//
void NotepadPlus::on_actionExit_triggered()
{
    QWidget::close();
}
//
// End Exit
//

//
// The Edit tab
//

//
// back (Ctrl+Z)
//
// not icon
void NotepadPlus::on_actionCancel_triggered()
{
    ui->textEditor->undo();
    helper_status::set_notifications(this, m_statusBar.notifications, "text canceled");

}
// icon
void NotepadPlus::on_actionbackIcon_triggered()
{
    ui->textEditor->undo();
    helper_status::set_notifications(this, m_statusBar.notifications, "text canceled");
}

//
// End undo
//

//
// cut
//
// not icon
void NotepadPlus::on_actionCut_triggered()
{
    ui->textEditor->cut();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is cut out");
}
// icon
void NotepadPlus::on_actioncutIcon_triggered()
{
    ui->textEditor->cut();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is cut out");
}
//
// End cut
//

//
// Find
//
// icon
void NotepadPlus::on_actionfindIcon_triggered()
{
    if (!findWindow)
    {
        findWindow = new FindWindow(this);
        connect(findWindow, &FindWindow::destroyed, this, &NotepadPlus::onFindWindowClosed); // for close find window
    }

    findWindow->show();
    findWindow->raise();
    findWindow->activateWindow();
}

// not icon
void NotepadPlus::on_actionFind_triggered()
{
    if (!findWindow)
    {
        findWindow = new FindWindow(this);
        connect(findWindow, &FindWindow::destroyed, this, &NotepadPlus::onFindWindowClosed); // for close find window
    }

    findWindow->show();
    findWindow->raise();
    findWindow->activateWindow();
}

void NotepadPlus::handleFindRequest(const FindWindow::find_work &work)
{
    QPalette palette = ui->textEditor->palette();
    palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
    palette.setColor(QPalette::HighlightedText, Qt::white);
    ui->textEditor->setPalette(palette);

    QTextDocument::FindFlags flags;
    if (work.check_case_sensitive)
        flags |= QTextDocument::FindCaseSensitively;
    if (work.check_whole_word)
        flags |= QTextDocument::FindWholeWords;
    if (work.check_find_top)
        flags |= QTextDocument::FindBackward;

    // Clear previous selection
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.clearSelection();

    // Count all matches first
    int matchCount = 0;
    QTextCursor countCursor(ui->textEditor->document());
    while (!countCursor.isNull() && !countCursor.atEnd())
    {
        countCursor = ui->textEditor->document()->find(work.text_find, countCursor, flags);
        if (!countCursor.isNull())
        {
            matchCount++;
            countCursor.movePosition(QTextCursor::NextCharacter);
        }
    }

    // Perform the search
    bool found = ui->textEditor->find(work.text_find, flags);

    if (!found)
    {
        // If not found, start search from beginning/end
        cursor = ui->textEditor->textCursor();

        if (work.check_find_top)
            cursor.movePosition(QTextCursor::End);
        else
            cursor.movePosition(QTextCursor::Start);

        ui->textEditor->setTextCursor(cursor);

        found = ui->textEditor->find(work.text_find, flags);
    }

    if (found)
        helper_status::set_notifications(this, m_statusBar.notifications,
                                         QString("Text found (%1 matches total)").arg(matchCount));
    else
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "Text not found");
        QMessageBox::information(this, "Search", "Text not found!");
    }
}




void NotepadPlus::onFindWindowClosed()
{
    findWindow = nullptr;
}
//
// End Find
//

//
// Replace
//
// not icon
void NotepadPlus::on_actionReplace_triggered()
{
    if (!replaceWindow)
    {
        replaceWindow = new ReplaceWindow(this);
        connect(replaceWindow, &ReplaceWindow::destroyed, this, &NotepadPlus::onReplaceWindowClosed); // for close replace window
    }

    replaceWindow->show();
    replaceWindow->raise();
    replaceWindow->activateWindow();
}

// icon
void NotepadPlus::on_actionreplaceIcon_triggered()
{
    if (!replaceWindow)
    {
        replaceWindow = new ReplaceWindow(this);
        connect(replaceWindow, &ReplaceWindow::destroyed, this, &NotepadPlus::onReplaceWindowClosed); // for close replace window
    }

    replaceWindow->show();
    replaceWindow->raise();
    replaceWindow->activateWindow();
}

void NotepadPlus::onReplaceWindowClosed()
{
    replaceWindow = nullptr;
}

void NotepadPlus::handleFindRequest_replace(const ReplaceWindow::find_replace_work &work)
{
    QPalette palette = ui->textEditor->palette();
    palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
    palette.setColor(QPalette::HighlightedText, Qt::white);
    ui->textEditor->setPalette(palette);

    QTextDocument::FindFlags flags;
    if (work.check_case_sensitive)
        flags |= QTextDocument::FindCaseSensitively;
    if (work.check_whole_word)
        flags |= QTextDocument::FindWholeWords;

    // Clear previous selection
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.clearSelection();

    // Count all matches first
    int matchCount = 0;
    QTextCursor countCursor(ui->textEditor->document());
    while (!countCursor.isNull() && !countCursor.atEnd())
    {
        countCursor = ui->textEditor->document()->find(work.text_find, countCursor, flags);
        if (!countCursor.isNull())
        {
            matchCount++;
            countCursor.movePosition(QTextCursor::NextCharacter);
        }
    }

    // Perform the search
    bool found = ui->textEditor->find(work.text_find, flags);

    if (!found)
    {
        // If not found, start search from beginning/end
        cursor = ui->textEditor->textCursor();

        if (work.check_find_top)
            cursor.movePosition(QTextCursor::End);
        else
            cursor.movePosition(QTextCursor::Start);

        ui->textEditor->setTextCursor(cursor);

        found = ui->textEditor->find(work.text_find, flags);
    }

    if (found)
        helper_status::set_notifications(this, m_statusBar.notifications,
                                         QString("Text found (%1 matches total)").arg(matchCount));
    else
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "Text not found");
        QMessageBox::information(this, "Search", "Text not found!");
    }
}

// replace text
void NotepadPlus::handleReplace_text(const ReplaceWindow::find_replace_work &work ,const QString& new_text)
{
    QPalette palette = ui->textEditor->palette();
    palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
    palette.setColor(QPalette::HighlightedText, Qt::white);
    ui->textEditor->setPalette(palette);

    QTextDocument::FindFlags flags;
    if (work.check_case_sensitive)
        flags |= QTextDocument::FindCaseSensitively;
    if (work.check_whole_word)
        flags |= QTextDocument::FindWholeWords;


    // Clear previous selection
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.clearSelection();

    // Perform the search
    bool found = ui->textEditor->find(work.text_find, flags);

    if (!found)
    {
        // If not found, start search from beginning/end
        cursor = ui->textEditor->textCursor();

        if (work.check_find_top)
            cursor.movePosition(QTextCursor::End);
        else
            cursor.movePosition(QTextCursor::Start);

        ui->textEditor->setTextCursor(cursor);

        found = ui->textEditor->find(work.text_find, flags);
    }

    if (found)
    {

        QTextCursor foundCursor = ui->textEditor->textCursor();

        foundCursor.insertText(new_text);
        helper_status::set_notifications(this, m_statusBar.notifications, "the word or letter has been changed!");
    }
    else
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "Text not found");
        QMessageBox::information(this, "Search", "Text not found!");
    }
}

// replace all text
void NotepadPlus::handlerRepalce_all_text(const ReplaceWindow::find_replace_work &work, const QString& new_text)
{
    QPalette palette = ui->textEditor->palette();
    palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
    palette.setColor(QPalette::HighlightedText, Qt::white);
    ui->textEditor->setPalette(palette);

    QTextDocument::FindFlags flags;
    if (work.check_case_sensitive)
        flags |= QTextDocument::FindCaseSensitively;
    if (work.check_whole_word)
        flags |= QTextDocument::FindWholeWords;

    // Clear previous selection
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.clearSelection();

    // Count all matches first
    int matchCount = 0;
    QTextCursor countCursor(ui->textEditor->document());
    while (!countCursor.isNull() && !countCursor.atEnd())
    {
        countCursor = ui->textEditor->document()->find(work.text_find, countCursor, flags);
        if (!countCursor.isNull())
        {
            matchCount++;
            countCursor.movePosition(QTextCursor::NextCharacter);
        }

        bool found = ui->textEditor->find(work.text_find, flags);

        if (!found)
        {
            cursor = ui->textEditor->textCursor();

            if (work.check_find_top)
                cursor.movePosition(QTextCursor::End);
            else
                cursor.movePosition(QTextCursor::Start);

            ui->textEditor->setTextCursor(cursor);

            found = ui->textEditor->find(work.text_find, flags);
        }
        if (found)
        {
            QTextCursor foundCursor = ui->textEditor->textCursor();
            foundCursor.insertText(new_text);
        }
        helper_status::set_notifications(this, m_statusBar.notifications, QString("(%1) matches changed").arg(matchCount));
    }
}

//
// End Replace
//

//
// copy
//
// not icon
void NotepadPlus::on_actionCopy_triggered()
{
    ui->textEditor->copy();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is copied");
}

// icon
void NotepadPlus::on_actioncopy_triggered()
{
    ui->textEditor->copy();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is copied");
}
//
// End Copy
//

//
// Paste
//
// not icon
void NotepadPlus::on_actionPaste_triggered()
{
    ui->textEditor->paste();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is paste");
}
// icon
void NotepadPlus::on_actionpasteIcon_triggered()
{
    ui->textEditor->paste();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is paste");
}
//
// End Paste
//

//
// Add Image (icon)
//
void NotepadPlus::on_actionAddImage_triggered()
{
    QTextCursor tmpCursor = ui->textEditor->textCursor();
    helper_image::insertImageFromFile(this, tmpCursor);
}
//
// End Add Image (icon)
//


//
// Select All
//
void NotepadPlus::on_actionSelect_All_triggered()
{
    ui->textEditor->selectAll();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is fully highlighted");
}
//
// End Select All
//

//
// Delete All
//
void NotepadPlus::on_actionDelete_All_triggered()
{
    ui->textEditor->clear();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text has been completely deleted");
}
//
// End Delete All
//

//
// the copyright, registered trademark and trademark marks
//
// copyright
void NotepadPlus::on_actionCopyright_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.insertText("©");

}
// registered trademark
void NotepadPlus::on_actionTrademark_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.insertText("™");
}
// registered trademark
void NotepadPlus::on_actionTrademark_2_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();
    cursor.insertText("®");
}
//
// End the copyright, registered trademark and trademark marks
//

//
// AutoSave
//

void NotepadPlus::on_actionAutosave_triggered()
{
    isAutoSaveEnabled = !isAutoSaveEnabled;

    if (isAutoSaveEnabled)
    {
        autoSaveTimer->start(autoSaveInterval);
        helper_status::set_notifications(this, m_statusBar.notifications, "AutoSave enabled");
    }
    else
    {
        autoSaveTimer->stop();
        helper_status::set_notifications(this, m_statusBar.notifications, "AutoSave disabled");
    }
}
//
// End AutoSave
//

//
// Date Time
//
void NotepadPlus::on_actionDateTime_triggered()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QTextCursor cursor = ui->textEditor->textCursor();

    cursor.insertText(currentDateTime.toString());
}
//
// End Date Time
//

//
// End The Edit Tab
//

//
// The Settings Tab
//

//
// Line Break
//
void NotepadPlus::on_actionLine_Break_triggered()
{
    isLineWrapEnabled = !isLineWrapEnabled;

    if (ui->actionLine_Break->isChecked())
    {
        ui->textEditor->setLineWrapMode(QTextEdit::WidgetWidth);
        ui->textEditor->setWordWrapMode(QTextOption::WordWrap);
        helper_status::set_notifications(this, m_statusBar.notifications, "Line Break enabled");
    }
    else
    {
        ui->textEditor->setLineWrapMode(QTextEdit::NoWrap);
        helper_status::set_notifications(this, m_statusBar.notifications, "Line Break disabled");
    }

    ui->actionLine_Break->setChecked(isLineWrapEnabled);
}
//
// End Line Break
//

//
// Status Bar Setting
//
void NotepadPlus::on_actionStatus_Bar_triggered(bool checked)
{
    if (checked)
        ui->statusBar->show();

    else
        ui->statusBar->hide();

}
//
// End Status Bar Setting
//

//
// Reset zoom
//
void NotepadPlus::on_actionZoom_Reset_triggered()
{
    zoomReset();
}
//
// End Reset zoom
//

//
// Reset settings
//
void NotepadPlus::on_actionReset_Text_Settings_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();


    // change ff
    QTextCharFormat format;

    // change color text
    QColor defaultColor_text;
    if (helper_theme::isDark)
    {
        defaultColor_text = QColor(Qt::white);
        ui->textEditor->setTextColor(defaultColor_text);
    }
    else
    {
        defaultColor_text = QColor(Qt::black);
        ui->textEditor->setTextColor(defaultColor_text);
    }

    // change fill color text
    QColor defaultColor_fillText;

    if (helper_theme::isDark)
    {
        defaultColor_fillText = QColor(QColor(42, 42, 42));
        format.setBackground(defaultColor_fillText);
    }
    else
    {
        defaultColor_fillText = QColor(Qt::white);
        format.setBackground(defaultColor_fillText);
    }

    cursor.mergeBlockCharFormat(format);

    ui->textEditor->mergeCurrentCharFormat(format); // for next  text change font family

    zoomReset();

    helper_font_text::Reset_Text_Format(ui->textEditor);
    helper_status::set_notifications(this, m_statusBar.notifications, "the text setting has been reset");
}
//
// End Reset settings
//

//
// change theme
//
// white theme
void NotepadPlus::on_actionWhite_triggered()
{
    helper_theme::set_light_theme(qApp);
    helper_status::set_notifications(this, m_statusBar.notifications, "The theme has been changed to white");
}
// dark theme
void NotepadPlus::on_actionDark_triggered()
{
    helper_theme::set_dark_theme(qApp);
    helper_status::set_notifications(this, m_statusBar.notifications, "The theme has been changed to dark");
}
//
// End change theme
//

//
// Show html code
//
void NotepadPlus::on_actionShow_Html_Code_triggered(bool checked)
{
    if (checked)
    {

        if (m_statusBar.path == "None" || m_statusBar.path == " ")
        {
            ui->actionShow_Html_Code->setChecked(false);
            QMessageBox::information(this, "Text", "The path to the text file was not found!");
            helper_status::set_notifications(this, m_statusBar.notifications, "The path to the text file was not found!");
            return;
        }
        else if (!m_statusBar.path.endsWith(".html"))
        {
            ui->actionShow_Html_Code->setChecked(false);
            QMessageBox::information(this, "Text", "Please open the html file!");
            helper_status::set_notifications(this, m_statusBar.notifications, "Please open the html file!");
            return;
        }

        ui->textEditor->setPlainText(helper_file::get_text_from_file(this, m_statusBar.path));
        helper_status::set_notifications(this, m_statusBar.notifications, "viewing the html code");
    }
    else
    {
        ui->textEditor->setHtml(helper_file::get_text_from_file(this, m_statusBar.path));
        helper_status::set_notifications(this, m_statusBar.notifications, "viewing html code as text");
    }
}
//
// End Show Html Code
//


//
// End The Settings Tab
//

//
// The About Tab
//

// About Program
void NotepadPlus::on_actionAbout_Program_triggered()
{
    if (!infoWindow)
    {
        infoWindow = new InfoWindow(this);
        connect(infoWindow, &InfoWindow::destroyed, this, &NotepadPlus::onInfoWindowClosed); // for close info
    }

    infoWindow->show();
    infoWindow->raise();
    infoWindow->activateWindow();
}

// GitHub
void NotepadPlus::on_actionGit_Hub_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Syneation"));
}

//
// End The About Tab
//

//
// Other Icons
//

//
//Redo Icon
//
void NotepadPlus::on_actionforwardIcon_triggered()
{
    ui->textEditor->redo();
    helper_status::set_notifications(this, m_statusBar.notifications, "the text is redo");
}
//
// End Redo Icon
//

//
// Icon Font Family Bold
//
void NotepadPlus::on_actionboldIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();

    bool checkClickOnFontBold = ui->actionboldIcon->isChecked();

    if (checkClickOnFontBold && cursor.hasSelection())
        helper_font_text::set_bold_ff(ui->textEditor, true);

    else if (!checkClickOnFontBold && cursor.hasSelection())
        helper_font_text::set_bold_ff(ui->textEditor, false);

    else if (!cursor.hasSelection())
    {
        if (ui->actionboldIcon->isChecked())
        {
            ui->actionboldIcon->setChecked(false);
            helper_font_text::set_bold_ff(ui->textEditor, false);
        }
        else
        {
            ui->actionboldIcon->setChecked(true);
            helper_font_text::set_bold_ff(ui->textEditor, true);
        }

        helper_status::set_notifications(this, m_statusBar.notifications, "please select the text");
        QMessageBox::information(this, "font family", "please select the text to change the font");
        return;
    }


    helper_status::set_notifications(this, m_statusBar.notifications, "the font has been changed to bold");

}

//
// End Icon Font Size Bold
//

//
// Icon Font Family Italics
//
void NotepadPlus::on_actionitalicsIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();

    bool checkClickOnFontItalics = ui->actionitalicsIcon->isChecked();

    if (checkClickOnFontItalics && cursor.hasSelection())
        helper_font_text::set_italics_ff(ui->textEditor, true);

    else if (!checkClickOnFontItalics && cursor.hasSelection())
        helper_font_text::set_italics_ff(ui->textEditor, false);

    else if (!cursor.hasSelection())
    {
        if (ui->actionitalicsIcon->isChecked())
        {
            ui->actionitalicsIcon->setChecked(false);
            helper_font_text::set_italics_ff(ui->textEditor, false);
        }
        else
        {
            ui->actionitalicsIcon->setChecked(true);
            helper_font_text::set_italics_ff(ui->textEditor, true);
        }

        helper_status::set_notifications(this, m_statusBar.notifications, "please select the text");
        QMessageBox::information(this, "font family", "please select the text to change the font");
        return;
    }


    helper_status::set_notifications(this, m_statusBar.notifications, "the font has been changed to italics");
}
//
// End Icon Font Family Italics
//

//
// Icon Font Family Underline
//
void NotepadPlus::on_actionunderlineIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();

    bool checkClickOnFontUnderline = ui->actionunderlineIcon->isChecked();

    if (checkClickOnFontUnderline && cursor.hasSelection())
        helper_font_text::set_underline_ff(ui->textEditor, true);

    else if (!checkClickOnFontUnderline && cursor.hasSelection())
        helper_font_text::set_underline_ff(ui->textEditor, false);

    else if (!cursor.hasSelection())
    {
        if (ui->actionunderlineIcon->isChecked())
        {
            ui->actionunderlineIcon->setChecked(false);
            helper_font_text::set_underline_ff(ui->textEditor, false);
        }
        else
        {
            ui->actionunderlineIcon->setChecked(true);
            helper_font_text::set_underline_ff(ui->textEditor, true);
        }

        helper_status::set_notifications(this, m_statusBar.notifications, "please select the text");
        QMessageBox::information(this, "font family", "please select the text to change the font");
        return;
    }

    helper_status::set_notifications(this, m_statusBar.notifications, "the font has been changed to underline");
}
//
// End Icon Font Family Underline
//

//
// Icon Font Family Strike Through
//
void NotepadPlus::on_actioncrossouttextIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();

    bool checkClickOnFontStrikeThrough = ui->actioncrossouttextIcon->isChecked();

    if (checkClickOnFontStrikeThrough && cursor.hasSelection())
        helper_font_text::set_strike_through_ff(cursor, true);

    else if (!checkClickOnFontStrikeThrough && cursor.hasSelection())
        helper_font_text::set_strike_through_ff(cursor, false);

    else if (!cursor.hasSelection())
    {
        if (ui->actioncrossouttextIcon->isChecked())
        {
            ui->actioncrossouttextIcon->setChecked(false);
            helper_font_text::set_underline_ff(ui->textEditor, false);
        }
        else
        {
            ui->actioncrossouttextIcon->setChecked(true);
            helper_font_text::set_underline_ff(ui->textEditor, true);
        }

        helper_status::set_notifications(this, m_statusBar.notifications, "please select the text");
        QMessageBox::information(this, "font family", "please select the text to change the font");
        return;
    }

    helper_status::set_notifications(this, m_statusBar.notifications, "the font has been changed to underline");
}
//
// End Icon Font Family Strike Through
//

//
// text left aligment
//
void NotepadPlus::on_actionleftTextIcon_triggered()
{
    ui->textEditor->setAlignment(Qt::AlignLeft);
    helper_status::set_notifications(this, m_statusBar.notifications, "text aligned to left");
}
//
// End text left aligment
//

//
// text width alignment
//
void NotepadPlus::on_actiontextByWidthIcon_triggered()
{
    ui->textEditor->setAlignment(Qt::AlignJustify);
    helper_status::set_notifications(this, m_statusBar.notifications, "text aligned to width");
}
//
// End text width alignment
//

//
// text center aligment
//
void NotepadPlus::on_actioncenterTextIcon_triggered()
{
    ui->textEditor->setAlignment(Qt::AlignCenter);
    helper_status::set_notifications(this, m_statusBar.notifications, "text aligned to center");
}
//
// End text center aligment
//

//
// text right alignment
//
void NotepadPlus::on_actionrightTextIcon_triggered()
{
    ui->textEditor->setAlignment(Qt::AlignRight);
    helper_status::set_notifications(this, m_statusBar.notifications, "text aligned to width");
}
//
// End text right alignment
//

//
// font family Icon
//
void NotepadPlus::on_actionfontFamilyIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();

    bool hasSelection = cursor.hasSelection();

    bool fontSelected = false;
    QFont initialFont = hasSelection ? cursor.charFormat().font() : ui->textEditor->font();
    QFont newFont = QFontDialog::getFont(&fontSelected, initialFont, this);

    if (!fontSelected) {
        QMessageBox::information(this, "font Family", "Font change canceled");
        helper_status::set_notifications(this, m_statusBar.notifications, "font change canceled");
        return;
    }

    if (hasSelection) {
        helper_font_text::set_selected_text_ff(newFont, cursor);
        helper_status::set_notifications(this, m_statusBar.notifications, "font family of selected text was changed");
    } else {
        ui->textEditor->setFont(newFont);
        helper_status::set_notifications(this, m_statusBar.notifications, "font family was changed");
    }
}

//
// End font family Icon
//

//
// fill the text bg icon
//
void NotepadPlus::on_actionfillTheTextBgIcon_triggered()
{
    QTextCharFormat format;

    QTextCursor cursor = ui->textEditor->textCursor();

    if (!cursor.hasSelection())
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "please select the text");
        QMessageBox::information(this, "text color", "please select the text to change background of the text");
        return;
    }

    QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "Select a color");

    if (cursor.hasSelection() && selectedColor.isValid())
    {
        format.setBackground(selectedColor);
        cursor.mergeCharFormat(format);
        helper_status::set_notifications(this, m_statusBar.notifications, "the text color has changed");
    }
    else
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "color selection canceled");
        QMessageBox::information(this, "text color", "color selection canceled");
    }
}
//
// End fill the text bg icon
//

//
// the text color
//
void NotepadPlus::on_actioncolorTextIcon_triggered()
{
    QTextCursor cursor = ui->textEditor->textCursor();

    if (!cursor.hasSelection())
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "please select the text");
        QMessageBox::information(this, "text color", "please select the text to change color text");
        return;
    }

    QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "Select a color");

    if (cursor.hasSelection() && selectedColor.isValid())
    {
        ui->textEditor->setTextColor(selectedColor);
        helper_status::set_notifications(this, m_statusBar.notifications, "the text color has changed");
    }
    else
    {
        helper_status::set_notifications(this, m_statusBar.notifications, "color selection canceled");
        QMessageBox::information(this, "text color", "color selection canceled");
    }
}
//
// End the text color
//

//
// increase icon
//
void NotepadPlus::on_actionincreaseIcon_triggered()
{
    zoomIn();
    helper_status::set_notifications(this, m_statusBar.notifications, "zoom increased");
}
//
// End increase icon
//

//
// reduce icon
//
void NotepadPlus::on_actionreduceIcon_triggered()
{
    zoomOut();
    helper_status::set_notifications(this, m_statusBar.notifications, "zoom decreased");
}
//
// End reduce icon
//

//
// info icon
//
void NotepadPlus::on_actioninfoIcon_triggered()
{
    if (!infoWindow)
    {
        infoWindow = new InfoWindow(this);
        connect(infoWindow, &InfoWindow::destroyed, this, &NotepadPlus::onInfoWindowClosed); // for close info
    }


    infoWindow->show_info();
}
void NotepadPlus::onInfoWindowClosed()
{
    infoWindow = nullptr; // resetting the pointer when closing
}
//
// End info icon
//

//
// End Other Icons
//



