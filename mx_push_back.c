#include "header.h"

void mx_push_back(t_islands **list, char *island_1, char *island_2, int distance) {
    t_islands *l = NULL;
    t_islands *node = mx_create_node(island_1, island_2, distance);

    if (list == NULL)
        list = &node;
    if (*list == NULL)
        *list = node;
    else {
        l = *list;
        while (l->next != NULL)
            l = l->next;
        l->next = node;
    }
    l = NULL;
}
