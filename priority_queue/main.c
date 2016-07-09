#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
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

  assert(get_max(&queue) == 46);

  assert(extract_max(&queue) == 46);
  assert(extract_max(&queue) == 34);
  assert(extract_max(&queue) == 19);
  assert(extract_max(&queue) == 17);
  assert(extract_max(&queue) == 17);
  assert(extract_max(&queue) == 15);
  assert(extract_max(&queue) == 14);
  assert(extract_max(&queue) == 12);
  assert(extract_max(&queue) == 11);
  assert(extract_max(&queue) == 5);
  assert(extract_max(&queue) == 4);


  return EXIT_SUCCESS;
}
