#include "header.h"
 
void mx_printstr_errore_type(const char *s) {
    write(2, s, mx_strlen(s));
}
