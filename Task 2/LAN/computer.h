#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QDebug>

#define OS_COUNT 4

class Computer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief The OS enum the list of accepted OS
     */
    enum OS
    {
        Windows = 0,
        Ubuntu,
        MacOS,
        TestOS
    };

    explicit Computer(OS os = TestOS, const QString& objectName = "", QObject *parent = 0);
    /**
     * @brief connected returns a list of computers connected to current
     * @return list of connected computers
     */
    QList<Computer*> &connected()
    {
        return connectedTo;
    }
    /**
     * @brief isInfected checks is current comp infected
     * @return true, if infected
     */
    bool isInfected();

public slots:
    /**
     * @brief infectCurrent try to infect current computer
     * @return true, if current infected
     */
    bool infectCurrent();
    /**
     * @brief infectCurrentForced infects this computer immediatly
     */
    void infectCurrentForced();
    /**
     * @brief connectTo connects computer to current
     * @param computer computer to connect to
     */
    void connectTo(Computer* computer);
    /**
     * @brief disconnectFrom disconnects computer from current
     * @param computer computer to disconnect from
     */
    void disconnectFrom(Computer* computer);
    /**
     * @brief disconnectAll disconnects all connected to current computers
     */
    void disconnectAll();

private:
    OS curOS;
    int curInfProb;
    bool m_infected;
    QList<Computer*> connectedTo;
    static const int infProb[OS_COUNT];
};

#endif // COMPUTER_H
