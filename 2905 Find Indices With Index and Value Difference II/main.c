#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize) {
    int i, j, k, diff, found = 0, possible = 0;
    int *indices;

    indices = (int *) malloc (sizeof (int) * 2);
    indices[0] = -1;
    indices[1] = -1;
    *returnSize = 2;

    for (i = 0; i < numsSize && found == 0; ++i) {
        if (nums[i] < valueDifference) {
            continue;
        }

        for (k = indexDifference; k < numsSize; ++k) {
            j = i + k;
            if (j < numsSize) {
                diff = nums[i] - nums[j];
                if (diff < 0) {
                    diff *= -1;
                }
                if (diff >= valueDifference) {
                    indices[0] = i;
                    indices[1] = j;
                    found = 1;
                    break;
                }
            }

            j = i - k;
            if (j >= 0) {
                diff = nums[i] - nums[j];
                if (diff < 0) {
                    diff *= -1;
                }
                if (diff >= valueDifference) {
                    indices[0] = i;
                    indices[1] = j;
                    found = 1;
                    break;
                }
            }
        }
    }

    return indices;
}

int main (int argc, char **argv) {
    int nums[] = {0, 8, 2, 5, 10};
    int numsSize = sizeof(nums) / sizeof (int);
    int indexDifference = 0;
    int valueDifference = 10;
    int *indices;
    int returnSize;

    indices = findIndices (nums, numsSize, indexDifference, valueDifference, &returnSize);

    printf ("indices = [%d, %d]", indices[0], indices[1]);

    return 0;
}