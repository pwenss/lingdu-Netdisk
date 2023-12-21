#ifndef DataBase_H
#define DataBase_H

#include <QObject>
#include <QSqlDataBase>
#include <QSqlQuery>
#include "protocol.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    static DataBase& instance();
    void init();
    ~DataBase();

signals:

public slots:

private:
    QSqlDatabase db; // object to connect to server database
public:
    QString Register(const char *name, const char *pwd);  // Register
    QString Login(const char *name, const char *pwd);  // Login
    QString Logout(const char *name, const char *pwd);  // Logout
};

#endif