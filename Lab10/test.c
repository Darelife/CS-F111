#include <stdio.h>
#include <string.h>
void stuff(char *sex) {
  char quote[50] = "";

  int n = 0;

  for (int i = 0; i < strlen(sex); i++) {
    char a = sex[i];
    int found = 0;
    for (int j = 0; j < n; j++) {
      if (quote[j] == a) {
        found = 1;
      }
    }
    if (!found) {
      quote[n] = a;
      n++;
    }
  }
  quote[n] = '\0';
  printf("%s", quote);
}
int main() {
  stuff("hello");
  return 0;
}