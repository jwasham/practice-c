#include <assert.h>

#ifndef PROJECT_SPLAY_TREE_H
#define PROJECT_SPLAY_TREE_H

typedef struct stnode {
  int value;
  struct stnode *left;
  struct stnode *right;
} spltree_node;

// Insert value into the tree
spltree_node *insert(spltree_node *root, int value);
// Splay new value to root of tree
spltree_node *splay(spltree_node *x, int value);
// Delete value from tree
spltree_node *delete (spltree_node *x, int value);
// Output the content of the tree
void print_debug(spltree_node *root);
// In-order traversal
void in_order(spltree_node *node);

#endif  // PROJECT_SPLAY_TREE_H
