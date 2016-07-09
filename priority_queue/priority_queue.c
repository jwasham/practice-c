#include "priority_queue.h"

void insert(MaxHeap* heap, int value) {
  // indexing at 1, not 0, to make parent finding clearer
  //     1 2 3 4 5 - index
  //     0 1 1 2 2 - parent

  if (heap->size == heap->capacity) {
    printf("Cannot add more items.");
    exit(EXIT_FAILURE);
  }

  heap->size++;
  heap->elements[heap->size] = value;

  sift_up(heap, heap->size);
}

void print_data(MaxHeap* heap) {
  for (int i = 1; i <= heap->size; ++i) {
    printf("%4d |", heap->elements[i]);
  }
  putchar('\n');
}

void sift_up(MaxHeap* heap, int i) {
  int temp;
  int parent;

  while (i > 1) {
    parent = i / 2;
    if (heap->elements[parent] < heap->elements[i]) {
      temp = heap->elements[i];
      heap->elements[i] = heap->elements[parent];
      heap->elements[parent] = temp;
    }
    i = parent;
  }
}

int get_max(MaxHeap* heap) {
  return heap->elements[1];
}

int extract_max(MaxHeap* heap) {
  int max = heap->elements[1];

  heap->elements[1] = heap->elements[heap->size];
  heap->size--;

  sift_down(heap, 1);

  return max;
}

void sift_down(MaxHeap* heap, int index) {
  int i = index;
  int swap_index;

  // no children - nothing to do
  // one child - swap if needed
  // 2 children - swap with larger if needed

  while (i * 2 <= heap->size) {
    int left_child_index = 2 * i;
    int right_child_index = 2 * i + 1;
    bool has_left = (left_child_index <= heap->size);
    bool has_right = (right_child_index <= heap->size);

    if (has_left && has_right) {
      int left_child_value = heap->elements[left_child_index];
      int right_child_value = heap->elements[right_child_index];

      if (left_child_value > right_child_value) {
        swap_index = left_child_index;
      } else { // right is greater or same
        swap_index = right_child_index;
      }
    } else if (has_left) {
      swap_index = left_child_index;
    } else if (has_right) {
      swap_index = right_child_index;
    } else {
      break;
    }

    if (heap->elements[swap_index] > heap->elements[i]) {
      int temp = heap->elements[i];
      heap->elements[i] = heap->elements[swap_index];
      heap->elements[swap_index] = temp;

      i = swap_index;
    } else {
      break;
    }
  }
}

int get_size(MaxHeap* heap) {
  return heap->size;
}

void remove_node(MaxHeap* heap, int index) {
  heap->elements[index] = heap->elements[heap->size];
  heap->size--;

  sift_down(heap, index);
}

bool is_empty(MaxHeap* heap) {
  return heap->size == 0;
}

void heap_sort(int* numbers, int count) {
  int temp;
  heapify(numbers, count);
  for (int i = count - 1; i > 0 ; --i) {
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;

    percolate_down(numbers, i, 0);
  }
}

void heapify(int* numbers, int count) {
  for (int i = count/2 - 1; i >= 0; --i) {
    percolate_down(numbers, count, i);
  }
}

void percolate_down(int* numbers, int count, int index) {
  int i = index;
  int swap_index;

  // no children - nothing to do
  // one child - swap if needed
  // 2 children - swap with larger if needed

  while ((i * 2) + 1 < count) {
    int left_child_index = 2 * i + 1;
    int right_child_index = 2 * i + 2;
    bool has_left = (left_child_index < count);
    bool has_right = (right_child_index < count);

    if (has_left && has_right) {
      int left_child_value = numbers[left_child_index];
      int right_child_value = numbers[right_child_index];

      if (left_child_value > right_child_value) {
        swap_index = left_child_index;
      } else { // right is greater or same
        swap_index = right_child_index;
      }
    } else if (has_left) {
      swap_index = left_child_index;
    } else if (has_right) {
      swap_index = right_child_index;
    } else {
      break;
    }

    if (numbers[swap_index] > numbers[i]) {
      int temp = numbers[i];
      numbers[i] = numbers[swap_index];
      numbers[swap_index] = temp;

      i = swap_index;
    } else {
      break;
    }
  }
}