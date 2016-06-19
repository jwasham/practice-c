#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_QUEUE_ARRAY_H
#define PROJECT_QUEUE_ARRAY_H

const int kQueueCapacity = 5;
const int kQueuePositions = kQueueCapacity + 1;

typedef struct JWQueueArrayImplementation {
  int data[kQueuePositions]; // 1 is unusable position
  int insert;
  int pop;
  int capacity;
} queue;

// Creates a new queue
queue * create_queue();
// Adds value to queue
void enqueue(queue *q, const int value);
// Returns value at front of queue, and removes from queue
const int dequeue(queue *q);
// Returns true if queue is empty
bool empty(queue *q);
// Returns true if queue is full
bool full(queue *q);
// Prints the content of the queue for debugging purposes.
void print_debug(queue *q);
// Checks to see if memory provided by malloc is valid and exits if not.
void check_memory(queue * address);

#endif //PROJECT_QUEUE_ARRAY_H
