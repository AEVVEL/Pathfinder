#include "header.h"

t_islands *mx_create_node(char *island_1, char *island_2, int distance) {
    t_islands *first_node = (t_islands*)malloc(sizeof(t_islands));

    first_node -> island_1 = island_1;
    first_node -> island_2 = island_2;
    first_node -> distance = distance;
    first_node -> next = NULL;
    return first_node;
}
