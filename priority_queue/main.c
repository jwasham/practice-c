#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>  // for memcp
#include "priority_queue.c"

int main(int argc, char* argv[]) {

  MaxHeap queue;
  queue.size = 0;
  queue.capacity = kQueueCapacity;

  insert(&queue, 4);
  assert(get_size(&queue) == 1);
  insert(&queue, 14);
  assert(get_size(&queue) == 2);
  insert(&queue, 34);
  assert(get_size(&queue) == 3);
  insert(&queue, 15);
  insert(&queue, 5);
  insert(&queue, 12);
  insert(&queue, 46);
  insert(&queue, 19);
  insert(&queue, 17);
  insert(&queue, 11);
  insert(&queue, 17);
  assert(get_size(&queue) == 11);

  assert(get_max(&queue) == 46);

  remove_node(&queue, 2); // 19

  //print_data(&queue);

  assert(get_size(&queue) == 10);

  assert(extract_max(&queue) == 46);
  assert(get_size(&queue) == 9);
  assert(extract_max(&queue) == 34);
  assert(get_size(&queue) == 8);
  assert(extract_max(&queue) == 17);
  assert(extract_max(&queue) == 17);
  assert(extract_max(&queue) == 15);
  assert(extract_max(&queue) == 14);
  assert(extract_max(&queue) == 12);
  assert(extract_max(&queue) == 11);
  assert(extract_max(&queue) == 5);
  assert(get_size(&queue) == 1);
  assert(extract_max(&queue) == 4);
  assert(get_size(&queue) == 0);

  assert(is_empty(&queue));

  // Now for sorting

  int to_sort[10] = {10, 123, 43, 17, 13, 9, 422, 2477, 18, 53};
  int sorted[10] = {9, 10, 13, 17, 18, 43, 53, 123, 422, 2477};

  // will do this one with a 0 indexed array, sorted in place

  heap_sort(to_sort, 10);

  for (int i = 0; i < 10; ++i) {
    printf("%5d ", to_sort[i]);
  }

  // compares 2 arrays for exact match
  assert(memcmp(to_sort, sorted, sizeof(to_sort)) == 0);

  return EXIT_SUCCESS;
}
