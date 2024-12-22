#include <stdio.h>

int main() {
  char *filename = "demo1.txt";
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("File not found: %s\n", filename);
    return -1;
  }
  // else {
  //   int c = fgetc(file);
  //   while (c != EOF) {
  //     printf("%c", c);
  //     c = fgetc(file);
  //   }
  //   fclose(file);
  //   return 0;
  // }
  char arr[100][100];
  int i = 0;
  char c = fgetc(file);
  while (c != EOF) {
    int j = 0;
    while (c != '\n' && c != EOF) {
      arr[i][j] = c;
      j++;
      c = fgetc(file);
    }
    arr[i][j] = '\0';
    i++;
    c = fgetc(file);
  }

  for (int j = 0; j < i; j++) {
    if (j)
      printf("-%s", arr[j]);
    else
      printf("%s", arr[j]);
  }
  printf("\nThe file has %d lines\n", i);
  fclose(file);

  FILE *file2 = fopen("demo2.txt", "w");
  // copy content of file to file2
  int cnt = 0;
  for (int j = 0; j < i; j++) {
    for (int k = 0; arr[j][k] != '\0'; k++) {
      fputc(arr[j][k], file2);
      cnt++;
    }
    fputc('\n', file2);
    cnt++;
  }

  return 0;
}