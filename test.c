#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n1 = 4;

typedef struct record {
  int id;
  struct record *next;
} record;

void insert(record *tableStart, record x) {
  record *y = (record *)malloc(sizeof(record));
  y->id = x.id;
  y->next = x.next;
  record *ptr = tableStart;
  record *before = NULL;
  while ((ptr != NULL) && (ptr->id < y->id)) {
    before = ptr;
    ptr = ptr->next;
  }
  if (before == NULL) {
    y->next = tableStart;
    tableStart = y;
  } else {
    y->next = before->next;
    before->next = y;
  }
}

void delete(record *tableStart, int x) {
  record *ptr = tableStart;
  record *before = NULL;

  while (ptr != NULL && ptr->id != x) {
    before = ptr;
    ptr = ptr->next;
  }
  if (before != NULL)
    before->next = ptr->next;
}

void create(record *tableStart, int n) {
  record *ptr = tableStart;
  for (int i = 0; i < n; i++) {
    record *t = ptr;
    t->id = i;
    t->next = malloc(sizeof(record));
    ptr = t->next;
    if (i == n - 1) {
      t->next = NULL;
    }
  }
  ptr = tableStart;
  while (ptr != NULL) {
    printf("%d ", ptr->id);
    ptr = ptr->next;
  }
}

typedef struct point {
  double x, y;
} point;

#define inf 100e100

double slope(point *p1, point *p2) {
  if (p1->x == p2->x)
    return inf;
  return ((p2->y - p1->y) / (p2->x - p1->x));
}

double *slopes(point pts[], int n) {
  double *slopes = (double *)malloc((n - 1) * sizeof(double));
  for (int i = 0; i < n - 1; i++) {
    slopes[i] = slope(&pts[i], &pts[i + 1]);
  }
  return slopes;
}

char **words(FILE *fp, int n) {
  char line[81]; // 80 + 1 (\0)
  char **words = malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    fgets(line, 81, fp);
    int len = strlen(line);
    words[i] = malloc((len + 1) * sizeof(char));
    strcpy(words[i], line);
  }
  return words;
}

int numofwords(FILE *fp) {
  char line[81];
  int ans = 0;
  while (fgets(line, 81, fp))
    ans++;
  return ans;
}

void revStr(char *s, char *ans) {
  int n = strlen(s);
  int maxLen = (n % 2) ? (n / 2 + 1) : (n / 2);
  for (int i = 0; i < maxLen; i++) {
    ans[i] = s[n - i - 1];
    ans[n - i - 1] = s[i];
  }
  ans[n] = '\0';
}

int main() {
  // record *tableStart = (record *)malloc(sizeof(record));
  // create(tableStart, 5);
  // printf("\n");
  // record x;
  // x.id = 3;
  // x.next = NULL;
  // insert(tableStart, x);
  // record *ptr = tableStart;
  // delete (tableStart, 0);
  // while (ptr != NULL) {
  //   printf("%d ", ptr->id);
  //   ptr = ptr->next;
  // }
  // printf("\n%d\n", n1);
  // int *arr = malloc(4);
  // arr[0] = 3;
  // printf("\n%d\n", arr[1]);
  // char ans[4];
  // revStr("abc", ans);
  // printf("%s", ans);
  FILE *ptr;
  ptr = fopen("test.txt", "r+");
  char *a = "AB";
  fprintf(ptr, "%s", a);
  fclose(ptr);
}