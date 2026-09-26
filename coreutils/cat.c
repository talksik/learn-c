/* TODO:
     1. read filename from argv[1]
     2. write errors to stderr
     3. open file for reading
     4. character by character forward to stdout
 */

#include <stdio.h>

#define MAX_LEN 500 

int main(int argc, char *argv[]) {
  FILE *file;
  int c;
  
  fprintf(stderr, "cat <filename>\n");

  if (argc != 2) {
    fprintf(stderr, "ERROR: invalid input\n");
    return -1;
  }

  file = fopen(argv[1], "r");
  if (!file) {
    fprintf(stderr, "ERROR: unable to open file\n");
    return -1;
  }

  while ((c = fgetc(file)) != EOF) {
    putc(c, stdout);
  }

  fprintf(stderr, "Completed forward to stdout");
  fclose(file);

  return 0;
}
