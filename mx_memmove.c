#include "header.h"

void *mx_memmove(void *dest, const void *src, size_t len) {
    char help[mx_strlen(src)];

    mx_memcpy(help, src, len);
    mx_memcpy(dest, help, len);
    return dest;
}
