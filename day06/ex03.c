#include <stdio.h>

int main(){
  int sum = 0, num = 1;

/*
  while(1){
    printf("%d \n", num);
    sum += num;
    if(num >= 5) break;
    num++;
  }
*/
  do{
    printf("%d \n", num);
    sum += num;
    if(num >= 5) break;
    num++;
  }while(1);

  printf("%d \n", sum);

  return 0;
}