#include "header.h"

void mx_printchar_errore(char c) {
    write(2, &c, 1);
}
