#include <stdio.h>

int main(){
  char a = 0x12, b = 0x34;
  short c = 0x5678;
  int t;
  int *pt;
  
  pt = &t;

  *(short *)(pt+0) = c;
  *((char *)pt+2) = b;
  *((char *)pt+3) = a;
  
  printf("%8x \n", *pt);
  printf("%8x \n", t);
  
  return 0;
}