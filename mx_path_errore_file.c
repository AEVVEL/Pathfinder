#include "header.h"

void mx_path_errore_file(int num_of_par, char **par, int *count, islands *island_par) {
    int check_for_file;

    if (num_of_par != 2) {
        mx_printstr_errore_type("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    check_for_file = open(par[1], O_RDONLY);
    if (check_for_file == -1) {
        mx_printstr_errore_type("error: file ");
        mx_printstr_errore_type(par[1]);
        mx_printstr_errore_type(" does not exist\n");
        exit(0);
    }
    mx_path_errore_content(check_for_file, par[1], count, island_par);
    close(check_for_file);
}
