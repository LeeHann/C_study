#include <stdio.h>
#include <SDL2/SDL.h>
#include "button.h"
#include "util.h"

// extern SDL_bool bLoop;

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID, SDL_bool m_bVisible, void (*pCallbackBtnPush)(struct _S_BUTTON *))
{
  pBtn->m_bVisible = SDL_TRUE;
  // pBtn->bCheckHitRect = SDL_FALSE;
  pBtn->m_nFSM = 0;
  pBtn->m_Rect.x = x;
  pBtn->m_Rect.y = y;
  pBtn->m_Rect.w = w;
  pBtn->m_Rect.h = h;

  pBtn->m_fillColor.r = 0xff;
  pBtn->m_fillColor.g = 0;
  pBtn->m_fillColor.b = 0;
  pBtn->m_fillColor.a = 0;
  pBtn->m_pCallbackBtnPush = pCallbackBtnPush;
  pBtn->m_nID = btnID;
}

void Button_Render(S_BUTTON *pBtn, SDL_Renderer *pRender)
{
  if (pBtn->m_bVisible)
  {
    //반투명 모드 활성화
    SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(pRender, 255, 255, 255, 255);
    SDL_RenderDrawRect(pRender, &pBtn->m_Rect);

    SDL_SetRenderDrawColor(pRender, pBtn->m_fillColor.r, pBtn->m_fillColor.g, pBtn->m_fillColor.b, pBtn->m_fillColor.a);
    SDL_RenderFillRect(pRender, &pBtn->m_Rect);

    //반투명 모드 비 활성화
    SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_NONE);
  }
}

void Button_DoEvent(S_BUTTON *pBtn, SDL_Event *pEvt)
{
  if (pBtn->m_nFSM == 0)
  {
    switch (pEvt->type)
    {
    case SDL_MOUSEMOTION:
      if (checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y))
      {
        pBtn->m_fillColor.a = 0x80;
        pBtn->m_nFSM = 1;
      }
      break;
    }
  }
  else if (pBtn->m_nFSM == 1) //사각형 내부진입상태
  {
    switch (pEvt->type)
    {
    case SDL_MOUSEMOTION:
      if (!checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y))
      {
        pBtn->m_fillColor.a = 0;

        pBtn->m_nFSM = 0;
      }
      break;
    case SDL_MOUSEBUTTONDOWN:
      if (checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y))
      {
        if (pBtn->m_pCallbackBtnPush != NULL)
        {
          pBtn->m_pCallbackBtnPush(pBtn);
        }
      }
      break;
    }
  }
}