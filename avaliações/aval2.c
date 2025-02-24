#include <stdio.h>

int main(void) {
    int numero;
    
    int *p = &numero;
    *p = 5;

    printf("%d\n", numero);

    return 0;
}