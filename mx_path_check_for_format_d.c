#include "header.h"

void mx_path_check_for_format_d(char *island_str, int counter) {
    int i = 0;

    if (island_str[0] == '\n') {
        mx_printstr_errore_type("error: line ");
        mx_printint_errore(counter);
        mx_printstr_errore_type(" is not valid");
        exit(0);
    }
    while (island_str[i] != '\n') {
        if (island_str[i] < 48 || island_str[i] > 57 || island_str[i] == '\0') {
            mx_printstr_errore_type("error: line ");
            mx_printint_errore(counter);
            mx_printstr_errore_type(" is not valid");
            exit(0);
        }
        i++;
    }
    return;
}
