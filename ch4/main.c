#include <stdio.h>
#include "helper.h"

void increment();

int main() {
  printf("hello world\n");

  increment();
  increment();

  printf("sum within main: %d\n", sum);

  sum++;

  printf("sum within main: %d\n", sum);

  return 0;
}
