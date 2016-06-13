JForwardList *jforward_list_new() {
  JForwardList *jlist = malloc(sizeof(JForwardList));
  jlist->head = 0;
  jlist->tail = 0;

  return jlist;
}

void jforward_list_destroy(JForwardList *jlist) {
  struct SingleNode *current = jlist->head;
  struct SingleNode *next;
  while (current != 0) {
    next = current->next;
    free(current);
    current = next;
  }

  free(jlist);
}

int jforward_list_size(JForwardList *jlist) {
  int size = 0;

  struct SingleNode *current = jlist->head;
  while (current != 0) {
    size++;
    current = current->next;
  }

  return size;
}

void jforward_list_push_front(JForwardList *jlist, int value) {
  struct SingleNode *head = jlist->head;

  struct SingleNode *node = malloc(sizeof(struct SingleNode));
  node->data = value;
  node->next = head;

  jlist->head = node;

  if (jlist->tail == 0) {
    jlist->tail = node;
  }
}

void jforward_list_print_debug(JForwardList *jlist) {
  struct SingleNode *current = jlist->head;

  printf("head: %p\n", jlist->head);
  printf("tail: %p\n", jlist->tail);
  printf("path: ");

  while (current != 0) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("\n\n");
}