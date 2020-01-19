#include "header.h"

char **mx_help_strsplit_dop(const char *s, char c, int count, char **arr);
bool mx_help_count_border(char *s, char c, char **start, char **end);

char **mx_strsplit(const char *s, char c) {
    char **arr = NULL;
    int count = 0;

    if (!s)
        return NULL;
    count = mx_count_words(s, c);
    arr = (char **) malloc((count+ 1) * sizeof(char *) );
    arr = mx_help_strsplit_dop(s, c, count, arr);
    arr[count] = NULL;
    return arr;
}

bool mx_help_count_border(char *s, char c, char **start, char **end) {
    for (*start = s; **start == c; (*start)++)
        if (**start =='\0')
            return false;
    for (*end = *start; **end != c && **end != '\0'; (*end)++)
    ;
    return true;
}

char **mx_help_strsplit_dop(const char *s, char c, int count, char **arr) {
    char *str= (char *)s;
    char *start = NULL;
    char *end = NULL;
    int a;
    int d = 0;;

    for (a = 0; a < count && mx_help_count_border(str, c,&start, &end); a++) {
        arr[a] = mx_strnew((size_t)(end - start + 1));
        for (str = start; str != end; str++) {
            arr[a][d] = *str;
            d++;
        }
        str = end + 1;
    }
    return arr;
}
