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
#include <QtGui/QIcon>
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
    QPushButton *UP_BUTTON;
    QPushButton *DOWN_BUTTON;
    QPushButton *REFRESH_BUTTON;

    void setupUi(QWidget *File)
    {
        if (File->objectName().isEmpty())
            File->setObjectName("File");
        File->resize(520, 390);
        File->setStyleSheet(QString::fromUtf8(""));
        AddFolder_Button = new QPushButton(File);
        AddFolder_Button->setObjectName("AddFolder_Button");
        AddFolder_Button->setGeometry(QRect(360, 10, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        AddFolder_Button->setFont(font);
        AddFolder_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Upload_Button = new QPushButton(File);
        Upload_Button->setObjectName("Upload_Button");
        Upload_Button->setGeometry(QRect(160, 10, 111, 31));
        Upload_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;\n"
""));
        pushButton_5 = new QPushButton(File);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 100, 80, 24));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        pushButton_6 = new QPushButton(File);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 140, 80, 24));
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        pushButton_7 = new QPushButton(File);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 180, 80, 24));
        pushButton_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        pushButton_8 = new QPushButton(File);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(20, 220, 80, 24));
        pushButton_8->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        pushButton_9 = new QPushButton(File);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(20, 260, 80, 24));
        pushButton_9->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        pushButton_10 = new QPushButton(File);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(20, 300, 80, 24));
        pushButton_10->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Download_Button = new QPushButton(File);
        Download_Button->setObjectName("Download_Button");
        Download_Button->setGeometry(QRect(120, 10, 91, 31));
        Download_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Share_Button = new QPushButton(File);
        Share_Button->setObjectName("Share_Button");
        Share_Button->setGeometry(QRect(270, 10, 81, 31));
        Share_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Delete_Button = new QPushButton(File);
        Delete_Button->setObjectName("Delete_Button");
        Delete_Button->setGeometry(QRect(420, 10, 81, 31));
        Delete_Button->setStyleSheet(QString::fromUtf8("font: 9pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        widget = new QWidget(File);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 80, 371, 291));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        UP_BUTTON = new QPushButton(File);
        UP_BUTTON->setObjectName("UP_BUTTON");
        UP_BUTTON->setGeometry(QRect(120, 50, 31, 31));
        UP_BUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  \n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/Up.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        UP_BUTTON->setIcon(icon);
        UP_BUTTON->setIconSize(QSize(25, 25));
        DOWN_BUTTON = new QPushButton(File);
        DOWN_BUTTON->setObjectName("DOWN_BUTTON");
        DOWN_BUTTON->setGeometry(QRect(150, 50, 31, 31));
        DOWN_BUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  \n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/DOWN.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        DOWN_BUTTON->setIcon(icon1);
        DOWN_BUTTON->setIconSize(QSize(25, 25));
        REFRESH_BUTTON = new QPushButton(File);
        REFRESH_BUTTON->setObjectName("REFRESH_BUTTON");
        REFRESH_BUTTON->setGeometry(QRect(180, 50, 31, 31));
        REFRESH_BUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  \n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Refresh.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        REFRESH_BUTTON->setIcon(icon2);
        REFRESH_BUTTON->setIconSize(QSize(25, 25));
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
        UP_BUTTON->raise();
        DOWN_BUTTON->raise();
        REFRESH_BUTTON->raise();

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
        pushButton_7->setText(QCoreApplication::translate("File", "Video", nullptr));
        pushButton_8->setText(QCoreApplication::translate("File", "Music", nullptr));
        pushButton_9->setText(QCoreApplication::translate("File", "document", nullptr));
        pushButton_10->setText(QCoreApplication::translate("File", "else", nullptr));
        Download_Button->setText(QCoreApplication::translate("File", "Download", nullptr));
        Share_Button->setText(QCoreApplication::translate("File", "Share", nullptr));
        Delete_Button->setText(QCoreApplication::translate("File", "Delete", nullptr));
        UP_BUTTON->setText(QString());
        DOWN_BUTTON->setText(QString());
        REFRESH_BUTTON->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class File: public Ui_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_H
