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
  
  int num = 1; // 0001
  while(SDL_TRUE){
    num ^= 1;
    //if(num == 1) num = 0;
    //else num = 1;
    printf("[%2d] \r", num);
    SDL_Delay(500);
  }
  return 0;
}