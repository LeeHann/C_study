#include "../engine/core.h"
#include "../engine/graph.h"

int main(int argc, char* argv[])
{
  tDE_graph_init();

  tDE_S_Node *pNode = SDL_calloc(sizeof(tDE_S_Node), 1);
  tDE_graph_add_node(pNode, NULL);

  tDE_S_Node *pNode2 = SDL_calloc(sizeof(tDE_S_Node), 1);
  tDE_graph_add_node(pNode2, NULL);

  printf("%d %d \n", pNode->m_nID, pNode2->m_nID);

  SDL_free(pNode2);
  SDL_free(pNode);
  tDE_graph_close();
  return 0;
}