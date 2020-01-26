#include "path.h"

void mx_test_err(int argc) {
	if (argc != 2) {
		mx_printerr("usage: ./pathfinder [filename]\n");
		exit(EXIT_FAILURE);
	}
}
