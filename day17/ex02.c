//xml파일에 저장된 아틀라스 정보를 나눠 키보드로 전환/회전

#include "../engine/core.h"

tDE_S_SheetData g_sheetDataAssets[1024];
int g_select_SheetIndex = 0;
float g_fAngle = 0;

int main(int argc, char *argv[])
{
  tDE_S_Core *pEngineCore = tDE_setup_1("example2", 640, 480, 0);

  SDL_bool bLoop = SDL_TRUE;

  {
    int nCount = 0;
    static char szBuf[256];

    FILE *fp = fopen("../res/tanks/sheet_tanks.xml", "rt");

    while (fgets(szBuf, sizeof(szBuf), fp))
    {
      tDE_S_SheetData _tmp;
      if (tDE_util_parseSheet(szBuf, &_tmp))
      {
        g_sheetDataAssets[nCount++] = _tmp;
        //   printf("%32s%4d%4d%4d%4d\n", data.szName, data.x, data.y, data.w, data.h);
      }
    }
    fclose(fp);
  }

  SDL_Texture *pTanksTex = tDE_util_loadTexture(pEngineCore, "../res/tanks/sheet_tanks.png");
  
  Uint32 _tick = SDL_GetTicks();

  while (bLoop)
  {
    SDL_Delay(1000/60);
    Uint32 _detaTick = SDL_GetTicks() - _tick;
    _tick = SDL_GetTicks();

    SDL_SetRenderDrawColor(pEngineCore->m_pRender, 0, 0, 0, 0xff);
    SDL_RenderClear(pEngineCore->m_pRender);

    {
      Uint16 sheet_index = g_select_SheetIndex;
      SDL_Point center = {g_sheetDataAssets[sheet_index].m_area.w / 2, g_sheetDataAssets[sheet_index].m_area.h / 2};
      SDL_Rect _destRt = {320 - center.x,
                          240 - center.y,
                          g_sheetDataAssets[sheet_index].m_area.w,
                          g_sheetDataAssets[sheet_index].m_area.h};
      // SDL_RenderCopy(pEngineCore->m_pRender, pTanksTex,
      //                &g_sheetDataAssets[sheet_index].m_area, &_destRt);

      SDL_RenderCopyEx(pEngineCore->m_pRender, pTanksTex, &g_sheetDataAssets[g_select_SheetIndex].m_area,
                       &_destRt, g_fAngle, &center, SDL_FLIP_NONE);
    }
    {
      SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};

      tDE_S_SheetData *_pSheet = &g_sheetDataAssets[g_select_SheetIndex];
      char szInfo[256];
      sprintf(szInfo, "%s,%4d%4d%4d%4d",
              _pSheet->szName,
              _pSheet->m_area.x,
              _pSheet->m_area.y,
              _pSheet->m_area.w,
              _pSheet->m_area.h);

      SDL_Surface *textSurface = TTF_RenderText_Solid(pEngineCore->m_pDefaultFont,
                                                      szInfo,
                                                      _whiteColor);
      SDL_Texture *pTex = SDL_CreateTextureFromSurface(pEngineCore->m_pRender, textSurface);

      SDL_Rect _dstRect = {0, 0, textSurface->w, textSurface->h};
      SDL_RenderCopy(pEngineCore->m_pRender, pTex, NULL, &_dstRect);

      SDL_FreeSurface(textSurface);
      SDL_DestroyTexture(pTex);
    }

    { //십자선 그리기
      SDL_SetRenderDrawColor(pEngineCore->m_pRender, 0x00, 0xff, 0x00, 0xff);
      SDL_RenderDrawLine(pEngineCore->m_pRender,
                         pEngineCore->m_ScreenWidth / 2, 0,
                         pEngineCore->m_ScreenWidth / 2, pEngineCore->m_ScreenHeight);
      SDL_RenderDrawLine(pEngineCore->m_pRender,
                         0, pEngineCore->m_ScreenHeight / 2,
                         pEngineCore->m_ScreenWidth, pEngineCore->m_ScreenHeight / 2);
    }

    SDL_RenderPresent(pEngineCore->m_pRender);

    
    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {

      switch (_event.type)
      {
      case SDL_KEYDOWN:
        if (_event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        {
          if (g_select_SheetIndex > 0)
          {
            g_select_SheetIndex--;
          }
        }
        else if (_event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
        {
          g_select_SheetIndex++;
        }
        else if (_event.key.keysym.scancode == SDL_SCANCODE_UP)
        {
          g_fAngle += ((float)_detaTick/100.0) * 90;
        }
        else if (_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
          g_fAngle -= ((float)_detaTick/100.0) * 90;
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

  SDL_DestroyTexture(pTanksTex);
  tDE_closeCore(pEngineCore);
  return 0;
}