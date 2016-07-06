#include "bst.h"

bst_node* insert(bst_node* node, const int value) {
  if (node == 0) {
    bst_node* new_node = malloc(sizeof(bst_node));
    if (new_node == NULL) {
      printf("Unable to allocate memory.");
      exit(0);
    }

    new_node->value = value;
    new_node->left = 0;
    new_node->right = 0;

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

void delete_tree(bst_node* node) {
  if (node == NULL)
    return;

  delete_tree(node->left);
  delete_tree(node->right);
  free(node);
}

bool is_in_tree(bst_node* node, int value) {
  if (node == NULL) {
    return false;
  }

  if (value < node->value) {
    return is_in_tree(node->left, value);
  } else if (value > node->value) {
    return is_in_tree(node->right, value);
  } else {
    return true;
  }
}

int get_height(bst_node* node) {
  if (node == NULL) {
    return 0;
  }

  return 1 + max_num(get_height(node->left), get_height(node->right));
}

int max_num(int val1, int val2) {
  if (val1 >= val2) {
    return val1;
  } else {
    return val2;
  }
}

int get_min(bst_node* node) {
  if (node == NULL) {
    return 0;
  }

  bst_node* current = node;

  while (current->left != NULL) {
    current = current->left;
  }

  return current->value;
}

int get_max(bst_node* node) {
  if (node == NULL) {
    return 0;
  }

  bst_node* current = node;

  while (current->right != NULL) {
    current = current->right;
  }

  return current->value;
}