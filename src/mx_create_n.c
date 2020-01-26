#include "path.h"

t_path *mx_create_n(char *name, int distance) {
	t_path *node = (t_path*)malloc(sizeof(t_path));

	if (distance == 0 || distance == -1)//
		exit(-1);
	node->name = name;
	node->distance = distance;
	node->next = NULL;
	return node;
}

t_queue *mx_create_list(t_path *way) {
	t_queue *route = (t_queue *)malloc(sizeof(t_queue));

    route->way = way;
    route->in_compatible = 1;
    route->next = NULL;
    return route;
}

t_path *mx_n_create(int id) {
	t_path *tmp = (t_path*)malloc(sizeof(t_path));

	tmp->id = id;
	tmp->next = NULL;
	return tmp;
}
