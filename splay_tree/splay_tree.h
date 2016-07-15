#ifndef PROJECT_SPLAY_TREE_H
#define PROJECT_SPLAY_TREE_H

typedef struct stnode {
  int value;
  struct stnode * left;
  struct stnode * right;
} spltree_node;

spltree_node * insert(spltree_node *root, int value);
spltree_node * splay(spltree_node *x, int value);

#endif //PROJECT_SPLAY_TREE_H
