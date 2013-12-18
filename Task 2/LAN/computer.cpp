#include "computer.h"

const int Computer::infProb[4] = {37, 19, 26, 100};

Computer::Computer(Computer::OS os, const QString &objectName, QObject *parent) :
    QObject(parent), curOS(os), curInfProb(infProb[curOS])
{
    setObjectName(objectName);
}

bool Computer::isInfected()
{
    return m_infected;
}

bool Computer::infectCurrent()
{
    int rndNumber = qrand() % 100;
    if (rndNumber < curInfProb)
    {
        infectCurrentForced();
        return true;
    }
    return false;
}

void Computer::infectCurrentForced()
{
    m_infected = true;
}

void Computer::connectTo(Computer *computer)
{
    if (connectedTo.contains(computer))
        return;
    connectedTo.append(computer);
}

void Computer::disconnectFrom(Computer *computer)
{
    if (!connectedTo.contains(computer))
        return;
    connectedTo.removeAll(computer);
}

void Computer::disconnectAll()
{
    connectedTo.clear();
}
