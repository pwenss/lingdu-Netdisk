#include "file.h"
#include "ui_file.h"
#include <QInputDialog>
#include <QMessageBox>
#include "tcpclient.h"
#include "protocol.h"
#include <QDebug>

File::File(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::File)
{
    ui->setupUi(this);

    ui->Download_Button->hide();
    ui->Share_Button->hide();
    ui->Delete_Button->hide();

    iconLayout = new QGridLayout(ui->widget);
    iconLayout->setRowStretch(5, 1);
    iconLayout->setColumnStretch(6, 1);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    connect(buttonGroup, QOverload<QAbstractButton*,bool>::of(&QButtonGroup::buttonToggled),
            this, &File::onFolderIconChecked);  // button checked change: update shown buttons in file widget

    curDirect = "root";
}

File::~File()
{
    delete ui;
}

File& File::instance()
{
    static File file;
    return file;
}

FolderIcon::FolderIcon(QString Name)
{
    QToolButton* Tb = new QToolButton();
    Tb->setIcon(QIcon("D:\\QT\\Project\\NetDisk\\TcpClient\\folder.jpg"));

    Tb->setStyleSheet("border: none;");
    Tb->setIconSize(QSize(80, 80));
    Tb->setFixedSize(100, 100);
    Tb->raise();
    Tb->setText(Name);
    Tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Tb->setCheckable(true);
    Tb->setStyleSheet("QToolButton { border: none; }"
                      "QToolButton:checked { background-color: lightblue; }");
    button = Tb;
    name = Name;
}

FolderIcon::~FolderIcon()
{
    delete(button);
}

// Show the folder widget of current parent directory
void File::refresh()
{
    PDU *pdu = mkPDU(0);
    pdu->type = MSGTYPE::REFRESH_FOLDER;
    strncpy(pdu->meta, TcpClient::instance().userName.toStdString().c_str(), TcpClient::instance().userName.size());
    strncpy(pdu->meta+32, curDirect.toStdString().c_str(), curDirect.size());

    TcpClient::instance().cliSocket.write((char*)pdu,pdu->len);

    free(pdu);
    pdu = NULL;

}

void File::showFolder(QStringList nameList)
{
    int ColumnSize = 4;

    // Delete previous button
    for(int i=0; i<iconLayout->count(); ++i)
        iconLayout->removeItem(iconLayout->itemAt(i));
    for (QAbstractButton *button : buttonGroup->buttons())
    {
        buttonGroup->removeButton(button);
        delete button;
    }

    for (int i = 0; i < nameList.size(); ++i)
    {
        QString name = nameList.at(i);

        FolderIcon* icon= new FolderIcon(name);
        buttonGroup->addButton(icon->button);

        int row = i/ColumnSize;
        int column = i%ColumnSize;

        qDebug() << row <<column << name;
        iconLayout->addWidget(icon->button, row, column);

        connect(icon->button, &QToolButton::clicked, this, [=]() {
            onFolderIconClicked(icon);
        }); // Folder ICon click() --- onFolderIconClicked(icon)

    }

    ui->widget->update();
}

// Response Message Execute Function
void File::recvMsg(PDU* pdu)
{

    // Distinguished the message type and Execute
    switch (pdu->type)
    {
    // Folder Task1: Add folder
    case ADD_FOLDER:
    {
        if(0 == strcmp(pdu->meta,ADD_FOLDER_SUCCESS))
        {
            QMessageBox::information(this,"Add Folder",ADD_FOLDER_SUCCESS);
            refresh();
        }
        else if(0 == strcmp(pdu->meta,ADD_FOLDER_FAIL))
            QMessageBox::warning(this,"Add Folder","Folder has already existed!");

        break;
    }
    case REFRESH_FOLDER:
    {
        const char* charData = pdu->data;
        QString combinedString(charData);
        QStringList nameList = combinedString.split('#');

        qDebug() << "nameList:" <<nameList;
        showFolder(nameList);
    }
    case DELETE_FOLDER:
    {
        if(0 == strcmp(pdu->meta,DELETE_FOLDER_SUCCESS))
        {
            QMessageBox::information(this,"Delete Folder",DELETE_FOLDER_SUCCESS);
            refresh();
        }
        else if(0 == strcmp(pdu->meta,DELETE_FOLDER_FAIL))
            QMessageBox::warning(this,"Delete Folder","Unexpected Error!");

        break;
    }
    default:
    {
        break;
    }
    }

}





void File::on_AddFolder_Button_clicked()
{
    QString name = QInputDialog::getText(this,"Add folder","Folder name");

    if(!name.isEmpty())
    {
        if(name.size() > 32)
        {
            QMessageBox::warning(this,"Error","Folder name cannot exceed 32 characters!");
        }
        else
        {
            QString userName = TcpClient::instance().userName;

            PDU *pdu = mkPDU(name.size() + 1);
            pdu->type = MSGTYPE::ADD_FOLDER;
            strncpy(pdu->meta,userName.toStdString().c_str(),userName.size());
            strncpy(pdu->meta + 32,curDirect.toStdString().c_str(),curDirect.size());
            memcpy(pdu->data,name.toStdString().c_str(),name.size());

            TcpClient::instance().cliSocket.write((char*)pdu,pdu->len);

            free(pdu);
            pdu = NULL;
        }
    }
    else
    {
        QMessageBox::warning(this,"Error","Foler name cannot be null!");
    }


}

void File::onFolderIconClicked(FolderIcon* icon)
{
    // icon->button->update();
    // ui->widget->update();
}

// Update shown buttons
void File::onFolderIconChecked()
{
    int checkedCount = buttonGroup->checkedButton() ? 1 : 0;
    if (checkedCount)
    {
        ui->Upload_Button->hide();
        ui->AddFolder_Button->hide();

        ui->Download_Button->show();
        ui->Share_Button->show();
        ui->Delete_Button->show();
    }
    else
    {
        ui->Upload_Button->show();
        ui->AddFolder_Button->show();

        ui->Download_Button->hide();
        ui->Share_Button->hide();
        ui->Delete_Button->hide();
    }
}

// Delete folder
void File::on_Delete_Button_clicked()
{
    // Get all selected button
    QList<QAbstractButton*> checkedButtons;
    QStringList names;
    for (QAbstractButton* button : buttonGroup->buttons())
    {
        if (button->isChecked())
            checkedButtons.append(button);
    }
    // Delete
    for (QAbstractButton* button : checkedButtons)
        names.append(button->text());
    QString combinedString = names.join("#");

    PDU *pdu = mkPDU(combinedString.length() + 1);
    pdu->type = MSGTYPE::DELETE_FOLDER;
    strncpy(pdu->meta,TcpClient::instance().userName.toStdString().c_str(),TcpClient::instance().userName.size());
    strncpy(pdu->meta + 32,curDirect.toStdString().c_str(),curDirect.size());
    memcpy(pdu->data,combinedString.toStdString().c_str(),combinedString.size());

    TcpClient::instance().cliSocket.write((char*)pdu,pdu->len);

    free(pdu);
    pdu = NULL;

}

