// array

JArray * jarray_new(int capacity) {

  // allocate a size as a power of 2

  JArray *arr = malloc(sizeof(JArray));
  arr->size = 0;
  arr->capacity = capacity;
  arr->data = (int *) malloc(sizeof(int) * capacity);

  return arr;
}

int jarray_size(JArray *arrptr) {
  return arrptr->size;
}

void jarray_destroy(JArray *arrptr) {
//  printf("** Freeing memory **\n");
  free(arrptr->data);
  free(arrptr);
}

bool jarray_append(JArray * arrptr, int item) {

  int success = 0;

  if (arrptr->size < arrptr->capacity) {
    *(arrptr->data + arrptr->size) = item;
    arrptr->size += 1;
    success = 1;
  }

  return success;
}

void jarray_print(JArray *arrptr) {
  printf("Size: %d\n", arrptr->size);
  printf("Capacity: %d\n", arrptr->capacity);
  printf("Items:\n");

  for (int i = 0; i < arrptr->size; ++i) {
    printf("%d: %d\n", i, *(arrptr->data + i));
  }

  printf("---------\n");
}

int jarray_capacity(JArray *arrptr) {
  return arrptr->capacity;
}

bool jarray_is_empty(JArray *arrptr) {
  int is_empty = 0;

  if (arrptr->size == 0) {
    is_empty = 1;
  }

  return is_empty;
}

// tests

void run_all_tests() {
  test_size_init();
  test_append();
  test_append_past_capacity();
  test_capacity();
  test_empty();
}

void test_size_init() {
  JArray * aptr = jarray_new(5);
  int initial_size = jarray_size(aptr);
  assert(initial_size == 0);
  jarray_destroy(aptr);
}

void test_append() {
  JArray * aptr = jarray_new(2);
  jarray_append(aptr, 2);
  jarray_append(aptr, 12);
  int new_size = jarray_size(aptr);
  assert(new_size == 2);
  jarray_destroy(aptr);
}

void test_append_past_capacity() {
  JArray * aptr = jarray_new(3);
  jarray_append(aptr, 10);
  jarray_append(aptr, 6);
  jarray_append(aptr, 5);
  jarray_append(aptr, 11);
  int new_size = jarray_size(aptr);
  assert(new_size == 3);
  jarray_destroy(aptr);
}

void test_capacity() {
  JArray * aptr = jarray_new(3);
  jarray_append(aptr, 10);
  int capacity = jarray_capacity(aptr);
  assert(capacity == 3);
  jarray_destroy(aptr);
}

void test_empty() {
  JArray * aptr = jarray_new(2);
  bool empty = jarray_is_empty(aptr);
  assert(empty == 1);
  jarray_append(aptr, 1);
  empty = jarray_is_empty(aptr);
  assert(empty == 0);
  jarray_destroy(aptr);
}
