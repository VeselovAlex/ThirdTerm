#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <cstdlib>
#include "opsystem.h"
#include <QDebug>

class Computer : public QObject
{
    Q_OBJECT
public:
    explicit Computer(QObject *parent = 0, OpSystem* os = NULL) : QObject(parent), osys(os), infection(false)
    {
        qDebug() << "Created";
    }

signals:
    bool infected(Computer*);
    bool virus();
public slots:
    void infect()
    {
        int rnd = rand() % 100;
        if (osys->probability() > rnd)
        {
            infection = true;
            qDebug() << "infected";
            emit infected(this);
        }
    }

    void turn()
    {
        if (infection)
            emit virus();
    }

private:
    OpSystem* osys;
    bool infection;
};

#endif // COMPUTER_H
