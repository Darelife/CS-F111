#include <stdio.h>

int main() {
  int num = 10;
  int sex = 69;
  int *ptr1 = &sex;
  int *ptr = &num;

  printf("Value of num: %d\n", num);
  printf("Address of num: %p\n", &num);
  printf("Value of ptr: %p\n", ptr);
  printf("Value pointed by ptr: %d\n", *ptr);

  return 0;
}