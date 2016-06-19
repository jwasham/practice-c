void run_all_tests() {
  test_empty();
  test_enqueue();
  test_dequeue();
  test_rotation();
}

void test_empty() {
  queue * q = create_queue();

  assert(empty(q));

  enqueue(q, 43);

  assert(empty(q) == false);

  free(q);
}

void test_enqueue() {
  queue *q = create_queue();

  enqueue(q, 100);
  enqueue(q, 200);
  enqueue(q, 300);
  enqueue(q, 400);
  enqueue(q, 500);

  assert(full(q));

  free(q);
}

void test_dequeue() {
  queue *q = create_queue();

  assert(empty(q));

  enqueue(q, 100);
  assert(empty(q) == false);
  assert(dequeue(q) == 100);

  assert(empty(q));

  free(q);
}

void test_rotation() {
  queue *q = create_queue();

  enqueue(q, 100);
  enqueue(q, 200);
  assert(dequeue(q) == 100);
  enqueue(q, 300);
  enqueue(q, 400);
  assert(dequeue(q) == 200);
  enqueue(q, 500);
  enqueue(q, 600);
  enqueue(q, 700);

  //print_debug(q);

  // should now have 300, 400, 500, 600, 700

  assert(full(q));

  free(q);
}
