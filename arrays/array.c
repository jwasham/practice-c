// array

JArray * jarray_new(int capacity) {

  int true_capacity = jarray_determine_capacity(capacity);

  JArray *arr = malloc(sizeof(JArray));
  arr->size = 0;
  arr->capacity = true_capacity;
  arr->data = (int *) malloc(sizeof(int) * true_capacity);

  return arr;
}

int jarray_determine_capacity(int capacity) {

  const int kMinInitialCapacity = 1;
  const int kMinCapacity = 16;
  int true_capacity = 16;

  if (capacity < kMinInitialCapacity) {
    exit(EXIT_FAILURE);
  }

  int power = kMinCapacity;
  while (capacity > power/2) {
    power *= 2;
  }

  true_capacity = power;

  return true_capacity;
}

void jarray_resize(JArray *arrptr) {

  int old_capacity = arrptr->capacity;
  int new_capacity = jarray_determine_capacity(old_capacity);

  int *new_data = (int *) malloc(sizeof(int) * new_capacity);

  for (int i = 0; i < old_capacity; i++) {
    *(new_data + i) = *(arrptr->data + i);
  }

  free(arrptr->data);

  arrptr->data = new_data;
  arrptr->capacity = new_capacity;
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

  if (arrptr->size == arrptr->capacity) {
    // time to double
    jarray_resize(arrptr);
  }

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

//  printf("Items:\n");
//  for (int i = 0; i < arrptr->size; ++i) {
//    printf("%d: %d\n", i, *(arrptr->data + i));
//  }

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
  test_empty();
  test_resize();
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

void test_resize() {
  JArray * aptr = jarray_new(2);

  int old_capacity = jarray_capacity(aptr);
  assert(old_capacity == 16);

  // forces a resize
  for (int i = 0; i < 18; i++) {
    jarray_append(aptr, i + 1);
  }

  int new_capacity = jarray_capacity(aptr);
  assert(new_capacity == 32);
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
