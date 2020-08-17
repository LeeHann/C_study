#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../core.h"

typedef struct __S_sprite
{
  tDE_S_ObjectBase m_base;

  SDL_Texture *m_pTexture;
  SDL_Rect m_srcRect;
  SDL_Point m_ptPos;

  void (*m_callbackMouseDown)(void *);
  void (*m_callbackKeyDown)(void *);
  void (*m_callbackJoystick)(void *);

  void *m_pExtend;

} tDE_Entity_S_Sprite;

static void _destroy(void *pObj);
static void _render(void *pObj, SDL_Renderer *pRender);
static void _doEvent(void *pObj, SDL_Event *pEvt);
tDE_S_ObjectBase *tDE_Entity_createSprite(int x, int y, Uint16 nID,
                                          SDL_Rect srcRect,
                                          SDL_Texture *pTexture,
                                          void (m_callbackMouseDown)(void *),
                                          void (m_callbackKeyDown)(void *),
                                          void (m_callbackJoystick)(void *));
#endif