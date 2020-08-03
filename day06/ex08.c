#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  else{
    printf("success SDL INIT\n");
  }

  // 숫자 입력 받기
  int num;
  printf("input number : ");
  scanf("%d", &num);

  // 이진수 출력
/*
  for(int i=0; i<4; i++){
    if(8 & num<<i)
      printf("1");
    else
      printf("0");
  }
*/
  for(int i=0; i<8; i++){
    int _status = num & (0x80 >> i);
    if(_status){
      printf("1");
    }
    else{
      printf("0");
    }
  }

  return 0;
}