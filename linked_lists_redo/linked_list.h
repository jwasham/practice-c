#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_LINKED_LIST_REDO_H
#define PROJECT_LINKED_LIST_REDO_H

typedef struct Node {
  int val;
  struct Node *next;
} node_t;

// Prints the values stored in the list.
void print_list(node_t *head);
// Returns the count of values stored in the list.
int size(node_t *head);
// Checks memory address and exits program if invalid.
void check_address(void *addr);
// Returns number of data elements in list
int size(node_t *head);
// Pushes the given value onto the beginning of the list.
void push_front(node_t **head, int value);
// Frees memory and tears down list.
void destroy_list(node_t *head);
// Returns true if list is empty.
bool empty(node_t *head);
// Returns the value of the nth item
int value_at(node_t *head, int n);
// Remove first item in the list, returning its value.
int pop_front(node_t **head);
// Adds an item at the end of the list.
void push_back(node_t **head, int value);
// Remove the last item in the list, returning its value.
int pop_back(node_t **head);
// Returns the value at the front of the list.
int front(node_t *head);
// Returns the value at the end of the list.
int back(node_t *head);
// Insert given value at index (starts at 0, like array), so current item at
// that index is pointed to by next at index
void insert(node_t **head, int index, int value);
// Removes node at given index (starts at 0, like array)
void erase(node_t **head, int index);
// Returns the value of the node at nth position from the end of the list. For
// last item, n = 1, second to last, n = 2
int value_n_from_end(node_t *head, int n);
// Reverse the linked list
void reverse(node_t **head);
// Removes the first item in the list with this value
void remove_value(node_t **head, int value);

#endif  // PROJECT_LINKED_LIST_REDO_H
