#include <stdio.h>

void main(){
  int a = 0x12345678; // 78, 56, 34, 21
  int *pA = &a;
  int *pB = pA;
  char *pC = (char *)pA;

  printf("%x \n", *pA);
  printf("%x \n", *pB);
  printf("%x \n", *pC); // 78
  printf("%x \n", *(pC+1)); // 56
  printf("%x \n", *(pC+2)); // 34
}
