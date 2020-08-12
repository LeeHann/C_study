#include <stdio.h>
#include "ex05.h"
#include "ex05.h" //헤더파일의 중복 참조 막기 -> 헤더 파일에 ifndef 사용

int main(){
  printf("data sum : %d", data[0]+data[1]+data[2]);
  return 0;
}