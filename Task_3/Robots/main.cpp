#include <iostream>
#include "matrixFunctions.h"

using std::cout;
using std::endl;

bool ableToDestroy(bool **source, bool *robots, int dim)
{
    bool** matrix = transitionMatrix(source, dim);
    int* order = toCellDiagonal(matrix, dim);
    int* cSizes = cellSizes(matrix, dim);

    int conCompNumber = cSizes[0];
    int pos = 0;

    for (int i = 1; i <= conCompNumber; i++)
    {
        int robotCount = 0;
        int size = cSizes[i];
        for (int j = pos; j < pos + size; j++)
        {
            if (robots[order[j]])
                robotCount++;
        }
        pos += size;

        if (robotCount == 1)
            return false;
    }

    delete[] cSizes;
    delete[] order;
    for (int i = 0; i < dim; i++)
        delete[] matrix[i];
    delete[] matrix;

    return true;
}

int main()
{
    bool src[5][5] =  {{1, 1, 0, 0, 0},
                       {1, 1, 1, 1, 0},
                       {0, 1, 1, 1, 0},
                       {0, 1, 1, 1, 1},
                       {0, 0, 0, 1, 1}};

    bool** test = new bool*[5];

    for (int i = 0; i < 5; i++)
    {
        test[i] = new bool[5];
        for (int j = 0; j < 5; j++)
            test[i][j] = src[i][j];
    }

    bool src2[5][5] = {{1, 1, 0, 0, 0},
                       {1, 1, 1, 0, 0},
                       {0, 1, 1, 1, 1},
                       {0, 0, 1, 1, 0},
                       {0, 0, 1, 0, 1}};

    bool** test2 = new bool*[5];

    for (int i = 0; i < 5; i++)
    {
        test2[i] = new bool[5];
        for (int j = 0; j < 5; j++)
            test2[i][j] = src2[i][j];
    }

    bool robots1[5] = {1, 1, 0, 0, 0};
    bool robots2[5] = {1, 0, 0, 0, 0};
    bool robots3[5] = {1, 1, 1, 1, 1};
    bool robots4[5] = {1, 1, 0, 1, 0};

    cout << "TEST 1" << endl;
    cout << (ableToDestroy(test, robots1, 5) ? "Destroy" : "Not destroy") << endl;
    cout << (ableToDestroy(test, robots2, 5) ? "Destroy" : "Not destroy") << endl;
    cout << (ableToDestroy(test, robots3, 5) ? "Destroy" : "Not destroy") << endl;
    cout << (ableToDestroy(test, robots4, 5) ? "Destroy" : "Not destroy") << endl;
    cout << endl << "TEST 2" << endl;
    cout << (ableToDestroy(test2, robots1, 5) ? "Destroy" : "Not destroy") << endl;
    cout << (ableToDestroy(test2, robots2, 5) ? "Destroy" : "Not destroy") << endl;
    cout << (ableToDestroy(test2, robots3, 5) ? "Destroy" : "Not destroy") << endl;
    cout << (ableToDestroy(test2, robots4, 5) ? "Destroy" : "Not destroy") << endl;

    for (int i = 0; i < 5; i++)
    {
        delete[] test[i];
        delete[] test2[i];
    }
    delete[] test;
    delete[] test2;

    return 0;
}

