#include "header.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    int i = 0;

    for (; i < (int)n; i++ ) {
        ((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
    }
    return dst;
}
