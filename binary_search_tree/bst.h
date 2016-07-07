#include <stdbool.h>

#ifndef PROJECT_BST_H
#define PROJECT_BST_H

typedef struct bst_node_t {
  int value;
  struct bst_node_t* left;
  struct bst_node_t* right;
} bst_node;

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
// Returns the minimum value in the tree, 0 if empty
int get_min(bst_node* node);
// Returns the maximum value in the tree, 0 if empty
int get_max(bst_node* node);
// Returns true if given node is root of a binary search tree
bool is_binary_search_tree(bst_node* node);
// Returns true if the node's value is between a min and max
bool is_between(bst_node* node, int min, int max);
// Deletes the given value from the tree
bst_node* delete_value(bst_node* node, int value);
// Returns the node containing the minimum value in the tree rooted by the given
// node.
void get_min_node(bst_node* node);
// Returns next-highest value in tree after given value, -1 if none
int get_successor(bst_node* node, int value);

#endif  // PROJECT_BST_H
