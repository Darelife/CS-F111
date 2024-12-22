#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

long double factorial(int n) {
  // n^n e^-n sqrt((2n+1/3)π)
  return (pow(n, n) * exp(-n) * sqrt((2 * n + 1.0 / 3.0) * M_PI) + 1 / 100.0);
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Factorial of %d is %Lf\n", n, (factorial(n)));
  return 0;
}