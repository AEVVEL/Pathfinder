NAME = pathfinder

INC =  path.h 

SRC	= \
main.c \
mx_sortpath.c \
mx_add_in_path.c \
mx_atoi_plus.c \
mx_check_originality.c \
mx_create_n.c \
mx_empty_file.c \
mx_exit_wrong_islands.c \
mx_file_does_ext.c \
mx_find_all_ways.c \
mx_find_conection.c \
mx_invalid_num_island.c \
mx_isalpha.c \
mx_isdigit.c \
mx_line_invalid.c \
mx_parse.c \
mx_parse_line.c \
mx_print_way.c \
mx_printerr.c \
mx_push_bk.c \
mx_pushb.c \
mx_test_err.c \
mx_write_id.c \
mx_free_first_list.c \

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

CFLAGS = -std=c11 -Wall -Werror -Wextra -Wpedantic
		
all: install

install: 
		@make -sC libmx
		@cp $(addprefix src/, $(SRC)) . 
		@cp $(addprefix inc/, $(INC)) .
		@clang $(CFLAGS) -c $(SRC) -I $(INC)
		@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
		@mkdir -p obj
		@mv $(OBJ) ./obj

clean:
		@make clean -sC libmx
		@rm -rf $(INC) $(SRC) ./obj

uninstall: clean 
		@rm -rf $(NAME)

reinstall: uninstall install
