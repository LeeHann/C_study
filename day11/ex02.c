#include <stdio.h>

int main(){
  int **pp;
  int data = 3;

  int *p;
  p = &data;
  pp = &p;
  //pp = (int **)&data; //segmentation fault

  printf("%d \n", **pp);

  return 0;
}