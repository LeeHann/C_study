#include <stdio.h>
#include <SDL2/SDL.h>

int _Sum(int data1, int data2){
  int result = data1 + data2;
  return result;
}

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  int result = _Sum(5, 3);
  printf("%d \n", result);
  
  SDL_Quit();
  return 0;
}