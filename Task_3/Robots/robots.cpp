#include "robots.h"
#include "matrixFunctions.h"

bool RobotsGraph::ableToDestroy(bool **source, bool *robots, int dim)
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
