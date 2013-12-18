#ifndef COMPUTERTEST_H
#define COMPUTERTEST_H

#include <QTest>
#include "computer.h"

class ComputerTest : public QObject
{
    Q_OBJECT
public:
    explicit ComputerTest(QObject *parent = 0);
private slots:
    void initTestCase();
    void testInfectCurrent();
    void testConnect();
    void testDisconnect();
    void cleanupTestCase();
private:
    Computer* computer1;
    Computer* computer2;
};

#endif // COMPUTERTEST_H
