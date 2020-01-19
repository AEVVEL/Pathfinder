#include "header.h"

int main(int argv, char *argc[]) {
    char **name_file = argc;
    int number_of_island = 0;
    islands *island_par = mx_create_node(NULL, NULL, 0);

    mx_path_errore_file(argv, name_file, &number_of_island, island_par);
    //system("leaks -quiet a.out");
}
