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
#include <QButtonGroup>
#include <QTimer>
namespace Ui {
class File;
}

// To show the folder icon
class FolderIcon
{
public:
    QToolButton* button;
    QString name;
    QString ID;
public:
    FolderIcon(QString Name, QString ID);
    ~FolderIcon();
};

// To show the file icon
class FileIcon
{
public:
    QToolButton* button;
    QString name;
    // QString ID;  //parent(curDirect) and name is enough to identify
    FileIcon(QString Name, QString format);
    ~FileIcon();
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
    QTimer clickTimer; // Monitor Double-Clicked Event
    QButtonGroup* buttonGroup; // group of icons
    QList<FolderIcon*> folderIcons;
    QList<FileIcon*> fileIcons;

    QGridLayout* iconLayout;  // Lay out icon

    QString curDirect; // Current directory

    //Upload: to pass to UploadData()
    // QTimer* timer;
    QString filePath;

private slots:
    void show(QStringList folderList, QStringList fileList);
    void on_AddFolder_Button_clicked();
    void onFolderIconDoubleClicked(FolderIcon* icon);
    void onIconChecked();

    void on_Delete_Button_clicked();
    void on_UP_BUTTON_clicked();
    void on_DOWN_BUTTON_clicked();
    void on_REFRESH_BUTTON_clicked();
    void on_Upload_Button_clicked();
    void UploadData();
    void on_Download_Button_clicked();

    void on_Latest_Button_clicked();
    void on_Photo_Button_clicked();
    void on_Video_Button_clicked();
    void on_Music_Button_clicked();
    void on_Document_Button_clicked();
    void on_Else_Button_clicked();

public:
    void searchRootID();
    void refresh();
    void recvMsg(PDU* pdu);
    void downloadFileData();
};


#endif // FILE_H
