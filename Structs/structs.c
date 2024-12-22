#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} cartesian_t;

int quadrant(cartesian_t c) {
  if (c.x >= 0) {
    if (c.y >= 0)
      return 1;
    else
      return 4;
  } else {
    if (c.y >= 0)
      return 2;
    else
      return 3;
  }
  // Implement the function here
  return 0;
}

typedef struct {
  int real;
  int imaginary;
} complex_t;

complex_t addC(complex_t a, complex_t b) {
  complex_t c = {a.real + b.real, a.imaginary + b.imaginary};
  return c;
}

int gcd(int a, int b) {
  if (a == b)
    return a;
  if (a % b == 0)
    return b;
  if (b == 1)
    return a;
  if (a == 1)
    return b;

  return (gcd(b, a % b));
}
int main() {
  //
  // cartesian_t c = {1, 2};
  // printf("%d\n", quadrant(c));

  // complex_t a = addC((complex_t){1, 2}, (complex_t){2, 3});
  // printf("%d + i%d", a.real, a.imaginary);
  int nu = 12;
  int de = 18;
  int g = gcd(nu, de);
  printf("%d\n", gcd(nu, de));
  nu /= g;
  de /= g;
  printf("%d/%d", nu, de);
  return 0;
}