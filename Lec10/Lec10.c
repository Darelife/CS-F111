#include <stdio.h>
#include <string.h>

int isValid(char *pass) {
  int upper = 0;
  int dig = 0;
  int len = strlen(pass);
  if (len < 8) {
    return 0;
  }
  for (int i = 0; i < len; i++) {
    if (pass[i] >= 'A' && pass[i] <= 'Z') {
      // printf("upper: %c\n", pass[i]);
      upper = 1;
    }
    if (pass[i] >= '0' && pass[i] <= '9') {
      // printf("digit: %c\n", pass[i]);
      dig = 1;
    }
  }
  if (upper && dig) {
    return 1;
  } else
    return 0;
}
int main() {
  char pass[100];
  while (!isValid(pass)) {
    printf("Enter password: ");
    scanf("%s", pass);
    if (isValid(pass)) {
      printf("Valid password\n");
    } else {
      printf("Invalid password\n");
    }
  }
  return 0;
}
