//xml파일에 저장된 아틀라스 정보를 나눠 키보드로 전환/회전
//맵 크기에 따라 캐릭터가 갈 수 있는 거리를 한정 짓기

//드래그로 맵 그리기
//레이어 중첩 버튼

//맵 저장, 수정, 불러오기, 초기화, 맵 전환
//캐릭터 불투명화

#include "../engine/core.h"

void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex, Uint16 _x, Uint16 _y, Uint16 _index);

tDE_S_SheetData g_sheetDataAssets[1024];
int g_select_SheetIndex = 0;
float g_fAngle = 0;

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

Uint16 g_worldMap_Layer[10][100];
Uint16 g_nSelectTileIndex = 0;

int main(int argc, char *argv[])
{
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 100; j++)
      g_worldMap_Layer[i][j] = -1;

  tDE_S_Core *pEngineCore = tDE_setup_1("example2", WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  {
    int nCount = 0;
    static char szBuf[256];

    FILE *fp = fopen("../res/tanks/sheet_tanks.xml", "rt");

    while (fgets(szBuf, sizeof(szBuf), fp))
    {
      tDE_S_SheetData _tmp;
      if (tDE_util_parseSheet(szBuf, &_tmp))
        g_sheetDataAssets[nCount++] = _tmp;
    }
    fclose(fp);
  }

  SDL_Texture *pTanksTex = tDE_util_loadTexture(pEngineCore, "../res/tanks/sheet_tanks.png");
  SDL_Texture *pMapTex = tDE_util_loadTexture(pEngineCore, "../res/dungeontiles.png");
  Uint32 _tick = SDL_GetTicks();

  SDL_bool bLoop = SDL_TRUE;
  SDL_bool bDrag_l = SDL_FALSE;
  SDL_bool bDrag_r = SDL_FALSE;

  while (bLoop)
  {
    SDL_Delay(1000 / 60);
    Uint32 _detaTick = SDL_GetTicks() - _tick;
    _tick = SDL_GetTicks();

    SDL_SetRenderDrawColor(pEngineCore->m_pRender, 0, 0, 0, 0xff);
    SDL_RenderClear(pEngineCore->m_pRender);

    { //타일 팔레트 렌더링
      putTile(pEngineCore->m_pRender, pMapTex, 15, 0, g_nSelectTileIndex);
      SDL_Rect _dstRt = {440, 100, 48 * 4, 72 * 4};
      SDL_RenderCopy(pEngineCore->m_pRender, pMapTex, NULL, &_dstRt);
    }
    { //월드맵 렌더링
      for (int i = 0; i < 100; i++)
      {
        int _index = g_worldMap_Layer[0][i];
        if (_index != -1)
          putTile(pEngineCore->m_pRender, pMapTex, i % 10, i / 10, _index);
      }
    }

    { //물체 렌더링
      Uint16 sheet_index = g_select_SheetIndex;
      SDL_Point center = {g_sheetDataAssets[sheet_index].m_area.w / 2, g_sheetDataAssets[sheet_index].m_area.h / 2};
      SDL_Rect _destRt = {320 - center.x,
                          240 - center.y,
                          g_sheetDataAssets[sheet_index].m_area.w,
                          g_sheetDataAssets[sheet_index].m_area.h};

      SDL_RenderCopyEx(pEngineCore->m_pRender, pTanksTex, &g_sheetDataAssets[g_select_SheetIndex].m_area,
                       &_destRt, g_fAngle, &center, SDL_FLIP_NONE);
    }
    { //텍스트 렌더링
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

    //월드맵 처리
    int _x = (_event.motion.x) / 32;
    int _y = (_event.motion.y) / 32;
    int _tileIndex = _y * 8 + _x;

    if (bDrag_l)
    {
      if (_x < 8 && _y < 8)
        g_worldMap_Layer[0][_tileIndex] = g_nSelectTileIndex;
    }
    if (bDrag_r)
    {
      if (_x < 8 && _y < 8)
        g_worldMap_Layer[0][_tileIndex] = -1;
    }
    
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
          g_fAngle += ((float)_detaTick / 100.0) * 90;
        }
        else if (_event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
          g_fAngle -= ((float)_detaTick / 100.0) * 90;
        }
        break;

      case SDL_MOUSEBUTTONDOWN:
      {
        if (_event.button.button == 1) //좌클릭
        {                              //팔레트 처리
          {
            int _x1 = (_event.motion.x - 440) / 32;
            int _y1 = (_event.motion.y - 100) / 32;

            if ((_x1 >= 0 && _y1 >= 0) && (_x1 < 6 && _y1 < 9))
              g_nSelectTileIndex = _y1 * 6 + _x1;
          }
          bDrag_l = SDL_TRUE;
        }
        else if (_event.button.button == 3) //우클릭
        {
          bDrag_r = SDL_TRUE;
        }
      }
      break;

      case SDL_MOUSEBUTTONUP:
        if (_event.button.button == 1)
          bDrag_l = SDL_FALSE;
        else if (_event.button.button == 3)
          bDrag_r = SDL_FALSE;
        break;

      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }

  SDL_DestroyTexture(pMapTex);
  SDL_DestroyTexture(pTanksTex);
  tDE_closeCore(pEngineCore);
  return 0;
}