#include "path.h"

static int i_open_file(t_head *head) {
	int fd = open(head->file, O_RDONLY);

	if (fd < 0)
    	mx_file_does_ext(head);
     return fd;
}

static void after_parse(t_head *head, char *string, int ret_fd) {
	int res = 0;
	int num_line = 1;
	int invalid = 0;

	while ((res = mx_read_line(&string, 20, '\n', ret_fd) > -1)) {
		num_line++;
	if (string[0] == '\0' || string[0] == '-') ///
		mx_line_invalid(num_line);
	invalid = mx_parse_line(head, string);
	free(string);
	if (invalid == -1)
		mx_line_invalid(num_line);
	}
}

void mx_read_num_islands(t_head *head, int fd) {
	int res;
	char *string = NULL;
	int num_line = 1;

	res = mx_read_line(&string, 20, '\n', fd);
	if (res < 0)
		mx_empty_file(head);
	if (string[0] == '\0')
		mx_line_invalid(num_line);//////
	head->num_islands = mx_atoi_plus(string);
	free(string);
	if (head->num_islands <= -1) 
		mx_exit_wrong_islands();

	head->island = (t_island *)malloc(sizeof(t_island) * head->num_islands);
	mx_memset(head->island, 0, sizeof(t_island) * head->num_islands);
}

void mx_parse(t_head *head) {
    int ret_fd = i_open_file(head);
	char *string = NULL;

	mx_read_num_islands(head, ret_fd);
	after_parse(head, string, ret_fd);
	if (head->num_islands > head->now_isld)
		mx_invalid_num_island();







		
}
