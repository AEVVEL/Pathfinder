#include "header.h"

static void add_to_list(char *island, t_islands *sorted_list);

void mx_path_create_sorted_list(t_islands *sorted_list, t_islands *island_par) {
    while (island_par->next != NULL) {
        add_to_list(island_par->island_1, sorted_list);
        add_to_list(island_par->island_2, sorted_list);
        island_par = island_par->next;
    }
}

static void add_to_list(char *island, t_islands *sorted_list) {
    t_islands *help_node = sorted_list;

    while (help_node->next != NULL) {
        if (mx_strcmp(help_node->island_1, island) == 0)
            return;
        help_node = help_node->next;
    }
    help_node->island_1 = island;
    mx_push_back(&sorted_list, NULL, NULL, -1);
}
