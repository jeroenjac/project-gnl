PATH_GNL=../gnl
FLAGS="-Wall -Werror -Wextra"
CC=clang

#test param
SIZE=16

rm a.out
$CC main-gnl.c ${PATH_GNL}/get_next_line_utils.c ${PATH_GNL}/get_next_line.c ${FLAGS} -D BUFFER_SIZE=$SIZE
./a.out "oneline.txt" | cat -e  #15 chars + 1 = 16
#./a.out "lines2.txt" | cat -e
