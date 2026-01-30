void rotate (int **matrix, int matrixSize, int *matrixColSize) {
    int n, m, i, j;
    n = matrixSize;
    
    // transpose the matrix
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // reverse each row
    for (i = 0; i < n; ++i) {
        m = matrixColSize[i];
        for (j = 0; j < m / 2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][m - 1 - j];
            matrix[i][m - 1 - j] = temp;
        }
    }
}