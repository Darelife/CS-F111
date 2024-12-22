#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void insertAtEnd(struct Node *head, int data) {
  struct Node *ptr = head;
  struct Node *t = malloc(sizeof(struct Node));
  t->data = data;
  t->next = NULL;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = t;
}

void insertAtBeginning(struct Node **head, int data) {
  struct Node *t = malloc(sizeof(struct Node));
  t->data = data;
  t->next = *head;
  *head = t;
}

void insertAtIndex(struct Node *head, int index, int data) {
  struct Node *ptr = head;
  struct Node *t = malloc(sizeof(struct Node));
  t->data = data;
  for (int i = 0; i < index - 1; i++) {
    ptr = ptr->next;
  }
  t->next = ptr->next;
  ptr->next = t;
}

struct Node *linkedList(int n, int *arr) {
  struct Node *ptr = malloc(sizeof(struct Node));
  struct Node *a = ptr;
  for (int i = 0; i < n; i++) {
    struct Node *t = ptr;
    t->data = arr[i];
    t->next = malloc(sizeof(struct Node));
    ptr = t->next;
    if (i == n - 1) {
      t->next = NULL;
    }
  }
  ptr = a;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  return a;
}

int main(int argc, char const *argv[]) {
  int arr[argc - 1];
  for (int i = 0; i < argc - 1; i++) {
    arr[i] = atoi(argv[i + 1]);
  }
  struct Node *a = linkedList(argc - 1, arr);
  printf("\n");
  insertAtBeginning(&a, 2);
  printf("done\n");
  // insertAtIndex(&a, 2, 30);
  for (struct Node *ptr = a; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->data);
  }
  return 0;
}