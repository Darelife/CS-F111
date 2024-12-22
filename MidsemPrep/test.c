#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) { b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { a *b / gcd(a, b); }
int main() {
  // printf("%d\n", gcd(10, 100));
  printf("\n");
  printf("%10.2lf\n", 5454.34342);
  return 0;
}