#include <stdio.h>
#include <stdlib.h>

int minOperations(int n) {
    int k;
    --n;
    k = (n - n % 2) / 2 + 1;
    return (n + n % 2) * k / 2;
}

int printArray (int n) {
    int *array;

    array = (int *) malloc (n * sizeof (int));
    for (int i = 0; i < n; ++i) {
        array[i] = 2 * i + 1;
        printf ("%d ", array[i]);
    }
    printf ("\n");
    free(array);
}

int main (void) {
  int n, result;

  printf ("Enter the value of n: ");
  scanf ("%d", &n);

  printArray (n);

  result = minOperations(n);
  printf ("Min operations: %d\n", result);

  return 0;
}