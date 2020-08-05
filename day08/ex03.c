#include <stdio.h>
#include <SDL2/SDL.h>

Uint16 map_layer1[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}  
};
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *gWindow;

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

 gWindow = SDL_CreateWindow("GAME", // creates a window
  SDL_WINDOWPOS_CENTERED,
  SDL_WINDOWPOS_CENTERED,
  WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  
  // Game Loop
  SDL_bool bLoop = SDL_TRUE;
  while(bLoop){
    // 입력 처리
    SDL_Event event;
    // Events mangement
    while (SDL_PollEvent(&event)){
      switch(event.type){
        case SDL_QUIT:
          bLoop = SDL_FALSE;
          break;
          
        default :
          break;
      }
    }
    //출력 처리(Rendering)
  }

  SDL_DestroyWindow(gWindow);
  SDL_Quit();
  return 0;
}