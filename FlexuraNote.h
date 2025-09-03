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

#ifndef FLEXURANOTE_H
#define FLEXURANOTE_H

#include "infowindow.h"
#include "findwindow.h"
#include "replacewindow.h"

#include <iostream>
#include <ostream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QDesktopServices>
#include <QAbstractTextDocumentLayout>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextFragment>
#include <QTextImageFormat>
#include <QTextLayout>
#include <QWheelEvent>
#include <QMainWindow>
#include <QDateTime>
#include <QTextEdit>
#include <QImage>
#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QFont>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class NotepadPlus;
}
QT_END_NAMESPACE

//
// Label Status Bar
//
struct LStatus_bar {
    int length = 0;
    int lines = 0;
    int Ln = 0;
    int Col = 0;
    int Pos = 0;
    int zoom = 0;
    int count_tab = 0;

    int tmp_count_save_file = 0;

    QString path = "None";
    QString notifications = "None";
    QString encoding = "None";
};
//
// End Label Status Bar
//

class NotepadPlus : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotepadPlus(QWidget *parent = nullptr);
    ~NotepadPlus();

    QString currentFile;

    // access to status-bar
    LStatus_bar& statusBarState() { return m_statusBar; }

    // for find
    void find_text();
    void setSearchHighlightColor(const QColor& color);

public slots:
    // find && replace
    void handleFindRequest(const FindWindow::find_work &work);
    void handleFindRequest_replace(const ReplaceWindow::find_replace_work &work);
    void handleReplace_text(const ReplaceWindow::find_replace_work &work, const QString& new_text);
    void handlerRepalce_all_text(const ReplaceWindow::find_replace_work &work, const QString& new_text);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    // for drag and drop files
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    // for check close main window
    void closeEvent(QCloseEvent *event);


private slots:
    void onInfoWindowClosed(); // for info window
    void onFindWindowClosed(); // for find window
    void onReplaceWindowClosed(); // for replace window

    void on_NotepadPlus_customContextMenuRequested(const QPoint &pos);

    void autoSave();

    void on_actionOpen_triggered();

    void on_actionnewFileIcon_triggered();

    void on_actionNew_File_triggered();

    void on_actionopenFileIcon_triggered();

    void on_actionsaveIcon_triggered();

    void on_actionSave_triggered();

    void updateCursorStatus();

    void on_actionboldIcon_triggered();

    void on_actionSave_As_triggered();

    void on_actionSaveAsIcon_triggered();

    void on_actionPrint_triggered();

    void on_actionprintIcon_triggered();

    void on_actionExit_triggered();

    void on_actionCancel_triggered();

    void on_actionbackIcon_triggered();

    void on_actionCut_triggered();

    void on_actioncutIcon_triggered();

    void on_actiontextByWidthIcon_triggered();

    void on_actionCopy_triggered();

    void on_actioncopy_triggered();

    void on_actionPaste_triggered();

    void on_actionpasteIcon_triggered();

    void on_actionSelect_All_triggered();

    void on_actionDelete_All_triggered();

    void on_actionCopyright_triggered();

    void on_actionTrademark_triggered();

    void on_actionTrademark_2_triggered();

    void on_actionAutosave_triggered();

    void on_actionDateTime_triggered();

    void on_actionforwardIcon_triggered();

    void on_actionLine_Break_triggered();

    void on_actionitalicsIcon_triggered();

    void on_actionunderlineIcon_triggered();

    void on_actioncrossouttextIcon_triggered();

    void on_actionleftTextIcon_triggered();

    void on_actioncenterTextIcon_triggered();

    void on_actionrightTextIcon_triggered();

    void on_actionfontFamilyIcon_triggered();

    void on_actionfillTheTextBgIcon_triggered();

    void on_actioncolorTextIcon_triggered();

    void on_actionincreaseIcon_triggered();

    void on_actionreduceIcon_triggered();

    void on_actionReset_Text_Settings_triggered();

    void on_actionWhite_triggered();

    void on_actionDark_triggered();

    void on_actionZoom_Reset_triggered();

    void on_actioninfoIcon_triggered();

    void on_actionAbout_Program_triggered();

    void on_actionGit_Hub_triggered();

    void on_actionfindIcon_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionreplaceIcon_triggered();

    void on_actionAddImage_triggered();

    void on_actionStatus_Bar_triggered(bool checked);



    void on_actionShow_Html_Code_triggered(bool checked);

private:
    Ui::NotepadPlus *ui;
    InfoWindow *infoWindow; // for window info
    FindWindow *findWindow; // for find window
    ReplaceWindow *replaceWindow; // for replace window

    LStatus_bar m_statusBar; // status bar status

    // timer for autosave
    QTimer *autoSaveTimer;
    int autoSaveInterval = 5; // time for autosave (default 5 sec)
    bool isAutoSaveEnabled = false;

    // for line break
    bool isLineWrapEnabled = false;

    // for status bar
    bool isStatusBarEnabled = true;

    // for zoom
    double m_currentZoom = 1.0;// 1.0 = 100%

    // for search
    QList<QTextCursor> searchHighlights; // Для хранения выделений поиска

    // for change size image
    bool is_Image_At_Position(const QPoint &pos, QTextImageFormat &imageFormat);
    void resizeImage(QTextImageFormat &imageFormat);

//
// for simple work with different tasks
//
public:
    // for func e.g. : set_notifications()
    void updateFilePath(const QString& path);
    void updateNotification(const QString& message);
    void updateLenLines(const QString& path);
    void updateLnColPos(const QString& message);
    void updateEncoding(const QString& encoding);
    void updateZoom();
    // work with files
    void updateSaveText(const QString& fileName);
    void updateSaveAsText(const QString& fileName);
    void print_text();
    // for zoom
    void zoomIn();
    void zoomOut();
    void zoomReset();
    void initializeZoom();
    void applyCurrentZoom();


};
#endif // FLEXURANOTE_H
