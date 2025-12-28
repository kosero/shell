#include "linenoise.h"
#include "tokenize.h"
#include <stdio.h>
#include <stdlib.h>

#define PROMPT "$ "
#define HISTORY_LENGTH 1024
#define MAX_ARGS 1024

int main(void) {
  if (!linenoiseHistorySetMaxLen(HISTORY_LENGTH)) {
    fprintf(stderr, "Could not set history!");
    exit(1);
  }

  char *line;
  char *args[MAX_ARGS];
  while ((line = linenoise(PROMPT)) != NULL) {
    int args_read = s_read(line, args, MAX_ARGS);

    fprintf(stdout, "Read %d args\n", args_read);
    for (int i = 0; i < args_read; i++) {
      fprintf(stdout, "arg[%d] = %s\n", i, args[i]);
    }

    // skip empty lines
    if (args_read == 0) {
      linenoiseFree(line);
      continue;
    }

    // TODO: eval step

    linenoiseHistoryAdd(line);
    linenoiseFree(line);
  }

  return 0;
}
