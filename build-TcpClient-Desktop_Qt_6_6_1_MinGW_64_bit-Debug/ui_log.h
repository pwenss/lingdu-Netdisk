/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QLineEdit *UserName_lineEdit;
    QLineEdit *Password_lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Login_Button;
    QPushButton *Register_Button;
    QPushButton *Logout_Button;

    void setupUi(QWidget *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName("Log");
        Log->resize(281, 184);
        UserName_lineEdit = new QLineEdit(Log);
        UserName_lineEdit->setObjectName("UserName_lineEdit");
        UserName_lineEdit->setGeometry(QRect(110, 40, 131, 31));
        Password_lineEdit = new QLineEdit(Log);
        Password_lineEdit->setObjectName("Password_lineEdit");
        Password_lineEdit->setGeometry(QRect(110, 80, 131, 31));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(Log);
        label->setObjectName("label");
        label->setGeometry(QRect(22, 42, 71, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(Log);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(22, 90, 81, 16));
        label_2->setFont(font);
        Login_Button = new QPushButton(Log);
        Login_Button->setObjectName("Login_Button");
        Login_Button->setGeometry(QRect(30, 140, 71, 31));
        Register_Button = new QPushButton(Log);
        Register_Button->setObjectName("Register_Button");
        Register_Button->setGeometry(QRect(210, 110, 71, 31));
        Register_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	text-decoration: underline;\n"
"	font: italic 10pt \"Monospac821 BT\";\n"
"	color: rgb(85, 85, 255);\n"
"    border: none;\n"
"}"));
        Logout_Button = new QPushButton(Log);
        Logout_Button->setObjectName("Logout_Button");
        Logout_Button->setGeometry(QRect(150, 140, 81, 31));
        Logout_Button->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QWidget *Log)
    {
        Log->setWindowTitle(QCoreApplication::translate("Log", "TcpClient", nullptr));
        label->setText(QCoreApplication::translate("Log", "UserName", nullptr));
        label_2->setText(QCoreApplication::translate("Log", "Password", nullptr));
        Login_Button->setText(QCoreApplication::translate("Log", "Login", nullptr));
        Register_Button->setText(QCoreApplication::translate("Log", "Register", nullptr));
        Logout_Button->setText(QCoreApplication::translate("Log", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
