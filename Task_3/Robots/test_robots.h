#ifndef TEST_ROBOTS_H
#define TEST_ROBOTS_H

#include <QObject>
#include <QtTest/QTest>
#include <fstream>
#include <iostream>

#include "robots.h"

using std::cout;
using std::endl;

class Test_Robots : public QObject
{
    Q_OBJECT
public:
    explicit Test_Robots(QObject *parent = 0);
private slots:
    void initTestCase();
    void testDestroy();
    void testDestroy_data();
    void cleanupTestCase();
private:
    bool*** testMatrixArray;
    bool**  testRobotsArray;
    bool**  testResultArray;

    int matrixCount;
    int robotsCount;
};

#endif // TEST_ROBOTS_H
