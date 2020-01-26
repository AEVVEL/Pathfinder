#include "path.h"

static void add_island(char *str, int len1, t_head *head);

int mx_parse_line(t_head *head, char *str) {
	int i = 0;
	int len_word1 = 0;
	int len_word2 = 0;

	while (mx_isalpha(str[i]))
		i++;	
	if (str[i] != '-' || str[i + 1] == ',') ////
		return -1;
	len_word1 = i;
	i = i + 1;
	while (mx_isalpha(str[i])) 
		i++;	
	if (str[i] != ',' || mx_atoi_plus(&str[i + 1]) <= 0) /// change == -1
		return -1;
	len_word2 = i - (len_word1 + 1);
	add_island(str, len_word1, head);
	add_island((&str[len_word1 + 1]), len_word2, head);
	mx_push_bk(str, len_word1, len_word2, head);
	return 0;
}

static void add_island(char *str, int len1, t_head *head) {
	int island = (mx_check_originality(str, head, len1));

	if (island == -1) {
		if (head->now_isld == head->num_islands)
			mx_invalid_num_island();
		head->island[head->now_isld].name = mx_strndup(str, len1);
		str = &str[len1 + 1];
		head->now_isld = head->now_isld + 1;
	}
}
