#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
#include "protocol.h"

TcpClient::TcpClient(QWidget *parent) : QWidget(parent), ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    loadConfig();
    // when receive the response message, execute
    connect(&cliSocket, SIGNAL(readyRead()),this,SLOT(recvMsg()));  //QTconnect:  signal-->slot
    cliSocket.connectToHost(QHostAddress(IP),port); // Connect to server
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::loadConfig()
{
    QFile file(":/client.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray baData = file.readAll();
        QString strData = baData.toStdString().c_str();

        strData.replace("\r\n"," ");
        QStringList strList = strData.split(" ");
        IP = strList.at(0);
        port = strList.at(1).toUShort();
        qDebug() << "IP地址为：" << IP << "端口为：" << port;

        file.close();
    }
    else
    {
        QMessageBox::critical(this,"open config","open config failed");
    }
}



// Response Message Execute Function
void TcpClient::recvMsg()
{
    // Read the PDU
    qDebug() << cliSocket.bytesAvailable();
    uint len = 0;
    cliSocket.read((char*)&len,sizeof(uint));
    uint msgLen = len - sizeof(PDU);
    PDU *pdu = mkPDU(msgLen);
    cliSocket.read((char*)pdu+sizeof(uint),len-sizeof(uint));

    // Distinguished the message type and Execute
    switch (pdu->type)
    {
    // User Task1: Register
    case REGISTER:
    {
        if(0 == strcmp(pdu->meta,REGISTER_SUCCESS))
            QMessageBox::information(this,"Redister",REGISTER_SUCCESS);
        else if(0 == strcmp(pdu->meta,REGISTER_FAIL))
            QMessageBox::warning(this,"Register",REGISTER_FAIL);

        break;
    }
    // User Task2: Login
    case LOGIN:
    {
        if(0 == strcmp(pdu->meta,LOGIN_SUCCESS))
            QMessageBox::information(this,"Login",LOGIN_SUCCESS);
        else if(0 == strcmp(pdu->meta,LOGIN_FAIL1))
            QMessageBox::warning(this,"Login","Password error!\nPlease check again!");
        else
            QMessageBox::warning(this,"Login","User not exist!\nPlease check again!");
        break;
    }
    // User Task3: Logout
    case LOGOUT:
    {
        if(0 == strcmp(pdu->meta,LOGOUT_SUCCESS))
            QMessageBox::information(this,"Login",LOGOUT_SUCCESS);
        else if(0 == strcmp(pdu->meta,LOGOUT_FAIL1))
            QMessageBox::warning(this,"Login","Password error!\nPlease check again!");
        else
            QMessageBox::warning(this,"Login","User not exist!\nPlease check again!");
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


// User Task 1: Register ---- MSGTYPE::Login
void TcpClient::on_Register_Button_clicked()
{
    QString name = ui->UserName_lineEdit->text();
    QString pwd = ui->Password_lineEdit->text();

    // illeagl input
    if(name.isEmpty())
        QMessageBox::critical(this,"Register Error","UserName cannot be empty!");
    else if(pwd.isEmpty())
        QMessageBox::critical(this,"Register Error","Password cannot be empty!");\

    // send register message to server
    else
    {
        PDU *pdu = mkPDU(0);
        pdu->type = REGISTER;
        strncpy(pdu->meta,name.toStdString().c_str(),32);
        strncpy(pdu->meta + 32,pwd.toStdString().c_str(),32);
        cliSocket.write((char*)pdu,pdu->len);
        free(pdu);
        pdu = NULL;
    }

}

// User Task 2:  Login---- MSGTYPE::Login
void TcpClient::on_Login_Button_clicked()
{
    QString name = ui->UserName_lineEdit->text();
    QString pwd = ui->Password_lineEdit->text();

    // illeagl input
    if(name.isEmpty())
        QMessageBox::critical(this,"Login Error","UserName cannot be empty!");
    else if(pwd.isEmpty())
        QMessageBox::critical(this,"Login Error","Password cannot be empty!");

    // send register message to server
    else
    {
        PDU *pdu = mkPDU(0);
        pdu->type = LOGIN;
        strncpy(pdu->meta,name.toStdString().c_str(),32);
        strncpy(pdu->meta + 32,pwd.toStdString().c_str(),32);
        cliSocket.write((char*)pdu,pdu->len);
        free(pdu);
        pdu = NULL;
    }
}

// User Task3: Log out
void TcpClient::on_Logout_Button_clicked()
{
    QString name = ui->UserName_lineEdit->text();
    QString pwd = ui->Password_lineEdit->text();

    // illeagl input
    if(name.isEmpty())
        QMessageBox::critical(this,"Logout Error","UserName cannot be empty!");
    else if(pwd.isEmpty())
        QMessageBox::critical(this,"Logout Error","Password cannot be empty!");

    // send register message to server
    else
    {
        PDU *pdu = mkPDU(0);
        pdu->type = LOGOUT;
        strncpy(pdu->meta,name.toStdString().c_str(),32);
        strncpy(pdu->meta + 32,pwd.toStdString().c_str(),32);
        cliSocket.write((char*)pdu,pdu->len);
        free(pdu);
        pdu = NULL;
    }
}

