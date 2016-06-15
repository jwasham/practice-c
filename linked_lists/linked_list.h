#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

struct SingleNode {
  int data;
  struct SingleNode *next;
};

typedef struct JWImplementationSinglyLinkedList {
  struct SingleNode *head;
  struct SingleNode *tail;
} JForwardList;

// Creates a new JList singly linked list.
JForwardList *jforward_list_new();
// Frees memory for given JList.
void jforward_list_destroy(JForwardList *jlist);
// Returns number of data elements in list.
int jforward_list_size(JForwardList *jlist);
// Returns true if list is empty
bool jforward_list_empty(JForwardList *jlist);
// Adds the given value to the front of the list
void jforward_list_push_front(JForwardList *jlist, int value);
// Prints the elements in the list for debugging purposes.
void jforward_list_print_debug(JForwardList *jlist);
// Returns the value of the first item in the list.
int jforward_list_front(JForwardList *jlist);
// Returns the value of the end item.
int jforward_list_back(JForwardList *jlist);
// Removes item at front.
void jforward_list_pop_front(JForwardList *jlist);
// Adds an item at the end
void jforward_list_push_back(JForwardList *jlist, int value);
// Removes the item from the end.
void jforward_list_pop_back(JForwardList *jlist);
// Insert value at index, so current item at that index is pointed to by next in new node.
void jforward_list_insert(JForwardList *jlist, int index, int value);
// Returns the value of the nth item
int jforward_list_value_at(JForwardList *jlist, int index);
// Removes node at given index
void jforward_list_erase(JForwardList *jlist, int index);
// Returns the value of the node at nth position from the end of the list.
// For last item, n=1, for second-to-last, n=2, etc.
int jforward_list_value_n_from_end(JForwardList *jlist, int n);
// Reverse the values stored in the list.
void jforward_list_reverse(JForwardList *jlist);
// Removes the first item in the list with this value
void jforward_list_remove(JForwardList *jlist, int value);
// Checks to see if given value is valid for memory, and exits if so
void check_address(void *p);

#endif  // PROJECT_LINKED_LIST_H
