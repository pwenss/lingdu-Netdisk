#include "file.h"
#include "ui_file.h"
#include <QInputDialog>
#include <QMessageBox>
#include "tcpclient.h"
#include "protocol.h"
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
#include <QFileDialog>
#include <QThread>
#include <QPixmap>
#include "tcpclient.h"


//Used in downLoadFileData()
//Global variable used to record the progress of receiving file data across multiple rounds.
QFile file;
qint64 totalSize;
qint64 readSize;


File::File(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::File)
{
    // timer = new QTimer;

    ui->setupUi(this);

    ui->Download_Button->hide();
    ui->Delete_Button->hide();
    ui->UP_BUTTON->setEnabled(false);

    iconLayout = new QGridLayout(ui->widget);
    iconLayout->setRowStretch(5, 1);
    iconLayout->setColumnStretch(6, 1);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    connect(buttonGroup, QOverload<QAbstractButton*,bool>::of(&QButtonGroup::buttonToggled),
            this, &File::onIconChecked);  // button checked change: update shown buttons in file widget
    // connect(timer,SIGNAL(timeout()),this,SLOT(UploadData()));

    searchRootID();// Initial 'CurDirect'
}

File::~File()
{
    delete ui;
}

File& File::instance()
{
    static File file;
    return file;
}

FolderIcon::FolderIcon(QString Name, QString id)
{
    QToolButton* Tb = new QToolButton();
    QPixmap pixmap(":/img/icons/folder.jpg");
    QIcon icon(pixmap);
    Tb->setIcon(icon);

    Tb->setStyleSheet("border: none;");
    Tb->setIconSize(QSize(80, 80));
    Tb->setFixedSize(100, 100);
    Tb->raise();
    Tb->setText(Name);
    Tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Tb->setCheckable(true);
    Tb->setStyleSheet("QToolButton { border: none; }"
                      "QToolButton:checked { background-color: lightblue; }");
    button = Tb;
    name = Name;
    ID = id;
}

FolderIcon::~FolderIcon()
{
    delete(button);
}

