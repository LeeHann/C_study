#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  int n = 5, k = 0, l=0;
  //scanf("%d", &n);
  
  char star[10][10];
  for(int i=0; i<(n/2+n%2); i++, l++){
    for(int j=0; j<(n-i*2)/2; j++, k++){
      printf(" ");
    }
    for(int j=0; j<i*2+1; j++, k++){
      printf("*");
    }
    printf("\n");
  }
  for(int i=0; i<n/2; i++, l++){
    for(int j=0; j<=i; j++, k++){
      printf(" ");
    }
    for(int j=n/2-i%2; j>=i; j--, k++){
      printf("*");
    }
    printf("\n");
  }

  SDL_Quit();
  return 0;
}