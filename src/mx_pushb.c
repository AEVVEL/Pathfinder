#include "path.h"

void mx_pushb(t_path **path, t_path **node) {
	t_path *tmp = *path;

	if (!tmp) {
		*path = *node;
		return;
	}
	while (tmp->next != NULL) {
		if (!mx_strcmp(tmp->name, (*node)->name)) {
			free((*node)->name);
			free((*node));
			return;
		}
		tmp = tmp->next;
	}
	tmp->next = *node;
}

