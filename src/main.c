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

    // Command not found
    command[strcspn(command, "\n")] = '\0';
    printf("%s: command not found\n", command);
  }

  return 0;
}
