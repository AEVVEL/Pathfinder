#include "header.h"

/*int mx_get_char_index(const char *str, char c) {
    int i = 0;

    if (str == '\0')
        return -2;
    while (str[i] != '\0') {
        if (str[i] == c)
            return i;
        i++;
    }
    return -1;
}  */ 

int mx_get_char_index(const char *str, char c) {
    int len = mx_strlen(str);
    int i;

    if (str == NULL) 
        return -2;
    for (i = 0; i < len; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
