#ifndef WIRE_H
#define WIRE_H

#include <QObject>
#include "computer.h"


class Wire : public QObject
{
    Q_OBJECT
public:
    Wire(Computer* comp1, Computer* comp2)
    {
        cmpt1 = comp1;
        cmpt2 = comp2;
        QObject::connect(cmpt1, SIGNAL(virus()), cmpt2, SLOT(infect()));
        QObject::connect(cmpt2, SIGNAL(virus()), cmpt1, SLOT(infect()));
        QObject::connect(cmpt1, SIGNAL(destroyed()), this, SLOT(deleteLater()));
        QObject::connect(cmpt2, SIGNAL(destroyed()), this, SLOT(deleteLater()));
    }
    ~Wire()
    {
        QObject::disconnect(cmpt1, SIGNAL(virus()), cmpt2, SLOT(infect()));
        QObject::disconnect(cmpt2, SIGNAL(virus()), cmpt1, SLOT(infect()));
    }

private:
    Computer* cmpt1;
    Computer* cmpt2;

};

#endif // WIRE_H
