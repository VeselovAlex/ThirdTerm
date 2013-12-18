#include "computertest.h"

ComputerTest::ComputerTest(QObject *parent) :
    QObject(parent)
{
}

void ComputerTest::initTestCase()
{
    computer1 = new Computer(Computer::TestOS, "1");
    computer2 = new Computer(Computer::TestOS, "2");

    QVERIFY2(computer1 != NULL, "Computer_1 init fail");
    QVERIFY2(computer2 != NULL, "Computer_2 init fail");
}

void ComputerTest::testInfectCurrent()
{
    QVERIFY2(computer1->infectCurrent(), "Computer_1 infect failed");
}

void ComputerTest::testConnect()
{
    computer1->connectTo(computer2);
    QVERIFY(computer1->connected().contains(computer2));
}

void ComputerTest::testDisconnect()
{
    computer1->disconnectFrom(computer2);
    QVERIFY(!computer1->connected().contains(computer2));
    QVERIFY(!computer2->connected().contains(computer1));
}

void ComputerTest::cleanupTestCase()
{
    delete computer1;
    delete computer2;
}


