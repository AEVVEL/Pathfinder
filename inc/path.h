#ifndef PATH_H
#define PATH_H

#include "libmx/inc/libmx.h"

typedef struct s_path {
	struct s_path *next;
	char *name;
	int distance;
	int id;
	struct s_path *previous;
} t_path;

typedef struct s_queue {
	t_path *way; //послідовність вертикальних кімнат
	struct s_queue *next; // послідовність горизонтальних кімнат
	int in_compatible; //незавершина кімната 
	int num_p;
} t_queue;

typedef struct s_island {
	char *name;
	t_path *connections;
	int index;
} t_island;

typedef struct s_head {
	char *file;
	t_island *island;
	int num_islands;
	int now_isld;
} t_head;

t_path *mx_lastn(t_path *path);///
void mx_add_in_path(t_queue **queue);///
void mx_sortpath(t_queue **queue);////
void mx_printerr(const char *s);
void mx_parse(t_head *head);
int mx_parse_line(t_head *head, char *string);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
int mx_atoi_plus(char *str);
void mx_push_bk(char *str, int len1, int len2, t_head *head);
int mx_check_originality(char *island1, t_head *head, int len1);
t_path *mx_create_n(char *name, int distance);
void mx_pushb(t_path **path, t_path **node);
void mx_pback(t_path *queue, int id);
void mx_write_id(t_head *head);
void mx_find_all_ways(t_head *head, int start, int finish);
t_path *mx_n_create(int id);
void mx_free_first_list(t_queue *queue);
t_queue *mx_create_list(t_path *way);
void mx_print_way(t_path *way, t_head *head);
int mx_print_dist(t_path *way, t_head *head, int plus);
int mx_get_distance(t_path *conn, int id);
void mx_check_all_conect(t_head *head, t_queue *queue, t_queue *tmp_list);
void mx_dup_way(t_queue *queue, t_path *src_tmp, int id, t_head *head);	
void mx_find_conection(t_head *head);
void mx_write_index(t_head *head, int start);
void mx_find_path(t_head *head, int start, int finish);
void mx_read_num_islands(t_head *head, int fd);

//error
void mx_test_err(int argc);
void mx_exit_wrong_islands(void);
void mx_file_does_ext(t_head *head);
void mx_empty_file(t_head *head);
void mx_line_invalid(int num_line);
void mx_invalid_num_island(void);

 #endif
