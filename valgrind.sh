#!/usr/bin/env bash

if [ $1 = "C" ]
then
    /usr/bin/clang -ggdb main.c -std=c99 -Wall -Werror -o program && /usr/local/bin/valgrind ./program
elif [ $1 = "Cpp" ]
then
    /usr/bin/clang++ -std=c++11 -stdlib=libc++ main.cc -Wall -Werror -o program && /usr/local/bin/valgrind ./program
fi
