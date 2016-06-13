void run_all_tests() {
  test_size();
  test_push_front();
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
