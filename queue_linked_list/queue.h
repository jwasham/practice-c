#include <stdbool.h>
#include <stdio.h>

#ifndef PROJECT_QUEUE_LINKED_LIST_H
#define PROJECT_QUEUE_LINKED_LIST_H

typedef struct Node {
  int value;
  struct Node *next;
} node;

typedef struct Queue {
  node *head;
  node *tail;
} queue;

// Creates new queue
queue * create_queue();
// Adds value at end of available storage
void enqueue(queue *q, int value);
// Returns value of least recently added element and removes it
const int dequeue(queue *q);
// Returns true if queue is empty
bool empty(queue *q);
// Prints contents of queue, starting with least recently added item first
void print_debug(queue *q);
// Checks address of allocated memory and exits if allocation failed
void check_address(void *addr);
// Free up memory used by queue
void destroy_queue(queue *q);

#endif //PROJECT_QUEUE_LINKED_LIST_H
