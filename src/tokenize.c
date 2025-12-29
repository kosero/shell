#include "tokenize.h"
#include <string.h>

int s_read(char *input, char **args, const int max_args,
           const char *token_seps) {
  int i = 0;
  char *token = strtok(input, token_seps);
  while (token != NULL && i < (max_args - 1)) {
    args[i++] = token;
    token = strtok(NULL, token_seps);
  }
  args[i] = NULL;
  return i;
}
