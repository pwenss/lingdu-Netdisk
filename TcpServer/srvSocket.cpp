#include "srvSocket.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

bool readFile=false;
QFile file;
qint64 totalSize;
qint64 readSize;

srvSocket::srvSocket()
{
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));  // QTcpSocket::teadyRead() --> srvSocket::recvMsg()
}


// Receive the message form client
void srvSocket::recvMsg()
{

    if(readFile == true) // To receive the filedata send by the client, not the format of PDU
    {
        // The tcp cannot send all the filedata once, so we need to receive it multipul times, and each send isn't the type of PDU!
        qDebug()<<"Begin Read";

        // Read all send data
        QByteArray buff = readAll();
        file.write(buff);
        readSize += buff.size();
        qDebug()<<"Received the file : Currrent Received: "<<readSize<<"  TotalSize: "<<totalSize;

        if(readSize == totalSize)
        {
            file.close();
            readFile = false;

            PDU *respdu = mkPDU(0);
            respdu->type = UPLOAD;
            strcpy(respdu->meta,UPLOAD_SUCCESS);

            write((char*)respdu,respdu->len);

            delete(respdu);
        }
        else if(readSize > totalSize)
        {
            // Error 2: ReadSize more than totalSize

            file.close();
            readFile = false;
            PDU *respdu = NULL;
            respdu = mkPDU(0);
            respdu->type = UPLOAD;
            strcpy(respdu->meta,UPLOAD_FAIL2);

            write((char*)respdu,respdu->len);

            delete(respdu);
        }

        return;
    }

    // Read the PDU
    uint len = 0;
    read((char*)&len,sizeof(uint));
    uint msgLen = len - sizeof(PDU);
    PDU *pdu = mkPDU(msgLen);
    read((char*)pdu+sizeof(uint),len-sizeof(uint));

    qDebug()<<"Server Received PDU: "<<"len"<<pdu->len<<"type"<<pdu->type<<"dataLen"<<pdu->dataLen<<"meta"<<pdu->meta;

    switch (pdu->type)
    {
    // User Task1: Resgister
    case REGISTER:
    {
        // Read data
        char name[32] = {'\0'};
        char pwd[32] = {'\0'};
        strncpy(name,pdu->meta,32);
        strncpy(pwd,pdu->meta+32,32);

        // Process
        QString msg = DataBase::instance().Register(name,pwd);

        // Send response message to target client
        PDU *respdu = mkPDU(0);
        respdu->type = REGISTER;
        strcpy(respdu->meta,msg.toStdString().c_str());

        write((char*)respdu, respdu->len);

        free(respdu);
        break;
    }
    // User Task2: Login
    case LOGIN:
    {

        // Read data
        char name[32] = {'\0'};
        char pwd[32] = {'\0'};
        strncpy(name,pdu->meta,32);
        strncpy(pwd,pdu->meta+32,32);

        // Process
        QString msg = DataBase::instance().Login(name,pwd);

        // Send response message to target client
        PDU *respdu = mkPDU(0);
        respdu->type = LOGIN;
        strcpy(respdu->meta,msg.toStdString().c_str());

        write((char*)respdu, respdu->len);

        delete (respdu);
        break;
    }
    case LOGOUT:
    {

        // Read data
        char name[32] = {'\0'};
        char pwd[32] = {'\0'};
        strncpy(name,pdu->meta,32);
        strncpy(pwd,pdu->meta+32,32);

        // Process
        QString msg = DataBase::instance().Logout(name,pwd);

        // Send response message to target client
        PDU *respdu = mkPDU(0);
        respdu->type = LOGOUT;
        strcpy(respdu->meta,msg.toStdString().c_str());

        write((char*)respdu, respdu->len);

        delete (respdu);
        break;
    }

    // Folder task:
    case ROOTID:
    {
        char userName[32] = {'\0'};
        strncpy(userName,pdu->meta, 32);

        // Process
        QString id = DataBase::instance().SearchRootID(userName);

        PDU *respdu = mkPDU(0);
        respdu->type = ROOTID;
        strncpy(respdu->meta, id.toStdString().c_str(),id.size());

        qDebug()<<"Server Emitted PDU--Refresh:  "<<"len: "<<respdu->len<<"type: "<<respdu->type<<"dataLen: "<<respdu->dataLen<<"meta: "<<respdu->meta;

        write((char*)respdu, respdu->len);

        delete (respdu);
        break;

    }
    case REFRESH_FOLDER:
    {

        // Read data
        char userName[32] = {'\0'};
        char parent[32] = {'\0'};
        strncpy(userName,pdu->meta, 32);
        strncpy(parent,pdu->meta+32, 32);

        // Process
        QStringList folderList = DataBase::instance().RefreshFolder(userName, parent);
        QStringList fileList = DataBase::instance().RefreshFile(userName, parent);

        qDebug() << "Folder List:" <<folderList<<"  File List: "<<fileList;

        // Send response message to target client
        // Data format: [ name '//' ID # ...] '@' [ name # name #... ]
        QString combinedFolder = folderList.join('#'); // We use # to split the different string
        QString combinedFile = fileList.join('#');
        QString combinedString = combinedFolder+'@'+combinedFile;

        PDU *respdu = mkPDU(combinedString.size()+1);
        respdu->type = REFRESH_FOLDER;
        memcpy(respdu->data,combinedString.toStdString().c_str(),combinedString.size());

        qDebug()<<"Server Emitted PDU--Refresh:  "<<"len: "<<respdu->len<<"type: "<<respdu->type<<"dataLen: "<<respdu->dataLen<<"meta: "<<respdu->meta;

        write((char*)respdu, respdu->len);

        delete (respdu);
        break;
    }

    // Folder task:
    case ADD_FOLDER:
    {

        // Read data
        char userName[32] = {'\0'};
        char parent[32] = {'\0'};
        strncpy(userName,pdu->meta,32);
        strncpy(parent,pdu->meta+32,32);
        char folderName[32] = {'\0'};
        strncpy(folderName,pdu->data,pdu->dataLen);
        qDebug()<<"Folder name in server:" << folderName;

        // Process
        QString msg = DataBase::instance().AddFolder(userName,parent,folderName);

        // Send response message to target client
        PDU *respdu = mkPDU(0);
        respdu->type = ADD_FOLDER;
        strcpy(respdu->meta,msg.toStdString().c_str());

        write((char*)respdu, respdu->len);

        delete (respdu);
        break;
    }

    case DELETE:
    {

        // Read data
        char userName[32] = {'\0'};
        char parent[32] = {'\0'};
        strncpy(userName,pdu->meta,32);
        strncpy(parent,pdu->meta+32,32);

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

        // Process
        QString msgFolder = DataBase::instance().DeleteFolder(userName,parent,folderList);
        QString msgFile = DataBase::instance().DeleteFile(userName,parent,fileList);

        // Send response message to target client
        PDU *respdu = mkPDU(0);
        respdu->type = DELETE;
        strcpy(respdu->meta,msgFolder.toStdString().c_str());

        write((char*)respdu, respdu->len);

        delete respdu;
        break;
    }

    case UP_FOLDER:
    {
        // Read data
        char userName[32] = {'\0'};
        char ID[32] = {'\0'};
        strncpy(userName,pdu->meta,32);
        strncpy(ID,pdu->meta+32,32);

        // Process
        QString parent = DataBase::instance().UPFolder(userName,ID);
        qDebug()<<"Parent: "<<parent;

        // Send response message to target client
        PDU *respdu = mkPDU(0);
        respdu->type = UP_FOLDER;
        strncpy(respdu->meta, parent.toStdString().c_str(), 32);

        write((char*)respdu, respdu->len);

        delete respdu;
        break;
    }

    case UPLOAD:
    {
        // Read data
        char userName[32] = {'\0'};
        char parent[32] = {'\0'};
        char fileName[32] = {'\0'};
        strncpy(userName,pdu->meta, 32);
        strncpy(parent,pdu->meta+32, 32);
        strncpy(fileName,pdu->meta+64, 32);
        sscanf(pdu->data,"%lld",&totalSize);

        QString filePath = "D:\\QT\\Project\\NetDisk\\Data\\"+QString(userName)+'\\'+QString(parent)+'#'+QString(fileName);

        // Process
        QString msg = DataBase::instance().AddFile(userName,parent,fileName);

        if (msg==UPLOAD_SUCCESS)
        {
            file.setFileName(filePath);

            if(file.open(QIODevice::WriteOnly))
            {
                readFile = true;
                readSize = 0;
            }

            PDU* respdu = mkPDU(0);
            respdu->type = UPLOAD;
            strcpy(respdu->meta,UPLOAD_REQUEST_ACCEPTED);

            write((char*)respdu,respdu->len);

            delete(respdu);
            break;
        }
        else
        {
            // Error 1: File have already existed!
            PDU* respdu = mkPDU(0);
            respdu->type = UPLOAD;
            strcpy(respdu->meta,UPLOAD_FAIL1);

            write((char*)respdu,respdu->len);

            delete(respdu);
            break;
        }
    }

    case DOWNLOAD:
    {
        // Read data
        char userName[32] = {'\0'};
        char parent[32] = {'\0'};
        char fileName[32] = {'\0'};

        strncpy(userName,pdu->meta, 32);
        strncpy(parent,pdu->meta+32, 32);
        strncpy(fileName,pdu->meta+64, 32);

        filePath = "D:\\QT\\Project\\NetDisk\\Data\\"+QString(userName)+'\\'+QString(parent)+'#'+QString(fileName);

        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"Error: cannot open the file to download! ";
            PDU* respdu = mkPDU(0);
            respdu->type = DOWNLOAD;
            strcpy(respdu->meta,DOWNLOAD_FAIL);

            write((char*)respdu,respdu->len);

            delete(respdu);
            break;
        }
        qint64 fileSize = file.size() + 109; // The data transferred is always 109 bytes larger than the actual file size, nomatter the format?
        file.close();

        PDU* respdu = mkPDU(21);
        respdu->type = DOWNLOAD;
        strcpy(respdu->meta, DOWNLOAD_REQUEST_ACCEPTED);
        sprintf(respdu->data, "%lld", fileSize);

        write((char*)respdu,respdu->len);

        DownloadData(); // To unify with the format of file.h and to make sure the data won't be lost

        delete(respdu);
    }

    case SEARCH:
    {
        // Read data
        char userName[32] = {'\0'};
        char type[32] = {'\0'};

        strncpy(userName,pdu->meta, 32);
        strncpy(type,pdu->meta+32, 32);

        QStringList names = DataBase::instance().Search(userName, type);

        QString combinedString = names.join('#');
        PDU* respdu = mkPDU(combinedString.size()+1);
        respdu->type = SEARCH;
        strcpy(respdu->meta, SEARCH_SUCCESS);
        memcpy(respdu->data, combinedString.toStdString().c_str(), combinedString.size());

        write((char*)respdu,respdu->len);

        delete(respdu);
    }

    default:
    {
        break;
    }
    }
    delete pdu;


}

void srvSocket::DownloadData()
{
    char *buffer = new char[4096];
    int readSize=0;
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly)) // We have already verified that the file can be opened. Here is for the robustness.
    {
        qDebug()<<"Error: Cannot open the file! ";
        return;
    }

    while(true)
    {
        readSize = file.read(buffer,4096);
        // qDebug()<<"Send FileData: "<<readSize;

        if(readSize>0&&readSize<=4096)
            write(buffer, readSize);

        else if(readSize==0)
            break;

        else
        {
            qDebug()<<"Error: Unexpected Error: the send data is more than the file size!";
            break;
        }

    }

    delete[] buffer;

}
