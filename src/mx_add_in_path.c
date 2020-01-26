#include "path.h"

static void addprev(t_path **path) {
	t_path *slw = *path;
	t_path *fst = (*path)->next;

	slw->previous = NULL;
	while (fst) {
		fst->previous = slw;
		fst = fst->next;
		slw = slw->next;
	}
}

t_path *mx_lastn(t_path *path) {
	t_path *last = path;

	while(last->next)
		last = last->next;
	return last;
}

void mx_add_in_path(t_queue **queue) {
	int i = 0;
	t_queue *temp = *queue;

	while (temp) {
		addprev(&(temp->way));//add
		temp->num_p = i;
		i = i + 1;
		temp = temp->next;
	}
}
