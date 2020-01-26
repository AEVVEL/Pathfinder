#include "path.h"

void mx_empty_file(t_head *head) {
	mx_printerr("error: file ");
	mx_printerr(head->file);
	mx_printerr(" is empty\n");
	exit(-1);
}
