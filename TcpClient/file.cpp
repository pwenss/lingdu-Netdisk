#include "file.h"
#include "ui_file.h"
#include <QInputDialog>
#include <QMessageBox>
#include "tcpclient.h"
#include "protocol.h"


File::File(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::File)
{
    ui->setupUi(this);

    ui->Download_Button->hide();
    ui->Share_Button->hide();
    ui->Delete_Button->hide();
    iconLayout = new QGridLayout(ui->widget);

    iconLayout->setRowStretch(5, 1);
    iconLayout->setColumnStretch(6, 1);

    curDirect = "root";
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

FolderIcon::FolderIcon(QString Name)
{
    QToolButton* Tb = new QToolButton();
    Tb->setIcon(QIcon("D:\\QT\\Project\\TcpClient\\folder.jpg"));
    Tb->setStyleSheet("border: none;");
    Tb->setIconSize(QSize(50, 50));
    Tb->setFixedSize(80, 80);
    Tb->raise();

    Tb->setText(Name);
    Tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    button = Tb;
    name = Name;
}

FolderIcon::~FolderIcon()
{
    delete(button);
}

// Show the folder widget of current parent directory
void File::refresh()
{
    PDU *pdu = mkPDU(0);
    pdu->type = MSGTYPE::REFRESH_FOLDER;
    strncpy(pdu->meta, TcpClient::instance().userName.toStdString().c_str(), TcpClient::instance().userName.size());
    strncpy(pdu->meta+32, curDirect.toStdString().c_str(), curDirect.size());

    TcpClient::instance().cliSocket.write((char*)pdu,pdu->len);

    free(pdu);
    pdu = NULL;

}

void File::showFolder(QStringList nameList)
{
    int ColumnSize = 5;

    // Delete previous button
    for(int i=0; i<iconLayout->count(); ++i)
        iconLayout->removeItem(iconLayout->itemAt(i));
    qDeleteAll(icons.begin(), icons.end());
    icons.clear();

    for (int i = 0; i < nameList.size(); ++i)
    {
        QString name = nameList.at(i);

        FolderIcon* icon= new FolderIcon(name);
        icons.append(icon);

        int row = (icons.count() - 1)/ColumnSize;
        int column = (icons.count()- 1)%ColumnSize;

        qDebug() << row <<column << name;
        iconLayout->addWidget(icon->button, row, column);
    }

    ui->widget->update();
}

// Response Message Execute Function
void File::recvMsg(PDU* pdu)
{

    // Distinguished the message type and Execute
    switch (pdu->type)
    {
    // Folder Task1: Add folder
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
        QString combinedString(charData);
        QStringList nameList = combinedString.split('#');

        qDebug() << "nameList:" <<nameList;
        showFolder(nameList);
    }
    default:
    {
        break;
    }
    }

}





void File::on_AddFolder_Button_clicked()
{
    QString name = QInputDialog::getText(this,"Add folder","Folder name");

    if(!name.isEmpty())
    {
        if(name.size() > 32)
        {
            QMessageBox::warning(this,"Error","Folder name cannot exceed 32 characters!");
        }
        else
        {
            QString userName = TcpClient::instance().userName;

            PDU *pdu = mkPDU(curDirect.size() + 1);
            pdu->type = MSGTYPE::ADD_FOLDER;
            strncpy(pdu->meta,userName.toStdString().c_str(),userName.size());
            strncpy(pdu->meta + 32,curDirect.toStdString().c_str(),curDirect.size());
            memcpy(pdu->data,name.toStdString().c_str(),name.size());

            TcpClient::instance().cliSocket.write((char*)pdu,pdu->len);

            free(pdu);
            pdu = NULL;
        }
    }
    else
    {
        QMessageBox::warning(this,"Error","Foler name cannot be null!");
    }



}

