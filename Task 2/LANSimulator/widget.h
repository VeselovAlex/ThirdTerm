#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "lan.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void addComputer();
    void removeComputer();
    void start();
    void plug(int c1, int c2);
    void showInfected(int pos);

private:
    Ui::Widget *ui;
    LAN network;

};

#endif // WIDGET_H
