#include "header.h" 

static char *mx_scan_island(int par_for_check);

char **mx_scan_islands(int par_for_check, islands *island_par) {
    char *island = NULL;
    char **splited_island_1 = NULL;
    char **splited_island_2 = NULL;
    int counter = 2;

    island = mx_scan_island(par_for_check);
    while (island != NULL) {
        mx_path_check_for_format_s(island, counter);
        splited_island_1 = mx_strsplit(island, '-');
        mx_path_check_for_format_c(splited_island_1[0], counter);
        island_par->island_1 = mx_strdup(splited_island_1[0]);
        splited_island_2 = mx_strsplit(splited_island_1[1], ',');
        mx_del_strarr(&splited_island_1);
        mx_path_check_for_format_c(splited_island_2[0], counter);
        mx_path_check_for_format_d(splited_island_2[1], counter);
        island_par->island_2 = mx_strdup(splited_island_2[0]);
        mx_del_strarr(&splited_island_2);
        mx_strdel(&island);
        island = mx_scan_island(par_for_check);
        counter++;
    }
    return NULL;
}

static char *mx_scan_island(int par_for_check) {
    int count = 0;
    int size_str = 1;
    int cheker;
    char *file_str = mx_strnew(size_str);

    cheker = read(par_for_check, &file_str[count], 1);
    if (cheker == 0)
        return NULL;
    while (file_str[count] != '\n' && file_str[count] != '\0') {
        count++;
        size_str++;
        file_str = mx_realloc(file_str, size_str);
        read(par_for_check, &file_str[count], 1);
    }
    return file_str;
}
