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

Friend& Friend::instance()
{
    static Friend _friend;
    return _friend;
}

void Friend::on_online_Button_clicked()
{

}

