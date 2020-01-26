#include "path.h"



int mx_check_str(char *argv) {
	char *str = mx_file_to_str(argv);

	if (str = NULL)
		return;
	if (str[mx_strlen(str) - 1] != '\n')
		return -1;
		
}
