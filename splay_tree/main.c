#include <stdio.h>
#include <stdlib.h>
#include "splay_tree.c"

int main(int argc, char* argv[]) {
  spltree_node* root = NULL;

  root = insert(root, 67);

  print_debug(root);

  root = insert(root, 45);
  root = insert(root, 183);

  print_debug(root);

  root = insert(root, 23);
  root = insert(root, 59);

  print_debug(root);

  root = delete (root, 23);
  root = delete (root, 183);
  root = delete (root, 67);

  print_debug(root);

  root = delete (root, 45);
  root = delete (root, 59);

  print_debug(root);

  return EXIT_SUCCESS;
}