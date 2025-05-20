#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    int i, j, index;
    int **result, *data, *columnSizes;

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (m * n < originalSize) {
        return NULL;
    }

    result      = (int **) malloc (sizeof (int *) * m);
    data        = (int *) malloc (sizeof (int) * m * n);
    columnSizes = (int *) malloc (sizeof (int) * m);

    for (i = 0; i < m && i * n < originalSize; ++i) {
        result[i] = data + i * n;
        for (j = 0; j < n && i * n + j < originalSize; ++j) {
            data[i * n + j] = original[i * n + j];
        }
        columnSizes[i] = j;
    }
    if (i != m || (m == 1 && j < n)) {
        return NULL;
    }

    *returnSize = i;
    *returnColumnSizes = columnSizes;
    return result;
}