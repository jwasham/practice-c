#include <stdio.h>

int main(int argc, char* argv[]) {
  int num_count = 30;
  int numbers[] = {5432, 989, 7510, 3,   583, 8919, 542, 123,  597, 42,
                   7506, 184, 2409, 187, 45,  824,  4,   2650, 9,   662,
                   3928, 170, 5358, 395, 842, 7697, 110, 14,   99,  221};

  for (int i = 0; i < num_count; ++i) {
    printf("%d, ", numbers[i]);
  }

  return 0;
}