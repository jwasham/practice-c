
#ifndef PROJECT_PRIORITY_QUEUE_H
#define PROJECT_PRIORITY_QUEUE_H

const int kQueueCapacity = 1000;

typedef struct MaxHeap {
  int size;
  // Just keeping it small and static for learning purposes
  // and indexing at 1
  int elements[kQueueCapacity + 1];
  int capacity;
} MaxHeap;

// Insert the given value into the heap.
void insert(MaxHeap* heap, int value);
// Output the elements of the data in array form
void print_data(MaxHeap* heap);
// Satisfies the max-heap property from given node up to root, if needed.
void sift_up(MaxHeap* heap, int index);
// Returns the maximum element in the heap
int get_max(MaxHeap* heap);
// Removes the maximum element from the heap, returning its key
int extract_max(MaxHeap* heap);
// Satisfies the max-heap property from given node down to leaf, if needed.
void sift_down(MaxHeap* heap, int index);
// Returns the number of elements stored in the heap
int get_size(MaxHeap* heap);

#endif  // PROJECT_PRIORITY_QUEUE_H
