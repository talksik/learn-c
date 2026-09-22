#include <stdio.h>

int add(int, int);

int counter = 0;

int main(int argc, char **argv) {
  printf("hello\n");

  char data[200];
  char *other_data = "hello";

  char *data_ptr = data;

  printf("size of data: %d\n", sizeof(data));
  printf("size of data_ptr: %d\n", sizeof(data_ptr));
  printf("size of other_data: %d\n", sizeof(other_data));
  printf("size of int: %d\n", sizeof(int));
  printf("size of char *: %d\n", sizeof(char *));

  add(2, 3);

  extern int counter;
  printf("global counter: %d\n", counter);

  int c;
  while((c = getchar()) != EOF) {
    if (c == 'x') {
      return 0;
    }
    printf("char: %d | ", c);
    putchar(c);
    putchar('\n');
  }
}

int add(int a, int b) {
  return a + b;
}
