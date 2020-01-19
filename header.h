#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct islands_list {
    char *island_1;
    char *island_2;
    int distance;
    struct islands_list *next;
} islands;

int mx_get_char_index(const char *str, char c);
void mx_printint(int n);
void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_str_reverse(char *s);
char *mx_strnew(const int size);
void *mx_realloc(void *ptr, size_t size);
int mx_str_to_digits(char *str_of_digits);
char **mx_scan_islands(int par_for_check, islands *island_par);
int mx_count_words(const char *str, char c);
void mx_printstr_errore_type(const char *s);
void *mx_memmove(void *dest, const void *src, size_t len);
void mx_path_errore_file(int num_of_par, char **par, int *count, islands *island_par);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void mx_path_errore_content(int open_file, char *file_name, int *count, islands *island_par);

bool mx_help_count_border(char *s, char c, char **start, char **end);
char **mx_help_strsplit_dop(const char *s, char c, int count, char **arr);
char **mx_strsplit(const char *s, char c);


islands *mx_create_node(char* island_1, char *island_2, int distance);

#endif