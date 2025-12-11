#include <stdio.h>
#include <string.h>

int main() {
  printf("----* LINE COUNTER *----\n");

  char filePath[256];
  FILE *file;
  char buffer[256];
  int lineNum = 0;

  printf("Give the files absolute path: \n");
  if (fgets(filePath, sizeof(filePath), stdin)) {
    size_t len = strlen(filePath);
    if (len > 0 && filePath[len - 1] == '\n') {
      filePath[len - 1] = '\0';
    }
  }

  file = fopen(filePath, "r");
  if (file == NULL) {
    printf("File was not found!\n");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    lineNum += 1;
    printf("Line %d: %s\n", lineNum, buffer);
  }

  return 0;
}
