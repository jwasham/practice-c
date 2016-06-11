#include <stdio.h>  // for IO
#include <stdlib.h> // for malloc
#include <assert.h>
#include "array.h"
#include "array.c"

void run_example();

// Implements a vector (called JArray) from a C array.

int main(int argc, char* argv[]) {

  run_all_tests();
  run_example();

  return EXIT_SUCCESS;
}

void run_example() {
  int capacity = 0;

  printf("Enter many numbers would you like to store: ");
  scanf("%d", &capacity);

  printf("You'll be storing %d numbers.\n", capacity);

  // make it so

  JArray *aptr = jarray_new(capacity);

  int append_success = 0;
  for (int d = 1; d <= capacity; ++d) {
    append_success = jarray_append(aptr, d);
    if (! append_success) {
      printf("No more room.\n");
    }
  }

  jarray_print(aptr);

  jarray_destroy(aptr);
}