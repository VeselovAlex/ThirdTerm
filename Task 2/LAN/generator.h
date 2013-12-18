#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include "computer.h"
/**
 * @brief The Generator class emits signal to process next turn
 */
class Generator : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The State enum defines the state of signal generation
     */
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
    /**
     * @brief start Starts the signal generation
     */
    void start();
    /**
     * @brief stop Stops the signal generation
     */
    void stop();
    /**
     * @brief pause Pause the signal generation
     */
    void pause();
    /**
     * @brief runNextTurn emits signal to process next turn
     */
    void runNextTurn();
protected:
    /**
     * @brief impStart is used for extension of start()
     */
    virtual void impStart(){}
    /**
     * @brief impStop is used for extension of stop()
     */
    virtual void impStop(){}
    /**
     * @brief impPause is used for extension of pause()
     */
    virtual void impPause(){}
    /**
     * @brief impNextTurn is used for extension of nextTurn()
     */
    virtual void impNextTurn(){}

    State m_state;

};

#endif // GENERATOR_H
