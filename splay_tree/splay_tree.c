#include "splay_tree.h"

/**
 * This is a top-down implementation of a splay tree.
 */
spltree_node* insert(spltree_node* root, int value) {
  spltree_node* new_node = malloc(sizeof(spltree_node));
  assert(new_node);

  new_node->value = value;

  if (root == NULL) {
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
  }

  root = splay(root, value);

  if (value < root->value) {
    new_node->left = root->left;
    new_node->right = root;
    root->left = NULL;

    return new_node;
  } else if (value > root->value) {
    new_node->left = root;
    new_node->right = root->right;
    root->right = NULL;

    return new_node;
  }

  // new node was already root
  free(new_node);

  return root;
}

spltree_node* splay(spltree_node* x, int value) {
  spltree_node temp, *l, *r, *y;

  temp.left = temp.right = NULL;
  l = r = &temp;

  for (;;) {
    if (value < x->value) {
      if (x->left == NULL) break;
      if (value < x->left->value) {   // rotate right
        y = x->left;
        x->left = y->right;
        y->right = x;
        x = y;
        if (x->left == NULL) break;
      }
      r->left = x;                    // link right
      r = x;
      x = x->left;
    } else if (value > x->value) {
      if (x->right == NULL) break;
      if (value > x->right->value) {  // rotate left
        y = x->right;
        x->right = y->left;
        y->left = x;
        x = y;
        if (x->right == NULL) break;
      }
      l->right = x;                   // link left
      l = x;
      x = x->right;
    } else {
      break;
    }
  }

  l->right = x->left;
  r->left = x->right;
  x->left = temp.right;
  x->right = temp.left;

  return x;
}

spltree_node* delete (spltree_node* root, int value) {
  spltree_node* x;

  if (root == NULL) return NULL;

  root = splay(root, value);

  if (value == root->value) {
    if (root->left == NULL) {
      x = root->right;
    } else {
      x = splay(root->left, value);
      x->right = root->right;
    }

    free(root);

    return x;
  }

  return root;
}

void print_debug(spltree_node* node) {
  if (node == NULL) {
    printf("-- empty --");
  } else {
    in_order(node);
  }

  putchar('\n');
}

void in_order(spltree_node* node) {
  if (node == NULL) return;

  in_order(node->left);
  printf("%d < ", node->value);
  in_order(node->right);
}