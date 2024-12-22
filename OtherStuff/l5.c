#include <stdio.h>

int main() {
    int c;
    int d;
    // scanf("%d", &a);
    // Why do i need to use &a here?
    // What is the difference between &a and a?
    // &a is the address of a


    // Pointers
    int *b = &c;
    int *e = &d;
    printf("%p\n", b);
    printf("%p\n", e);

    // Dereferencing
    printf("%d\n", *b);
    printf("%d\n", *e);
    return 0;
}