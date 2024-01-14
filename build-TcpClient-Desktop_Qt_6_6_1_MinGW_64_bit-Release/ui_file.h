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
    QPushButton *Latest_Button;
    QPushButton *Photo_Button;
    QPushButton *Video_Button;
    QPushButton *Music_Button;
    QPushButton *Document_Button;
    QPushButton *Else_Button;
    QPushButton *Download_Button;
    QPushButton *Delete_Button;
    QWidget *widget;
    QPushButton *UP_BUTTON;
    QPushButton *DOWN_BUTTON;
    QPushButton *REFRESH_BUTTON;

    void setupUi(QWidget *File)
    {
        if (File->objectName().isEmpty())
            File->setObjectName("File");
        File->resize(669, 479);
        File->setStyleSheet(QString::fromUtf8(""));
        AddFolder_Button = new QPushButton(File);
        AddFolder_Button->setObjectName("AddFolder_Button");
        AddFolder_Button->setGeometry(QRect(390, 10, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        AddFolder_Button->setFont(font);
        AddFolder_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Upload_Button = new QPushButton(File);
        Upload_Button->setObjectName("Upload_Button");
        Upload_Button->setGeometry(QRect(150, 10, 111, 31));
        Upload_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;\n"
""));
        Latest_Button = new QPushButton(File);
        Latest_Button->setObjectName("Latest_Button");
        Latest_Button->setGeometry(QRect(20, 110, 81, 31));
        Latest_Button->setFont(font);
        Latest_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Photo_Button = new QPushButton(File);
        Photo_Button->setObjectName("Photo_Button");
        Photo_Button->setGeometry(QRect(20, 170, 81, 31));
        Photo_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Video_Button = new QPushButton(File);
        Video_Button->setObjectName("Video_Button");
        Video_Button->setGeometry(QRect(20, 230, 81, 31));
        Video_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Music_Button = new QPushButton(File);
        Music_Button->setObjectName("Music_Button");
        Music_Button->setGeometry(QRect(20, 300, 81, 31));
        Music_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Document_Button = new QPushButton(File);
        Document_Button->setObjectName("Document_Button");
        Document_Button->setGeometry(QRect(20, 360, 81, 31));
        Document_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Else_Button = new QPushButton(File);
        Else_Button->setObjectName("Else_Button");
        Else_Button->setGeometry(QRect(20, 420, 81, 31));
        Else_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        Download_Button = new QPushButton(File);
        Download_Button->setObjectName("Download_Button");
        Download_Button->setEnabled(false);
        Download_Button->setGeometry(QRect(260, 10, 91, 31));
        Download_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Download_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;\n"
"disabled { color: red };\n"
""));
        Download_Button->setAutoRepeatDelay(300);
        Delete_Button = new QPushButton(File);
        Delete_Button->setObjectName("Delete_Button");
        Delete_Button->setGeometry(QRect(530, 10, 81, 31));
        Delete_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);\n"
"border: 2px solid black; \n"
"border-radius: 10px;"));
        widget = new QWidget(File);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 80, 521, 381));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        UP_BUTTON = new QPushButton(File);
        UP_BUTTON->setObjectName("UP_BUTTON");
        UP_BUTTON->setGeometry(QRect(120, 50, 31, 31));
        UP_BUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  \n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/icons/Up.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        UP_BUTTON->setIcon(icon);
        UP_BUTTON->setIconSize(QSize(25, 25));
        DOWN_BUTTON = new QPushButton(File);
        DOWN_BUTTON->setObjectName("DOWN_BUTTON");
        DOWN_BUTTON->setGeometry(QRect(150, 50, 31, 31));
        DOWN_BUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  \n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/icons/DOWN.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        DOWN_BUTTON->setIcon(icon1);
        DOWN_BUTTON->setIconSize(QSize(25, 25));
        REFRESH_BUTTON = new QPushButton(File);
        REFRESH_BUTTON->setObjectName("REFRESH_BUTTON");
        REFRESH_BUTTON->setGeometry(QRect(180, 50, 31, 31));
        REFRESH_BUTTON->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;  \n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/icons/Refresh.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        REFRESH_BUTTON->setIcon(icon2);
        REFRESH_BUTTON->setIconSize(QSize(25, 25));
        Delete_Button->raise();
        Download_Button->raise();
        AddFolder_Button->raise();
        Upload_Button->raise();
        Latest_Button->raise();
        Photo_Button->raise();
        Video_Button->raise();
        Music_Button->raise();
        Document_Button->raise();
        Else_Button->raise();
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
        Latest_Button->setText(QCoreApplication::translate("File", "Latest", nullptr));
        Photo_Button->setText(QCoreApplication::translate("File", "Photo", nullptr));
        Video_Button->setText(QCoreApplication::translate("File", "Video", nullptr));
        Music_Button->setText(QCoreApplication::translate("File", "Music", nullptr));
        Document_Button->setText(QCoreApplication::translate("File", "Document", nullptr));
        Else_Button->setText(QCoreApplication::translate("File", "Else", nullptr));
        Download_Button->setText(QCoreApplication::translate("File", "Download", nullptr));
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
