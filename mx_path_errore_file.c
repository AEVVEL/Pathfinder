#include "header.h"

static void check_for_equle(int num_of_par, int counter);

void mx_path_errore_file(int num_of_par, char **par, int *count, t_islands *island_par) {
    int check_for_file;
    int counter;

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
    counter = mx_path_errore_content(check_for_file, par[1], count, island_par);
    check_for_equle(*count, counter);
    close(check_for_file);
}

static void check_for_equle(int num_of_par, int counter) {
    if (num_of_par != counter) {
        mx_printstr_errore_type("error: invalid number of islands\n");
    }
}
