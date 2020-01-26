#include "path.h"

void mx_free_first_list(t_queue *queue) {
	t_queue *cpy;
	t_path *cpy_way;

	while (queue) {
		cpy = queue->next;
		while (queue->way) {
			cpy_way = queue->way->next;
			free(queue->way);
			queue->way = cpy_way;
		}
		free(queue);
		queue = cpy;
	}	
}
