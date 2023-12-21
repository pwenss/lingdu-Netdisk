#include "srvSocket.h"
#include <QDebug>

srvSocket::srvSocket()
{
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));  // QTcpSocket::teadyRead() --> srvSocket::recvMsg()
}


// Receive the message form client
void srvSocket::recvMsg()
{

    qDebug() << this->bytesAvailable();
    uint len = 0;
    read((char*)&len,sizeof(uint));
    uint msgLen = len - sizeof(PDU);
    PDU *pdu = mkPDU(msgLen);
    read((char*)pdu+sizeof(uint),len-sizeof(uint));
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
        write((char*)respdu,respdu->len);
        free(respdu);
        respdu = NULL;
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

        write((char*)respdu,respdu->len);
        free(respdu);
        respdu = NULL;
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

        write((char*)respdu,respdu->len);
        free(respdu);
        respdu = NULL;
        break;
    }
    default:
    {
        break;
    }
    }
    free(pdu);
    pdu = NULL;
}
