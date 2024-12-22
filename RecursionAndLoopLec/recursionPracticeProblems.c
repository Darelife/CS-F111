#include <math.h>
#include <stdio.h>

int recursivePower(int base, int exp) {
  if (exp == 0)
    return 1;
  return base * recursivePower(base, exp - 1);
}

int sumTillN(int n) {
  if (n == 0)
    return 0;
  return n + sumTillN(n - 1);
}

int sumTillNminusM(int n, int m) {
  if (n == m)
    return n;
  return n + sumTillNminusM(n - 1, m);
}

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

int starTriangle(char c, int n, int goal) {
  if (n > goal)
    return 0;
  printNtimes(c, n);
  printf("\n");
  return starTriangle(c, n + 1, goal);
}
int printFactors(int n, int i) {
  if (i > n)
    return 0;
  if (n % i == 0) {
    printf("%d ", i);
  }
  return printFactors(n, i + 1);
}

int isPrime(int n, int i) {
  if (i == 1)
    return 1;
  if (n % i == 0)
    return 0;
  return isPrime(n, i - 1);
}

int armstrong(int n, int n1, int sum, int temp) {
  if (temp == 0) {
    if (n == sum)
      return 1;
    else {
      return 0;
    }
  }
  int digit = temp % 10;
  sum += pow(digit, n1);
  temp /= 10;
  return armstrong(n, n1, sum, temp);
}

int fib(int n) {
  if (n == 0 || n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

// TODO: Fix this
// NOT WORKING AS OF RN
int memoizedFib(int n, int *arr) {
  if (n == 0 || n == 1)
    return 1;
  if (arr[n] != -1)
    return arr[n];
  arr[n] = memoizedFib(n - 1, arr) + memoizedFib(n - 2, arr);
  return arr[n];
}

int main() {
  int q;
  printf("Enter the question number to run\n");
  scanf("%d", &q);
  if (q == 13) {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", recursivePower(m, n));
  } else if (q == 14) {
    int n;
    scanf("%d", &n);
    printf("%d", sumTillN(n));
  } else if (q == 15) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", sumTillNminusM(n, m));
  } else if (q == 16) {
    char c;
    int n;
    scanf(" %c %d", &c, &n);
    printNtimes(c, n);
  } else if (q == 17) {
    char c;
    int n;
    scanf(" %c %d", &c, &n);
    starTriangle(c, 1, n);
  } else if (q == 18) {
    int n;
    scanf("%d", &n);
    printFactors(n, 1);
  } else if (q == 19) {
    int n;
    scanf("%d", &n);
    if (isPrime(n, n / 2))
      printf("Prime\n");
    else
      printf("Not Prime\n");
  } else if (q == 20) {
    int n;
    scanf("%d", &n);
    if (armstrong(n, log10(n) + 1, 0, n) == 1)
      printf("Armstrong\n");
    else
      printf("Not Armstrong\n");
  } else if (q == 21) {
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
  } else if (q == 22) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
      arr[i] = -1;
    }
    printf("%d", memoizedFib(n, arr));
  }
  return 0;
}