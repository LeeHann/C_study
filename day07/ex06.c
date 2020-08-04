#include <stdio.h>
#include <SDL2/SDL.h>

int counter(){
  static int counter = 0; //counter 함수를 벗어나도 다시 선언되어도 변수 값이 초기화되지 않고 유지
  return counter++;
}

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  printf("%d \n", counter());
  printf("%d \n", counter());
  printf("%d \n", counter());
  printf("%d \n", counter());

  SDL_Quit();
  return 0;
}