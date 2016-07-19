#include "test_merge_sort.h"
#include <math.h>

bool is_sorted(int* numbers, int count) {
  double last_num = -INFINITY;
  bool sorted = true;

  for (int i = 0; i < count; ++i) {
    if (numbers[i] < (int)last_num) {
      sorted = false;
    }

    last_num = numbers[i];
  }

  return sorted;
}