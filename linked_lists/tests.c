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
  test_value_at();
  test_erase();
  test_value_n_from_end();
  test_reverse();
  test_reverse_single();
  test_reverse_empty();
  test_remove();
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

void test_value_at() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_back(tester, 1);
  jforward_list_push_back(tester, 2);
  jforward_list_push_back(tester, 3);

  assert(jforward_list_value_at(tester, 0) == 1);
  assert(jforward_list_value_at(tester, 1) == 2);
  assert(jforward_list_value_at(tester, 2) == 3);

  jforward_list_destroy(tester);
}

void test_insert() {
  JForwardList *tester = jforward_list_new();

  jforward_list_insert(tester, 0, 5);
  assert(jforward_list_size(tester) == 1);
  assert(jforward_list_value_at(tester, 0) == 5);

  jforward_list_insert(tester, 0, 3);
  assert(jforward_list_value_at(tester, 0) == 3);
  assert(jforward_list_value_at(tester, 1) == 5);

  jforward_list_insert(tester, 1, 4);
  assert(jforward_list_value_at(tester, 0) == 3);
  assert(jforward_list_value_at(tester, 1) == 4);
  assert(jforward_list_value_at(tester, 2) == 5);

  jforward_list_push_front(tester, 20);
  jforward_list_push_front(tester, 10);

  jforward_list_insert(tester, 2, 2);
  assert(jforward_list_value_at(tester, 2) == 2);
  assert(jforward_list_value_at(tester, 3) == 3);

  jforward_list_destroy(tester);
}

void test_erase() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_front(tester, 5);
  jforward_list_erase(tester, 0);

  assert(jforward_list_size(tester) == 0);

  jforward_list_push_back(tester, 1);
  jforward_list_push_back(tester, 2);

  jforward_list_erase(tester, 0);
  assert(jforward_list_value_at(tester, 0) == 2);

  jforward_list_push_back(tester, 3);

  jforward_list_erase(tester, 1);

  assert(jforward_list_value_at(tester, 0) == 2);

  jforward_list_push_back(tester, 3);
  jforward_list_push_back(tester, 4);

  jforward_list_erase(tester, 2);
  assert(jforward_list_value_at(tester, 1) == 3);

  jforward_list_destroy(tester);
}

void test_value_n_from_end() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_back(tester, 123);
  jforward_list_push_back(tester, 623);
  jforward_list_push_back(tester, 987);
  jforward_list_push_back(tester, 629);
  jforward_list_push_back(tester, 812);
  jforward_list_push_back(tester, 238);

  assert(jforward_list_value_n_from_end(tester, 4) == 987);
  assert(jforward_list_value_n_from_end(tester, 2) == 812);
  assert(jforward_list_value_n_from_end(tester, 6) == 123);

  jforward_list_destroy(tester);

  // test with single item list

  JForwardList *tester2 = jforward_list_new();

  jforward_list_push_back(tester2, 999);
  assert(jforward_list_value_n_from_end(tester2, 1) == 999);

  jforward_list_destroy(tester2);
}

void test_reverse() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_back(tester, 2);
  jforward_list_push_back(tester, 3);
  jforward_list_push_back(tester, 5);
  jforward_list_push_back(tester, 8);
  jforward_list_push_back(tester, 11);

  jforward_list_reverse(tester);

  assert(jforward_list_value_at(tester, 0) == 11);
  assert(jforward_list_value_at(tester, 1) == 8);
  assert(jforward_list_value_at(tester, 2) == 5);
  assert(jforward_list_value_at(tester, 3) == 3);
  assert(jforward_list_value_at(tester, 4) == 2);

  jforward_list_destroy(tester);
}

void test_reverse_single() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_back(tester, 2);

  jforward_list_reverse(tester);

  assert(jforward_list_value_at(tester, 0) == 2);

  jforward_list_destroy(tester);
}

void test_reverse_empty() {
  JForwardList *tester = jforward_list_new();

  // if there was an uncovered case this would blow up
  jforward_list_reverse(tester);

  jforward_list_destroy(tester);
}

void test_remove() {
  JForwardList *tester = jforward_list_new();

  jforward_list_push_back(tester, 2);
  jforward_list_push_back(tester, 4);
  jforward_list_push_back(tester, 6);

  jforward_list_remove(tester, 6);
  assert(jforward_list_size(tester) == 2);
  assert(jforward_list_value_at(tester, 0) == 2);
  assert(jforward_list_value_at(tester, 1) == 4);

  jforward_list_remove(tester, 2);
  assert(jforward_list_size(tester) == 1);
  assert(jforward_list_value_at(tester, 0) == 4);

  jforward_list_remove(tester, 4);
  assert(jforward_list_size(tester) == 0);

  jforward_list_destroy(tester);
}