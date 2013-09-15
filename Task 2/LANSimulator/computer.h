#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <cstdlib>
#include "opsystem.h"

class Computer : public QObject
{
    Q_OBJECT
public:
    explicit Computer(QObject *parent = 0, OpSystem* os = NULL) : QObject(parent), osys(os), infection(false){}

signals:
    bool infected(bool);
    bool virus();
public slots:
    void infect()
    {
        int rnd = rand() % 100;
        if (osys->probability() > rnd)
        {
            infection = true;
            emit infected(true);
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
