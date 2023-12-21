// The sub widget

#ifndef FILE_H
#define FILE_H

#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

namespace Ui {
class File;
}
class FolderIcon
{
public:
    QPushButton* button;
    QString name;

public:
    FolderIcon(QString Name);
    ~FolderIcon();
};

class File : public QWidget
{
    Q_OBJECT

public:
    explicit File(QWidget *parent = nullptr);
    ~File();

public:
    Ui::File *ui;
    QList<FolderIcon*> icons; // list of icons
    QGridLayout* iconLayout;  // Lay out icon

private slots:
    void on_AddFolder_Button_clicked();
};

#endif // FILE_H
