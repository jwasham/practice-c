
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
// Removes the node at the given index
void remove_node(MaxHeap* heap, int index);
// Returns true if queue is empty
bool is_empty(MaxHeap* heap);
// Sorts the given array
void heap_sort(int* numbers, int count);
// Required by heap_sort with an in-place 0-indexed array
void heapify(int* numbers, int count);
// This is a sift down that is customized for 0-indexed arrays
void percolate_down(int* numbers, int count, int index);

#endif  // PROJECT_PRIORITY_QUEUE_H
