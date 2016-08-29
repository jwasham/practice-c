#include <stdio.h>
/*
 * Just a simple program so I can inspect the assembly code.
 * gcc -O2 -S -c main.c
 */

int main(int argc, char *argv[]) {

  printf("I like the number %d.\n", 12345);

  return 0xf00d;
}