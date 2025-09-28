/*#ifndef MULTICURSOR_H
#define MULTICURSOR_H

#include <QTextEdit>
#include <QDebug>

class MultiCursor
{
public:
    explicit MultiCursor(QWidget *parent = nullptr);

    //------------------------------
    // Managing additional cursors
    //------------------------------
    // Do not work :(
    static void add_cursor(const QPoint& position);
    static void clear_cursor();

    // get the count cursors
    int cursor_count(QPaintEvent *e) const { return m_cursors.size() + 1; }

protected:
    static void paintEvent(QPaintEvent *e) override;

private:
    QList<QTextCursor> m_cursors;
}

#endif // MULTICURSOR_H
*/
