#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_LEN 1000

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Only support one command `ls` without any path param\n");
    return -1;
  }

  char path[MAX_LEN];
  getcwd(path, MAX_LEN);
  if (!path) {
    printf("Unable to get current path\n");
    return -1;
  }

  printf("Current path: %s\n", path);

  DIR *dir = opendir(path);
  if (!dir) {
    printf("Unable to view dir\n");
    return -1;
  }

  struct dirent *next_item;
  while ((next_item = readdir(dir)) != NULL) {
    if (strlen(next_item->d_name) == 0 ||
	next_item->d_name[0] == '.') {
      continue;
    }
    printf("item: %s\n", next_item->d_name);
  }
  
  closedir(dir);
}
