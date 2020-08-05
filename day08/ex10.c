#include <stdio.h>
#include <stdlib.h>
//#define swap(a,b) {int tmp=a; a=b; b=tmp;}

void _sort(int arr[], int last){
  int min;
  
  for(int i=0; i<last; i++){
    min = arr[i];
    for(int j=i+1; j<last; j++){
      if(min >= arr[j]){ 
        int tmp = min;
        min = arr[j];
        arr[j] = tmp;
      }
    }
    arr[i] = min;
  }
}

int main(){
  int num[105];
  for(int i=0; i<100; i++){
    num[i] = rand()%100;
    printf("%d ", num[i]);
  }
  printf("\n\n");

  _sort(num, 100);

  for(int i=0; i<100; i++){
    printf("%d ", num[i]);
  }
  return 0;
}