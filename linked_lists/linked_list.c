JForwardList *jforward_list_new() {
  JForwardList *jlist = malloc(sizeof(JForwardList));
  check_address(jlist);

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
  check_address(node);

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

bool jforward_list_empty(JForwardList *jlist) { return jlist->head == 0; }

int jforward_list_front(JForwardList *jlist) {
  if (jlist->head == 0) {
    printf("Cannot get front of empty list\n");
    exit(EXIT_FAILURE);
  }

  return jlist->head->data;
}

int jforward_list_back(JForwardList *jlist) {
  if (jlist->tail == 0) {
    printf("Cannot get back of empty list\n");
    exit(EXIT_FAILURE);
  }

  return jlist->tail->data;
}

void jforward_list_pop_front(JForwardList *jlist) {
  if (jlist->head == 0) {
    printf("Cannot pop front of empty list\n");
    exit(EXIT_FAILURE);
  }

  struct SingleNode *temp = jlist->head;

  jlist->head = jlist->head->next;

  if (jlist->tail == temp) {
    jlist->tail = jlist->head;
  }

  free(temp);
}

void jforward_list_push_back(JForwardList *jlist, int value) {
  struct SingleNode *node = malloc(sizeof(struct SingleNode));
  check_address(node);

  node->data = value;
  node->next = 0;

  if (jlist->head == 0) {
    jlist->head = node;
    jlist->tail = node;
  } else {
    jlist->tail->next = node;
    jlist->tail = node;
  }
}

void jforward_list_pop_back(JForwardList *jlist) {
  if (jlist->tail == 0) {
    printf("Cannot pop back of empty list\n");
    exit(EXIT_FAILURE);
  }

  if (jlist->head == jlist->tail) {
    free(jlist->head);
    jlist->head = 0;
    jlist->tail = 0;
  } else {
    struct SingleNode *current = jlist->head;
    struct SingleNode *last = jlist->head;

    while (current != jlist->tail) {
      last = current;
      current = current->next;
    }

    free(current);

    last->next = 0;
    jlist->tail = last;
  }
}

void jforward_list_insert(JForwardList *jlist, int index, int value) {
  struct SingleNode *current = jlist->head;
  struct SingleNode *last = jlist->head;

  int current_index = 0;
  while (index > current_index && current != 0) {
    ++current_index;
    last = current;
    current = current->next;
  }

  if (current_index < index) {
    printf("Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  struct SingleNode *node = malloc(sizeof(struct SingleNode));
  check_address(node);

  node->data = value;

  if (index == 0 && jlist->head == 0) {
    node->next = 0;
    jlist->head = node;
    jlist->tail = node;
  } else if (index == 0) {
    node->next = jlist->head;
    jlist->head = node;
  } else if (current == jlist->tail) {
    node->next = current;
    last->next = node;
  } else if (current == 0) {
    printf("Cannot insert - index beyond size (1)\n");
    exit(EXIT_FAILURE);
  } else {
    node->next = last->next;
    last->next = node;
  }
}

int jforward_list_value_at(JForwardList *jlist, int index) {
  struct SingleNode *current = jlist->head;

  int current_index = 0;
  while (index > current_index && current != 0) {
    ++current_index;
    current = current->next;
  }

  if (current_index < index || current == 0) {
    printf("Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  return current->data;
}

void jforward_list_erase(JForwardList *jlist, int index) {

  if (jlist->head == 0) {
    printf("Cannot erase: empty list\n");
    exit(EXIT_FAILURE);
  }

  struct SingleNode *current = jlist->head;
  struct SingleNode *last = jlist->head;

  int current_index = 0;
  while (index > current_index && current != 0) {
    ++current_index;
    last = current;
    current = current->next;
  }

  if (current_index < index) {
    printf("Index out of bounds\n");
    exit(EXIT_FAILURE);
  }

  if (index == 0) {
    jlist->head = current->next;
    if (jlist->tail == current) {
      jlist->tail = jlist->head;
    }
  } else {
    last->next = current->next;
    if (jlist->tail == current) {
      jlist->tail = last;
    }
  }

  free(current);
}

int jforward_list_value_n_from_end(JForwardList *jlist, int n) {

  struct SingleNode *first = jlist->head;
  struct SingleNode *match = jlist->head;

  for (int i = 0; i < n; ++i) {
    if (first) {
      first = first->next;
    } else {
      printf("List not long enough to find nth item from end.");
      exit(EXIT_FAILURE);
    }
  }

  while (first) {
    first = first->next;
    match = match->next;
  }

  return match->data;
}

void jforward_list_reverse(JForwardList *jlist) {

  struct SingleNode *prev = NULL;
  struct SingleNode *current = jlist->head;
  struct SingleNode *next;

  jlist->tail = jlist->head;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  jlist->head = prev;
}

void jforward_list_remove(JForwardList *jlist, int value) {
  struct SingleNode *current = jlist->head;
  struct SingleNode *prev = NULL;

  while (current) {
    if (current->data == value) {
      if (prev) {
        prev->next = current->next;
        jlist->tail = current == jlist->tail ? prev : jlist->tail;
      } else {
        jlist->head = current->next;
        jlist->tail = current == jlist->tail ? NULL : jlist->tail;
      }
      free(current);
      break;
    }
    prev = current;
    current = current->next;
  }
}

void check_address(void *p) {
  if (p == NULL) {
    printf("Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
}
