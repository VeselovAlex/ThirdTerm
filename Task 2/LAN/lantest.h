#ifndef LANTEST_H
#define LANTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "lan.h"

class LANTest : public QObject
{
    Q_OBJECT
public:
    explicit LANTest(QObject *parent = 0);
private slots:
    void initTestCase();
    void testAddByPtr();
    void testAddByOS();
    void testTurns();
    void cleanupTestCase();
private:
    LAN* lan;

};

#endif // LANTEST_H
