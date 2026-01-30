#include <stdio.h>
#include <stdlib.h>

char *g_end = NULL;

int calculate (char *s) {
    int is_digit = 0;
    int temp = 0;
    int operand[2];
    int index = 0;
    char operator = '\0';
    int is_negative = 0;
    int brackets = 0;

    while (1) {
        if (*s >= '0' && *s <= '9') {
            if (is_digit == 0) {
                is_digit = 1;
                temp = 0;
            }
            temp = temp * 10 + (*s - '0');
        } else {
            if (is_digit == 1 || *s == ')' || *s == '\0') {
                if (is_digit == 1) {
                    is_digit = 0;
                    operand[index] = temp * ((is_negative == 1)? -1 : 1);
                    is_negative = 0;
                }
                if (index == 1 && operator != '\0') {
                    if (operator == '+') {
                        operand[0] = operand[0] + operand[1];
                    } else {
                        operand[0] = operand[0] - operand[1];
                    }
                    operator = '\0';
                }
                if (index == 0) ++index;

                if (*s == ')') {
                    if (brackets == 0) {
                        g_end = s;
                        break;
                    }
                    --brackets;
                } else if (*s == '\0') {
                    break;
                }

            } else if (*s == '(') {
                ++brackets;
                temp = calculate (++s);
                operand[index] = temp * ((is_negative == 1)? -1 : 1);
                is_negative = 0;
                if (index == 0) ++index;
                s = g_end - 1;
            }

            if (*s == '+' || *s == '-') {
                if (index == 0 || (index == 1 && operator != '\0')) {
                    if (*s == '-') is_negative = 1;
                } else {
                    operator = *s;
                }
            }
        }

        ++s;
    }

    return operand[0];
}

int main (int argc, char **argv) {
    if (argc == 2) {
        printf ("result = %d\n", calculate (argv[1]));
    }

    return 0;
}