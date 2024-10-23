#include <stdio.h>
#include <stdlib.h>
#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t buffer_size = 100;

  line = (char*) malloc(buffer_size + 1);

  while (getline(&line, &buffer_size, stdin) > 0) {
    char* result = disemvowel(line);
    printf("%s\n", result);
    free(result);
  }

  free(line);
}
