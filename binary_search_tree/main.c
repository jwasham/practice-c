#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include "bst.c"

int main(int argc, char* argv[]) {
  bst_node* root = NULL;

  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 3);
  root = insert(root, 11);
  root = insert(root, 16);

  print_tree(root);

  int node_count = get_node_count(root);

  printf("Tree contains %d nodes.\n", node_count);

  return 0;
}
