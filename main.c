#include "header.h"

int main(int argv, char *argc[]) {
    char **name_file = argc;
    int number_of_island = 0;
    t_islands *island_par = mx_create_node(NULL, NULL, -1);
    t_islands *sorted_list = mx_create_node(NULL, NULL, -1);

    mx_path_errore_file(argv, name_file, &number_of_island, island_par);
    mx_path_create_sorted_list(sorted_list, island_par);
    system("leaks -q a.out");
}
