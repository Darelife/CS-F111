#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int a, b, k, ans = 0;
    scanf("%d %d %d", &a, &b, &k);
    int ar[a];
    int br[b];
    for (int j = 0; j < a; j++) {
      scanf("%d", &ar[j]);
    }
    for (int j = 0; j < b; j++) {
      scanf("%d", &br[j]);
    }
    for (int j = 0; j < a; j++) {
      for (int l = 0; l < b; l++) {
        if (ar[j] + br[l] <= k)
          ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}