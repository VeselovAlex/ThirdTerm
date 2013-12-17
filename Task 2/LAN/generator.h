#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include "computer.h"

class Generator : public QObject
{
    Q_OBJECT
public:
    enum State
    {
        Stopped,
        Running,
        Paused
    };

    explicit Generator(QObject *parent = 0);
signals:
    bool nextTurn();
public slots:
    void start();
    void stop();
    void pause();
    void runNextTurn();
protected:
    virtual void impStart(){}
    virtual void impStop(){qDebug("Stopped");}
    virtual void impPause(){}
    virtual void impNextTurn(){}

    State m_state;
    Computer* m_first;

};

#endif // GENERATOR_H
