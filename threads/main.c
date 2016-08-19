#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  printf("Forking...");

  int pid = fork();

  if (pid > 0) {
    printf("Still in parent - %d. Child pid is %d.\n", getpid(), pid);

    for (int i = 1; i <= 10; ++i) {
      printf("\t%d\n", i);
      sleep(1);
    }
  } else if (pid == 0) {
    printf(" - in child - %d.\n", getpid());

    for (int i = -1; i >= -10; --i) {
      printf("\t%d\n", i);
      sleep(1);
    }

    int pidc = fork();

    if (pidc > 0) {
      printf(" - Still in child - %d. Child of child is %d.\n", getpid(), pidc);
    } else if (pidc == 0) {
      printf(" - - child of child - %d.\n", getpid());
    }

  } else if (pid < 0) {
    exit(-1);
  }

  exit(0);
}