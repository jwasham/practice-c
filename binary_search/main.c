#include <assert.h>
#include <stdlib.h>
#include "binary_search.h"

int main(int argc, char *argv[]) {
  // binary search

  const int size1 = 10;
  int test1[size1] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
  assert(binary_search(23, test1, size1) == 2);
  assert(binary_search(0, test1, size1) == 0);
  assert(binary_search(10121, test1, size1) == 9);
  assert(binary_search(155, test1, size1) == -1);
  assert(binary_search(-1, test1, size1) == -1);
  assert(binary_search(10122, test1, size1) == -1);

  const int size2 = 2;
  int test2[size2] = {0, 1};
  assert(binary_search(0, test2, size2) == 0);
  assert(binary_search(1, test2, size2) == 1);
  assert(binary_search(2, test2, size2) == -1);

  const int size3 = 1;
  int test3[size3] = {123};
  assert(binary_search(123, test3, size3) == 0);
  assert(binary_search(1, test3, size3) == -1);

  // binary search recursive

  const int size4 = 10;
  int test4[size4] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
  assert(binary_search_recur(23, test4, 0, size4) == 2);
  assert(binary_search_recur(0, test4, 0, size4) == 0);
  assert(binary_search_recur(10121, test4, 0, size4) == 9);
  assert(binary_search_recur(155, test4, 0, size4) == -1);
  assert(binary_search_recur(-1, test4, 0, size4) == -1);
  assert(binary_search_recur(10122, test4, 0, size4) == -1);

  const int size5 = 2;
  int test5[size5] = {0, 1};
  assert(binary_search_recur(0, test5, 0, size5) == 0);
  assert(binary_search_recur(1, test5, 0, size5) == 1);
  assert(binary_search_recur(2, test5, 0, size5) == -1);

  const int size6 = 1;
  int test6[size6] = {123};
  assert(binary_search_recur(123, test6, 0, size6) == 0);
  assert(binary_search_recur(1, test6, 0, size6) == -1);

  return EXIT_SUCCESS;
}