#include "friend.h"
#include "ui_friend.h"

Friend::Friend(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Friend)
{
    ui->setupUi(this);
}

Friend::~Friend()
{
    delete ui;
}

void Friend::on_online_Button_clicked()
{

}

