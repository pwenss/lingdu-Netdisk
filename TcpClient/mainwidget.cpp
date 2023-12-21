#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    fileW = new File;
    friendW = new Friend;

    ui->stackedWidget->addWidget(fileW);
    ui->stackedWidget->addWidget(friendW);

}


MainWidget::~MainWidget()
{
    delete ui;
}
MainWidget& MainWidget::instance()
{
    static MainWidget mw;
    return mw;
}

void MainWidget::on_Friend_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(friendW);
}

void MainWidget::on_File_Button_clicked()
{
    ui->stackedWidget->setCurrentWidget(fileW);
}

