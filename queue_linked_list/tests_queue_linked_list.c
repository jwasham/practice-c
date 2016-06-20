void run_all_tests() {
  test_empty();
  test_all();
}

void test_empty() {
  queue *q = create_queue();

  assert(empty(q));

  destroy_queue(q);
}

void test_all() {
  queue *q = create_queue();

  enqueue(q, 100);
  assert(empty(q) == false);
  assert(dequeue(q) == 100);
  enqueue(q, 200);
  enqueue(q, 300);
  enqueue(q, 400);
  assert(dequeue(q) == 200);
  assert(dequeue(q) == 300);
  assert(dequeue(q) == 400);

  assert(empty(q));

  destroy_queue(q);
}
