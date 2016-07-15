#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "splay_tree.c"

int main(int argc, char* argv[]) {
  spltree_node* root = NULL;

  root = insert(root, 67);
  root = insert(root, 45);
  root = insert(root, 183);
  root = insert(root, 23);
  root = insert(root, 59);

  root = delete (root, 23);

  return EXIT_SUCCESS;
}