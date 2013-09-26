#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addComputer()));
    QObject::connect(ui->startButton, SIGNAL(clicked()), this, SLOT(start()));
    QObject::connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeComputer()));
    QObject::connect(ui->tableNetwork, SIGNAL(cellClicked(int,int)), this, SLOT(plug(int,int)));
    QObject::connect(&network, SIGNAL(computerInfected(int)), this, SLOT(showInfected(int)));
}


Widget::~Widget()
{
    delete ui;
}

void Widget::addComputer()
{

    OpSystem* os;
    switch (ui->osComboBox->currentIndex()) {
    case 0:
    {
        os = new Windows();
        break;
    }
    case 1:
    {
        os = new Ubuntu();
        break;
    }
    case 2:
    {
        os = new MacOS();
        break;
    }
    case 3:
    {
        os = new VasyaOS();
        break;
    }
    default:
    {
        return;
        break;
    }
    }
    network.addComputer(os);
    ui->tableNetwork->setRowCount(ui->tableNetwork->rowCount() + 1);
    ui->tableNetwork->setColumnCount(ui->tableNetwork->columnCount() + 1);
    ui->tableStatus->setColumnCount(ui->tableStatus->columnCount() + 1);
}
void Widget::removeComputer()
{
    int num = ui->numSpinBox->value();
    network.removeComputer(num);

}

void Widget::start()
{
    network.externalInfection();
}

void Widget::plug(int c1, int c2)
{
    network.plug(c1, c2);
}

void Widget::showInfected(int pos)
{
    ui->tableStatus->item(0, pos)->setText("Infected");
}
