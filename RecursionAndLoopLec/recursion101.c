#include <math.h>
#include <stdio.h>

// Works for 0 <= n < 10^20
long long int countDigits(long long int n) {
  if (n == 0)
    return 1;
  return ((log10(n)) / 1) + 1;
}

long long int countDig(long long int n) {
  if (n < 10)
    return 1;
  return (1 + countDig(n / 10));
}

int printNlines(char c, int n) {
  if (n == 0)
    return 0;
  printf("%c", c);
  printNlines(c, n - 1);
}

int increasingStarPattern(int n) {
  if (n > 0) {
    increasingStarPattern(n - 1);
    printNlines('*', n);
    printf("\n");
  }
}

int main() {
  long long int n;
  printf("Enter a whole number: ");
  scanf("%lld", &n);
  // printf("%d", log10(n));
  printf("Number of digits in %lld is %lld\n", n, countDigits(n));
  return 0;
}
