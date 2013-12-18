#include "matrixFunctions.h"


bool **transitionMatrix(bool **source, int dim)
{
    assert(dim > 0);
    assert(source);

    bool **res  = new bool*[dim];
    bool **copy = new bool*[dim];

    for (int i = 0; i < dim; i++)
    {
        res[i]  = new bool[dim];
        copy[i] = new bool[dim];

        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            copy[i][j] = source[i][j];
        }
        copy[i][i] = 0;
        res[i][i] = 1;
    }

    bool * buffer = new bool[dim];

    for (int ord = 1; ord < dim; ord++)
    {
        for (int i = 0; i < dim; i++)
            buffer[i] = 0;

        for (int row = ord; row < dim; row++)
        {
            bool value = copy[row][ord - 1];
            if (value)
                for (int i = ord; i < dim; i++)
                    buffer[i] = buffer[i] || copy[row][i];
        }

        for (int row = ord; row < dim; row++)
        {
            res[row][ord - 1] = buffer[row];
            res[ord - 1][row] = buffer[row];
        }

    }

    delete[] buffer;
    for (int i = 0; i < dim; i++)
        delete[] copy[i];
    delete[] copy;

    return res;
}

void sortRowsByElement(bool **source, int nElem, int nFirstRow, int nRows, int* rowOrder)
{
    if (nRows <= 1)
        return;

    for (int i = 0; i < nRows; i++)
    {
        int row1 = i + nFirstRow;
        for (int j = i + 1; j < nRows; j++)
        {
            int row2 = j + nFirstRow;
            if (source[row1][nElem] < source[row2][nElem])
            {
                swapRows(source, row1, row2);
                std::swap(rowOrder[i], rowOrder[j]);
            }
        }
    }

    int nPositive = 0;
    for (int i = 0; i < nRows; i++)
        if (source[i + nFirstRow][nElem])
            nPositive++;


    int* posRowOrder = new int[nPositive];
    for (int i = 0; i < nPositive; i++)
        posRowOrder[i] = rowOrder[i];
    int* negRowOrder = new int[nRows - nPositive];
    for (int i = 0; i < nRows - nPositive; i++)
         negRowOrder[i] = rowOrder[nPositive + i];

    sortRowsByElement(source, nElem + 1, nFirstRow, nPositive, posRowOrder);
    sortRowsByElement(source, nElem + 1, nFirstRow + nPositive, nRows - nPositive, negRowOrder);

    for (int i = 0; i < nPositive; i++)
        rowOrder[i] = posRowOrder[i];
    for (int i = 0; i < nRows - nPositive; i++)
        rowOrder[nPositive + i] = negRowOrder[i];
}

int* sortRowsByAllElements(bool **source, int dim)
{
    int * rowOrder = new int[dim];
    for (int i = 0; i < dim; i++)
        rowOrder[i] = i;
    sortRowsByElement(source, 0, 0, dim, rowOrder);
    return rowOrder;
}

int* toCellDiagonal(bool **source, int dim)
{
    int* order = sortRowsByAllElements(source, dim);

    bool **buffer = new bool*[dim];

    for (int i = 0; i < dim; i++)
    {
        buffer[i]  = new bool[dim];
        for (int j = 0; j < dim; j++)
            buffer[i][j] = source[i][j];
    }

    for (int i = 0; i < dim; i++)
        if (i != order[i])
            for (int j = 0; j < dim; j++)
                source[j][i] = buffer[j][order[i]];

    for (int i = 0; i < dim; i++)
        delete[] buffer[i];
    delete[] buffer;

    return order;
}

int *cellSizes(bool **source, int dim)
{
    int row = 0;
    int* buf = new int[dim];
    int sum = 0;
    int nCells = 0;

    for (int col = dim - 1; col >= 0 && row < dim; col--)
    {
        bool value = source[row][col];
        if (value)
        {
            int size = (col + 1) - sum;
            buf[nCells++] = size;
            sum += size;
            row += size;
            col = dim;
        }
    }


    int* ret = new int[nCells + 1];
    ret[0] = nCells;
    for (int i = 1; i <= nCells; i++)
        ret[i] = buf[i - 1];

    delete[] buf;
    return ret;
}

void swapRows(bool **matrix, int row1, int row2)
{
    std::swap(matrix[row1], matrix[row2]);
}






