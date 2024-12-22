#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int binary_search(int nums[], int length, int key) {
  int min = 0;
  int max = length - 1;
  int mid = min + (max - min) / 2;
  for (int i = 0; i < length; i++) {
    int mid = min + (max - min) / 2;
    printf(" - Checking index %d\n", mid);
    if (nums[mid] == key) {
      return mid;
    } else if (nums[mid] < key) {
      min = mid + 1;
    } else if (nums[mid] > key) {
      max = mid - 1;
    }
  }
  return -1;
}

int count_vowels(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' ||
        str[i] == 'O' || str[i] == 'U') {
      count++;
    }
  }
  return count;
}

int get_arr_length() {
  int length = 0;
  while (length <= 0) {
    printf("How many numbers do you want to enter (between 1 and %d)? ",
           MAX_LENGTH);
    scanf("%d", &length);
  }
  return length;
}

void get_nums(int arr[], int length) {
  for (int i = 0; i < length; ++i)
    scanf("%d", &arr[i]);
}

int main() {
  printf("This program supports these operations:\n");
  printf("\t1. Search a key in a non-decreasing sequence of integers.\n\n");
  printf("\t2. Count the number of vowels in a string.\n\n");
  printf("Choose an operation: ");
  int operation = 0;
  scanf("%d", &operation);

  if (operation == 1) {
    int nums[MAX_LENGTH];
    int length = get_arr_length();
    printf("Enter %d integers in non-decreasing order (no duplicates): ",
           length);
    get_nums(nums, length);
    printf("Enter the key to search: ");
    int key;
    scanf("%d", &key);
    int index = binary_search(nums, length, key);

    printf("%d", key);
    if (index >= 0)
      printf(" found at index %d\n", index);
    else
      printf(" not found.\n");
  } else if (operation == 2) {
    printf("Enter a string: ");
    char str[MAX_LENGTH];
    scanf("%s", str);
    int ans = count_vowels(str);
    printf("%s has %d vowels\n", str, ans);
  }
  return 0;
}