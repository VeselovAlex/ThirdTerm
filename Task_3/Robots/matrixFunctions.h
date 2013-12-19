#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H
#include <assert.h>
#include <iostream>

/**
 * @brief transitionMatrix generates matrix, which is transition to symmetrical square matrix
 * @param source ptr to matrix
 * @param dim dimension of matrix
 * @return
 */
bool** transitionMatrix(bool** source, int dim);
/**
 * @brief toCellDiagonal tramforms matrix symmetrical square to cell-diagonal
 * @param source ptr to matrix
 * @param dim dimension of matrix
 * @return array, which contains the order of rows/columns in new matrix
 */
int *toCellDiagonal(bool** source, int dim);
/**
 * @brief cellSizes return the count and the dimections of cells in cell-diagonal matrix
 * @param source
 * @param dim
 * @return array of int, where first element contains the nuber of cells
 * and other contain the dimensions of cells
 */
int* cellSizes(bool** source, int dim);
/**
 * @brief swapRows swap two rows in matrix
 */
void swapRows(bool** matrix, int row1, int row2);
#endif // MATRIXFUNCTIONS_H
