#include "DataBase.h"
#include <QMessageBox>
#include <QDebug>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
}

// single instance
DataBase &DataBase::instance()
{
    static DataBase instance;
    return instance;
}

// Connect to my database
void DataBase::init()
{
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("netdisk");
    db.setUserName("root");
    db.setPassword("@dhsieHs54/");
    if(db.open())
    {
        QSqlQuery query;
        query.exec("select * from account");
        while(query.next())
        {
            QString data = QString("%1,%2,%3").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
            qDebug() << data;
        }
    }
    else
    {
        QMessageBox::critical(NULL,"Error","Failed to open the database!");
    }
}


// destructor to close the database
DataBase::~DataBase()
{
    db.close();
}


// Execute function
// Here we let the database function return the message QString


// User task1: Register
// Insert the account to the database
QString DataBase::Register(const char *name, const char *pwd)
{
    QString sql = QString("insert into account(username,password) values(\'%1\',\'%2\')").arg(name).arg(pwd);
    QSqlQuery query;
    if (query.exec(sql))
        return REGISTER_SUCCESS;
    else
        return REGISTER_FAIL;
}

// User task2: Login
// Query the record
QString DataBase::Login(const char *name, const char *pwd)
{
    QString sql = QString("select * from account where username = \'%1\'").arg(name);
    QSqlQuery query;
    query.exec(sql);

    if(query.next())
    {
        QString sql = QString("select * from account where username = \'%1\' and password = \'%2\'").arg(name).arg(pwd);
        query.exec(sql);
        if(query.next())
            return LOGIN_SUCCESS;
        else
            return LOGIN_FAIL1;
    }
    else
        return LOGIN_FAIL2;

}

// User task3: Logout
// Query the record
QString DataBase::Logout(const char *name, const char *pwd)
{
    QString sql = QString("select * from account where username = \'%1\'").arg(name);
    QSqlQuery query;
    query.exec(sql);

    if(query.next())
    {
        QString sql = QString("select * from account where username = \'%1\' and password = \'%2\'").arg(name).arg(pwd);
        query.exec(sql);
        if(query.next())
        {
            QString sql = QString("delete from account where username = \'%1\' and password = \'%2\'").arg(name).arg(pwd);
            query.exec(sql);
            return LOGOUT_SUCCESS;
        }
        else
            return LOGOUT_FAIL1;
    }
    else
        return LOGOUT_FAIL2;

}
