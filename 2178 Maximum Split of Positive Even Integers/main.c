#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_LENGTH    100001

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* maximumEvenSplit(long long finalSum, int* returnSize) {
    char array1[MAX_ARRAY_LENGTH];
    long long *array2;
    long long n;
    long long sum;
    long long temp;
    int count;

    // exclude odd numbers
    if ((finalSum % 2) != 0) {
        *returnSize = 0;
        return NULL;
    }

    // find nearest sum of unique even numbers
    memset (array1, 0, sizeof (array1));

    n = 0;
    count = 0;
    do {
        ++n;
        array1[n] = 1;
        sum = (n + n * n);
        ++count;
    } while (sum < finalSum);

    // remove numbers to get closer to finalSum
    if (sum > finalSum) {
        do {
            temp = sum - n * 2;
            if (temp >= finalSum) {
                array1[n] = 0;
                --count;
                sum = temp;
            }
            --n;
        } while (sum != finalSum);
    }

    // build array
    array2 = (long long *) malloc (sizeof (long long) * count);
    for (n = 1, count = 0; n < MAX_ARRAY_LENGTH; ++n) {
        if (array1[n] == 1) {
            array2[count++] = n * 2;
        }
    }

    *returnSize = count;

    return array2;
}

int main (int argc, char **argv) {
    long long *evenArray;
    int returnSize;
    int index;

    if (argc == 2) {
        evenArray = maximumEvenSplit (atoll(argv[1]), &returnSize);

        printf ("[");
        for (index = 0; index < returnSize; ++index) {
            printf ("%d", evenArray[index]);
            if (index + 1 < returnSize) {
                printf (" ");
            }
        }
        printf ("]\n");
    }

    return 0;
}