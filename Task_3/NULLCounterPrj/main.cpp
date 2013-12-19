#include <iostream>
#include "testnullcounter.h"
using namespace std;

int main()
{
    TestNULLCounter test;
    QTest::qExec(&test);
    return 0;
}

