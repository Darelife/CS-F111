#include <stdio.h>
#include <string.h>

int min(int a, int b) { return (a < b) ? a : b; }

void lexi(char *one, char *two) {
  for (int i = 0; i < min(strlen(one), strlen(two)); i++) {
    if (one[i] > 122 - 25)
      one[i] -= 32;
    if (two[i] > 122 - 25)
      one -= 32;
    if (one[i] < two[i])
      break;
    if (two[i] < one[i]) {
      // swap one and two
      char temp[100];
      strcpy(temp, one);
      strcpy(one, two);
      strcpy(two, temp);
      break;
    }
  }
  printf("%s\n", one);
  printf("%s\n", two);
  return;
}

int palindrome(char *str) {
  int len = strlen(str);
  // remove the spaces from the string
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != '_') {
      str[k++] = str[i];
    }
  }
  // reduce the number of characters in the string by 1
  // str[k] = '\0';
  str[k] = '\0';
  // printf("%s\n", str);
  len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char one[100];
  char two[100];
  printf("Enter first string: ");
  scanf("%s", one);
  printf("Enter second string: ");
  scanf("%s", two);
  lexi(one, two);
  if (palindrome(one)) {
    printf("Palindrome\n");
  } else {
    printf("Not a palindrome\n");
  }
}
