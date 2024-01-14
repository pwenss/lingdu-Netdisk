#ifndef SRVSOCKET_H
#define SRVSOCKET_H
#include <QTcpSocket>
#include <QString>
#include <QFile>
#include "protocol.h"
#include "Database.h"

class srvSocket : public QTcpSocket
{
    Q_OBJECT;

    QString filePath;

public:
    srvSocket();
public slots:
    void recvMsg();
    void DownloadData();
};

#endif
