#include "header.h"

void mx_str_reverse(char *s) {
    char help = 0;
    int len = mx_strlen(s);
    char *str = s;
    int i = 0;

    if (s == NULL) 
        return;
    for (; i < len / 2; i++) {
        help = s[i];
        str[i] = str[len - 1 - i];
        str[len - 1- i] = help;
    }
    *s = *str;
} 
