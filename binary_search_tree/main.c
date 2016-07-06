#include <stdio.h>
//#include <stdlib.h>
//#include <sys/queue.h>
#include <assert.h>
#include "bst.c"

int main(int argc, char* argv[]) {
  bst_node* root = NULL;

  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 3);
  root = insert(root, 11);
  root = insert(root, 16);

  //print_tree(root);
  printf("Tree contains %d nodes.\n", get_node_count(root));

  assert(is_in_tree(root, 3));
  assert(is_in_tree(root, 11));
  assert(is_in_tree(root, 16));
  assert(! is_in_tree(root, 0));
  assert(! is_in_tree(root, -1));

  assert(get_height(root) == 3);
  root = insert(root, 5);
  assert(get_height(root) == 4);

  assert(get_min(root) == 3);
  root = insert(root, 2);
  assert(get_min(root) == 2);

  assert(get_max(root) == 16);
  root = insert(root, 32);
  assert(get_max(root) == 32);

  //print_tree(root);



  delete_tree(root);

  return 0;
}
