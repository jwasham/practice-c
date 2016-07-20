void merge(int numbers[], int low, int mid, int high) {
  // temp array for holding sorted items
  int b[high - low - 1];
  int i = low;
  int j = mid + 1;
  int k = 0;

  // merge items from list in order
  while (i <= mid && j <= high) {
    if (numbers[i] <= numbers[j]) {
      b[k++] = numbers[i++];
    } else {
      b[k++] = numbers[j++];
    }
  }

  // copy the remaining items to tmp array
  while (i <= mid) b[k++] = numbers[i++];
  while (j <= high) b[k++] = numbers[j++];

  --k;
  while (k >= 0) {
    numbers[low + k] = b[k];
    --k;
  }
}

void merge_sort(int numbers[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    merge_sort(numbers, low, mid);
    merge_sort(numbers, mid + 1, high);
    merge(numbers, low, mid, high);
  }
}
