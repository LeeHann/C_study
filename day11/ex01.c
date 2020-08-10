#include <stdio.h>

int main(){
  int data = 0;
  int *p = &data;
  int **pp = &p;  //2차원
  int ***ppp = &pp; //3차원

  data++;
  printf("%d \n", *p); //1
  
  data++;
  printf("%d \n", **pp); //2
  
  data++;
  printf("%d \n", ***ppp); //3
  return 0;
}