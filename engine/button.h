#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct _S_BUTTON
{
  Uint16 m_nID;
  SDL_Rect m_Rect;
  // Uint16 m_nFSM;
  SDL_bool bCheckHitRect;

} S_BUTTON;

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID);
void Button_Render(S_BUTTON *pBtn, SDL_Renderer *pRender);
void Button_DoEvent(S_BUTTON *pBtn, SDL_Event *pEvt);

#endif