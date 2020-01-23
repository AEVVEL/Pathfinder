#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct s_islands_list {
    char *island_1;
    char *island_2;
    int distance;
    struct s_islands_list *next;
} t_islands;

int mx_get_char_index(const char *str, char c);
void mx_del_strarr(char ***arr);
void mx_printint(int n);
void mx_strdel(char **str);
void mx_path_check_for_format_d(char *island_str, int counter);
void mx_path_check_for_format_s(char *island_str, int counter);
void mx_path_check_for_format_c(char *island_str, int counter);
void mx_path_check_for_empty_list(t_islands *island_list, int counter);
void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
void mx_str_reverse(char *s);
void mx_printchar_errore(char c);
void mx_printint_errore(int n);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strnew(const int size);
void *mx_realloc(void *ptr, size_t size);
void mx_push_back(t_islands **list, char *island_1, char *island_2, int distance);
int mx_str_to_digits(char *str_of_digits);
int mx_scan_islands(int par_for_check, t_islands *island_par);
int mx_count_words(const char *str, char c);
void mx_printstr_errore_type(const char *s);
void *mx_memmove(void *dest, const void *src, size_t len);
void mx_path_errore_file(int num_of_par, char **par, int *count, t_islands *island_par);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void mx_print_strarr(char **arr, const char *delim);
int mx_path_errore_content(int open_file, char *file_name, int *count, t_islands *island_par);

bool mx_help_count_border(char *s, char c, char **start, char **end);
char **mx_help_strsplit_dop(const char *s, char c, int count, char **arr);
char **mx_strsplit(const char *s, char c);

void mx_path_create_sorted_list(t_islands *sorted_list, t_islands *island_par);


t_islands *mx_create_node(char* island_1, char *island_2, int distance);

#endif
