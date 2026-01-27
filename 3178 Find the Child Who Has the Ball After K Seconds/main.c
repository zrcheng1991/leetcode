#include <stdio.h>
#include <stdlib.h>

int numberOfChild(int n, int k) {
    k %= (n * 2 - 2);
    if (k >= n) {
        return n * 2 - k - 2;
    }
    return k;
}

int main (void) {
  int n, k;

  printf ("number of children: ");
  scanf ("%d", &n);
  printf ("number of seconds: ");
  scanf ("%d", &k);

  printf ("Child %d has the ball.\n", numberOfChild (n, k));

  return 0;
}