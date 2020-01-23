#include "header.h"

int mx_strlen(const char *s) {
    int len = 0;

    if (s == NULL)
        return 0;
    while (s[len] != '\0' && s[len] != '\n')
        len++;
    return len;
}
