void print_list(node_t *head) {
  node_t *current = head;

  while (current) {
    printf("%d -> ", current->val);
    current = current->next;
  }

  printf("\n");
}

int size(node_t *head) {
  int size = 0;

  node_t *current = head;
  while (current) {
    current = current->next;
    size++;
  }

  return size;
}

void push_front(node_t **head, int value) {
  node_t *node = malloc(sizeof(node_t));
  node->val = value;
  node->next = *head;

  *head = node;
}

void check_address(void *addr) {
  if (!addr) {
    printf("Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }
}

void destroy_list(node_t *head) {
  node_t *current = head;

  while (current) {
    node_t *next = current->next;
    free(current);
    current = next;
  }
}

bool empty(node_t *head) { return (head == NULL); }

int value_at(node_t *head, int n) {
  node_t *current = head;

  int i = 0;
  while (current && i < n) {
    ++i;
    current = current->next;
  }

  if (!current) {
    printf("Given index does not exist in list.");
    exit(EXIT_FAILURE);
  } else {
    return current->val;
  }
}

int pop_front(node_t **head) {
  if (*head == NULL) {
    printf("Unable to pop_front an empty list.");
    exit(EXIT_FAILURE);
  }

  int value = (*head)->val;

  node_t *front = *head;
  *head = front->next;

  free(front);

  return value;
}

void push_back(node_t **head, int value) {
  node_t *node = malloc(sizeof(node_t));
  node->val = value;
  node->next = NULL;

  if (*head == NULL) {
    *head = node;
    return;
  }

  node_t *current = *head;

  while (current->next) {
    current = current->next;
  }

  current->next = node;
}

int pop_back(node_t **head) {
  if (*head == NULL) {
    printf("Unable to pop_back from empty list.");
    exit(EXIT_FAILURE);
  }

  node_t *current = *head;
  node_t *prev = NULL;

  while (current->next) {
    prev = current;
    current = current->next;
  }

  int value = current->val;

  if (prev) {
    prev->next = NULL;
  } else {
    *head = NULL;
  }
  free(current);

  return value;
}

int front(node_t *head) {
  if (head == NULL) {
    printf("Unable to pop_back from empty list.");
    exit(EXIT_FAILURE);
  }

  return head->val;
}

int back(node_t *head) {
  if (head == NULL) {
    printf("Unable to pop_back from empty list.");
    exit(EXIT_FAILURE);
  }

  node_t *current = head;
  while (current->next) {
    current = current->next;
  }

  return current->val;
}

void insert(node_t **head, int index, int value) {
  node_t *current = *head;
  node_t *prev = NULL;

  int i;
  for (i = 0; i < index && current; ++i) {
    prev = current;
    current = current->next;
  }

  if (i != index) {
    printf("Given index out of bounds.");
    exit(EXIT_FAILURE);
  }

  node_t *node = malloc(sizeof(node_t));
  check_address(node);

  node->val = value;

  if (prev) {
    node->next = current;
    prev->next = node;
  } else {
    node->next = *head;
    *head = node;
  }
}

void erase(node_t **head, int index) {
  if (*head == NULL) {
    printf("Unable to erase from empty list.");
    exit(EXIT_FAILURE);
  }

  node_t *current = *head;
  node_t *prev = NULL;

  int i;
  for (i = 0; i < index && current; i++) {
    prev = current;
    current = current->next;
  }

  if (i != index) {
    printf("Index out of bounds.");
    exit(EXIT_FAILURE);
  }

  if (prev) {
    prev->next = current->next;
  } else {
    *head = current->next;
  }
  free(current);
}

int value_n_from_end(node_t *head, int n) {
  if (n < 1 || head == NULL) {
    printf("Cannot get nth item from end.");
    exit(EXIT_FAILURE);
  }

  node_t *current = head;
  node_t *match = head;

  int i;
  for (i = 0; i < n && current; ++i) {
    current = current->next;
  }

  if (i != n) {
    printf("List is too short to get nth item from end.");
    exit(EXIT_FAILURE);
  }

  while (current) {
    current = current->next;
    match = match->next;
  }

  return match->val;
}

void reverse(node_t **head) {
  node_t *prev = NULL;
  node_t *current = *head;
  node_t *next = *head;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}

void remove_value(node_t **head, int value) {
  node_t *current = *head;
  node_t *prev = NULL;

  while (current) {
    if (current->val == value) {
      if (prev) {
        prev->next = current->next;
      } else {
        *head = current->next;
      }
      free(current);
    }

    prev = current;
    current = current->next;
  }
}
