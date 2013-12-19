#include <iostream>
#include "matrixFunctions.h"
#include "test_robots.h"

using std::cout;
using std::endl;

int main()
{
    Test_Robots test;
    QTest::qExec(&test);
    return 0;
}

