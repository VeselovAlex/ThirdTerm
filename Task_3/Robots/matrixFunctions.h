#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H
#include <assert.h>
#include <iostream>

bool** transitionMatrix(bool** source, int dim);
int *toCellDiagonal(bool** source, int dim);
int* cellSizes(bool** source, int dim);
void swapRows(bool** matrix, int row1, int row2);
#endif // MATRIXFUNCTIONS_H
