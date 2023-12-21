/********************************************************************************
** Form generated from reading UI file 'friend.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIEND_H
#define UI_FRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Friend
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *online_Button;
    QPushButton *pushButton_4;
    QListView *listView;

    void setupUi(QWidget *Friend)
    {
        if (Friend->objectName().isEmpty())
            Friend->setObjectName("Friend");
        Friend->resize(437, 461);
        pushButton = new QPushButton(Friend);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 50, 80, 24));
        pushButton_2 = new QPushButton(Friend);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(270, 100, 80, 24));
        online_Button = new QPushButton(Friend);
        online_Button->setObjectName("online_Button");
        online_Button->setGeometry(QRect(270, 150, 80, 24));
        pushButton_4 = new QPushButton(Friend);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(270, 210, 80, 24));
        listView = new QListView(Friend);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(10, 10, 401, 421));
        listView->raise();
        pushButton->raise();
        pushButton_2->raise();
        online_Button->raise();
        pushButton_4->raise();

        retranslateUi(Friend);

        QMetaObject::connectSlotsByName(Friend);
    } // setupUi

    void retranslateUi(QWidget *Friend)
    {
        Friend->setWindowTitle(QCoreApplication::translate("Friend", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Friend", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Friend", "PushButton", nullptr));
        online_Button->setText(QCoreApplication::translate("Friend", "showOnline", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Friend", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Friend: public Ui_Friend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIEND_H
