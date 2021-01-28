PATH_GNL=../gnl
FLAGS="-Wall -Werror -Wextra"
CC=clang

#gcc -Wall -Werror -Wextra testing-gnl.c ${PATH_GNL}/get_next_line.c ${PATH_GNL)/get_next_line_utils.c
$CC main-gnl.c ${PATH_GNL}/get_next_line.c ${FLAGS} -D BUFFER_SIZE=32
./a.out "lines2.txt"
