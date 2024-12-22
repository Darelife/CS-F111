#include <math.h>
#include <stdio.h>
// q22 -> 18

int max(int a, int b) { return a > b ? a : b; }

void factors(int a) {
  printf("Factors of %d: ", a);
  for (int i = 1; i <= a / 2; i++) {
    if (a % i == 0)
      printf("%d ", i);
  }
  printf("%d", a);
  printf("\n");
}

int isPrime(int a) {
  for (int i = 2; i <= a / 2; i++) {
    if (a % i == 0)
      return 0;
  }
  return 1;
}

int armstrong(int a) {
  int sum = 0;
  int n = 1 + log10(a);
  for (int i = 0; i < n; i++) {
    sum += pow(a % 10, n);
    a /= 10;
  }
  return sum;
}

int gcd(int a, int b) {
  int ans = 0;
  for (int i = a < b ? a : b; i > 0; i--) {
    if (a % i == 0 && b % i == 0)
      ans = max(i, ans);
  }
  return ans;
}

// divisors of 12 using for loop -> i*i <= n
void divOf12() {
  int n = 12;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      printf("%d ", i);
      if (i != n / i)
        printf("%d ", n / i);
    }
  }
  printf("\n");
}
// 0 1 1 2 3 5 8 13 21 34 55
int fib(int n) {
  int last = 1;
  int secondLast = 0;
  int ans = 0;
  for (int i = 2; i < n; i++) {
    ans = last + secondLast;
    secondLast = last;
    last = ans;
  }
  return ans;
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  factors(n);
  printf("%s\n", isPrime(n) ? "Prime" : "Not Prime");
  printf("%s\n", n == armstrong(n) ? "Armstrong" : "Not Armstrong");
  printf("%d\n", fib(n));
  divOf12();
  return 0;
}