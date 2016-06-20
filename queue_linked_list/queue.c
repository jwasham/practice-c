queue * create_queue() {
  queue *q = malloc(sizeof(node));
  check_address(q);

  q->head = 0;
  q->tail = 0;

  return q;
}

void enqueue(queue *q, int value) {
  node *new_node = malloc(sizeof(node));
  check_address(new_node);

  new_node->value = value;
  new_node->next = 0;

  if (q->tail) {
    q->tail->next = new_node;
  }
  q->tail = new_node;

  if (q->head == 0) {
    q->head = new_node;
  }
}

const int dequeue(queue *q) {

  if (empty(q)) {
    printf("Unable to dequeue. Queue is empty.\n");
    exit(EXIT_FAILURE);
  }

  int value = q->head->value;

  node *temp = q->head;

  if (q->tail == q->head) {
    q->tail = 0;
  }

  q->head = q->head->next;
  free(temp);

  return value;
}

bool empty(queue *q) {
  return q->head == 0;
}

void print_debug(queue *q) {
  printf("Queue contents: ");

  node *current = q->head;

  while (current) {
    printf("%d < ", current->value);
    current = current->next;
  }

  printf("\n");
}

void check_address(void *addr) {
  if (addr == 0) {
    printf("Unable to allocate more memory.\n");
    exit(EXIT_FAILURE);
  }
}

void destroy_queue(queue *q) {

  node *current = q->head;
  node *temp = q->head;

  while (current) {
    temp = current;
    current = current->next;
    free(temp);
  }

  free(q);
}