#include "tokenize.h"
#include <string.h>

int s_read(char *input, char **args, int max_args) {
  int i = 0;
  char *token = strtok(input, " \t");
  while (token != NULL && i < (max_args - 1)) {
    args[i++] = token;
    token = strtok(NULL, " \t");
  }
  args[i] = NULL;
  return i;
}
