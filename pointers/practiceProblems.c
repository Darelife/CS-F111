#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int test = 0; test < t; test++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int nr[n];
    int mr[m];
    for (int i = 0; i < n; i++) {
      scanf("%d", &nr[i]);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &mr[i]);
    }
    int ans = 0; // Initialize ans inside the test cases loop
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (nr[i] + mr[j] <= k) {
          ans++;
        }
      }
    }
    printf("%d\n", ans); // Print ans after each test case
  }
  // return 0;
}
