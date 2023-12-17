/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QLineEdit *UserName_lineEdit;
    QLineEdit *Password_lineEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Login_Button;
    QPushButton *Register_Button;
    QPushButton *Logout_Button;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName("TcpClient");
        TcpClient->resize(278, 184);
        UserName_lineEdit = new QLineEdit(TcpClient);
        UserName_lineEdit->setObjectName("UserName_lineEdit");
        UserName_lineEdit->setGeometry(QRect(110, 40, 131, 31));
        Password_lineEdit = new QLineEdit(TcpClient);
        Password_lineEdit->setObjectName("Password_lineEdit");
        Password_lineEdit->setGeometry(QRect(110, 80, 131, 31));
        Password_lineEdit->setEchoMode(QLineEdit::Password);
        label = new QLabel(TcpClient);
        label->setObjectName("label");
        label->setGeometry(QRect(22, 42, 71, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(22, 90, 81, 16));
        label_2->setFont(font);
        Login_Button = new QPushButton(TcpClient);
        Login_Button->setObjectName("Login_Button");
        Login_Button->setGeometry(QRect(30, 140, 71, 31));
        Register_Button = new QPushButton(TcpClient);
        Register_Button->setObjectName("Register_Button");
        Register_Button->setGeometry(QRect(150, 140, 71, 31));
        Logout_Button = new QPushButton(TcpClient);
        Logout_Button->setObjectName("Logout_Button");
        Logout_Button->setGeometry(QRect(190, 120, 80, 24));

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        label->setText(QCoreApplication::translate("TcpClient", "UserName", nullptr));
        label_2->setText(QCoreApplication::translate("TcpClient", "Password", nullptr));
        Login_Button->setText(QCoreApplication::translate("TcpClient", "Login", nullptr));
        Register_Button->setText(QCoreApplication::translate("TcpClient", "Register", nullptr));
        Logout_Button->setText(QCoreApplication::translate("TcpClient", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
