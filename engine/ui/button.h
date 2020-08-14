#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct _S_BUTTON
{
  //배이스 구조체 
  S_UIBase m_base;

  SDL_Texture *m_pLable;
  SDL_Rect m_rectLabel;

  SDL_Rect m_Rect;
  Uint16 m_nFSM;
  SDL_Color m_fillColor;
  void (*m_pCallbackBtnPush)(struct _S_BUTTON *);
} S_BUTTON;

S_BUTTON *myui_createButton(SDL_Renderer *pRenderer,
                       int x, int y, int w, int h, Uint16 btnID,
                       const Uint16 *text,
                       TTF_Font *pFont,
                       void (*pCallbackBtnPush)(struct _S_BUTTON *));

#endif