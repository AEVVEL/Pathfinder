#include "path.h"

void mx_dup_way(t_queue *queue, t_path *src_tmp, int id, t_head *head) {
	t_path *copy_way = mx_n_create(src_tmp->id);
	t_path *ret_queue = copy_way;
	t_queue *new_list = NULL;

	src_tmp = src_tmp->next;
	while (src_tmp) {
		copy_way->next = mx_n_create(src_tmp->id);
		src_tmp = src_tmp->next;
		copy_way = copy_way->next;
	}
	copy_way->id = id;
	new_list = mx_create_list(ret_queue);
	new_list->next = queue->next;
	queue->next = new_list;
	if (!(head->island[id].index))
		queue->next->in_compatible = 0;
}

static int else_check(t_path *last_isld, t_head *head,
t_queue *tmp_list, t_path *tmp) {
	last_isld->next = mx_n_create(tmp->id);
	if (!head->island[tmp->id].index)
		tmp_list->in_compatible = 0;
	return 1;
}

void mx_check_all_conect(t_head *head, t_queue *queue, t_queue *tmp_list) {
	t_path *tmp = tmp_list->way;
	t_path *last_isld;
	int flag = 0;
	int sum_isld;

	while (tmp->next != NULL)
		tmp = tmp->next;
	last_isld = tmp;
	tmp = head->island[tmp->id].connections;
	while (tmp) {
		sum_isld = head->island[last_isld->id].index - tmp->distance;
		if (head->island[tmp->id].index == sum_isld) {
			 if (flag)
				 mx_dup_way(queue, tmp_list->way, tmp->id, head);
			 else {
				flag = flag + else_check(last_isld, head, tmp_list, tmp);
			 }
		}
		tmp = tmp->next;
	}
}

static void way_print(t_queue *tmp, t_head *head, int start, int finish) {
	mx_printstr("========================================\n");
	mx_printstr("Path: ");
	mx_printstr(head->island[start].name);
	mx_printstr(" -> ");
	mx_printstr(head->island[finish].name);
	mx_printstr("\n");
	mx_printstr("Route: ");
	mx_print_way(tmp->way, head);
	mx_printstr("\n");
	mx_printstr("Distance: ");
		if (mx_print_dist(tmp->way, head, 0)) {
			mx_printstr(" = ");
			mx_printint(head->island[tmp->way->id].index);
			mx_printstr("\n");
		}
		else {
			mx_printint(head->island[tmp->way->id].index);
			mx_printstr("\n");
		}
}

void mx_find_all_ways(t_head *head, int start, int finish) {
	t_queue *queue = mx_create_list(mx_n_create(finish));
	t_queue *tmp;
	int flag = 1;

	while (flag) {
		flag = 0;
		tmp = queue;
		while (tmp != NULL) {
			flag = flag + tmp->in_compatible;
			if (tmp->in_compatible)
				mx_check_all_conect(head, queue, tmp); 
			tmp = tmp->next;
		}
	}
	mx_sortpath(&queue);//////new
	for (tmp = queue; tmp; tmp = tmp->next) {
		 way_print(tmp, head, start, finish);
	mx_printstr("========================================\n");
	}
	mx_free_first_list(queue);	
}
