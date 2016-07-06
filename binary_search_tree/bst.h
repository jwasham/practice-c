#include <stdbool.h>

#ifndef PROJECT_BST_H
#define PROJECT_BST_H

typedef struct bst_node_t {
  int value;
  struct bst_node_t* left;
  struct bst_node_t* right;
} bst_node;

TAILQ_HEAD(tailhead, entry) head;

// Inserts the given value into the (sub)tree rooted by node.
bst_node* insert(bst_node* node, const int value);
// Outputs the values stored in the tree rooted by node.
void print_tree(bst_node* node);
// Returns the number of nodes stored in the tree
int get_node_count(bst_node* node);
// Deletes all nodes in tree, freeing their memory
void delete_tree(bst_node* node);
// Returns true if given value is in the tree
bool is_in_tree(bst_node* node, int value);
// Returns the height of the tree in nodes, 0 if empty
int get_height(bst_node* node);
// Returns the greater of 2 values
int max_num(int, int);

#endif  // PROJECT_BST_H
