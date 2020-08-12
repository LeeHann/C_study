#include <stdio.h>
#include <SDL2/SDL.h>
#include "../engine/util.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;

int main(int argc, char *argv[])
{
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
  SDL_bool bCheckHitRect = SDL_FALSE;
  SDL_bool bCheckHitRect2 = SDL_FALSE;
  
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(g_pRenderer);
    SDL_Rect testRect = {100, 100, 120, 120};
    SDL_Rect testRect2 = {250, 250, 100, 100};
     
    if (!bCheckHitRect)
    {
      SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
      SDL_RenderDrawRect(g_pRenderer, &testRect);
    }
    else
    {
      SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
      SDL_RenderFillRect(g_pRenderer, &testRect);
    }
    if (!bCheckHitRect2)
    {
      SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
      SDL_RenderDrawRect(g_pRenderer, &testRect2);
    }
    else
    {
      SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 255);
      SDL_RenderFillRect(g_pRenderer, &testRect2);
    }

    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_MOUSEBUTTONDOWN:
      {
        int _mx = _event.motion.x;
        int _my = _event.motion.y;
        if(checkPointInRect(&testRect, _event.motion.x, _event.motion.y) == SDL_TRUE){
          printf("push button1 \n");
        }
        if(checkPointInRect(&testRect2, _event.motion.x, _event.motion.y) == SDL_TRUE){
          printf("push button2 \n");
        }
      }
      break;
      case SDL_MOUSEMOTION:
      {
        // int _mx = _event.motion.x;
        // int _my = _event.motion.y;
        
        bCheckHitRect = checkPointInRect(&testRect, _event.motion.x, _event.motion.y);
        bCheckHitRect2 = checkPointInRect(&testRect2, _event.motion.x, _event.motion.y);

        // if ((testRect.x < _mx && testRect.y < _my) && (testRect.x + testRect.w > _mx && testRect.y + testRect.h > _my))
        // {
        //   bCheckHitRect = SDL_TRUE;
        //   printf("%4d%4d%2d\r", _event.motion.x, _event.motion.y, 1);
        // }
        // else
        // {
        //   bCheckHitRect = SDL_FALSE;
        //   printf("%4d%4d%2d\r", _event.motion.x, _event.motion.y, 0);
        // }
      }
      break;
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
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}