FileIcon::FileIcon(QString Name, QString format)
{
    // Set specified icon based on the file's format
    QToolButton* Tb = new QToolButton();
    if(format=="txt")
    {
        QPixmap pixmap(":/img/icons/txt.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="mp3")
    {
        QPixmap pixmap(":/img/icons/music.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="mp4")
    {
        QPixmap pixmap(":/img/icons/video.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="jpg" or format == "png")
    {
        QPixmap pixmap(":/img/icons/photo.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="pdf")
    {
        QPixmap pixmap(":/img/icons/pdf.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="doc")
    {
        QPixmap pixmap(":/img/icons/doc.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="docx")
    {
        QPixmap pixmap(":/img/icons/docx.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else if(format=="pdf")
    {
        QPixmap pixmap(":/img/icons/ppt.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }
    else
    {
        QPixmap pixmap(":/img/icons/else.jpg");
        QIcon icon(pixmap);
        Tb->setIcon(icon);
    }


    Tb->setStyleSheet("border: none;");
    Tb->setIconSize(QSize(80, 80));
    Tb->setFixedSize(100, 100);
    Tb->raise();
    Tb->setText(Name);
    Tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Tb->setCheckable(true);
    Tb->setStyleSheet("QToolButton { border: none; }"
                      "QToolButton:checked { background-color: lightblue; }");
    button = Tb;
    name = Name;
}

FileIcon::~FileIcon()
{
    delete(button);
}


// UI updata

// Show the folder widget of current parent directory
void File::refresh()
{
    PDU *pdu = mkPDU(0);
    pdu->type = MSGTYPE::REFRESH_FOLDER;
    strncpy(pdu->meta, TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, curDirect.toStdString().c_str(), 32);

    qDebug()<<"Client Emitted PDU -- Refresh: "<< "len"<<pdu->len<<"datalen"<<pdu->dataLen<<"meta"<<pdu->meta;

    TcpClient::instance().socket().write((char*)pdu, pdu->len);

    delete pdu;
}

void File::show(QStringList folderList, QStringList fileList)
{
    int ColumnSize = 4;

    // Delete previous button or label

    for (QAbstractButton *button : buttonGroup->buttons())
        buttonGroup->removeButton(button);
    while (iconLayout->count() > 0) {
        QLayoutItem *item = iconLayout->takeAt(0);

        if (item->widget()) {
            delete item->widget();
        }

        delete item;
    }
    folderIcons.clear();
    fileIcons.clear();

    // Add current button
    if(folderList.empty() && fileList.empty())
    {
        iconLayout->setRowStretch(0, 1);
        iconLayout->setColumnStretch(0, 1);

        QLabel* label = new QLabel(ui->widget);
        QFont font("Arial", 20);
        font.setItalic(true);
        label->setFont(font);
        label->setStyleSheet("color: red");
        label->setAlignment(Qt::AlignCenter);
        label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        label->setText("Empty Folder");

        iconLayout->addWidget(label);
        ui->DOWN_BUTTON->setEnabled(false);
    }

    else
    {
        iconLayout->setRowStretch(5, 1);
        iconLayout->setColumnStretch(6, 1);
        // Show Folder
        for (int i = 0; i < folderList.size(); ++i)
        {
            // nameList: [name + "//" + ID,...]
            QString nameUnit = folderList.at(i);
            QStringList nameUnitList = nameUnit.split("//");
            QString name = nameUnitList.at(0);
            QString ID = nameUnitList.at(1);

            FolderIcon* icon= new FolderIcon(name, ID);
            buttonGroup->addButton(icon->button);
            folderIcons.append(icon);

            int row = i/ColumnSize;
            int column = i%ColumnSize;

            iconLayout->addWidget(icon->button, row, column);

            // connect(icon->button, &QToolButton::clicked, this, [=]() {
            //     onFolderIconClicked(icon);
            // }); // Folder ICon click() --- onFolderIconClicked(icon)
            connect(icon->button, &QToolButton::clicked, this, [=]() {
                if (clickTimer.isActive() && clickTimer.remainingTime() > 9700 ) {
                    qDebug()<<clickTimer.remainingTime();
                    clickTimer.stop();
                    onFolderIconDoubleClicked(icon);
                } else {
                    clickTimer.stop();
                    clickTimer.start(10000);
                }
            }); // Folder Icon DoubleClick -- on FolderIconDoubleClicked
        }
        // Show File
        for (int i = folderList.size(); i < folderList.size()+fileList.size(); ++i)
        {
            QString name = fileList.at(i-folderList.size());
            QString format = name.section('.', 1, 1);

            FileIcon* icon= new FileIcon(name, format);
            buttonGroup->addButton(icon->button);
            fileIcons.append(icon);

            int row = i/ColumnSize;
            int column = i%ColumnSize;

            iconLayout->addWidget(icon->button, row, column);

        }
    }
    ui->widget->update();
}


// Update shown buttons
void File::onIconChecked()
{
    // shown buttons
    int checkedCount = buttonGroup->checkedButton() ? 1 : 0;
    if (checkedCount)
    {
        ui->Upload_Button->hide();
        ui->AddFolder_Button->hide();

        ui->Download_Button->show();
        ui->Download_Button->setEnabled(false);
        ui->Delete_Button->show();
    }
    else
    {
        ui->Upload_Button->show();
        ui->AddFolder_Button->show();

        ui->Download_Button->hide();
        ui->Delete_Button->hide();
    }
    // enable button
    QList<FileIcon*> checkedFileIcons;

    for (FileIcon* icon : fileIcons)
    {
        if (icon->button->isChecked())
            checkedFileIcons.append(icon);
    }
    // qDebug()<<"Current checked fileIcon: "<<checkedFileIcons.size();
    if (checkedFileIcons.size() == 1)
        ui->Download_Button->setEnabled(true);
    else
        ui->Download_Button->setEnabled(false);
}

// CD the target directory
void File::onFolderIconDoubleClicked(FolderIcon* icon)
{
    // qDebug()<<"Double Clicked";
    ui->UP_BUTTON->setEnabled(true);
    curDirect = icon->ID;
    refresh();
}



// Response Message Execute Function
void File::recvMsg(PDU* pdu)
{
    // Distinguished the message type and Execute
    switch (pdu->type)
    {
    case ROOTID:
    {
        curDirect = QString::fromUtf8(pdu->meta);
        qDebug()<<"Root id: "<<curDirect;
        break;
    }
    case ADD_FOLDER:
    {
        if(0 == strcmp(pdu->meta,ADD_FOLDER_SUCCESS))
        {
            QMessageBox::information(this,"Add Folder",ADD_FOLDER_SUCCESS);
            refresh();
        }
        else if(0 == strcmp(pdu->meta,ADD_FOLDER_FAIL))
            QMessageBox::warning(this,"Add Folder","Folder has already existed!");

        break;
    }
    case REFRESH_FOLDER:
    {
        const char* charData = pdu->data;
        QString combinedString = QString::fromUtf8(charData);
        QStringList lists = combinedString.split('@');
        QStringList folderList = lists[0].split('#');
        QStringList fileList = lists[1].split('#');

        // Determine whether the list is empty, we cannot use QStringList.empty here because it'll cause some problem
        if (folderList.contains(""))
            folderList=QStringList();
        if (fileList.contains(""))
            fileList=QStringList();

        qDebug() << "FolderList: " <<folderList<<folderList.size()<<"  FileList: "<<fileList<<fileList.size();
        show(folderList, fileList);
        break;
    }
    case DELETE:
    {
        if(0 == strcmp(pdu->meta,DELETE_FOLDER_SUCCESS))
        {
            QMessageBox::information(this,"Delete Folder",DELETE_FOLDER_SUCCESS);
            refresh();
        }
        else if(0 == strcmp(pdu->meta,DELETE_FOLDER_FAIL))
            QMessageBox::warning(this,"Delete Folder","Unexpected Error!");

        break;
    }
    case UP_FOLDER:
    {
        curDirect = QString::fromUtf8(pdu->meta);

        if(curDirect == "root")
             ui->UP_BUTTON->setEnabled(false);
        ui->DOWN_BUTTON->setEnabled(true);

        refresh();
        break;
    }
    case UPLOAD:
    {
        if(0 == strcmp(pdu->meta,UPLOAD_REQUEST_ACCEPTED))
        {
            QMessageBox::information(this,"Upload", "Begin Upload, please wait");
            UploadData();
        }
        else if(0 == strcmp(pdu->meta,UPLOAD_SUCCESS))
        {
            QMessageBox::information(this,"Upload", "Upload File Success!");
            refresh();
        }
        else if(0 == strcmp(pdu->meta,UPLOAD_FAIL1))
        {
            QMessageBox::warning(this,"Upload", "File has already existed!");
        }
        else if(0 == strcmp(pdu->meta,UPLOAD_FAIL2))
        {
            QMessageBox::warning(this,"Upload", "Read file error!");
        }
        break;
    }
    case DOWNLOAD:
    {
        if(0 == strcmp(pdu->meta,DOWNLOAD_REQUEST_ACCEPTED))
        {
            QMessageBox::information(this,"Download", "Begin Upload, please wait");
            readFile = true;
            readSize = 0;

            sscanf(pdu->data, "%lld", &totalSize);

            file.setFileName(filePath);
            if(!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(this,"UpLoad","Cannot open the file!");
                break;
            }

            downloadFileData();
        }
        // Notice that the receive process is in the client, so the success flag is also in the downloadData() not by the server
        // else if(0 == strcmp(pdu->meta,DOWNLOAD_SUCCESS))
        // {
        //     QMessageBox::information(this,"Download", "Upload File Success!");
        //     refresh();
        // }
        else if(0 == strcmp(pdu->meta,DOWNLOAD_FAIL))
        {
            QMessageBox::warning(this,"Download", "File cannot open in the server! ");
        }
        break;
    }
    case SEARCH:
    {
        const char* charData = pdu->data;
        QString combinedString = QString::fromUtf8(charData);
        QStringList names = combinedString.split('#');
        if (names.contains(""))
            names=QStringList();

        qDebug() << "nameList: " <<names;

        QStringList ids = QStringList();
        show(ids, names);
        break;
    }

    default:
    {
        break;
    }
    }

}



// Folder Task
//Get the user's 'root' ID
void File::searchRootID()
{
    PDU *pdu = mkPDU(0);
    pdu->type = MSGTYPE::ROOTID;
    strncpy(pdu->meta, TcpClient::instance().userName.toStdString().c_str(), 32);

    qDebug()<<"Client Emitted PDU -- Refresh: "<< "len"<<pdu->len<<"datalen"<<pdu->dataLen<<"meta"<<pdu->meta;

    TcpClient::instance().socket().write((char*)pdu, pdu->len);

    delete pdu;
}


// Add folder
void File::on_AddFolder_Button_clicked()
{
    QString name = QInputDialog::getText(this,"Add folder","Folder name");

    if(!name.isEmpty())
    {
        if(name.size() > 32)
        {
            QMessageBox::warning(this,"Add Folder","Folder name cannot exceed 32 characters!");
        }
        else if(name.contains('#'))
        {
            QMessageBox::warning(this,"Add Folder","Folder name cannot contain '#'!");
        }
        else
        {
            QString userName = TcpClient::instance().userName;

            // Meta: username+current Direct   Data: name
            PDU *pdu = mkPDU(name.size()+1);
            pdu->type = MSGTYPE::ADD_FOLDER;
            strncpy(pdu->meta,userName.toStdString().c_str(),32);
            strncpy(pdu->meta + 32,curDirect.toStdString().c_str(),32);
            memcpy(pdu->data,name.toStdString().c_str(),name.size());

            TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

            delete pdu;
        }
    }
    else
    {
        QMessageBox::warning(this,"Add Folder","Foler name cannot be null!");
    }


}

// Delete folder
void File::on_Delete_Button_clicked()
{
    // Get all selected button
    QList<FolderIcon*> checkedFolderIcons;
    QStringList IDs;
    for (FolderIcon* icon : folderIcons)
    {
        if (icon->button->isChecked())
            checkedFolderIcons.append(icon);
    }

    QList<FileIcon*> checkedFileIcons;
    QStringList names;
    for (FileIcon* icon : fileIcons)
    {
        if (icon->button->isChecked())
            checkedFileIcons.append(icon);
    }

    // Delete
    for (FolderIcon* icon: checkedFolderIcons)
        IDs.append(icon->ID);
    QString combinedFolderString = IDs.join("#");
    for (FileIcon* icon: checkedFileIcons)
        names.append(icon->name);
    QString combinedFileString = names.join("#");
    qDebug()<<"CombinedString to Delete: "<<combinedFileString;

    // Data format:  [folderList: name // id #... ] @ [fileList: name #... ]
    QString combinedString = combinedFolderString + '@' + combinedFileString;

    PDU *pdu = mkPDU(combinedString.size()+1);
    pdu->type = MSGTYPE::DELETE;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(),32);
    strncpy(pdu->meta + 32,curDirect.toStdString().c_str(),32);
    memcpy(pdu->data,combinedString.toStdString().c_str(),combinedString.size());

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete pdu;
}



void File::on_UP_BUTTON_clicked()
{
    qDebug()<<"UP folder";
    PDU *pdu = mkPDU(0);
    pdu->type = MSGTYPE::UP_FOLDER;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(),32);
    strncpy(pdu->meta + 32,curDirect.toStdString().c_str(),32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete pdu;
}


void File::on_DOWN_BUTTON_clicked()
{

    FolderIcon* icon = folderIcons.at(0);
    curDirect = icon->ID;
    ui->UP_BUTTON->setEnabled(true);
    refresh();
}


void File::on_REFRESH_BUTTON_clicked()
{
    refresh();
}

// Upload Task
// Send upload request to server
void File::on_Upload_Button_clicked()
{
    filePath = QFileDialog::getOpenFileName();
    if(filePath.isEmpty())
    {
        QMessageBox::warning(this,"UPLOAD","File connot be null!");
        return;
    }

    int index = filePath.lastIndexOf('/');
    QString fileName = filePath.mid(index + 1);

    QFile file(filePath);
    qint64 fileSize = file.size();

    PDU *pdu = mkPDU(21); // long long int
    // Write meta data, username, parent directory, file name
    pdu->type = UPLOAD;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, curDirect.toStdString().c_str(), 32);
    strncpy(pdu->meta+64, fileName.toStdString().c_str(), 32);
    sprintf(pdu->data,"%lld",fileSize);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Unbuffered))
    {
        QMessageBox::warning(this, "UPLOAD", "Cannot open the file!");
        return;
    }
    file.close();

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    qDebug()<<"File Size: "<<fileSize;

    delete pdu;

}
// Send file data to server
void File::UploadData()
{
    char *buffer = new char[4096];
    int readSize=0;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"UpLoad","Cannot open the file!");
        return;
    }

    while(true)
    {
        readSize = file.read(buffer,4096);
        qDebug()<<"Send FileData: "<<readSize;

        if(readSize>0&&readSize<=4096)
            TcpClient::instance().cliSocket.write(buffer, readSize);

        else if(readSize==0)
            break;

        else
        {
            QMessageBox::warning(this,"UPLOAD","Read file error!");
            break;
        }
    }
    delete[] buffer;
}



// Download Task:
// Send download request to server
void File::on_Download_Button_clicked()
{    // The size of fileName is one, otherwise the button is not enabled
    QList<FileIcon*> checkedFileIcons;
    QString fileName;
    for (FileIcon* icon : fileIcons)
    {
        if (icon->button->isChecked())
            fileName = icon->name;
    }


    // Here we donnot need to determine the legitimacy because it has been checked through the  button's enablement
    QString format = QString("Files (*.%1);;").arg(fileName.section('.', 1, 1));
    QString path = QFileDialog::getSaveFileName(
        this,
        tr("Download File"),
        QDir::homePath(),
        tr(format.toStdString().c_str()) // Set the file path format
        );
    if(path.isEmpty())
    {
        QMessageBox::warning(this,"Download","Download path cannot be empty!");
        return;
    }

    filePath = path;



    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = DOWNLOAD;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, curDirect.toStdString().c_str(), 32);
    strncpy(pdu->meta+64, fileName.toStdString().c_str(), 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);

}
// Receive file data from server
void File::downloadFileData()
{
    // The tcp cannot send all the filedata once, so we need to receive it multipul times, and each send isn't the type of PDU!

    // Read all send data
    QByteArray buff = TcpClient::instance().cliSocket.readAll();
    file.write(buff);
    readSize += buff.size();
    qDebug()<<"Received the file : Currrent Received: "<<readSize<<"  TotalSize: "<<totalSize;

    if(readSize == totalSize)// Success to finished the file download!
    {
        file.close();
        readFile = false;

        QMessageBox::information(this,"Download", "Download File Success!");
        refresh();
    }
    else if(readSize > totalSize)
    {
        // Error 2: ReadSize more than totalSize

        file.close();
        readFile = false;

        QMessageBox::warning(this,"Download", "Unexpected Error: The read size is more than the actual file size!");
    }

    return;

}


// Select files of specific format, under all paths
// By time
void File::on_Latest_Button_clicked()
{
    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = SEARCH;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, "Time", 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);

}


void File::on_Photo_Button_clicked()
{
    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = SEARCH;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, "Photo", 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);
}


void File::on_Video_Button_clicked()
{
    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = SEARCH;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, "Video", 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);
}


void File::on_Music_Button_clicked()
{
    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = SEARCH;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, "Music", 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);
}


void File::on_Document_Button_clicked()
{
    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = SEARCH;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, "Document", 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);
}


void File::on_Else_Button_clicked()
{
    PDU *pdu = mkPDU(0);
    // Write meta data:  username, parent directory, file name
    pdu->type = SEARCH;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(), 32);
    strncpy(pdu->meta+32, "Else", 32);

    TcpClient::instance().cliSocket.write((char*)pdu, pdu->len);

    delete(pdu);
}

