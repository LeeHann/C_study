#include <stdio.h>

int main(){
  char data[5] = {'a','b','c','d','e'};
  char *p = data;

  printf("%c %c %c %c\n", *p, *(p+1), *(data+2), p[3]); //a b c d
  
  p = p+1;
  //data = data+1; //error assignment to experssion with array type
  printf("%c \n", *p); //b

  return 0;
}