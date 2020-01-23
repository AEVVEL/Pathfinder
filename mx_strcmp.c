#include "header.h"

int mx_strcmp(const char *s1, const char *s2) {
    int cheker = 0;
    int ss1;
    int ss2;

    while (s1[cheker] != '\0' || s2[cheker] != '\0') {
        ss1 = s1[cheker];
        ss2 = s2[cheker];
        if (ss1 != ss2)
            return ss1 - ss2;
        cheker++;
    }
    return 0;
}
