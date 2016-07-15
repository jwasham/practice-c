#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "splay_tree.c"

int main(int argc, char* argv[]) {

  spltree_node* root = NULL;

  root = insert(root, 67);
  root = insert(root, 45);
  root = insert(root, 183);
  root = insert(root, 23);

  return EXIT_SUCCESS;
}