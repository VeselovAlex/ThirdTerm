#ifndef LAN_H
#define LAN_H

#include <QObject>
#include <QVector>
#include "computer.h"
#include "wire.h"

class LAN : public QObject
{
    Q_OBJECT
public:
    explicit LAN(QObject *parent = 0) : QObject(parent), infected(0), nAll(0){}

signals:
    bool nComputersChanged(int);
    bool nInfectedChanged(int);
    bool nextLANTurn();
    bool computerInfected(int);
public slots:
    void externalInfection()
    {
        int looser = rand() % nAll;
        while (!infected)
            comps[looser]->infect();
    }

    void nextTurn()
    {
        emit nextLANTurn();
    }

    void addComputer(OpSystem* os)
    {
        Computer* nComp = new Computer(this, os);
        QObject::connect(nComp, SIGNAL(infected(Computer*)), this, SLOT(oneMoreInfected(Computer*)));
        comps.append(nComp);
        emit nComputersChanged(++nAll);
    }

    void removeComputer(int num)
    {
        delete comps[num];
        comps.remove(num);
        if (nAll > 0)
            emit nComputersChanged(--nAll);
    }

    void oneMoreInfected(Computer* sender)
    {
        infected++;
        emit computerInfected(comps.indexOf(sender));
        emit nInfectedChanged(infected);
        QObject::disconnect(sender, SIGNAL(infected(Computer*)), this, SLOT(oneMoreInfected(Computer*)));
    }

    void plug(int c1, int c2)
    {
        if ((c1 < nAll) && (c2 < nAll))
        {
            Computer *comp1 = comps[c1];
            Computer *comp2 = comps[c2];
            Wire* wire = new Wire(comp1, comp2);
        }
    }

private:
    QVector<Computer*> comps;
    int infected;
    int nAll;
};

#endif // LAN_H
