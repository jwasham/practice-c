#include <stdio.h>
#include <string.h>  // for memcpy
#include "merge_sort.c"
#include "test_merge_sort.c"

int main(int argc, char* argv[]) {
  int num_count = 30;
  int original[] = {325432, 989,   547510, 3,   -93,  189019, 5042,  123,
                    597,    42,    7506,   184, 184,  2409,   45,    824,
                    4,      -2650, 9,      662, 3928, -170,   45358, 395,
                    842,    7697,  110,    14,  99,   221};

  int numbers[num_count];

  memcpy(numbers, original, sizeof numbers);

  printf("Sorting %d numbers...\n\n", num_count);

  merge_sort(numbers, 0, num_count - 1);

  if (is_sorted(numbers, num_count)) {
    printf("** SUCCESS! **\n");
  } else {
    printf("Uh oh - not in order.\n");
  }

  if (contain_same_ints(original, numbers, num_count)) {
    printf("** Contain the same elements! **\n");
  } else {
    printf("Uh oh - something is missing.\n");
  }

  print_ints(numbers, num_count);
  putchar('\n');
  print_ints(original, num_count);

  return 0;
}