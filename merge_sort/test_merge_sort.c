#include "test_merge_sort.h"
#include <math.h>

bool is_sorted(int* numbers, int count) {
  double last_num = -INFINITY;
  bool sorted = true;

  for (int i = 0; i < count; ++i) {
    if (numbers[i] < (int)last_num) {
      sorted = false;
      break;
    }

    last_num = numbers[i];
  }

  return sorted;
}

void print_ints(int numbers[], int count) {
  for (int i = 0; i < count; ++i) {
    printf("%d", numbers[i]);
    if (i < count - 1) {
      printf(", ");
    }
  }
}

bool contain_same_ints(int arr1[], int arr2[], int count) {
  for (int i = 0; i < count; ++i) {
    bool found = false;
    for (int j = 0; j < count; ++j) {
      if (arr1[i] == arr2[j]) {
        found = true;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }

  return true;
}
