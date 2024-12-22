// Enter required header files
#include <stdio.h>
/**
 * @brief Returns the binary form of the decimal representation of an integer
 *
 * - One of the methods to convert decimal to binary is by dividing the given
 * decimal number recursively by 2.
 * - The remainders are noted down till we get 0 as the final quotient.
 * - After this step, these remainders are written in reverse order to get the
 * binary value of the given decimal number.
 *
 * Example:
 * decimalToBinary(0) returns 0
 * decimalToBinary(1) returns 1
 * decimalToBinary(7) returns 111
 * decimalToBinary(200) returns 11001000
 */
// Have required parameter(s)
int decimalToBinary(int decimal) {
  // TODO
  if (decimal == 0) {
    return 0;
  }
  return (decimal % 2) + 10 * decimalToBinary(decimal / 2);
}

/**
 * @brief
 * - Performs simple arithmetic operations on the parameter 'balance' depending
on the options
 *   entered by the user.
 * - The function begins by printing the 'balance' and then asks for an option
from the user.
 * - The option entered by the user could be one of the following characters:
 *          '+', '-', 'e', 'c'
 * - On receiving an option 'e', the function does not ask as for any more
 *   options to be entered and returns 'e', thereby exiting from the function.
 * - On receiving one of '+', '-' as an option, the function waits for the user
 *   to enter an integer 'input' and performs the corresponding operation
between 'balance' and 'input'.
 * - On receiving the option 'c', cancel the last operation and continue from
there;
 *   If there are no more operations to cancel, exit the program.
 * - If the user enters some other option other than the 4 allowed, the program
exits.
 *
 * Example:
 *   - A possible run due to the function-call 'calculator(0)' is given below:
            Balance: 0
            +
            10
            Balance: 10
            +
            10
            Balance: 20
            +
            10
            Balance: 30
            e
 *   - Another possible run due to the function-call 'calculator(0)' is given
below: Balance: 0
            +
            10
            Balance: 10
            +
            10
            Balance: 20
            -
            5
            Balance: 15
            c
            Balance: 20
            +
            10
            Balance: 30
            c
            Balance: 20
            c
            Balance: 10
            e
*    - Another possible run due to the function-call 'calculator(0)' is given
below: Balance: 0
            +
            10
            Balance: 10
            -
            10
            Balance: 0
            c
            Balance: 10
            c
            Balance: 0
            c
*    - Another possible run due to the function-call 'calculator(0)' is given
below: Balance: 0
            -
            10
            Balance: -10
            *
 */

char calculator(int balance) {
  printf("Balance: %d\n", balance);
  int callBack = balance;
  char cc;
  scanf(" %c", &cc);

  // if (cc == '+' || cc == '-') {
  //   int value;
  //   scanf("%d", &value);
  //   if (cc == '+')
  //     calculator(balance + value);
  //   if (cc == '-')
  //     calculator(balance - value);
  // }

  if (cc == 'e' || cc == 'c')
    return cc;

  if (cc == '+') {
    int value;
    scanf("%d", &value);
    balance += value;
  } else if (cc == '-') {
    int value;
    scanf("%d", &value);
    balance -= value;
  }

  char c = calculator(balance);
  if (c == 'c') {
    calculator(callBack);
  } else if (c == 'e') {
    return 'e';
  }

  // char c1;
  // scanf("%c", &c1);
  // if (c1 == 'c') {
  //   calculator(callBack);
  // }
  // return cc;
  // if (cc == 'e')
  //   return 0;
}

// TAIL RECURSION ATTEMPT WITH 2 FUNCTIONS & MULTIPLE PARAMETERS

int main() {
  ///*******DO NOT CHANGE main()********

  printf("1. decimal to binary  2. calculator(0)\n");
  printf("Which function do you want to test? Enter 1 or 2 accordingly.\n");

  int option;
  scanf(" %d", &option);

  if (option == 1) {
    int decimal;
    printf("Enter a number between 0 and 1000 (both inclusive): ");
    scanf("%d", &decimal);
    printf("Binary is: %d\n", decimalToBinary(decimal));
  } else if (option == 2) {
    calculator(0);
  }
  return 0;
}