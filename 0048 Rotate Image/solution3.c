static inline void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate (int** matrix, int matrixSize, int* matrixColSize) {
    int layer, step;
    int x, y, x1, y1, x2, y2;

    for (layer = 0; layer < matrixSize / 2; ++layer) {
        step = matrixSize - 1 - layer * 2;
        for (x = y = layer; x < matrixSize - layer - 1; ++x) {
            // top <-> left
            x1 = x;
            y1 = y;
            x2 = layer;
            y2 = step - (x1 - layer) + layer;
            swap (&matrix[y1][x1], &matrix[y2][x2]);

            // left <-> bottom
            x1 = x2;
            y1 = y2;
            x2 = step - (matrixSize - 1 - layer - y1) + layer;
            y2 = matrixSize - 1 - layer;
            swap (&matrix[y1][x1], &matrix[y2][x2]);

            // bottom <-> right
            x1 = x2;
            y1 = y2;
            x2 = matrixSize - 1 - layer;
            y2 = matrixSize - 1 - layer - (step - (matrixSize - 1 - layer - x1));
            swap (&matrix[y1][x1], &matrix[y2][x2]); 
        }
    }
}