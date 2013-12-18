#include "lantest.h"

LANTest::LANTest(QObject *parent) :
    QObject(parent)
{
}

void LANTest::initTestCase()
{
    lan = new LAN();
    QVERIFY(lan != NULL);
}

void LANTest::testAddByPtr()
{
    Computer* comp = new Computer(Computer::TestOS, "Comp_1");
    lan->addComputer(comp);
    QVERIFY(lan->getCureAsString().contains("Comp_1"));
    lan->setFirstInfectedComp(comp);
    QVERIFY(!comp->isInfected());
    QVERIFY(lan->getFrontAsString().contains("Comp_1"));
}

void LANTest::testAddByOS()
{
    lan->addComputer(Computer::TestOS);
    lan->addComputer(Computer::TestOS);
    QCOMPARE(lan->getCureAsString().count("Comp"), 2);
    QCOMPARE(lan->getFrontAsString().count("Comp"), 1);
}

void LANTest::testTurns()
{
    LAN* lan2 = new LAN;

    Computer *comp1 = new Computer(Computer::TestOS, "Comp_1");
    Computer *comp2 = new Computer(Computer::TestOS, "Comp_2");
    Computer *comp3 = new Computer(Computer::TestOS, "Comp_3");
    Computer *comp4 = new Computer(Computer::TestOS, "Comp_4");
    Computer *comp5 = new Computer(Computer::TestOS, "Comp_5");

    lan->addComputer(comp1);
    lan->addComputer(comp2);
    lan->addComputer(comp3);
    lan->addComputer(comp4);
    lan->addComputer(comp5);

    lan->setFirstInfectedComp(comp1);

    lan->connectComputers(comp1, comp2);
    lan->connectComputers(comp1, comp3);
    lan->connectComputers(comp4, comp3);
    lan->connectComputers(comp5, comp3);

    lan->turn();
    QVERIFY(comp1->isInfected());
    QVERIFY(!comp2->isInfected());
    QVERIFY(!comp3->isInfected());
    QVERIFY(!comp4->isInfected());
    QVERIFY(!comp5->isInfected());

    lan->turn();
    QVERIFY(comp1->isInfected());
    QVERIFY(comp2->isInfected());
    QVERIFY(comp3->isInfected());
    QVERIFY(!comp4->isInfected());
    QVERIFY(!comp5->isInfected());

    lan->turn();
    QVERIFY(comp1->isInfected());
    QVERIFY(comp2->isInfected());
    QVERIFY(comp3->isInfected());
    QVERIFY(comp4->isInfected());
    QVERIFY(comp5->isInfected());

}


void LANTest::cleanupTestCase()
{
    delete lan;
}

