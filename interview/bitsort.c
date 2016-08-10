#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

int a[1 + N/BITSPERWORD];

void set(int i);
void clr(int i);
int test(int i);

int main(int argc, char *argv[]) {

  int i;

  for (i = 0; i < N; ++i) {
    clr(i);
  }

  while (scanf("%d", &i) != EOF)
    set(i);

  for (i = 0; i < N; ++i) {
    if (test(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}

void set(int i) {
  a[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i) {
  a[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i) {
  return a[i >> SHIFT] & (1 << (i & MASK));
}
