#include "header.h" 

static char *mx_scan_island(int par_for_check);

char **mx_scan_islands(int par_for_check, islands *island_par) {
    char *island = NULL;
    char **splited_island = NULL;

    island = mx_scan_island(par_for_check);
    //mx_printstr_errore_type(island);
    while (island != NULL) {
        splited_island = mx_strsplit(island, '-');
        island_par -> island_1 = splited_island[0];
        splited_island = mx_strsplit(splited_island[1], ',');
        island_par -> island_2 = splited_island[0];
        mx_printstr_errore_type(island_par -> island_1);
        mx_printstr_errore_type(island_par -> island_2);
        island = mx_scan_island(par_for_check);
        
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
