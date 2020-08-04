#include <stdio.h>
#include <SDL2/SDL.h>

int c = 5; // 전역 변수 c

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  
  int b = 3; //지역 변수 b1
  {
    int a = 1;
    int b = a + 1; //지역 변수 b2
    printf("%d \n", b); //지역 변수 b2를 사용
    printf("%d \n", c); //전역 변수 c를 사용
  }
  //int b = 5; //error 이미 선언된 변수를 재선언
  printf("%d \n", b); //지역 변수 b1를 사용
  printf("%d \n", c); //전역 변수 c를 사용
  SDL_Quit();
  return 0;
}