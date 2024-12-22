// #include <math.h>
#include <stdio.h>

int printNtimes(char c, int n) {
  if (n == 0)
    return 0;
  printf("%c", c);
  return printNtimes(c, n - 1);
}
int printTriangleTop(char c, int n, int space) {
  if (n <= 0)
    return 0;
  printNtimes(' ', space);
  printNtimes(c, n);
  printf("\n");
  return printTriangleTop(c, n - 2, space + 1);
}
int printTriangleBottom(char c, int n, int space, int goal) {
  if (n > goal)
    return 0;
  printNtimes(' ', space);
  printNtimes(c, n);
  printf("\n");
  return printTriangleBottom(c, n + 2, space - 1, goal);
}

int printRhombus(char c, int n, int space, int phase, int goal,
                 int patternWidth) {
  if (n >= goal && phase == 1)
    phase = 2;
  if (n <= 0 && phase == 2)
    return 0;
  printNtimes(c, 1);
  for (int i = 0; i < patternWidth; i++) {
    if (i == 0) {
      printNtimes(c, 1);
    }
    printNtimes(' ', space);
    printNtimes(c, n);
    printNtimes(' ', space);
    printNtimes(c, 1);
    if (i == patternWidth - 1) {
      printNtimes(c, 1);
    }
  }
  printf("\n");
  if (phase == 1)
    return printRhombus(c, n + 2, space - 1, phase, goal, patternWidth);
  return printRhombus(c, n - 2, space + 1, phase, goal, patternWidth);
}

int main() {
  int n;
  int patternWidth;
  int rows;
  scanf("%d %d %d", &n, &patternWidth, &rows);
  printf("\n\n\n");
  printNtimes('*', (n + 1) * patternWidth + 3);
  printf("\n");
  for (int i = 0; i < rows; i++) {
    printNtimes('*', (n + 1) * patternWidth + 3);
    printf("\n");
    printRhombus('*', n % 2, n / 2, 1, n, patternWidth);
    printNtimes('*', (n + 1) * patternWidth + 3);
    printf("\n");
  }
  printNtimes('*', (n + 1) * patternWidth + 3);
  printf("\n");
  return 0;
}
