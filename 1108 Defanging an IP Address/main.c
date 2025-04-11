#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * defangIPaddr(char * address){
    char *p, *result;
    int index = 0;

    result = (char *) malloc (sizeof (char) * 22);
    memset (result, 0, sizeof (char) * 22);

    p = address;
    while (*p != '\0') {
        if (*p != '.') {
            result[index++] = *p;
        } else {
            result[index++] = '[';
            result[index++] = '.';
            result[index++] = ']';
        }

        ++p;
    }

    return result;
}

int main (int argc, char **argv) {
    char *ipAddr = "1.1.1.1";
    char *result = NULL;

    result = defangIPaddr (ipAddr);
    printf ("result = %s\n", result);
    free (result);

    return 0;
}