#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <assert.h>

typedef int bool;

const int kMinCapacity = 16;

typedef struct JWImplementationArray {
  int size;
  int capacity;
  int *data;
} JArray;

// array functions

JArray *jarray_new(int capacity);
void jarray_destroy(JArray *arrptr);

void jarray_resize_for_size(JArray *arrptr, int candidate_size);
int jarray_determine_up_capacity(int capacity);
void jarray_upsize(JArray *arrptr);
void jarray_downsize(JArray *arrptr);
int jarray_size(JArray *arrptr);
void jarray_push(JArray *arrptr, int item);
void jarray_print(JArray *arrptr);
int jarray_capacity(JArray *arrptr);
bool jarray_is_empty(JArray *arrptr);
int jarray_at(JArray *arrptr, int index);
void jarray_insert(JArray * arrptr, int index, int value);
void jarray_prepend(JArray * arrptr, int value);
int jarray_pop(JArray *arrptr);
void jarray_delete(JArray *arrptr, int index);
void jarray_remove(JArray *arrptr, int value);

// tests

void run_all_tests();

void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
void test_resize();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_remove();

#endif  // PROJECT_ARRAY_H
