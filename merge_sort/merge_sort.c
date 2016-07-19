void merge(int a[], int low, int mid, int high) {
  // temporary array for holding merged values
  int b[high - low - 1];
  int i = low;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= high) {
    if (a[i] <= a[j])
      b[k++] = a[i++];
    else
      b[k++] = a[j++];
  }

  while (i <= mid) b[k++] = a[i++];

  while (j <= high) b[k++] = a[j++];

  --k;
  while (k >= 0) {
    a[low + k] = b[k];
    --k;
  }
}

void merge_sort(int a[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
