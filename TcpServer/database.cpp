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
    qDebug()<<"SQL: "<<sql;

    if (query.exec(sql))// If register success, then initial the root folder in the folder table !
    {
        QString sql = QString("insert into folder(user,name,parent) values(\'%1\','root','-1')").arg(name);
        QSqlQuery query;
        qDebug()<<"SQL: "<<sql;

        return REGISTER_SUCCESS;
    }
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


// Folder Task: Get the root ID
QString DataBase::SearchRootID(const char *name)
{
    QString sql = QString("SELECT ID FROM folder WHERE user = '%1' AND name = 'root'").arg(name);
    qDebug()<<"SQL: "<<sql;

    QSqlQuery query;
    query.exec(sql);
    query.next();
    QString id = query.value("ID").toString() ;

    return id;
}


// Folder task: Query Folder
QStringList DataBase::RefreshFolder(const char *userName, const char *parent)
{
    QStringList strList;
    QString sql = QString("SELECT name,ID FROM folder WHERE user = '%1' AND parent = '%2'").arg(userName).arg(parent);

    QSqlQuery query;
    query.exec(sql);
    qDebug() << "SQL--Refresh: "<<sql;
    while (query.next())
    {
        // unit: name "//" ID
        QString unit = query.value("name").toString() + "//" + query.value("ID").toString();
        strList.append(unit);
    }

    return strList;
}

// Folder task: Refresh file
QStringList DataBase::RefreshFile(const char *userName, const char *parent)
{
    QStringList strList;
    QString sql = QString("SELECT name FROM file WHERE user = '%1' AND parent = '%2'").arg(userName).arg(parent);

    QSqlQuery query;
    query.exec(sql);

    while (query.next())
    {
        QString unit = query.value("name").toString();
        strList.append(unit);
    }

    return strList;
}

// Folder task: ADD Folder / File
QString DataBase::AddFolder(const char *userName, const char *parent, const char *folderName)
{
    QString sql = QString("INSERT INTO folder (user, parent, name) VALUES (\'%1\', \'%2\', \'%3\')").arg(userName).arg(parent).arg(folderName);
    QSqlQuery query;
    qDebug() << "SQL: "<<sql;

    if(query.exec(sql))
        return ADD_FOLDER_SUCCESS;
    else
        return ADD_FOLDER_FAIL;

}

QString DataBase::AddFile(const char *userName, const char *parent, const char *fileName)
{
    char* format = std::strrchr(fileName, '.') + 1;
    QString sql = QString("INSERT INTO file (user, parent, name, format) VALUES (\'%1\', \'%2\', \'%3\', \'%4\')").arg(userName).arg(parent).arg(fileName).arg(format);
    QSqlQuery query;
    qDebug() << "SQL: "<<sql;

    if(query.exec(sql))
        return UPLOAD_SUCCESS;
    else
        return UPLOAD_FAIL1;

}


// Folder task: DELETE Folder/File
QString DataBase::DeleteFolder(const char *userName, const char *parent, QStringList idList)
{
    if(idList.empty())
        return DELETE_FOLDER_SUCCESS;

    QString sql;
    for (QString id : idList)
    {
        sql += QString("DELETE FROM folder WHERE user = \'%1\' AND parent = \'%2\' AND ID = \'%3\' ;").arg(userName).arg(parent).arg(id);
        sql += QString("DELETE FROM folder WHERE user = \'%1\' AND parent = \'%2\' AND ID >= 0 ;").arg(userName).arg(id);
    }
    QSqlQuery query;
    qDebug() << "SQL: "<<sql;

    if(query.exec(sql))
        return DELETE_FOLDER_SUCCESS;
    else
        return DELETE_FOLDER_FAIL;

}

QString DataBase::DeleteFile(const char *userName, const char *parent, QStringList nameList)
{
    if(nameList.empty())
        return DELETE_FOLDER_SUCCESS;

    QString sql;
    for (QString name : nameList)
        sql += QString("DELETE FROM file WHERE user = \'%1\' AND parent = \'%2\' AND name = \'%3\' ;").arg(userName).arg(parent).arg(name);

    QSqlQuery query;
    qDebug() << "SQL: "<<sql;

    if(query.exec(sql))
        return DELETE_FOLDER_SUCCESS;
    else
        return DELETE_FOLDER_FAIL;

}

// Folder task: UP Folder
QString DataBase::UPFolder(const char *userName, const char *ID)
{

    QString sql = QString("SELECT parent FROM folder WHERE user = \'%1\' AND  ID = \'%2\'").arg(userName).arg(ID);
    qDebug() << "SQL: "<<sql;
    QSqlQuery query;
    query.exec(sql);
    query.next();

    return query.value("parent").toString();
}

//Folder task: Search Files
QStringList DataBase::Search(const char *userName, const char *type)
{

    QStringList strList;
    QString sql;
    if (strcmp(type,"Time") == 0)
        sql = QString("SELECT name FROM file WHERE user = '%1' ORDER BY 'time'  DESC").arg(userName);
    else if (strcmp(type,"Photo") == 0)
        sql = QString("SELECT name FROM file WHERE user = '%1' AND  format IN ('jpg', 'png', 'bmp')").arg(userName);
    else if (strcmp(type,"Music") == 0)
        sql = QString("SELECT name FROM file WHERE user = '%1' AND format = 'mp3'").arg(userName);
    else if (strcmp(type,"Video") == 0)
        sql = QString("SELECT name FROM file WHERE user = '%1' AND format = 'mp4'").arg(userName);
    else if (strcmp(type,"Document") == 0)
        sql = QString("SELECT name FROM file WHERE user = '%1' AND format IN ( 'txt', 'ppt', 'pdf', 'doc', 'docx')").arg(userName);
    else if (strcmp(type,"Else") == 0)
        sql = QString("SELECT name FROM file WHERE user = '%1' AND format NOT IN ('txt', 'ppt', 'pdf', 'doc', 'docx', 'jpg', 'png', 'mp3', 'mp4')").arg(userName);

    QSqlQuery query;
    query.exec(sql);
    qDebug()<<"SQL: "<<sql;

    while (query.next())
    {
        QString unit = query.value("name").toString();
        strList.append(unit);
    }

    return strList;
}

