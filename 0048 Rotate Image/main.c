#include <stdio.h>
#include <stdlib.h>

extern void rotate(int **matrix, int matrixSize, int *matrixColSize);

int main () {
    int **matrix;
    int matrixSize = 3;
    int matrixColSize[3] = {3, 3, 3};
    
    matrix = (int **) malloc (matrixSize * sizeof (int *));
    matrix[0] = (int *) malloc (matrixColSize[0] * sizeof (int));
    matrix[1] = (int *) malloc (matrixColSize[1] * sizeof (int));
    matrix[2] = (int *) malloc (matrixColSize[2] * sizeof (int));

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    
    printf ("Before rotation:\n");
    for (int i = 0; i < matrixSize; i++) { 
        for (int j = 0; j < matrixColSize[i]; j++) {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }

    rotate (matrix, matrixSize, &matrixColSize[0]);

    printf ("After rotation:\n");
    for (int i = 0; i < matrixSize; i++) { 
        for (int j = 0; j < matrixColSize[i]; j++) {
            printf ("%d ", matrix[i][j]);
        }
        printf ("\n");
    }

    return 0;
}