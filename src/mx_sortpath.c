#include "path.h"

static int count_path(t_queue *queue) {
	t_queue *temp = queue;
	int count = 0;

	while(temp) {
		count++;
		temp = temp->next;
	}
	return count;
}

static int cmp(t_path *bnd, t_path *fst) {
	t_path *bond = mx_lastn(bnd);
	t_path *fast = mx_lastn(fst);
	
	while (bond && fast) {
		if (bond->id > fast->id)
			return 1;
		if (bond->id < fast->id)
			return 0;
		bond = bond->previous;
		fast = fast->previous;
	}
	if (bond && !fast)
		return 1;
	return 0;
}

static void swpd(t_queue **queue, t_queue **slow, t_queue **fast) {
	t_queue *temp = (*fast)->next;
	t_queue *cur = *queue;

	while(cur->next != *fast)
		cur = cur->next;
	cur->next = *slow;
	cur = *queue;
	if (*queue == *slow)
		*queue = *fast;
	else {
		while(cur && cur->next != *slow)
			cur = cur->next;
		cur->next = *fast;
	}
	(*fast)->next = (*slow)->next;
	(*slow)->next = temp;
}

static void swp(t_queue **queue, t_queue **slow, t_queue **fast) {
	t_queue *temp = (*fast)->next;
	t_queue *cur = *queue;

	if ((*slow)->next == *fast) {
		(*fast)->next = *slow;
		(*slow)->next = temp;
		if (*queue == *slow)
			*queue = *fast;
		else {
			while(cur && cur->next != *slow)
				cur = cur->next;
			cur->next = *fast;
		}
	}
	else swpd(&(*queue), &(*slow), &(*fast));
}

void mx_sortpath(t_queue **queue) {
	t_queue *slow = *queue;
	t_queue *fast = (*queue)->next;
	int size = count_path(*queue);

	mx_add_in_path(&(*queue));////////new
	for(int i = 0; i < size; i++) {
		slow = *queue;
		fast = slow->next;
		for (; slow->num_p != i; slow = slow->next)
			fast = slow->next;
		while(fast) {
			if (cmp(slow->way, fast->way) == 1) {
				swp(&(*queue), &slow, &fast);
				for (slow = *queue; slow->num_p != i; slow = slow->next)
					fast = slow->next;
			}
			else 
				fast = fast->next;
		}
	}
}
