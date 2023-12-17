#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QFile>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig(); // read Ip/Port from the config file


private slots:
    void recvMsg();    // receive response message from the server
    void on_Register_Button_clicked();
private slots:
    void on_Login_Button_clicked();

    void on_Logout_Button_clicked();

private:
    Ui::TcpClient *ui;
    QString IP;   // IP string
    quint16 port; // Port usigned short

    QTcpSocket cliSocket; // Tcp socket, used to connect to the server and transmit data
};
#endif
