#ifndef TESTNULLCOUNTER_H
#define TESTNULLCOUNTER_H

#include <QTest>
#include "arraynullcounter.h"

class TestNULLCounter : public QObject
{
    Q_OBJECT
public:
    explicit TestNULLCounter(QObject *parent = 0) :QObject(parent) {}
private slots:
    void testLinearArray();
    void testMatrix();
};

#endif // TESTNULLCOUNTER_H
