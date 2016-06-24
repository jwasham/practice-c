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
  assert(binary_search(-45, test3, size3) == -1);

  const int size4 = 3;
  int test4[size4] = {12, 34, 56};
  assert(binary_search(12, test4, size4) == 0);
  assert(binary_search(34, test4, size4) == 1);
  assert(binary_search(56, test4, size4) == 2);
  assert(binary_search(999, test4, size4) == -1);

  const int size5 = 5;
  int test5[size5] = {12, 34, 56, 78, 90};
  assert(binary_search(12, test5, size5) == 0);
  assert(binary_search(34, test5, size5) == 1);
  assert(binary_search(56, test5, size5) == 2);
  assert(binary_search(78, test5, size5) == 3);
  assert(binary_search(90, test5, size5) == 4);
  assert(binary_search(-1, test5, size5) == -1);
  assert(binary_search(-45, test5, size5) == -1);
  assert(binary_search(45, test5, size5) == -1);
  assert(binary_search(999, test5, size5) == -1);


  // binary search recursive

  const int size6 = 10;
  int test6[size6] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
  assert(binary_search_recur(23, test6, 0, size6) == 2);
  assert(binary_search_recur(0, test6, 0, size6) == 0);
  assert(binary_search_recur(10121, test6, 0, size6) == 9);
  assert(binary_search_recur(155, test6, 0, size6) == -1);
  assert(binary_search_recur(-1, test6, 0, size6) == -1);
  assert(binary_search_recur(10122, test6, 0, size6) == -1);

  const int size7 = 2;
  int test7[size7] = {0, 1};
  assert(binary_search_recur(0, test7, 0, size7) == 0);
  assert(binary_search_recur(1, test7, 0, size7) == 1);
  assert(binary_search_recur(-1, test7, 0, size7) == -1);
  assert(binary_search_recur(2, test7, 0, size7) == -1);

  const int size8 = 1;
  int test8[size8] = {123};
  assert(binary_search_recur(123, test8, 0, size8) == 0);
  assert(binary_search_recur(1, test8, 0, size8) == -1);

  const int size9 = 3;
  int test9[size9] = {12, 34, 56};
  assert(binary_search_recur(12, test9, 0, size9) == 0);
  assert(binary_search_recur(34, test9, 0, size9) == 1);
  assert(binary_search_recur(56, test9, 0, size9) == 2);
  assert(binary_search_recur(0, test9, 0, size9) == -1);
  assert(binary_search_recur(5, test9, 0, size9) == -1);
  assert(binary_search_recur(44, test9, 0, size9) == -1);
  assert(binary_search_recur(999, test9, 0, size9) == -1);

  const int size10 = 5;
  int test10[size10] = {12, 34, 56, 78, 90};
  assert(binary_search_recur(12, test10, 0, size10) == 0);
  assert(binary_search_recur(34, test10, 0, size10) == 1);
  assert(binary_search_recur(56, test10, 0, size10) == 2);
  assert(binary_search_recur(78, test10, 0, size10) == 3);
  assert(binary_search_recur(90, test10, 0, size10) == 4);
  assert(binary_search_recur(0, test10, 0, size10) == -1);
  assert(binary_search_recur(27, test10, 0, size10) == -1);
  assert(binary_search_recur(44, test10, 0, size10) == -1);
  assert(binary_search_recur(999, test10, 0, size10) == -1);

  return EXIT_SUCCESS;
}