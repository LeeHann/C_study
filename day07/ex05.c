#include <stdio.h>
#include <SDL2/SDL.h>

extern int result2;
void Sum(int, int);

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

//  printf("%d \n", result2); // linking error : static 변수로 선언된 전역 변수 참조
  SDL_Quit();
  return 0;
}