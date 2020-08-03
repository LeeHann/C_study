#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  else
  {
    printf("success SDL INIT\n");
  }
  SDL_Window *gWindow = SDL_CreateWindow("GAME", // creates a window
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         640, 480, 0);
  // triggers the program that controls
  // your graphics hardware and sets flags
  Uint32 render_flags = SDL_RENDERER_ACCELERATED;

  // creates a renderer to render our images
  SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow, -1, render_flags);

  // creates a surface to load an image into the main memory
  SDL_Surface *surface;

  // please provide a path for your image
  surface = IMG_Load("./basictiles.png");

  if (!surface)
  {
    printf("error msg %s\n", IMG_GetError());
    return 1;
  }

  // loads image to our graphics hardware memory.
  SDL_Texture *tex = SDL_CreateTextureFromSurface(gRenderer, surface);

  // clears main-memory
  SDL_FreeSurface(surface);

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    // clears the screen
    SDL_RenderClear(gRenderer);

    for (int iy = 0; iy < 8; iy++)
    {
      for (int ix = 0; ix < 8; ix++)
      {
        SDL_Rect src = {16 * 6, 16 * 1, 16, 16};
        SDL_Rect dest = {ix * 64, iy * 64, 64, 64};
        SDL_RenderCopy(gRenderer, tex, &src, &dest);
      }
    }

    {
      int ix = 2;
      int iy = 4;
      int _tile_index = 19;

      int _src_index_x = _tile_index % 8;
      int _src_index_y = _tile_index / 8;
      SDL_Rect src = {16 * _src_index_x, 16 * _src_index_y, 16, 16};
      SDL_Rect dest = {ix * 64, iy * 64, 64, 64};
      SDL_RenderCopy(gRenderer, tex, &src, &dest);
    }
    {
      int ix = 5;
      int iy = 5;
      int _tile_index = 19;

      int _src_index_x = _tile_index % 8;
      int _src_index_y = _tile_index / 8;
      SDL_Rect src = {16 * _src_index_x, 16 * _src_index_y, 16, 16};
      SDL_Rect dest = {ix * 64, iy * 64, 64, 64};
      SDL_RenderCopy(gRenderer, tex, &src, &dest);
    }
    SDL_RenderPresent(gRenderer);
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      }
    }
  }
  SDL_DestroyWindow(gWindow);
  return 0;
}