#include <stdio.h>

int main(){
  int a = 0x12345678;
  char *b;
  
  b = (char *)&a;
  printf("%x %x %x %x \n", *b, *(b+1), *(b+2), *(b+3));

  return 0;
}