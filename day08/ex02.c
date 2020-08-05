#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  int n = 4;
  //  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
  int m = 4;
  //  scanf("%d", &n);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  printf("\n");

  SDL_Quit();
  return 0;
}