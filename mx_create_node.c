#include "header.h"

islands *mx_create_node(char *island_1, char *island_2, int distance) {
    islands *first_node = (islands*)malloc(sizeof(islands));

    first_node -> island_1 = island_1;
    first_node -> island_2 = island_2;
    first_node -> distance = distance;
    first_node -> next = NULL;
    return first_node;
}
