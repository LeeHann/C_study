#include <stdio.h>

int main(){
  char data[2*1024*1024];
  
  data[0] = '1';
  printf("%d \n", data[0]);

  return 0;
}