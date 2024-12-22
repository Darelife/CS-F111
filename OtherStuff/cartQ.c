#include <stdio.h>

int cart(int c, int l) {
  if (c <= 1500) {
    if (l <= 200)
      return 100;
    else if (l <= 500)
      return 50;
    else
      return 20;
  } else if (c <= 5000) {
    if (l <= 200)
      return 80;
    else if (l <= 500)
      return 30;
    else
      return 10;
  } else {
    if (l <= 200)
      return 60;
    else if (l <= 500)
      return 20;
    else
      return 0;
  }
}

int main() {
  int c, l;
  printf("Enter the cost of the item: ");
  scanf("%d", &c);
  printf("Enter the loyalty points of the user: ");
  scanf("%d", &l);
  printf("The delivery charge is %d\n", cart(c, l));
}