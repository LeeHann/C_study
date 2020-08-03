#include <stdio.h>

int main(){
  int sum=0, num;
  
  //for(num=1; num<=5; num++){
  //for(num=1, sum=0; num<=5; num++){
  //for(int num=1; num<=5; num++){
  int sum = 0, num=1;
  for(;num<=5; num++){
    printf("%d \n", num);
    sum = sum + num;
  }
  printf("%d \n", sum);

  return 0;
}