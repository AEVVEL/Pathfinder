#include "path.h"

void mx_line_invalid(int num_line) {
	char *num_line_int = mx_itoa(num_line);

	mx_printerr("error: line ");
	mx_printerr(num_line_int);
	mx_printerr(" is not valid\n");
	exit(-1);
}
