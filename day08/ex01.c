#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  //data[y][x]
  char data[5][4] = {{1, 2, 3}, {4, 5, 6}};

  printf("%d \n", data[0][0]); //1
  printf("%d \n", data[1][1]); //5
  printf("%d \n", data[1][2]); //6

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%3d", data[i][j]);
    }
    printf("\n");
  }

  printf("----------------------\n");
  
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%3d", data[j][i]);
    }
    printf("\n");
  }

  SDL_Quit();
  return 0;
}