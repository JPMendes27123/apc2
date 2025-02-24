#include <stdio.h>

int main(void) {
    int n1 = 3, n2 = 5;
    
    int *p1 = &n1;
    int *p2 = &n2;
    int t;

    t = *p1;
    *p1 = *p2;
    *p2 = t;

    printf("n1: %d, n2: %d\n", n1, n2);

    return 0;
}