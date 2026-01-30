void rotate (int** matrix, int matrixSize, int* matrixColSize) {
    int n, layer, first, last;
    n = matrixSize;

    for (layer = 0; layer < n / 2; ++layer) {
        first = layer;
        last  = n - 1 - layer;

        for (int i = 0; i < last - first; ++i) {
            int top = matrix[first][first + i];

            // left -> top
            matrix[first][first + i] = matrix[last - i][first];

            // bottom -> left
            matrix[last - i][first] = matrix[last][last - i];

            // right -> bottom
            matrix[last][last - i] = matrix[first + i][last];

            // top -> right
            matrix[first + i][last] = top;
        }
    }
}