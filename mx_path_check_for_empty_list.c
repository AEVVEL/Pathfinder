#include "header.h"

void mx_path_check_for_empty_list(t_islands *island_list, int counter) {
    if (island_list->island_1 == NULL || island_list->island_2 == NULL ||
        island_list->distance == -1) {
            mx_printstr_errore_type("error: line ");
            mx_printint_errore(counter);
            mx_printstr_errore_type(" is not valid");
            exit(0);
        }
    return;
}
