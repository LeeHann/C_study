#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#include "../engine/text_lable.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
TTF_Font *g_pFont;

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  g_pWindow = SDL_CreateWindow("GAME", // creates a window
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  if (!g_pWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }

  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

  //Initialize SDL_ttf
  if (TTF_Init() == -1)
  {
    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    return 0;
  }
  else
  {
    printf("SDL_ttf initialize Ok!  \n");
  }

  //LOAD font file
  g_pFont = TTF_OpenFont("../adv/sdl/res/nmf.ttf", 28);

  if (!g_pFont)
  {
    printf("font file load error");
    printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    return 0;
  }
  else 
  {
    printf("font load ok!\n");
  }

  S_TextLable *ptxLable = createLable(g_pRenderer,100,100,1,L"hello Lable 한글.",g_pFont);

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 0xff);
    SDL_RenderClear(g_pRenderer);

    TextLable_render(ptxLable,g_pRenderer);
    
    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_KEYDOWN:
        printf("%d \n", _event.key.keysym.scancode);
        break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }
  
  TextLable_destory(ptxLable);
  TTF_CloseFont(g_pFont);
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}
