#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int alive;
} got_t;

int main() {
  char *filename = "./gotlist.txt";
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("File not found: %s\n", filename);
    return -1;
  }

  int i = 0;
  char line[100];
  char data[100][100];
  got_t a;
  while (fgets(line, sizeof(line), file)) {
    printf("%s\n", line);
    if (line[strlen(line) - 1] == '\n') {
      if (line[strlen(line) - 2] == '1') {
        line[strlen(line) - 2] = '0';
      }
    }
    if (line[strlen(line) - 1] == '1') {
      line[strlen(line) - 1] = '0';
    }
    strcpy(data[i], line); // copy the line to data[i]
    i++;
    printf("%s\n", data[i - 1]);
  }
  // clear the file
  fclose(file);
  FILE *file2 = fopen("./gotdead.txt", "w");

  for (int j = 0; j < i; j++) {
    // put the data
    // fprintf(file2, "%s\n", data[j]);
    fputs(data[j], file2);
  }
  fclose(file2);
  return 0;
}