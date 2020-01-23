#include "header.h"

int mx_str_to_digits(char *str_of_digits) {
    int rez = 0;
    int multiplier = 1;
    int i;

    mx_str_reverse(str_of_digits);
    for (i = 0; str_of_digits[i] != '\0' && str_of_digits[i] != '\n'; i ++) {
        rez += (str_of_digits[i] - 48) * multiplier;
        multiplier *= 10;
    }
    return rez;
}
