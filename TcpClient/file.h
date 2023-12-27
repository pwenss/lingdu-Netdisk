// The sub widget

#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QToolButton>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include "protocol.h"

namespace Ui {
class File;
}
class FolderIcon
{
public:
    QToolButton* button;
    QString name;

public:
    FolderIcon(QString Name);
    ~FolderIcon();
};

class File : public QWidget
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    ~File();
    static File& instance();

public:
    Ui::File *ui;
    QList<FolderIcon*> icons; // list of icons
    QGridLayout* iconLayout;  // Lay out icon

    QString curDirect; // Current directory

private slots:
    void showFolder(QStringList nameList);
    void on_AddFolder_Button_clicked();

public:
    void refresh();
    void recvMsg(PDU* pdu);
};

#endif // FILE_H
