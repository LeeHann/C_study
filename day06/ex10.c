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
  SDL_Window *gWindow = SDL_CreateWindow("GAME", // creates a window
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         640, 480, 0);
  SDL_bool bLoop = SDL_TRUE;

  while(bLoop){
    SDL_Event event;
    while (SDL_PollEvent(&event))
      {
        switch (event.type){
          case SDL_QUIT:
            bLoop = SDL_FALSE;
            break;
          case SDL_MOUSEBUTTONDOWN:
            printf("%d \n", event.button.button);
            break;
        }
      }
  }

  SDL_DestroyWindow(gWindow);
  return 0;
}