#include "header.h"

static void mx_recurcy(int m);

void mx_printint(int n) {
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    else if (n < 0){
        n *= -1;
        mx_printchar(45);
        mx_recurcy(n);
    }
    else {
        mx_recurcy(n);
    }
}

static void mx_recurcy(int m) {
    if (m / 10  > 0)
        mx_recurcy(m / 10);
    mx_printchar(m%10 + 48);
}
