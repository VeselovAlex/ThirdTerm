#include "generator.h"

Generator::Generator(QObject *parent) :
    QObject(parent), m_state(Stopped)
{
}

void Generator::start()
{
    m_state = Running;
    impStart();
}

void Generator::stop()
{
    m_state = Stopped;
    impStop();
}

void Generator::pause()
{
    m_state = Paused;
    impPause();
}

void Generator::runNextTurn()
{
    if (m_state == Running)
        emit nextTurn();
    impNextTurn();
}


