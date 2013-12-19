#include "testnullcounter.h"


void TestNULLCounter::testLinearArray()
{
    int array[5] = {0, 2, 0, 3, 1};
    ArrayNULLCounter<int> counter;
    QVERIFY(counter.countNULLElems(array, 5) == 2);
}

void TestNULLCounter::testMatrix()
{
    int** arr2 = new int*[2];
    arr2[0] = new int[5];
    arr2[1] = new int[5];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 5; j++)
            arr2[i][j] = 0;

    arr2[0][1] = 2;
    arr2[0][3] = 3;
    arr2[0][4] = 1;
    arr2[1][1] = 2;
    arr2[1][4] = 1;

    ArrayNULLCounter<int> counter2;
    QVERIFY(counter2.countNULLElems(arr2, 2, 5) == 5);
    delete[] arr2[0];
    delete[] arr2[1];
    delete[] arr2;
}
