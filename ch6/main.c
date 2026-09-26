#include <stdio.h>

typedef int Length;

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void test() {
  // struct point p1; // COMPILER ERROR: unknown storage size because struct not declared in this scope
  struct point *p1; // works because it's a forward declaration for an opaque pointer, and incomplete type, but cannot do pointer arithmetic

  printf("struct pointer size: %d\n", sizeof(struct point *));
  printf("int * size: %d\n", sizeof(int *));
  printf("char * size: %d\n", sizeof(char *));
}

int main(int argc, char *argv[]) {
  // you can declare the struct template along with a declaration and definition of a variable,
  // and then you can still reuse the struct template again later, however, probably not in another function or file scope
  struct point {
    int x;
    int y;
  } p = {100, 100};

  struct point another_point = {0, 3};

  printf("struct size: %d\n", sizeof(struct point));

  test();
}
