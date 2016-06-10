#ifndef PROJECT_9894_ARRAYS_ARRAY_H
#define PROJECT_9894_ARRAYS_ARRAY_H

typedef int bool;

typedef struct JWImplementationArray {
  int size;
  int capacity;
  int *data;
} JArray;

// array functions

JArray *jarray_new(int capacity);
void jarray_destroy(JArray *arrptr);

int jarray_size(JArray *arrptr);
bool jarray_append(JArray *arrptr, int item);
void jarray_print(JArray *arrptr);
int jarray_capacity(JArray *arrptr);
bool jarray_is_empty(JArray *arrptr);

// tests

void run_all_tests();

void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();

#endif  // PROJECT_9894_ARRAYS_ARRAY_H
