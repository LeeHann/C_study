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
  
  char num = 1; // 0000 0001
  
  // 0000 0010
  printf("%d \n", num << 1);
  // 0000 0100
  printf("%d \n", num << 2);

  num = 8; // 0000 1000
  // 0000 0010
  printf("%d \n", num >> 2);
  
  return 0;
}