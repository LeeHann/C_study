#include <stdio.h>
#include <SDL2/SDL.h>
#include "../engine/util.h"
#include "../engine/button.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;

S_BUTTON g_Buttons[2];

int main(int argc, char *argv[])
{
  Button_Init(&g_Buttons[0], 100,100,120,120, 1);
  Button_Init(&g_Buttons[1], 300,100,120,120, 2);
  
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  g_pWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
  if (!g_pWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_bool bLoop = SDL_TRUE;

  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(g_pRenderer);
   
    for(int i=0; i<2; i++) Button_Render(&g_Buttons[i], g_pRenderer);
    
    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      for(int i=0; i<2; i++) Button_DoEvent(&g_Buttons[i], &_event);
      switch (_event.type)
      {
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}