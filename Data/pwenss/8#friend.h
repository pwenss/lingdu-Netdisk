// The sub widget

#ifndef FRIEND_H
#define FRIEND_H

#include <QWidget>

namespace Ui {
class Friend;
}

class Friend : public QWidget
{
    Q_OBJECT

public:
    explicit Friend(QWidget *parent = nullptr);
    ~Friend();
    static Friend& instance();

private slots:
    void on_online_Button_clicked();

private:
    Ui::Friend *ui;
};

#endif // FRIEND_H
