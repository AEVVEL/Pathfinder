#include "path.h"

void mx_push_bk(char *str, int len1, int len2, t_head *head) {
	int i = mx_check_originality(str, head, len1);
	int j = mx_check_originality(&str[len1 + 1], head, len2);
	t_path *node = NULL;
	t_path *tmp = NULL;

	node = mx_create_n(
	mx_strndup(&str[len1 + 1], len2), mx_atoi_plus(&str[len1 + len2 + 2]));
	mx_pushb(&head->island[i].connections, &node);
	tmp = mx_create_n(
	mx_strndup(str, len1), mx_atoi_plus(&str[len1 + len2 + 2]));
	mx_pushb(&head->island[j].connections, &tmp);
}
