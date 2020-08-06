#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Uint16 map_layer1[100] = {
  14,14,80,14,14,14,14,14,14,14,
  14,14,80,14,14,14,14,14,14,14,
  14,14,80,14,14,14,14,14,14,14,
  14,14,80,80,80,80,80,80,80,80,
  14,14,14,14,14,14,14,14,14,14,
  14,14,14,14,14,14,14,14,14,14,
  14,14,14,14,14,14,14,14,14,14,
  14,14,14,14,14,14,14,14,14,14,
  14,14,14,14,14,14,14,14,14,14,
  14,14,14,14,14,14,14,14,14,14
  };
Uint16 map_layer2[64] = {
  14,14,80,27,55,36,36,56,
  14,14,80,14,14,14,14,45,
  14,14,80,14,14,14,14,53,
  14,44,48,91,91,81,91,91,
  14,44,14,99,99,14,99,99,
  14,44,14,44,14,14,14,14,
  14,44,14,44,14,14,14,14,
  14,44,14,44,14,14,14,14
  };

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *gWindow;
SDL_Renderer *gRenderer;
SDL_Texture *gTexture;

void _drawDot(int x, int y, Uint8 _r, Uint8 _g, Uint8 _b)
{
  SDL_Rect _dotInfo;
  _dotInfo.x = x * 16;
  _dotInfo.y = y * 16;
  _dotInfo.w = 16;
  _dotInfo.h = 16;
  SDL_SetRenderDrawColor(gRenderer, _r, _g, _b, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(gRenderer, &_dotInfo);
}

void _drawTile(int x, int y, Uint16 _tileIndex)
{
  SDL_Rect _tmpDstRt;
  _tmpDstRt.x = x * 40;
  _tmpDstRt.y = y * 40;
  _tmpDstRt.w = 40;
  _tmpDstRt.h = 40;

  SDL_Rect _tmpSrcRt;
  _tmpSrcRt.x = (_tileIndex % 8) * 16;
  _tmpSrcRt.y = (_tileIndex / 8) * 16;
  _tmpSrcRt.w = 16;
  _tmpSrcRt.h = 16;

  SDL_RenderCopy(gRenderer, gTexture, &_tmpSrcRt, &_tmpDstRt);
}

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    return 0;
  }

  gWindow = SDL_CreateWindow("GAME", // creates a window
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if(!gWindow)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  // creates a renderer to render our images
  gRenderer = SDL_CreateRenderer(gWindow, -1, render_flags);
  if(!gRenderer)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  //이미지 로딩
  {
    // creates a surface to load an image into the main memory
    SDL_Surface *surface;

    // please provide a path for your image
    surface = IMG_Load("../res/basictiles.png");
    if(!surface) {
      printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
      return 1;
    }

    // loads image to our graphics hardware memory.
    SDL_Texture *tex = SDL_CreateTextureFromSurface(gRenderer, surface);
    gTexture = tex;

    // clears main-memory
    SDL_FreeSurface(surface);
  }

  //게임루프
  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    //입력처리
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;

      default:
        break;
      }
    }
    //출력(rendering)
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);

    for (int iy = 0; iy < 10; iy++)
    {
      for (int ix = 0; ix < 10; ix++)
      {
        //Uint16 _dot = map_layer1[iy][ix];
        Uint16 _dot = map_layer1[iy * 10 + ix];
        int _x, _y;
        _x = ix + 0;
        _y = iy + 0;
        _drawTile(_x, _y, _dot);
      }
    }
    for (int iy = 0; iy < 8; iy++)
    {
      for (int ix = 0; ix < 8; ix++)
      {
        //Uint16 _dot = map_layer1[iy][ix];
        Uint16 _dot = map_layer2[iy * 8 + ix];
        int _x, _y;
        _x = ix + 0;
        _y = iy + 0;
        _drawTile(_x, _y, _dot);
      }
    }

    SDL_RenderPresent(gRenderer);
  }
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
  return 0;
}