#include "quick_sort.h"

void quick_sort(int numbers[], int left, int right) {

  if (left == right)
    return;

  int i = left;
  int j = right;
  int temp = 0;

  int count = right - left;
  int pivot_mod = rand() % count;

  int pivot = numbers[left + pivot_mod];

  while (i <= j) {
    while (numbers[i] < pivot) ++i;
    while (numbers[j] > pivot) --j;

    if (i <= j) {
      temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
      ++i;
      --j;
    }
  }

  if (left < j) {
    quick_sort(numbers, left, j);
  }

  if (right > i) {
    quick_sort(numbers, i, right);
  }
}
