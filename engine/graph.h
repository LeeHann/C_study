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
  
} tDE_S_Node;

void tDE_graph_init();
void tDE_graph_close();
Uint32 tDE_graph_add_node(tDE_S_Node *pNode, tDE_S_Node *pParent);
#endif