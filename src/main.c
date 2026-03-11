#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  while (1) {
    printf("$ ");

    // Wait for user command
    char command[256];
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "exit") == 0) {
      break;

    } else if (strncmp(command, "echo", 4) == 0) {
      char *arg = command + 5;

      if (arg == NULL) {
        printf("\n");
      } else {
        printf("%s\n", arg);
      }

    } else if (strncmp(command, "type ", 5) == 0) {
      char *arg = command + 5;

      if (strcmp(arg, "exit") == 0 || strcmp(arg, "echo") == 0 || strcmp(arg, "type") == 0) {
        printf("%s is a shell builtin\n", arg);
      } else {
        printf("%s: not found\n", arg);
      }

    } else {
      printf("%s: command not found\n", command);

    }
  }

  return 0;
}
