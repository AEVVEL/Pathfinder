#include "path.h"

void mx_file_does_ext(t_head *head) {
	mx_printerr("error: file ");
	mx_printerr(head->file);
	mx_printerr(" does not exist\n");
	exit(-1);
}
