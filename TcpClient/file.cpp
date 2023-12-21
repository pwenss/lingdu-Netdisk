#include "file.h"
#include "ui_file.h"

File::File(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::File)
{
    ui->setupUi(this);

    ui->Download_Button->hide();
    ui->Share_Button->hide();
    ui->Delete_Button->hide();
    iconLayout = new QGridLayout(ui->widget);

    iconLayout->setRowStretch(5, 1);//设置行比例系数
    iconLayout->setColumnStretch(6, 1);//设置列比例系数
}

File::~File()
{
    delete ui;
}

FolderIcon::FolderIcon(QString Name)
{
    QPushButton* Pb = new QPushButton();
    Pb->setIcon(QIcon("D:\\QT\\Project\\TcpClient\\folder.jpg")); // 替换成你的文件夹图标路径
    Pb->setStyleSheet("border: none;");
    Pb->setIconSize(QSize(50, 50)); // 调整图标大小
    Pb->setFixedSize(80, 80); // 调整按钮大小
    Pb->raise();

    button = Pb;
    name = Name;
}

FolderIcon::~FolderIcon()
{
    delete(button);
}

void File::on_AddFolder_Button_clicked()
{
    int ColumnSize = 5;

    QString name = "new";
    FolderIcon* i= new FolderIcon(name);
    icons.append(i);

    int row = icons.count()/ColumnSize;
    int column = icons.count()%ColumnSize;
    if (column==0)
        column=1;


    iconLayout->addWidget(i->button, row, column);

    ui->widget->update();

}

