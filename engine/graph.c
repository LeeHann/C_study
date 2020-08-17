#include "graph.h"

tDE_S_Node *g_pRootNode;
static Uint32 __nodeIDGenerator = 10000;

void tDE_graph_init()
{
  g_pRootNode = SDL_calloc(sizeof(tDE_S_Node), 1);
  g_pRootNode->m_nID = __nodeIDGenerator;
  __nodeIDGenerator++;
}

void tDE_graph_close()
{
  SDL_free(g_pRootNode);
}

Uint32 tDE_graph_add_node(tDE_S_Node *pNode, tDE_S_Node *pParent)
{
  pNode->m_nID = __nodeIDGenerator++;
  if(!pParent)
  {
    pParent = g_pRootNode;
  }
  if(!pParent->m_pChild)
  {
    pParent->m_pChild = pNode;
    pNode->m_pParent = pParent;
  }
  else
  {
    tDE_S_Node *_pChild = pParent->m_pChild;
    pParent->m_pChild = pNode;
    pNode->m_pParent = pParent;
    pNode->m_pNext = _pChild;
    _pChild->m_pPrev = pNode;
  }

  return pNode->m_nID;
}

void tDE_graph_Traverse(tDE_S_Node *pRoot, void (*callback)(void *node, void *ptr), void *param)