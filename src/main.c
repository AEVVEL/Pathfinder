#include "path.h"

int main(int argc, char* argv[]) {
	t_head head;

	mx_memset(&head, 0, sizeof(t_head));
	mx_test_err(argc);
	head.file = argv[1]; 
	mx_parse(&head);
	mx_write_id(&head);
	mx_find_conection(&head);
//system("leaks pathfinder");
}
