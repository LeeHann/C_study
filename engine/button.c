#include <SDL2/SDL.h>
#include <stdio.h>
#include "button.h"
#include "util.h"

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID)
{
  pBtn->bCheckHitRect = SDL_FALSE;
  pBtn->m_Rect.x = x;
  pBtn->m_Rect.y = y;
  pBtn->m_Rect.w = w;
  pBtn->m_Rect.h = h;

  pBtn->m_nID = btnID; 
}

void Button_Render(S_BUTTON *pBtn, SDL_Renderer *pRender)
{
  if(pBtn->bCheckHitRect)
  {
    SDL_SetRenderDrawColor(pRender, 255,0,0,255);
    SDL_RenderFillRect(pRender, &pBtn->m_Rect);
  }
  else
  {
    SDL_SetRenderDrawColor(pRender, 255,255,255,255);
    SDL_RenderDrawRect(pRender, &pBtn->m_Rect);
  }

}

void Button_DoEvent(S_BUTTON *pBtn, SDL_Event *pEvt)
{
  switch (pEvt->type)
  {
  case SDL_MOUSEMOTION:
    pBtn->bCheckHitRect = checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y);
    break;
  
  case SDL_MOUSEBUTTONDOWN:
    if(checkPointInRect(&pBtn->m_Rect, pEvt->motion.x, pEvt->motion.y))
    {
      printf("button ID : %d\n", pBtn->m_nID);
    }
    break;
  default:
    break;
  }
}