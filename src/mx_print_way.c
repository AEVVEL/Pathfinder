#include "path.h"

void mx_print_way(t_path *way, t_head *head) {
	if (way->next) {
		mx_print_way(way->next, head);
		mx_printstr(" -> ");
	}
	mx_printstr(head->island[way->id].name);
}

int mx_get_distance(t_path *conn, int id) {
	while(conn) {
		if (conn->id == id)
			return conn->distance;
		conn = conn->next;
	}
	return 0;
}

int mx_print_dist(t_path *way, t_head *head, int plus) {
	if (way->next->next) {
		plus = 1;
		mx_print_dist(way->next, head, plus);
		mx_printstr(" + ");
		mx_printint(mx_get_distance(head->island[way->id].connections,
		way->next->id));
		return 1;
	}
	else if (plus && way->next)
		mx_printint(mx_get_distance(head->island[way->id].connections,
		way->next->id));
	return 0;
}
