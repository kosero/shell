#include "execute.h"

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int s_execute(char *cmd, char **cmd_args) {
  // fprintf(stdout, "Executing `%s !\n", cmd);

  int status = 0;
  pid_t pid;

  pid = fork();
  if (pid < 0) {
    // fprintf(stderr, "Could not execute!\n");
    return -1;
  }

  if (pid == 0) {
    execv(cmd, cmd_args);
  } else {
    if (waitpid(pid, &status, 0) != pid) {
      // fprintf(stderr, "Could not wait for kiddo!\n");
      return -1;
    }
  }

  return status;
}
