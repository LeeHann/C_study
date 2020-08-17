#include "core.h"
#include <time.h>

tDE_S_Core *tDE_setup_1(const char *szTitle, int window_width, int window_height, Uint32 flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING))
  {
    printf("sdl init error : %s \n", SDL_GetError());
    return NULL;
  }

  tDE_S_Core *pCore = SDL_malloc(sizeof(tDE_S_Core));

  pCore->m_pWin = SDL_CreateWindow(szTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, flags);

  pCore->m_pRender = SDL_CreateRenderer(pCore->m_pWin, -1, SDL_RENDERER_ACCELERATED);

  if (!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
  {
    printf("sdl_image dll init error : %s \n", SDL_GetError());
    return NULL;
  }

  if(TTF_Init() == -1)
  {
    printf("sdl_ttf dll init error : %s \n", SDL_GetError());
    return NULL;
  }

  pCore->m_pDefaultFont = TTF_OpenFont("../res/nmf.ttf", 14);
  if(!pCore->m_pDefaultFont)
  {
    printf("load default font error : %s \n", SDL_GetError());
  }

  printf("init module ok \n");
  printf("engine start at %8d\n", time(NULL));
  srand(time(NULL));

  return pCore;
}

void tDE_closeCore(tDE_S_Core *pCore)
{
  TTF_CloseFont(pCore->m_pDefaultFont);
  SDL_DestroyRenderer(pCore->m_pRender);
  SDL_DestroyWindow(pCore->m_pWin);
}

SDL_Texture *tDE_util_loadTexture(tDE_S_Core *pCore, const char *filename)
{
  SDL_Surface *surface;
  surface = IMG_Load(filename);
  
  if(surface == NULL)
  {
    printf("file load error : %s \n", SDL_GetError());
    return NULL;
  }
  else
  {
    printf("load success %s\n", filename);
  }
  SDL_Texture *pTex = SDL_CreateTextureFromSurface(pCore->m_pRender, surface);
  SDL_FreeSurface(surface);
  return pTex;
}