#include "graphs.h"

UndirectedGraph * ugraph_create(int v) {
  UndirectedGraph * g = malloc(sizeof(UndirectedGraph) + sizeof(struct neighbor *) * v);
  assert(g);

  g->v = v;
  g->e = 0;

  for (int i = 0; i < v; ++i) {
    g->adjacency_list[i] = malloc(sizeof(struct neighbors));
    assert(g->adjacency_list[i]);

    g->adjacency_list[i]->length = 0;
  }

  return g;
}

void ugraph_destroy(UndirectedGraph* g) {

}