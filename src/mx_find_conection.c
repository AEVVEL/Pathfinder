#include "path.h"

void mx_pback(t_path *queue, int id) {
	while (queue->next != NULL) {
		if (queue->next->id == id) 
			return;
		queue = queue->next;
	}
	queue->next = mx_n_create(id);
}

static void cmp_cand(t_path *queue, t_head *head,
int candidate, t_path *cpy) {
	head->island[cpy->id].index = candidate;
	mx_pback(queue, cpy->id);
}

void mx_write_index(t_head *head, int start) {
	t_path *queue = mx_n_create(start);
	t_path *cpy;
	int candidate;
	int next_isld;

	head->island[start].index = 0;
	while (queue) {
		cpy = head->island[queue->id].connections;
		while (cpy) {
			candidate = head->island[queue->id].index + cpy->distance;
		 	next_isld = head->island[cpy->id].index;
			if (next_isld > candidate)
				cmp_cand(queue, head, candidate, cpy);
			cpy = cpy->next;
		}
		cpy = queue->next;
		free(queue);
		queue = cpy;
	}
}

void mx_find_path(t_head *head, int start, int finish) {
	for (int i = 0; i < head->num_islands; i++) 
		head->island[i].index = 2147483647;
	mx_write_index(head, start);
	mx_find_all_ways(head, start, finish);

}

void mx_find_conection(t_head *head) {
	int i = 0;
	int j = 0;

	while (i < head->num_islands) {
		j = i + 1;
		while (j < head->num_islands) {
			mx_find_path(head, i, j);
			j++;
		}
		i++;
	}
}
