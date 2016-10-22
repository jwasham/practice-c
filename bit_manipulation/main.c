#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_bits(int i);

void btoa(char bits, char *output, int size);

bool is_little_endian();

int main(int argc, char *argv[]) {
  const int size = sizeof(unsigned int) * 8;

  //  for (unsigned int i = 0; i < 20; ++i) {
  //    char buffer[size + 1] = {0};
  //    buffer[size] = '\0';
  //    btoa(i, buffer, size);
  //    printf("%3d: %s\n", i, buffer);
  //  }

  //  char buffer[size + 1] = {0};
  //  buffer[size] = '\0';
  //  unsigned int bf = 0x70;
  //  btoa(bf, buffer, size);
  //  printf("%3d: %s\n", bf, buffer);

  // bool isPowerOfTwo = x && !(x & (x - 1));

  // |= (1 << 2);

  // turn on 3rd bit from end (2^2)
  int x = 0;
  print_bits(x);
  x |= (1 << 2);
  print_bits(x);
  // turn it off
  x = 65535;
  print_bits(x);
  x &= ~(1 << 2);
  print_bits(x);

  if (is_little_endian()) {
    printf("This system is little endian.\n");
  } else {
    printf("This system is big endian.\n");
  }

  return EXIT_SUCCESS;
}

void print_bits(int i) {
  const int size = sizeof(int) * 8;

  char buffer[size + 1] = {0};
  buffer[size] = '\0';
  btoa(i, buffer, size);
  printf("%9d: %s\n", i, buffer);
}

void btoa(char bits, char *output, int size) {
  for (int i = size - 1; i >= 0; --i, bits >>= 1) {
    output[i] = (char)('0' + (bits & 1));
  }
}

bool is_little_endian() {
  // Casting method
  //  short stored_number = 1;
  //  char *cPtr = (char *) &stored_number;
  //  printf("MSB = %d\n", *(cPtr));
  //  return (*cPtr);

  // Union method
  union {
    short number;
    char oneByte;
  } endianTest;

  endianTest.number = 1;

  return endianTest.oneByte;
}