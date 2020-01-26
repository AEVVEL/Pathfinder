#include "path.h"

void mx_write_id(t_head *head) {
	int i = 0;
	int j = 0;
	t_path *tmp;

	while (i < head->num_islands) {
		tmp = head->island[i].connections;
		while (tmp) {
			j = 0;
			while (j < head->num_islands) {
				if (!mx_strcmp(tmp->name, head->island[j].name)) {
					tmp->id = j;
					break;
				}
				j++;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
