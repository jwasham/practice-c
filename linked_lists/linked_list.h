#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

typedef int bool;

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
// Adds the given value to the front of the list
void jforward_list_push_front(JForwardList *jlist, int value);
// Prints the elements in the list for debugging purposes
void jforward_list_print_debug(JForwardList *jlist);

#endif  // PROJECT_LINKED_LIST_H
