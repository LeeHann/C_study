#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "core.h"

typedef struct __graph_node
{
  Uint32 m_nID;

  struct __graph_node *m_pNext;
  struct __graph_node *m_pPrev;
  
  struct __graph_node *m_pChild;
  struct __graph_node *m_pParent;
  
  void *m_pEntity;//다 담을 수 있다. 버튼/텍스트/...
} tDE_S_Node;

void tDE_graph_init();
void tDE_graph_close();
Uint32 tDE_graph_add_node(tDE_S_Node *pNode, tDE_S_Node *pParent);
void tDE_graph_Traverse(tDE_S_Node *pRoot, void (*callback)(void *node, void *ptr), void *param);
tDE_S_Node *tDE_graph_FindNodeById(tDE_S_Node *pRoot, Uint32 nID);
void tDE_graph_remove_node(tDE_S_Node *pNode);

#endif