#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include "../engine/util.h"
#include "../engine/button.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;

S_BUTTON g_Buttons[5];
static SDL_bool bLoop = SDL_TRUE;

void callback_Btn1_Push(S_BUTTON *pBtn)
{
  bLoop = SDL_FALSE;
}

void callback_Btn2_Push(S_BUTTON *pBtn)
{
  // bLoop = SDL_FALSE;
  pBtn->m_fillColor.r =0;
  pBtn->m_fillColor.g =0;
  pBtn->m_fillColor.b =255;
  pBtn->m_fillColor.a =255;
  
}
int main(int argc, char *argv[])
{
  Button_Init(&g_Buttons[0], 100, 100, 120, 120, 1, SDL_TRUE, callback_Btn1_Push);
  Button_Init(&g_Buttons[1], 300, 100, 120, 120, 2, SDL_TRUE, callback_Btn2_Push);
  Button_Init(&g_Buttons[2], 500, 100, 120, 120, 3, SDL_TRUE, NULL);
  Button_Init(&g_Buttons[3], 200, 300, 120, 120, 4, SDL_TRUE, NULL);
  Button_Init(&g_Buttons[4], 400, 300, 120, 120, 5, SDL_TRUE, NULL);

  srand((unsigned int)time(NULL));

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  g_pWindow = SDL_CreateWindow("GAME", // creates a window
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (!g_pWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }

  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(g_pRenderer);

    for (int i = 0; i < 5; i++)
      Button_Render(&g_Buttons[i], g_pRenderer);

    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      for (int i = 0; i < 5; i++)
        Button_DoEvent(&g_Buttons[i], &_event);

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