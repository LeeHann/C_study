#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../engine/tile.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
SDL_Texture *g_pTileSet;

Uint16 g_worldMap_Layer_1[64];

Uint16 g_nSelectTileIndex = 0;

int main(int argc, char *argv[])
{
  for (int i = 0; i < 64; i++)
    g_worldMap_Layer_1[i] = -1;

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

  {
    SDL_Surface *psurf;
    psurf = IMG_Load("../res/dungeontiles.png");
    SDL_Texture *pTex = SDL_CreateTextureFromSurface(g_pRenderer, psurf);
    g_pTileSet = pTex;
    SDL_FreeSurface(psurf);
  }

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 1);
    SDL_RenderClear(g_pRenderer);

    //select tile
    putTile(g_pRenderer, g_pTileSet, 15, 0, g_nSelectTileIndex);

    //440,100
    {
      //pallete Rendering
      SDL_Rect _dstRt = {440, 100, 48 * 4, 72 * 4};
      SDL_RenderCopy(g_pRenderer, g_pTileSet, NULL, &_dstRt);
    }

    //render world map
    {
      for (int i = 0; i < 64; i++)
      {
        int _index = g_worldMap_Layer_1[i];
        if (_index != -1)
        {
          putTile(g_pRenderer, g_pTileSet, i % 8, i / 8, _index);
        }
      }
    }
    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_MOUSEMOTION:
      {
        printf("%4d%4d\r", _event.motion.x, _event.motion.y);
      }
      break;
      case SDL_MOUSEBUTTONDOWN:
      {
        printf("%8d\r", _event.button.button);
        if (_event.button.button == 1)
        { //팔레트 처리
          {
            int _x = (_event.motion.x - 440) / 32;
            int _y = (_event.motion.y - 100) / 32;

            if ((_x >= 0 && _y >= 0) && (_x < 6 && _y < 9))
            {
              g_nSelectTileIndex = _y * 6 + _x;
            }
            printf("%4d%4d\r", _x, _y);
          }
          //월드맵 처리
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;

            if (_x < 8 && _y < 8)
            {
              int _tileIndex = _y * 8 + _x;
              //printf("%d  \r", _tileIndex);
              g_worldMap_Layer_1[_tileIndex] = g_nSelectTileIndex;
              printf("%4d%4d%4d\r", _x, _y, _tileIndex);
            }
          }
        }
        else if (_event.button.button == 3) //우클릭
        {
          int _x = (_event.motion.x) / 32;
          int _y = (_event.motion.y) / 32;

          if (_x < 8 && _y < 8)
          {
            int _tileIndex = _y * 8 + _x;
            g_worldMap_Layer_1[_tileIndex] = -1;
          }
        }
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

  SDL_DestroyTexture(g_pTileSet);
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}
