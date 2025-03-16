#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 150

int main(int argc, char **argv) {
  char cur_line[LINE_LEN];
  int ret = 0;

  FILE *fd = fopen(argv[1], "r");

  for (int i = 1; i < argc; i++) {
    FILE *fd = fopen(argv[i], "r");
    if (NULL == fd) {
      printf("wcat: cannot open file\n");
      return 1;
    }

    while (fgets(cur_line, sizeof(cur_line), fd)) {
      printf("%s", cur_line);
    }

    ret = fclose(fd);
    if (0 != ret) {
      break;
    }
  }

  return ret;
}
