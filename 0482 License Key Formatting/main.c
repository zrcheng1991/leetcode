#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* s, int k) {
    char *p;
    int len;
    char *temp;
    int index1 = 0;
    int resultSize;
    char *result;
    int index2 = 0;
    int partCount = 0;

    temp = (char *) malloc (sizeof (char) * k);
    memset (temp, 0, sizeof (char) * k);

    p = s;
    len = 0;
    while (*p != '\0') {
        if (*p != '-') {
            ++len;
        }
        ++p;
    }

    resultSize = len + len / k + 1;
    result = (char *) malloc (sizeof (char) * resultSize);
    memset (result, 0, sizeof (char) * resultSize);

    len %= k;

    while (1) {
        if (*s != '-' && *s != '\0') {
            if (index1 < k) {
                if (*s >= 'a' && *s <= 'z') {
                    temp[index1++] = *s - 0x20;
                } else {
                    temp[index1++] = *s;
                }
            }
        }

        if (index1 == k || (partCount == 0 && index1 == len) || *s == '\0') {
            if (index1 != 0) {
                if (partCount != 0) {
                    result[index2++] = '-';
                }
                memcpy (result + index2, temp, index1);
                index2 += index1;
                index1 = 0;
                memset (temp, 0, sizeof (char) * k);
                ++partCount;
            }
        }

        if (*s == '\0') {
            break;
        }

        ++s;
    }

    free (temp);

    return result;
}

int main (int argc, char **argv) {
    char *s = "5F3Z-2e-9-w";
    int k = 4;

    printf ("result: %s\n", licenseKeyFormatting (s, k));

    return 0;
}