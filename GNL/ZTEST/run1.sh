gcc -Wall -Werror -Wextra srcs/gnl_tester.c ../GNL.c ../get_next_line_utils.c -I ../ -D BUFFER_SIZE=1 && ./a.out
