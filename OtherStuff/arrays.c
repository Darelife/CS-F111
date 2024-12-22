#include <stdio.h>

#define la(i, a, b) for (int i = a; i < b; i++)
#define int long int

double mean(int arr[], int n) {
  int sum = 0;
  la(i, 0, n) { sum += arr[i]; }
  return sum / n;
}

signed main() {
  // int n;
  // scanf("%d", &n);
  // int arr[n];
  // la(i, 0, n) {
  //   scanf("%d", &arr[i]);
  //   //
  // }
  // printf("%lf\n", mean(arr, n));
  // return 0;
  int n1 = 15, n2 = 4;
  double n3 = n1 / n2;
  n1 /= n3;
  printf("%d\n", n1);
  printf("%d\n", n2);
  printf("%lf\n", n3);
  return 0;
}