#include "header.h"

static int check_for_empty(int par_for_check_1, char *file_name);
static int check_for_digits(int par_for_check_1, char *buffer);
static void check_for_format(int par_for_chek_2, islands *island_par);

void mx_path_errore_content(int open_file, char *file_name, int *count, islands *island_par) {
    int digit = check_for_empty(open_file, file_name);
    *count = digit;
    check_for_format(open_file, island_par);
}

static int check_for_empty(int par_for_check_1, char *file_name) {
    char buffer[11];
    int cheker;
    
    cheker = read(par_for_check_1, buffer, 1);
    if (cheker != 1) {
        mx_printstr_errore_type("error: file ");
        mx_printstr_errore_type(file_name);
        mx_printstr_errore_type(" is empty\n");
        close(par_for_check_1);
        exit(0);
    }
    return check_for_digits(par_for_check_1, buffer);
}

static int check_for_digits(int par_for_check_1, char *buffer) {
    int cheker;
    int i = 1;

    cheker = read(par_for_check_1, &buffer[i], 1);
    for (; cheker > 0 && buffer[i] != '\n';) {
        if (buffer[i] < 48 || buffer[i] > 57) {
            mx_printstr_errore_type("error: line 1 is not valid\n");
            close(par_for_check_1);
            exit(0);
        }
        i++;
        cheker = read(par_for_check_1, &buffer[i], 1);
    }
    buffer[i] = '\0';
    return  mx_str_to_digits(buffer);
}

static void check_for_format(int par_for_chek_2, islands *island_par) {
    mx_scan_islands(par_for_chek_2, island_par);   
}
