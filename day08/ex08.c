#include <stdio.h>

//void testGet(int num){ //복사만 일어나고 지역을 벗어나면 지역변수 num은 사라짐
void testGet(int *num){ //a에 대한 주소값 복사, 주소에 3을 넣어줌 // call by pointer
  *num = 3;
}

void _sum(int a, int b, int *c){
  *c = a + b;
}

void main(){
  int a = 0;
  int x = 1, y = 2, z;

  testGet(&a);
  _sum(x, y, &z);

  printf("%d \n", a);
  printf("%d %d %d \n", x, y, z);
}