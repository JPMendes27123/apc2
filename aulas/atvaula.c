#include <stdio.h>

int main(void) {

  printf("sizeof(int): %zu\n", sizeof(int));
  printf("sizeof(char): %zu\n", sizeof(char));
  printf("sizeof(float): %zu\n", sizeof(float));
  printf("sizeof(double): %zu\n", sizeof(double));
  
  int inteiro = 100; // &inteiro = 0x100
  printf("i: %d, i+1: %d, i+20: %d\n", inteiro, inteiro+1, inteiro+20);
  printf("i: %d, i-1: %d, i-20: %d\n", inteiro, inteiro-1, inteiro-20);

  short int *pint = (short int *)&inteiro;
  printf("pint: %p, pint+1: %p, pint+20: %p\n", (void*) pint, (void*) (pint+1), (void*) (pint+20));
  printf("pint: %p, pint-1: %p, pint-20: %p\n", (void*) pint, (void*) (pint-1), (void*) (pint-20));

  char *pchar = (char *)&inteiro;
  printf("pchar: %p, pchar+1: %p, pchar+20: %p\n", (void*) pchar, (void*) (pchar+1), (void*) (pchar+20));
  printf("pchar: %p, pchar-1: %p, pchar-20: %p\n", (void*) pchar, (void*) (pchar-1), (void*) (pchar-20));

  double *pdouble = (double *)&inteiro;
  printf("pdouble: %p, pdouble+1: %p, pdouble+20: %p\n", (void*) pdouble, (void*) (pdouble+1), (void*) (pdouble+20));
  printf("pdouble: %p, pdouble-1: %p, pdouble-20: %p\n", (void*) pdouble, (void*) (pdouble-1), (void*) (pdouble-20));
  
  return 0;
}