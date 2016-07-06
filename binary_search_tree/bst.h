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

#endif  // PROJECT_BST_H
