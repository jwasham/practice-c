#include "bst.h"

bst_node* insert(bst_node* node, const int value) {
  if (node == NULL) {
    bst_node* new_node = malloc(sizeof(bst_node));
    if (new_node == NULL) {
      printf("Unable to allocate memory.");
      exit(0);
    }

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    node = new_node;

    return node;
  }

  if (value < node->value) {
    node->left = insert(node->left, value);
  } else if (value > node->value) {
    node->right = insert(node->right, value);
  }

  return node;
}

void print_tree(bst_node* node) {
  if (node == NULL) {
    return;
  }

  print_tree(node->left);
  printf("%d\n", node->value);
  print_tree(node->right);
}

int get_node_count(bst_node* node) {
  if (node == NULL) {
    return 0;
  }

  return 1 + get_node_count(node->left) + get_node_count(node->right);
}