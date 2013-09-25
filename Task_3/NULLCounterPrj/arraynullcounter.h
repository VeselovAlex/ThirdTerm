#ifndef ARRAYNULLCOUNTER_H
#define ARRAYNULLCOUNTER_H

template <typename T>
/**
 * @brief The class counts NULL elements in 1- and 2-dimensional arrays
 */
class ArrayNULLCounter
{
public:
    /**
     * @brief countNULLElems counting NULL elements in the linear array
     * @param array - pointer to linear array
     * @param size - capacity of the array
     * @return number of NULL elements
     */
    int countNULLElems(T* array, int size)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            if (array[i] == 0)
                sum++;
        return sum;
    }
    /**
     * @brief countNULLElems counting NULL elements in the matrix
     * @param array - pointer to matrix
     * @param nRow - number of rows of matrix
     * @param nCol - number of columns of matrix
     * @return number of NULL elements
     */
    int countNULLElems(T** array, int nRow, int nCol)
    {
        int sum = 0;
        for (int i = 0; i < nRow; i++)
            sum += countNULLElems(array[i], nCol);
        return sum;

    }

};

#endif // ARRAYNULLCOUNTER_H
