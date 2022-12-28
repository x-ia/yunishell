# /bin/bash
make
gcc -Wall -Wextra -Werror libtest.c mylib.a -Iinclude
./a.out
./a.out ""
./a.out "Good morning"
