#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.c"

int main(int argc, char* argv[]) {
  bst_node* root = NULL;

  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 3);
  root = insert(root, 11);
  root = insert(root, 16);

  // print_tree(root);
  printf("Tree contains %d nodes.\n", get_node_count(root));

  assert(is_in_tree(root, 3));
  assert(is_in_tree(root, 11));
  assert(is_in_tree(root, 16));
  assert(!is_in_tree(root, 0));
  assert(!is_in_tree(root, -1));

  assert(get_height(root) == 3);
  root = insert(root, 5);
  assert(get_height(root) == 4);

  assert(get_min(root) == 3);
  root = insert(root, 2);
  assert(get_min(root) == 2);

  assert(get_max(root) == 16);
  root = insert(root, 32);
  assert(get_max(root) == 32);

  assert(is_binary_search_tree(root));

  // make bad tree
  bst_node* bad_root = malloc(sizeof(bst_node));
  bad_root->value = 10;
  bad_root->left = NULL;
  bad_root->right = malloc(sizeof(bst_node));
  bad_root->right->value = 9;
  bad_root->right->left = NULL;
  bad_root->right->right = NULL;

  assert(!is_binary_search_tree(bad_root));

  root = delete_value(root, 4);
  assert(!is_in_tree(root, 4));

  printf("Tree contains %d nodes.\n", get_node_count(root));

  root = insert(root, 4);

  assert(get_successor(root, 3) == 4);   // 4 is right child of 3
  assert(get_successor(root, 2) == 3);   // 3 is parent of 2, 2 is left child
  assert(get_successor(root, 4) == 5);   // 5 is root, 4 is right child of 3
  assert(get_successor(root, 5) == 11);  // 11 is min in right subtree of 5

  delete_tree(root);
  delete_tree(bad_root);

  return 0;
}
