#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.c"
#include "test_merge_sort.c"

int main(int argc, char* argv[]) {
  int num_count = 30;
  int numbers[] = {325432, 989,   547510, 3,   -93,  189019, 5042,  123,
                   597,    42,    7506,   184, 184,  2409,   45,    824,
                   4,      -2650, 9,      662, 3928, -170,   45358, 395,
                   842,    7697,  110,    14,  99,   221};

  printf("Sorting %d numbers...\n\n", num_count);

  merge_sort(numbers, 0, num_count - 1);

  if (is_sorted(numbers, num_count)) {
    printf("** SUCCESS! ** \n");
  } else {
    printf("Uh oh - not in order:\n");
  }

  for (int i = 0; i < num_count; ++i) {
    printf("%d", numbers[i]);
    if (i < num_count - 1) {
      printf(", ");
    }
  }

  return 0;
}