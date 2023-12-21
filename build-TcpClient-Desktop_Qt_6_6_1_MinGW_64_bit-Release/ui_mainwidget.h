/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QPushButton *Friend_Button;
    QPushButton *File_Button;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(773, 516);
        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(160, 20, 601, 471));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        Friend_Button = new QPushButton(MainWidget);
        Friend_Button->setObjectName("Friend_Button");
        Friend_Button->setGeometry(QRect(20, 30, 101, 31));
        File_Button = new QPushButton(MainWidget);
        File_Button->setObjectName("File_Button");
        File_Button->setGeometry(QRect(20, 100, 101, 31));

        retranslateUi(MainWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        Friend_Button->setText(QCoreApplication::translate("MainWidget", "Friend", nullptr));
        File_Button->setText(QCoreApplication::translate("MainWidget", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
