#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  int n = 5;
  //scanf("%d", &n);
  
  char star[10][10];
  for(int i=0; i<n; i++){
    for(int j=0; j<(n-i)/2; j++){
      printf(" ");
    }
    for(int j=0;;){}
  }
/*
  for(int i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%c", star[i][j]);
    }
    printf("\n");
  }
*/
  SDL_Quit();
  return 0;
}