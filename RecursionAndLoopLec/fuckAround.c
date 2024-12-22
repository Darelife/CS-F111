#include <stdio.h>

int randomQuestionOnLoop() {
  int money = 100;
  while (1) {
    printf("You have inr %3d\n", money);
    int cost;
    printf("Enter the cost of the item ");
    scanf("%d", &cost);
    if ((money -= cost) >= 0) {
      printf("Money Left : %3d\n", money);
    } else {
      printf("Dudeeeee u are in debtttttt\n");
      break;
    }

    if (cost == 0)
      break;
  }
  return 0;
}

int evenSum(int a, int b) {
  int sum = 0;
  while (a <= b) {
    if (a % 2 == 0) {
      sum += a;
      a += 2;
    } else {
      a += 1;
    }
  }
  printf("%d", sum);
}

int evenSumRecursion(int a, int b) {
  int sum = 0;
  if (a > b)
    return 0;
  else if (a % 2 == 0)
    sum += a + evenSumRecursion(a + 2, b);
  else
    sum += evenSumRecursion(a + 1, b);
  return sum;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  evenSum(a, b);
  printf("\n");
  printf("%d\n", evenSumRecursion(a, b));
}
