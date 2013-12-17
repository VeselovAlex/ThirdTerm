#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QDebug>

#define OS_COUNT 4

class Computer : public QObject
{
    Q_OBJECT
public:
    enum OS
    {
        Windows = 0,
        Ubuntu,
        MacOS,
        TestOS
    };

    explicit Computer(OS os = TestOS, const QString& objectName = "", QObject *parent = 0);
    QList<Computer*> &connected()
    {
        return connectedTo;
    }

public slots:
    bool infectCurrent();
    void infectCurrentForced();
    void connectTo(Computer* computer);
    void disconnectFrom(Computer* computer);
    void disconnectAll();

private:
    OS curOS;
    int curInfProb;
    bool m_infected;
    QList<Computer*> connectedTo;
    static const int infProb[OS_COUNT];
};

#endif // COMPUTER_H
