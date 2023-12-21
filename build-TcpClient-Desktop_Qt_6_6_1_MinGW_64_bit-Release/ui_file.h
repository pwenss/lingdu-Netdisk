/********************************************************************************
** Form generated from reading UI file 'file.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_H
#define UI_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_File
{
public:
    QPushButton *AddFolder_Button;
    QPushButton *Upload_Button;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *Download_Button;
    QPushButton *Share_Button;
    QPushButton *Delete_Button;
    QWidget *widget;

    void setupUi(QWidget *File)
    {
        if (File->objectName().isEmpty())
            File->setObjectName("File");
        File->resize(520, 419);
        AddFolder_Button = new QPushButton(File);
        AddFolder_Button->setObjectName("AddFolder_Button");
        AddFolder_Button->setGeometry(QRect(360, 10, 111, 31));
        Upload_Button = new QPushButton(File);
        Upload_Button->setObjectName("Upload_Button");
        Upload_Button->setGeometry(QRect(160, 10, 121, 31));
        pushButton_5 = new QPushButton(File);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 100, 80, 24));
        pushButton_6 = new QPushButton(File);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 140, 80, 24));
        pushButton_7 = new QPushButton(File);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 180, 80, 24));
        pushButton_8 = new QPushButton(File);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 220, 80, 24));
        pushButton_9 = new QPushButton(File);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 260, 80, 24));
        pushButton_10 = new QPushButton(File);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 300, 80, 24));
        Download_Button = new QPushButton(File);
        Download_Button->setObjectName("Download_Button");
        Download_Button->setGeometry(QRect(120, 10, 81, 31));
        Share_Button = new QPushButton(File);
        Share_Button->setObjectName("Share_Button");
        Share_Button->setGeometry(QRect(270, 10, 81, 31));
        Delete_Button = new QPushButton(File);
        Delete_Button->setObjectName("Delete_Button");
        Delete_Button->setGeometry(QRect(420, 10, 81, 31));
        widget = new QWidget(File);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 70, 371, 291));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Delete_Button->raise();
        Share_Button->raise();
        Download_Button->raise();
        AddFolder_Button->raise();
        Upload_Button->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        widget->raise();

        retranslateUi(File);

        QMetaObject::connectSlotsByName(File);
    } // setupUi

    void retranslateUi(QWidget *File)
    {
        File->setWindowTitle(QCoreApplication::translate("File", "Form", nullptr));
        AddFolder_Button->setText(QCoreApplication::translate("File", "Add Folder", nullptr));
        Upload_Button->setText(QCoreApplication::translate("File", "Upload", nullptr));
        pushButton_5->setText(QCoreApplication::translate("File", "Latest", nullptr));
        pushButton_6->setText(QCoreApplication::translate("File", "Photo", nullptr));
        pushButton_7->setText(QCoreApplication::translate("File", "Viedo", nullptr));
        pushButton_8->setText(QCoreApplication::translate("File", "Music", nullptr));
        pushButton_9->setText(QCoreApplication::translate("File", "document", nullptr));
        pushButton_10->setText(QCoreApplication::translate("File", "else", nullptr));
        Download_Button->setText(QCoreApplication::translate("File", "Download", nullptr));
        Share_Button->setText(QCoreApplication::translate("File", "Share", nullptr));
        Delete_Button->setText(QCoreApplication::translate("File", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class File: public Ui_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_H
