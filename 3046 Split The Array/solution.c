#include <stdlib.h>
#include <stdbool.h>

bool isPossibleToSplit(int* nums, int numsSize) {
    int numTable[100] = {0};
    int index;

    for (index = 0; index < numsSize; ++index) {
        ++numTable[nums[index] - 1];
    }

    for (index = 0; index < 100; ++index) {
        if (numTable[index] > 2) {
            return false;
        }
    }

    return true;
}