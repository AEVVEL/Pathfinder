#include "header.h"

void mx_path_check_for_format_s(char *island_str, int counter) {
    int i = 0;
    int first_counter = 0;
    int second_counter = 0;

    while (island_str[i] != '\n' && island_str[i] != '\0') {
        if (island_str[i] == '-')
            first_counter++;
        else if (island_str[i] == ',')
            second_counter++;
        i++;
    }
    if (first_counter != 1 || second_counter != 1) {
        mx_printstr_errore_type("error: line ");
        mx_printint_errore(counter);
        mx_printstr_errore_type(" is not valid");
        exit(0);
    }
    return;
}
