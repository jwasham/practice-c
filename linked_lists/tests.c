void run_all_tests() {
  test_size();
  test_push_front();
  test_empty();
  test_front();
  test_back();
  test_pop_front();
  test_push_back();
  test_pop_back();
  test_insert();
}

void test_size() {
  int size = 0;

  // empty

  JForwardList *tester = jforward_list_new();
  size = jforward_list_size(tester);
  assert(size == 0);

  // non-empty

  jforward_list_push_front(tester, 12);
  assert(jforward_list_size(tester) == 1);

  jforward_list_destroy(tester);
}

void test_push_front() {
  JForwardList *tester = jforward_list_new();
  assert(jforward_list_size(tester) == 0);
  // jforward_list_print_debug(tester);

  jforward_list_push_front(tester, 6);
  assert(jforward_list_size(tester) == 1);

  // jforward_list_print_debug(tester);

  jforward_list_push_front(tester, 11);
  jforward_list_push_front(tester, 45);
  assert(jforward_list_size(tester) == 3);

  // jforward_list_print_debug(tester);

  jforward_list_destroy(tester);
}

void test_empty() {
  JForwardList *tester = jforward_list_new();
  assert(jforward_list_empty(tester) == 1);

  jforward_list_push_front(tester, 63);
  assert(jforward_list_empty(tester) == 0);

  jforward_list_push_front(tester, 3);
  assert(jforward_list_empty(tester) == 0);

  jforward_list_destroy(tester);
}

void test_front() {
  JForwardList *tester = jforward_list_new();
  jforward_list_push_front(tester, 121);
  assert(jforward_list_front(tester) == 121);

  jforward_list_push_front(tester, 44);
  assert(jforward_list_front(tester) == 44);

  jforward_list_destroy(tester);
}

void test_back() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_front(tester, 121);
  assert(jforward_list_back(tester) == 121);

  jforward_list_push_front(tester, 44);
  assert(jforward_list_back(tester) == 121);

  jforward_list_destroy(tester);
}

void test_pop_front() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_front(tester, 50);
  jforward_list_push_front(tester, 100);

  assert(jforward_list_front(tester) == 100);

  jforward_list_pop_front(tester);
  assert(jforward_list_front(tester) == 50);

  jforward_list_destroy(tester);
}

void test_push_back() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_front(tester, 99);
  jforward_list_push_front(tester, 13);
  assert(jforward_list_back(tester) == 99);

  jforward_list_push_back(tester, 500);
  assert(jforward_list_back(tester) == 500);

  jforward_list_destroy(tester);
}

void test_pop_back() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_back(tester, 16);
  jforward_list_push_back(tester, 84);
  assert(jforward_list_back(tester) == 84);

  jforward_list_pop_back(tester);
  assert(jforward_list_back(tester) == 16);
  assert(jforward_list_size(tester) == 1);

  jforward_list_push_back(tester, 100);
  jforward_list_push_back(tester, 200);
  assert(jforward_list_size(tester) == 3);

  jforward_list_pop_back(tester);
  assert(jforward_list_back(tester) == 100);
  assert(jforward_list_size(tester) == 2);

  jforward_list_pop_back(tester);
  jforward_list_pop_back(tester);
  assert(jforward_list_empty(tester));

  jforward_list_destroy(tester);
}

void test_insert() {
  JForwardList *tester = jforward_list_new();

  jforward_list_insert(tester, 0, 5);
  assert(jforward_list_size(tester) == 1);
  assert(jforward_list_back(tester) == 5);

  jforward_list_insert(tester, 0, 3);
  assert(jforward_list_size(tester) == 2);
  assert(jforward_list_front(tester) == 3);
  assert(jforward_list_back(tester) == 5);

  jforward_list_insert(tester, 1, 4);
  assert(jforward_list_size(tester) == 3);
  assert(jforward_list_front(tester) == 3);
  assert(jforward_list_back(tester) == 5);

  jforward_list_push_front(tester, 20);
  jforward_list_push_front(tester, 10);

  jforward_list_insert(tester, 4, 6);
  assert(jforward_list_back(tester) == 5);

  jforward_list_destroy(tester);
}