#include "../engine/core.h"
#include "../engine/graph.h"

void callBackFreeAll(void *pNode, void *ptr)
{
  SDL_free(pNode);
}

void callBackTraverse(void *pNode, void *ptr)
{
  tDE_S_Node *_pnode = pNode;
  printf("%4d\n", _pnode->m_nID);
}

int main(int argc, char *argv[])
{
  tDE_graph_init();

//생성
  for(int i=0; i<10; i++)
  {
    tDE_S_Node *pNode = SDL_calloc(sizeof(tDE_S_Node), 1);
    tDE_graph_add_node(pNode, NULL);
  }
  //printf("%d %d \n", pNode->m_nID, pNode2->m_nID);

//순회
  tDE_graph_Traverse(NULL, callBackTraverse, NULL);

//검색
  tDE_S_Node *pFindNode = tDE_graph_FindNodeById(NULL, 10002);
  if(pFindNode)
  {
    printf("\n%d \n", pFindNode->m_nID);
  }

//삭제
  tDE_graph_remove_node(pFindNode, pFindNode->m_pParent);
  
  printf("--------------------------------------\n");
  tDE_graph_Traverse(NULL, callBackTraverse, NULL);

  // SDL_free(pNode2);
  // SDL_free(pNode);
  tDE_graph_Traverse(NULL, callBackFreeAll, NULL);
  tDE_graph_close();
  return 0;
}