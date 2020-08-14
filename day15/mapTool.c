#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

int doTokenize(char *szBuf, char szBufToken[][32]);
void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex, Uint16 _x, Uint16 _y, Uint16 _index);

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_Window *gWindow;
SDL_Renderer *g_pRenderer;
SDL_Texture *g_pTitleTexture;
SDL_Texture *g_pButton;
TTF_Font *g_pFont;

SDL_bool bLoop = SDL_TRUE;

Uint16 g_worldMap_Layer_1[64];
Uint16 g_nSelectTileIndex = 0;

void processCmd(char *_szCmd, SDL_bool *bLoop)
{
  static char szCmd[32];
  static char szTokens[8][32];

  strcpy(szCmd, _szCmd);

  printf("token count %s\n", szCmd);
  int _numToken = doTokenize(szCmd, szTokens);

  printf("token count %d\n", _numToken);

  if (strcmp(szTokens[0], "quit") == 0)
  {
    *bLoop = SDL_FALSE;
  }
  else if (strcmp(szTokens[0], "setTile") == 0)
  {
    //setTile x y index
    int _x = SDL_atoi(szTokens[1]);
    int _y = SDL_atoi(szTokens[2]);
    int _index = SDL_atoi(szTokens[3]);

    g_worldMap_Layer_1[(_y * 8) + _x] = _index;
  }
  else if (strcmp(szTokens[0], "save") == 0)
  {
    //save file.map
    char *pFileName = szTokens[1];
    SDL_RWops *rw = SDL_RWFromFile(pFileName, "wb");
    SDL_RWwrite(rw, g_worldMap_Layer_1, sizeof(Uint16), 64);
    SDL_RWclose(rw);
  }
  else if (strcmp(szTokens[0], "load") == 0)
  {
    char *pFileName = szTokens[1];
    SDL_RWops *rw = SDL_RWFromFile(pFileName, "rb");
    SDL_RWread(rw, g_worldMap_Layer_1, sizeof(Uint16), 64);
    SDL_RWclose(rw);
  }
}

int main(int argc, char *argv[])
{
  for (int i = 0; i < 64; i++)
    g_worldMap_Layer_1[i] = -1;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  gWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  if (!gWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }
  g_pRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
  {
    SDL_Surface *surface;
    surface = IMG_Load("../res/dungeontiles.png");
    SDL_Texture *tex = SDL_CreateTextureFromSurface(g_pRenderer, surface);
    SDL_FreeSurface(surface);
    g_pTitleTexture = tex;
  }

  {
    SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};
    SDL_Color _blackColor = {0, 0, 0, 0x00};
    SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(g_pFont, L"SWAP", _whiteColor);

    g_pButton = SDL_CreateTextureFromSurface(g_pRenderer, textSurface);
    SDL_FreeSurface(textSurface);
  }

  static char strBuf[32] = {
      0,
  };

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
  g_pFont = TTF_OpenFont("../../adv/sdl/res/nmf.ttf", 28);

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

  int nTileIndex = 0;

  int nInputFSM = 0; //0 -> ready , 1-> text input

  //processCmd("setTile 0 0 1", NULL);
  //processCmd("setTile 1 0 1", NULL);
  //processCmd("setTile 2 0 1", NULL);

  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(g_pRenderer);

    //select tile
    putTile(g_pRenderer, g_pTitleTexture, 15, 0, g_nSelectTileIndex);

    //440,100
    {
      //pallete Rendering
      SDL_Rect _dstRt = {440, 100, 48 * 4, 72 * 4};
      SDL_RenderCopy(g_pRenderer, g_pTitleTexture, NULL, &_dstRt);
    }

    //render world map
    {
      for (int i = 0; i < 64; i++)
      {
        int _index = g_worldMap_Layer_1[i];
        if (_index != -1)
        {
          putTile(g_pRenderer, g_pTitleTexture, i % 8, i / 8, _index);
        }
      }
    }

    // for multiple rendering
    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_MOUSEMOTION:
      {
        //printf("%4d%4d\r", _event.motion.x, _event.motion.y);
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
            //printf("%4d%4d\r", _x, _y);
          }
          //월드맵 처리
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;

            if (_x < 8 && _y < 8)
            {
              int _tileIndex = _y * 8 + _x;
              g_worldMap_Layer_1[_tileIndex] = g_nSelectTileIndex;
              //printf("%4d%4d%4d\r", _x, _y, _tileIndex);
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
      case SDL_KEYDOWN:
        if (_event.key.keysym.sym == SDLK_RETURN)
        {
          if (nInputFSM == 0)
          {
            printf("input msg : \n");
            SDL_StartTextInput();
            nInputFSM = 1;
          }
          else if (nInputFSM == 1)
          {
            printf("\n%s\n", strBuf);
            processCmd(strBuf, &bLoop);

            strBuf[0] = 0x00;
            SDL_StopTextInput();
            nInputFSM = 0;
          }
        }
        else if (_event.key.keysym.sym == SDLK_BACKSPACE)
        {
          int _count = strlen(strBuf);
          if (_count > 0) //버퍼에 값이 존재 할때만...
          {
            _count--;
            strBuf[_count] = 0x00;
            printf("%s \r", strBuf);
          }
        }
        break;
      case SDL_TEXTINPUT:
      {
        strcat(strBuf, _event.text.text);
        printf("%s \r", strBuf);
      }
      break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }

  TTF_CloseFont(g_pFont);
  SDL_DestroyTexture(g_pTitleTexture);
  SDL_DestroyRenderer(g_pRenderer);

  SDL_DestroyWindow(gWindow);
  SDL_Quit();
  return 0;
}